#include "ASlib.h"


typedef struct {
    pid_t padre;
    pid_t nieto;
    pid_t hijo;
    int destino;

} Mensaje;
const char *myfifo1;
//const char *myfifo2;

void main_nieto11(pid_t pid);
void main_nieto12(pid_t pid);
void main_nieto21(pid_t pid);
void main_nieto22(pid_t pid);
void crea_mensaje(Mensaje mensaje,int destino );
void imprimir_mensaje(Mensaje *msg_padre);
void envia_mensaje(const char *fifo, Mensaje mensaje);
void recepcion_mensaje(const char *fifo);