#ifndef __VECTOR_H__
#define __VECTOR_H_

#include "article.h"

typedef struct vector* Vector;

Vector new_vector();
void add_article(Vector vector, Article a);
#endif
