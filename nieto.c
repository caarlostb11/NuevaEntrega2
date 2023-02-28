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
    //mkfifo(fifo, 0666);
    TPrint("2- llego");


     // Crear el FIFO si no existe
     TPrint("3- llego");
    // Abrir el FIFO en modo escritura
    int fd = open(fifo, O_WRONLY);
    TPrint("4- llego");
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

       TPrint("5- llego");
    
    // Escribir la estructura en el FIFO
    ssize_t bytes_escritos = write(fd, &mensaje, sizeof(mensaje));
    if (bytes_escritos == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    
    // Cerrar el FIFO
    close(fd);

    printf("\n**********MENSAJE ENVIADO**********");
   


}

void recepcion_mensaje(const char *fifo){
   
    Mensaje mensaje;
    int fd = open(fifo, O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(1);
    }

    if (read(fd, &mensaje, sizeof(Mensaje)) == -1) {
        perror("read");
        exit(1);
    }

    printf("Mensaje recibido:\n");
    printf("Padre: %d\n", mensaje.padre);
    printf("Nieto: %d\n", mensaje.nieto);
    printf("Hijo: %d\n", mensaje.hijo);
    printf("Destino: %d\n", mensaje.destino);

    close(fd);


}