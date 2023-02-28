// ASlib.
// Biblioteca de funciones para Arquitectura de Sistemas II

#ifndef TOOLS_H
#define TOOLS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>
#include <sys/types.h>


pid_t Fork(void(*proceso)());
void TInit(int ntabs, int id);
void TPrint(const char *texto);
void TPrint_int(const char *texto, int valor);
void TPrint_float(const char *texto, float valor);
void TPrint_string (const char *texto, const char* valor);

void Pausa(int minimo, int maximo);

void Line_init();
char *Line_get();
void Line_free();

#define TRACE \
    printf("%s:%d\n",__FILE__,__LINE__)
    
#define ERROR(msj)\
    {\
    fprintf(stderr,"ERROR %s--> %s:%d\n",msj,__FILE__,__LINE__);\
    exit(EXIT_FAILURE);\
    }

#endif
