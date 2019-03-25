#if __ARTICLE_H__
#define __ARTICLE_H__

typedef struct article *Article{
  char*  title;
  char* info;
  char*  abstract;
  char** category;
  char*  url;
};

void add_tilte(Article a, char* t, int size);
void add_info(Article a, char* t, int size);
void add_abstract(Article a, char* t, int size);
void add_category(Article a, char* t, int size);
void add_url(Article a, char* url, int size);

#endif
