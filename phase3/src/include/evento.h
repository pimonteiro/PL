#ifndef _EVENTO_H_
#define _EVENTO_H_

#include <glib.h>

typedef struct evento* Evento;


Evento create_evento(char* data, char* desc);

#endif
