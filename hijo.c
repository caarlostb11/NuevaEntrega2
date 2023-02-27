#include "ASlib.h"
#include "hijo.h"
#include "nieto.h"

void crear_nietos1();
void crear_nietos2();

void main_hijo1(pid_t pid){

    crear_nietos1();
    printf("\n\n ****** ACTIVAR_RECEPCION_HIJO() ");
  

}

void main_hijo2(pid_t pid){
    
    TPrint("ESTOY EN MAIN_HIJO2");
    crear_nietos2();
    
}


void crear_nietos1(){
     pid_t pidnieto11, pidnieto12;
    
    pidnieto11 = fork(); // crea el primer proceso hijo
    
    if (pidnieto11 == 0) { // si es el proceso hijo
        pidnieto11= getpid();
        printf("Soy el nieto 11 (PID=%d)\n", pidnieto11);
        // aquí se puede ejecutar el código correspondiente del primer hijo
        main_nieto11(pidnieto11);
    }
    
    pidnieto12 = fork(); // crea el segundo proceso hijo
    
    if (pidnieto12 == 0) { // si es el proceso hijo
        pidnieto12= getpid();
        printf("Soy el nieto 12 (PID=%d)\n", pidnieto12);
        // aquí se puede ejecutar el código correspondiente del segundo hijo
        main_nieto12(pidnieto12);
    }
     waitpid(pidnieto11, NULL, 0);
    waitpid(pidnieto12, NULL, 0);
}
void crear_nietos2(){
     pid_t pidnieto21, pidnieto22;
    
    pidnieto21 = fork(); // crea el primer proceso hijo
    
    if (pidnieto21 == 0) { // si es el proceso hijo
        pidnieto21= getpid();
        printf("Soy el nieto21 (PID=%d)\n", pidnieto21);
        // aquí se puede ejecutar el código correspondiente del primer hijo
        main_nieto21(pidnieto21);
    }
    
    pidnieto22 = fork(); // crea el segundo proceso hijo
    
    if (pidnieto22 == 0) { // si es el proceso hijo
        pidnieto22= getpid();
        printf("Soy el nieto22 (PID=%d)\n", pidnieto22);
        // aquí se puede ejecutar el código correspondiente del segundo hijo
        main_nieto22(pidnieto22);
    }
     waitpid(pidnieto21, NULL, 0);
    waitpid(pidnieto22, NULL, 0);
}

void activar_recepcion_hijo(const char *fifo){
printf("\n\n ****** ACTIVAR_RECEPCION_HIJO() ");
      Mensaje msg_recibidoh1;
      //printf("%s",myfifo1);
     while (1)
    {
        recepcion_mensaje(fifo);

        //imprimir_mensaje(&msg_recibidoh1);

      //  msg_recibidoh1->hijo = pid_hijo1;
      //  printf("\n\n ****** main_hijo1 imprimir mensaje: ");
       // imprimir_mensaje(&msg_recibidoh1);
        _exit(0);
    }


}