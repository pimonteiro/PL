CC = gcc
CFLAGS = -Wall -Wextra -O2 -g

articles: input.l article.o vector.o
	@mkdir bin
	@flex
	$(CXX) $(CFLAGS) lex.yy.cc article.o -o bin/articles
	@rm -c lex.yy.c article.o vector.o

article.o:
	$(CXX) -c article.cpp $(CFLAGS)

vector.o:
	$(CXX) -c vector.cpp $(CFLAGS)

clean:
	@rm -rf ../bin lex.yy.cc *.o 2>/dev/null || true
