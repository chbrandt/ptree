
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


List* list_destroy(List* p);


/******************************************************************************/
/* DELETE P-TREE NODES*/
// dep:

PTree* ptree_destroy(PTree* p) {

    if (p != NULL) {
        ptree_destroy(p->zero);
        ptree_destroy(p->um);
        list_destroy(p->p_oc);
        free(p);
    }

    return NULL;
}
/*///*/


/******************************************************************************/
/* DELETE LIST OF KEY OCCURRENCES */
// dep:

List* list_destroy(List* p) {
    if (p != NULL) {
        list_destroy(p->p);
        free(p);
    }
    return NULL;
}
/*///*/
