#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>
#include <sys/types.h>

#include "ASlib.h"
#include "nieto.h"

const char *myfifo1 = "tuberia_hijo1";
// const char *myfifo2 = "/tmp/tuberia_hijo2";

/*
void main_nieto11(pid_t pid)
{
    _exit(0);
}

void main_nieto12(pid_t pid)
{
    _exit(0);
}

void main_nieto21(pid_t pid)
{
    _exit(0);
}

void main_nieto22(pid_t pid)
{
    _exit(0);
}

void crea_mensaje(Mensaje mensaje, int destino)
{
}
*/

void imprimir_mensaje(Mensaje *mensaje)
{
    printf(" PADRE: %d\n", mensaje->padre);
    printf(" HIJO: %d\n", mensaje->hijo);
    printf(" NIETO: %d\n", mensaje->nieto);
    printf(" DESTINO: %d\n", mensaje->destino);
}


void envia_mensaje(const char *fifo, Mensaje mensaje)
{
    // Esto ha dicho Adrián que lo hagamos en el main
    // umask(0);
    // unlink(fifo);
    // mkfifo(fifo, 0666);

    int fd;
    TPrint("1- envia_mensaje linea 60");
    fd = open("tuberia_hijo1", O_RDWR); //DE AQUÍ NO PASA EL PROGRAMA NO LO ENTIENDO JODER LAS 2 DE LA MAÑANA YA


    TPrint_int("********Valor de fd: ", fd);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Escribir la estructura en el FIFO
    ssize_t bytes_escritos = write(fd, &mensaje, sizeof(mensaje));
    if (bytes_escritos == -1)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }

    close(fd);
    //TPrint_int("Bytes_escritos = ", bytes_escritos);
    printf("\n*** Mensaje enviado ***");
}


void recepcion_mensaje(const char *fifo)
{
    TPrint("Entro a recepcion mensaje");
    Mensaje mensaje;
    int fd = open(fifo, O_RDWR);
    TPrint_string("Fifo en recp msg: ", fifo);
    TPrint_int("Fifo en recp msg: ", fd);

    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    TPrint("Empiezo el read");
    
    if (read(fd, &mensaje, sizeof(Mensaje)) == -1)
    {
        perror("read");
        exit(1);
    }

    TPrint("Termino el read");
    printf("\n*** Mensaje recibido: ***\n");
    printf("Padre: %d\n", mensaje.padre);
    printf("Nieto: %d\n", mensaje.nieto);
    printf("Hijo: %d\n", mensaje.hijo);
    printf("Destino: %d\n", mensaje.destino);

    close(fd);
}



void compruebo_fifo(const char *fifo)
{
    if (access(fifo, F_OK) != -1)
    { // Verifica si el archivo FIFO existe
        printf("El archivo FIFO %s existe.\n", fifo);
        if (access(fifo, R_OK | W_OK) != -1)
        { // Verifica si el proceso tiene permiso de lectura y escritura
            printf("El proceso tiene permisos de lectura y escritura en el archivo FIFO %s.\n", fifo);
        }
        else
        {
            printf("El proceso no tiene permisos de lectura y/o escritura en el archivo FIFO %s.\n", fifo);
        }
    }
    else
    {
        printf("El archivo FIFO %s no existe.\n", fifo);
    }
}