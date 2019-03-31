#ifndef ARTICLE_H
#define ARTICLE_H

typedef struct article{
  char*  title;
  char** info;
  char**  abstract;
  char** category;
  char*  url;
  int n_category;
  int n_words;
  int n_info;
}* Article;

Article new_article();
void add_title(Article a, char* t, int size);
void add_info(Article a, char* t, int size);
void add_abstract(Article a, char* t, int size);
void add_category(Article a, char* t, int size);

#endif
