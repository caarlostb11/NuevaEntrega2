// ASlib.c
// Biblioteca de funciones para Arquitectura de Sistemas II
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#include "ASlib.h"

#define N_TABS 80
static char tabs[N_TABS];


pid_t Fork(void(*proceso)()){
    pid_t pidFork = fork();
    if(pidFork < 0){
     printf("ERROR\n");
    exit(EXIT_FAILURE);
 }else if (pidFork == 0){
	TPrint_int("Soy el Hijo y mi pid es: ",getpid());
	proceso();
    exit(EXIT_SUCCESS);
 }
    return pidFork;

}






void TInit(int ntabs, int id)
	{
    int i;
    if (id < 10000000 && ntabs<N_TABS-10)
        {
		char*p=tabs;
        for (i=0; i<ntabs; i++) *p++='\t';
		sprintf(p,"[%d]",id);
		}
    else
        ERROR("Encolumnado erróneo");
    }

void TPrint(const char *texto) { printf("%s%s\n",tabs,texto); }
void TPrint_int(const char* texto, int valor) { printf("%s%s%d\n",tabs,texto,valor); }
void TPrint_float(const char* str, float valor) { printf("%s%s%0.2f\n",tabs,str,valor); }
void TPrint_string (const char *texto, const char* valor) { printf("%s%s%s\n",tabs,texto,valor); }

void Pausa(int minimo, int maximo)
	{
	int tiempo ;
	
	tiempo = (minimo < maximo)
		? (rand()%(maximo-minimo))+minimo
        : minimo;

	usleep(tiempo*1000);
	}

char *linea;
size_t tamano;
void Line_init()
	{
	linea = NULL;
	tamano = 0;
	}
char *Line_get()
	{
	ssize_t n = getline(&linea,&tamano,stdin);

	if (n == -1) {perror("Entrada erronea"); exit(EXIT_FAILURE);}
	linea[strlen(linea)-1]=0;
	return(linea);
	}
void Line_free()
	{
	free(linea);
	}

