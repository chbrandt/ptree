
#include "PTree.h"

/* Size of keywords */
#define SIZE 9
#define vSIZE 9

/* Flags: */
#define ZERO 0
#define UM 1
#define LEAF 0
#define NODE 1
#define KEY 2
#define BELOW 0
#define ABOVE 1

struct list {
    int noc;
    struct list *p;
};

struct ptree {
    char chave[vSIZE];
    //  int ocorrencias;
    int bit;
    int tipo;
    struct list *p_oc;
    struct ptree *p_acima;
    struct ptree *zero;
    struct ptree *um;
};

// ----- //



/******************************************************************************/
/* CREATE PATRICIA TREE */
// dep:

PTree* ptree_create(char* key_file, char* text_file) {

    int _bit;
    int var_bitPosition, var_bitValue;
    char key[vSIZE];    // string to store keys read from key_file
    PTree *p_leaf;      // pointer to leaf structures with <key> value
    PTree *paux;        // <paux> walk within structures
    PTree *p_tree;      // main ptree pointer


    FILE* fp_keyfile = fopen(key_file, "rt");
    if (fp_keyfile == NULL) {
        fprintf(stderr, "ERROR: Unable to open the keys file. Finishing program.\n");
        exit(EXIT_FAILURE);
    }


    // Initialize the Tree pointer.
    p_tree = NULL;


    /*
     * We have to compare the new keys with the ones
     * in the tree leaves.
     */
    while (fgets(key, SIZE, fp_keyfile) != NULL) {

        // Check whether the line read is empty.
        remove_newlinechar(key);
        lower_string(key);

        // If the key is empty or is just a character, do nothing.
        if (strlen(key)<=1)
            continue;

        fprintf(stderr,"Chave sendo lida: %s\n",key);

        /*
         * First we need to treat the empty tree.
         * We simply create the first leaf to see the sun shinning...
         */
        if (p_tree == NULL) {

            p_tree = ptree_createleaf(key, NULL);
            p_tree->p_oc = search_text4key(key, text_file);
            continue;

        }

        /*
         * Right below I'll treat the particular case of
         * the second insertion (a leaf) and Node allocation.
         */
        if (p_tree->tipo == LEAF) {

            p_leaf = ptree_createleaf(key, NULL);
            p_leaf->p_oc = search_text4key(key, text_file);

            p_tree = ptree_createnode(p_tree, p_leaf, NULL, 0);

            continue;

        }

        /*
         * By now we have a tree with two leaves and a node.
         * Lets add keys to tree from now on following the next procedures.
         */
        if (p_tree->tipo == NODE) {

            // Create the leaf node with a new key.
            p_leaf = ptree_createleaf(key, NULL);
            p_leaf->p_oc = search_text4key(key, text_file);

            /* Walk through Nodes till find a Leaf. */
            paux = walk_ptree(p_tree, p_leaf->chave, LEAF); // paux is pointing to a leaf

            /* Check bit location to verify */
            _bit = paux->p_acima->bit;
            var_bitPosition = compara_chaves(paux->chave, p_leaf->chave);
            var_bitValue = ptree_bit(var_bitPosition, p_leaf->chave);

            /*
             * If the new key differs on a later bit then the existing ones (keys),
             * just add the new node in place of the old (recently compared) key.
             */
            if (var_bitPosition == _bit)
                continue;

            if (var_bitPosition > _bit) {

                paux = ptree_createnode(paux, p_leaf, paux->p_acima, var_bitPosition); // Here, paux enters as leaf and exits as node
                paux = connect_nodes(paux, p_leaf->chave, paux->p_acima); // paux exits pointing to the old node for leaves.

                continue;

            } else {

                /*
                 * Else, if the new key differs in earlier bit position, look for
                 * the place inside the tree where to place the new node.
                 */
                paux = walk_upnodes(paux, var_bitPosition, BELOW);
                paux = ptree_createnode(paux, p_leaf, paux->p_acima, var_bitPosition);
                paux = connect_nodes(paux, p_leaf->chave, paux->p_acima);

            }
            /* fi */
            p_tree = walk_upnodes(paux, 0, ABOVE);
        }
        /* fi */

    }
    /* while done */

    return p_tree;
}
/*///*/

