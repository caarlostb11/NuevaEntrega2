
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
#include "hijo.h"
#include "nieto.h"

// void crear_hijos();
int leer_terminal();
void compruebo_fifo(const char *fifo);

int main()
{
    unlink(myfifo1);
    umask(0);
    mkfifo(myfifo1, 0666);

    pid_t pid_padre, pid_hijo1, pid_hijo2;
    Mensaje mensaje_a_enviar;

    // Creo al padre
    pid_padre = getpid();
    TPrint_int("El pid del padre es: ", pid_padre);

    // Creación de los hijos
    if (getpid() == pid_padre)
    {
        pid_hijo1 = Fork((*main_hijo1)());
        Pausa(1, 2);
    }

    if (getpid() == pid_padre)
    {
        pid_hijo2 = Fork((*main_hijo2)());
        Pausa(1, 2);
    }

    while (1)
    {
        int numero_terminal;
        numero_terminal = leer_terminal();

        if (numero_terminal == 11 || numero_terminal == 12 || numero_terminal == 21 || numero_terminal == 22)
        {
            // *** Relleno el mensaje por defecto ***
            mensaje_a_enviar.padre = pid_padre;
            mensaje_a_enviar.hijo = pid_hijo1; //Esto debe ser 0 pero los pongo ahí para ver que funcionan
            mensaje_a_enviar.nieto = pid_hijo2; //Deber ser 0 este también
            mensaje_a_enviar.destino = numero_terminal;
        }

        switch (numero_terminal)
        {
        case 11:

            TPrint("\n\n*** Mensaje a enviar ***");
            imprimir_mensaje(&mensaje_a_enviar);
            TPrint("*** **************** ***\n");
            Pausa(1, 2);

            // Compruebo el FIFO (me dice si está creado y los permisos que tiene)
            compruebo_fifo(myfifo1);

            // Abrir el FIFO en modo escritura
            //activar_recepcion_hijo(myfifo1);
            envia_mensaje(myfifo1, mensaje_a_enviar);
            recepcion_mensaje(myfifo1);

            break;

        case 12:

            break;

        case 21:

            break;

        case 22:

            break;
        }
    }
}


int leer_terminal()
{

    char comando[4];
    char letra;
    int num = 0;

    while (1)
    {
        printf("\n*** Introduce un comando válido: ");
        fgets(comando, 100, stdin);
        sscanf(comando, "%c%d\n", &letra, &num);

        switch (letra)
        {
        case 'N':
            if (num == 11 || num == 12 || num == 21 || num == 22)
            {
                printf("*** Comando correcto ***\n");
                return num;
            }
            else
            {
                perror("\n*** Comando incorrecto ***\n");
            }
            break;

        case 'F':
            if (strcmp(comando, "FIN") != 0)
            {
                printf("\nFIN\n");
                return num;
            }
            else
            {
                perror("\n*** Comando incorrecto ***\n");
            }
            break;

        default:
            perror("*** Comando incorrecto ***\n");
            break;
        }
    }
}







//CREO QUE ESTO SE PUEDE BORRAR YA NO HACE FALTA 
/*
void crear_hijos()
{

    pid_t pid1, pid2;

    pid1 = fork(); // crea el primer proceso hijo

    if (pid1 == 0) { // si es el proceso hijo 1
        pid1 = getpid();
        printf("Soy el primer hijo (PID=%d)\n", pid1);
        // aquí se puede ejecutar el código correspondiente del primer hijo
        main_hijo1(pid1);
        exit(0); // termina el proceso hijo 1
    }

    pid2 = fork(); // crea el segundo proceso hijo

    if (pid2 == 0) { // si es el proceso hijo 2
        pid2= getpid();
        printf("Soy el segundo hijo (PID=%d)\n", pid2);
        // aquí se puede ejecutar el código correspondiente del segundo hijo
        main_hijo2(pid2);

        exit(0); // termina el proceso hijo 2
    }


    // espera a que los hijos terminen
    //waitpid(pid1, NULL, 0);
    //waitpid(pid2, NULL, 0);

}
*/
