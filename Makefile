CC = gcc
CFLAGS = -Wall -Wextra -O2 -g

articles: input.l article.o vector.o
	@mkdir bin
	@flex
	$(CC) $(CFLAGS) lex.yy.cc article.o -o bin/articles
	@rm -c lex.yy.c article.o vector.o

article.o:
	$(CC)  $(CFLAGS) -c article.c

vector.o:
	$(CC)  $(CFLAGS) -c vector.c

clean:
	@rm -rf ../bin lex.yy.cc *.o 2>/dev/null || true
