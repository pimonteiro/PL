#ifndef _UTIL_H_
#define _UTIL_H_

void factos_base(Pessoa p, FILE* f);
void imprime_pessoa(Pessoa p, FILE* f, GHashTable* hash, GList* imp);
int imprimido(GList* list, int id);

#endif