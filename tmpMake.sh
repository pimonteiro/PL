make prepare && gcc -Wall -O2 -o bin/prog src/evento.c src/lex.yy.c src/pessoa.c src/util.c src/y.tab.c $(pkg-config --cflags --libs glib-2.0)
