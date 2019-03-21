#if __VECTOR_H__
#define __VECTOR_H__

typedef struct vector *Vector{
  Article** vector;
  int size;
};

void add_article(Vector vector, Article a);
#endif
