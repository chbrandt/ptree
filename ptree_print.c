
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
/* PRINT TREE KEYS */
// dep:

void ptree_print(PTree* p) {

    if (p != NULL) {

        ptree_print(p->zero);
        ptree_print(p->um);

        // Find a Leaf, print key and occurrences.
        if (p->tipo == LEAF) {
            printf("%s: \t", p->chave);
            List* pL = p->p_oc;
            while (pL != NULL) {
                printf("%d ", pL->noc);
                pL = pL->p;
            }
            printf("\n");
        }

    }

    return;
}
/*///*/
