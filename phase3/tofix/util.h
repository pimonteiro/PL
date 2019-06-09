#ifndef _UTIL_H_
#define _UTIL_H_
#include "../src/include/pessoa.h"
#include "../src/include/evento.h"
#include <stdio.h>

void factos_base(Pessoa p, FILE* f);
void imprime_pessoa(Pessoa p, FILE* f, GHashTable* hash, GList* imp);
int imprimido(GList* list, int id);

#endif