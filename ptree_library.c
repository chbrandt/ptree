
#include "PTree.h"

// Size of keywords
#define SIZE 9
#define vSIZE 9

// Flags:
#define ZERO 0
#define UM 1
#define LEAF 0
#define NODE 1
#define KEY 2
#define BELOW 0
#define ABOVE 1

#define LiNesize 121

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


/******************************************************************************/
/* Lower the characters on key: */
//

void lower_string(char* key){

    int size = strlen(key);
    int i;

    for (i=0 ; i<size ; i++)
        key[i] = tolower(key[i]);

}

/*///*/



/******************************************************************************/
/* Remove newline chars and empty lines: */
//

void remove_newlinechar(char* key) {

    int size = strlen(key);

    if (key[size - 1] == '\n')
        key[size - 1] = '\0';

}
/*///*/



/******************************************************************************/
/* WALK UP P-TREE NODES */
//

PTree* walk_upnodes(PTree* p, int bit, int flag) {

    PTree* p_ant = NULL;

    while ((p->bit > bit) && (p->p_acima != NULL)) {
        p_ant = p;
        p = p->p_acima;
    }

    if (flag == BELOW)
        return p_ant;
    else
        return p;

}
/*///*/



/******************************************************************************/
/* WALK THROUGH P-TREE NODES LOOKING FOR A LEAF */
//

PTree* walk_ptree(PTree* paux, char* key, int flag) {

    int var_bitValue;
    PTree* p_ant = NULL; //<p_ant> stores the address of the node before current position

    if(!paux)
        return NULL;

    while (paux->tipo == NODE) {
        var_bitValue = ptree_bit(paux->bit, key);
        p_ant = paux;
        if (var_bitValue == UM) {
            paux = paux->um;
        } else {
            paux = paux->zero;
        }
    }

    // Now, paux is pointing to a leaf.
    // The function can return the leaf address, the address of the last Node,
    // or NULL if it is the case that one is searching for a particular key(flag=KEY)
    // and it is (the key) not found. Otherwise, if (flag==KEY) the keys do match
    // each other, the addres of the current leaf is returned.

    if (flag == KEY)
        if (compara_chaves(key, paux->chave) == 0) {
            return paux;
        } else {
            return NULL;
        }

    if (flag == LEAF)
        return paux;
    else
        return p_ant;

}
/*///*/



/******************************************************************************/
/* CONNECT NODES INSIDE THE P-TREE */
//

PTree* connect_nodes(PTree* p_newnode, char* key, PTree* p_above) {

    int var_bitPosition;
    int var_keybitValue;

    var_bitPosition = p_above->bit;
    var_keybitValue = ptree_bit(var_bitPosition, key);

    if (var_keybitValue == ZERO)
        p_above->zero = p_newnode;
    else
        p_above->um = p_newnode;

    return p_above;
}
/*///*/



/******************************************************************************/
/* CREATE THE FIRST P-TREE NODE */
//

PTree* ptree_createnode(PTree* p_tree, PTree* p_leaf, PTree* p_above, int var_bitPosition) {

    PTree* p_node;
    int var_bitValue; // [0,1]: <key> value on bitPosition

    // In case we have leaves being connected.
    if (var_bitPosition == 0)
        var_bitPosition = compara_chaves(p_tree->chave, p_leaf->chave);

    var_bitValue = ptree_bit(var_bitPosition, p_leaf->chave);

    // Create and initialize the node..
    p_node = (PTree*) malloc(sizeof (PTree));
    p_node->bit = var_bitPosition;
    p_node->tipo = NODE;
    p_node->p_acima = p_above;
    p_node->zero = NULL;
    p_node->um = NULL;

    // Update leaves for the address corresponding to new/above node..
    p_tree->p_acima = p_node;
    p_leaf->p_acima = p_node;

    // Check where (by which bit) to connect the node to leaves..
    if (var_bitValue == UM) {
        p_node->um = p_leaf;
        p_node->zero = p_tree;
    } else {
        p_node->um = p_tree;
        p_node->zero = p_leaf;
    }

    // Return the address of the new node..
    return p_node;
}
/*///*/



/******************************************************************************/
/* CREATE P-TREE LEAF */
//

PTree* ptree_createleaf(char* key, PTree* p_above) {

    PTree* p_leaf;

    // Create the leaf node and initialize it..
    p_leaf = (PTree*) malloc(sizeof (PTree));
    strcpy(p_leaf->chave, key);
    p_leaf->tipo = LEAF;
    p_leaf->bit = 0;
    p_leaf->p_oc = NULL;
    p_leaf->p_acima = p_above;
    p_leaf->zero = NULL;
    p_leaf->um = NULL;

    // Return leaf address..
    return p_leaf;
}
/*///*/



/******************************************************************************/
/* SEARCH FOR THE GIVEN KEY INSIDE TEXT */
//

List* search_text4key(char* key, char* text_file) {

    int linhanum = 0;
    char linha[LiNesize];
    List* p = NULL;
    List *pnew, *paux;
    char* pSTR;
    int nSTR, lSTR, incr;

    FILE* fp = fopen(text_file, "rt");
    if (!fp) {
        printf("File %s could not be opened. Finishing program.\n", text_file);
        exit(EXIT_FAILURE);
    }


    while (fgets(linha, LiNesize, fp) != NULL) {

        nSTR = strlen(linha);
        incr = 1;
        if (linha[nSTR-1] == '\n'){
            incr = 0;
            linhanum++;
        }

        // Check whether the line read is empty.
        remove_newlinechar(linha);
        lower_string(linha);
        // If line is empty, go ahead..
        if (key[0] == '\0')
            continue;


        if ((pSTR = strstr(linha, key)) != NULL) {

            nSTR = strlen(key);
            if ( (pSTR[nSTR] < 65) || (pSTR[nSTR] > 122) ){
                pnew = (List*) malloc(sizeof (List));
                pnew->noc = linhanum + incr;
                pnew->p = NULL;
                if (p == NULL) {
                    p = pnew;
                    paux = p;
                } else {
                    paux->p = pnew;
                    paux = pnew;
                }
            }else{
                if( (pSTR[nSTR] > 90) && (pSTR[nSTR] < 97) ){
                    pnew = (List*) malloc(sizeof (List));
                    pnew->noc = linhanum;
                    pnew->p = NULL;
                    if (p == NULL) {
                        p = pnew;
                        paux = p;
                    } else {
                        paux->p = pnew;
                        paux = pnew;
                    }
                }
            }
        }
    }

    fclose(fp);

    return p;
}
/*///*/

