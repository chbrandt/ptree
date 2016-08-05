
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


void ascii2bit(char letra, int* bin);
int* int2bit(int inteiro, int* bin);
int compara_chaves(char* pkey, char* key);


/*******************************
 *
 * ptree_bit():
 *   Funcao que recebe um dado valor posicional de um procurado bit
 *   e uma string(ponteiro) para verificar o valor do tal do bit(0,1).
 *   A funcao retorna o valor do i-esimo bit (0,1) da string.

 */
int ptree_bit(int i, char* key) {
    // "i" assume valores de 1 a 64 (as palavras tem 8 letras(char) no maximo).
    // 8 letras x 8 bits = 64

    int posicao, bit;
    int bin[] = {0, 0, 0, 0, 0, 0, 0, 0};

    /*
     * Primeiro temos que encontrar que letra corresponde ao i-esimo bit pedido
     * e que bit eh este dentre os 8 de cada elemento char de uma string:
     */
    i--;
    posicao = i / 8;
    bit = i % 8;

    /*
     * Agora convertemos o caractere correspondente `a "posicao" encontrada para binario:
     */
    ascii2bit(key[posicao], bin);

    // Retorna o valor binario do bit "bit" da letra em "posicao":
    return bin[bit];
}
/* --- */

/********************************
 *
 * ascii2bit():
 *   Recebe um char de argumento e transforma em binario.
 *   A funcao retorna um ponteiro para 8 bits correspondente
 *   ao valor do char em binario.

 */
void ascii2bit(char letra, int* bin) {

    int y;
    float x, a2i;

    /*
     * Abaixo faz-se a conversao do caractere(letra) passado para binario.
     */
    a2i = (int) letra;
    a2i = (float) a2i;
    do {
        x = log2(a2i);
        y = (int) x;
        bin[7 - y] = 1;
        a2i = a2i - pow(2, y);
    } while (a2i != 0);

    /*
     * Retorna o vetor de bits correspondente ao caractere dado:
     */
    //  return bin;

}
/* --- */

/********************************
 *
 * int2bit():
 *   Recebe um inteiro de argumento e transforma em binario.
 *   A funcao retorna um ponteiro para 8 bits correspondente
 *   ao valor do char em binario.

 */
int* int2bit(int inteiro, int* bin) {

    int y;
    float x, a2i;

    /*
     * Abaixo faz-se a conversao do caractere(letra) passado para binario.
     */
    a2i = (float) inteiro;
    do {
        x = log2(a2i);
        y = (int) x;
        bin[7 - y] = 1;
        a2i = a2i - pow(2, y);
    } while (a2i != 0);

    /*
     * Retorna o vetor de bits correspondente ao caractere dado:
     */
    return bin;

}
/* --- */

/********************************
 *
 * compara_chaves():
 *   Esta funcao compara duas chaves(strings) passadas por argumento.
 *   A comparacao busca qual a letra e avalia a posicao nos bits
 *   onde ocorre a diferenca.
 *   A saida da funcao eh a posicao do bit na(s) string(s) onde
 *   estas diferiram.

 * Ex:
 ...
     string1[]='aranha'
     string2[]='arara'
     bit = compara_chave(string1,string2);   //# bit=28
 ...

 */
int compara_chaves(char* pkey, char* key) {

    int cmp = 0, i = 0;
    int treeorkey;
    int bintree[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int binkey[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int bit, size;

    /*
     * Compara se e onde (em que letra) as strings diferem:
     */
    size = strlen(pkey);
    size = (strlen(key) > size) ? strlen(key) : size;
    do {
        cmp++;
        treeorkey = strncmp(pkey, key, cmp);
    } while ((treeorkey == 0) && (cmp < size));


    /*
     * Se forem iguais as chaves, retornar valor nulo:
     */
    if (treeorkey == 0)
        return 0;

    /*
     * Converto o (valor do) caractere onde as strings diferiram para binario,
     * e comparo as cadeias de bits:
     */
    ascii2bit(pkey[cmp - 1], bintree);
    ascii2bit(key[cmp - 1], binkey);
    while (bintree[i] == binkey[i]) {
        i++;
    }

    /*
     * Posicao (em bits) em que as string diferem
     */
    bit = (cmp - 1)*8 + (i + 1);

    /*
     * Retorna posicao do bit em que as string diferem
     */
    return bit;

}
