#ifndef VECTOR_H
#define VECTOR_H

#include "article.h"

typedef struct vector{
  Article* vector;
  int size;
  int used;
}* Vector;


Vector new_vector();
void add_article(Vector vector, Article a);
#endif
