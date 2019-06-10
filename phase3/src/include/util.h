#ifndef _UTIL_H_
#define _UTIL_H_

void factos_base(Pessoa p, FILE* f, GList* imp);
void imprime_pessoa(Pessoa p, FILE* f, GHashTable* hash, GList* imp);
int imprimido(GList* list, int id);
void imprime_prolog(Pessoa p, FILE* f, GHashTable* hash, GList* imp);

#endif
