#ifndef _EVENTO_H_
#define _EVENTO_H_


#define N      "nasceu"
#define M      "morreu"
#define NA     "nasceu aprox"
#define MA     "morreu aprox"

struct evento
{
    int data; //data do evento
    char* descricao;

};

typedef struct evento* Evento;


Evento create_evento(int data, char* desc);

#endif
