
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
/* READ KEY OCCURRENCES ON TEXT */
//

int ptree_getoccurrences(PTree *p_tree, char *key, int **occurrences) {

    PTree* p;
    List* paux;
    int contador = 0, i;

    p = p_tree;

    // Lower key character.
    lower_string(key);

    // Walk through tree till a Leaf and check whether the keys match each other.
    p = walk_ptree(p, key, KEY);
    if (p == NULL) {
        *occurrences = NULL;
        return 0;
    }

    // If they match, count it.
    paux = p->p_oc;
    while (paux != NULL) {
        contador++;
        paux = paux->p;
    }

    // Create occurrences vector and add to it the occurrences.
    *occurrences = (int*) malloc(contador * sizeof (int));
    paux = p->p_oc;
    for (i = 0; i < contador; i++) {
        (*occurrences)[i] = paux->noc;
        paux = paux->p;
    }

    return contador;
}
/*///*/
