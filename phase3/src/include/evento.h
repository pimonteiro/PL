#ifndef _EVENTO_H_
#define _EVENTO_H_

typedef struct evento
{
    char* data; //data do evento
    char* descricao;

}*Evento;

Evento create_evento(char* data, char* desc);

#endif
