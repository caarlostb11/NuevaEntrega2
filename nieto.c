#include "ASlib.h"
#include "nieto.h"

const char *myfifo1 = "tuberia_hijo1";
//const char *myfifo2 = "/tmp/tuberia_hijo2";



void main_nieto11(pid_t pid){
    _exit(0);
}

void main_nieto12(pid_t pid){
    _exit(0);
}

void main_nieto21(pid_t pid){
    _exit(0);
}

void main_nieto22(pid_t pid){
    _exit(0);
}


void crea_mensaje(Mensaje mensaje,int destino ){




}

void imprimir_mensaje(Mensaje *msg_padre)
{
    printf("\n%d\n", msg_padre->padre);
    printf("%d\n", msg_padre->hijo);
    printf("%d\n", msg_padre->nieto);
    printf("%d\n", msg_padre->destino);
}


void envia_mensaje(const char *fifo, Mensaje mensaje){
   // umask(0);
   // unlink(fifo);
    TPrint("1- llego");
   // mkfifo(fifo, 0666);
    TPrint("2- llego");
    FILE *fifofd = fopen("myfifo", "w");
    TPrint("3- llego");

    if (fifofd == NULL)
    {
        perror("Error en el open");
        exit(EXIT_FAILURE);
    }

    fwrite(&mensaje, sizeof(Mensaje), 1, fifofd); //Escribir msg en el FILE


    printf("\n**********MENSAJE ENVIADO**********");
    imprimir_mensaje(&mensaje);
    fclose(fifofd); // Cerrar el archivo FIFO


}

void recepcion_mensaje(const char *fifo){

    Mensaje mensaje_recibido;
    FILE *fifofd = fopen("myfifo", "r");

    if (fifofd == NULL)
    {
        perror("Error en el open");
        exit(EXIT_FAILURE);
    }

    fread(&mensaje_recibido, sizeof(Mensaje), 1, fifofd); //Escribir msg en el FILE


    printf("\n**********MENSAJE RECIBIDO**********");
    imprimir_mensaje(&mensaje_recibido);
    fclose(fifofd); // Cerrar el archivo FIFO


}