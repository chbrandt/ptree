/* 
 * File:   main.c
 * Author: chbrandt
 *
 * Created on July 9, 2009, 9:24 AM
 */

#include "PTree.h"

/*
 * 
 */
int main(int argc, char** argv) {

    PTree* ptree;
    int *occurrences, n_occurrences;
    char keyword[9];
    int i = 0, nlinhas;

    printf("%d argumentos\n\n", argc);
    if(argc!=3){
        printf("ERROR: argumentos\n\n Sintaxe: > ptree <keysfile> <textfile>\n\n");
        exit(EXIT_FAILURE);
    }


    printf("Criando P-Tree...\n");
    ptree = ptree_create(argv[1], argv[2]);
    printf("Arvore criada.\n\n");

    printf("Qual a palavra-chave a procurar?\n");
    scanf(" %8[^\n]", keyword);

    n_occurrences = ptree_getoccurrences(ptree, keyword, &occurrences);

    if (n_occurrences <= 0)
        printf("\n Nao ha ocorrencias de %s\n\n", keyword);
    else {
        printf("\n Ocorrencias de *%s*, linhas: ", keyword);
        for (i = 0; i < n_occurrences - 1; i++)
            printf("%d, ", occurrences[i]);
        printf("%d\n\n", occurrences[n_occurrences - 1]);
    }

    printf("Indice completo:\n");
    ptree_print(ptree);
    printf("\n");

    ptree_destroy(ptree);

    return (EXIT_SUCCESS);
}
