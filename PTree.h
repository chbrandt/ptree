/* 
 * File:   PTree.h
 * Author: chbrandt
 *
 * Created on July 9, 2009, 9:27 AM
 */

#ifndef _PTREE_H
#define	_PTREE_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _PTREE_H */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


typedef struct ptree PTree;
typedef struct list List;

/* TAD - user functions */
PTree* ptree_create(char* key_file, char* text_file);
PTree* ptree_destroy(PTree* p);
void ptree_print(PTree* p);
int ptree_bit(int i, char* key);
int ptree_getoccurrences(PTree* p, char* key, int **occurrences);


/* Internal functions - PTree library stuff */
void remove_newlinechar(char* key);
int compara_chaves(char* pkey, char* key);
List* list_destroy(List* p);
List* search_text4key(char* key, char* text_file);
PTree* ptree_createleaf(char* key, PTree* p_above);
PTree* walk_upnodes(PTree* p, int bit, int flag_level);
PTree* walk_ptree(PTree* paux, char* key, int flag_type);
PTree* connect_nodes(PTree* p_newnode, char* key, PTree* p_above);
PTree* ptree_createnode(PTree* pesq, PTree* pdir, PTree* p_above, int var_bitPosition);
