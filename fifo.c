#include "ASlib.h"
#include "hijo.h"
#include "nieto.h"


//void crear_hijos();
int leer_terminal();

int main(){
    unlink(myfifo1);
    umask(0); // Descubrir luego q es
    mkfifo(myfifo1,S_IFIFO|0666);
    pid_t pid_padre = getpid();
    TPrint_int("El pid del padre es: ", pid_padre);
   
    //unlink(myfifo2);
  
    if(getpid() == pid_padre){
        pid_t pid_hijo1 =Fork(main_hijo1());
            
    }

    if(getpid() == pid_padre){
        pid_t pid_hijo2 =Fork(main_hijo2());
    }


    
    //sleep(3);
    //mkfifo(myfifo2, S_IFIFO | 0666);
   /*
   while(1){
    //Leemos comando por terminal
    int numero_terminal;
    numero_terminal = leer_terminal();

    if(numero_terminal==11 || numero_terminal==12 || numero_terminal == 21 || numero_terminal==22 ){
        TPrint("HACEMOS COSITAS");
        Mensaje mensaje_a_enviar;
        mensaje_a_enviar.padre = pid_padre;
        mensaje_a_enviar.hijo = 0;
        mensaje_a_enviar.nieto = 0;
        mensaje_a_enviar.destino=numero_terminal;

        TPrint_int("NUMERO TERMINAL: ", numero_terminal);

        switch (numero_terminal){
            case 11:
                TPrint("ENTRAMOS EN CASE 11");
                //printf("MYFIFO1: %s", myfifo1);
                //imprimir_mensaje(&mensaje_a_enviar);
                envia_mensaje(myfifo1, mensaje_a_enviar);
                activar_recepcion_hijo(myfifo1);

                break;

            case 12:

                break;

            case 21:

                break;

            case 22:

                break;
        }
    }

   
   
    
   
   }*/

}

/*
void crear_hijos(){

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

}*/

int leer_terminal(){

    char comando[4];
    char letra;
    int num = 0;

    while(1){
        printf("\nIntroduce un comando válido: ");
        fgets(comando,100, stdin);
        sscanf(comando, "%c%d\n", &letra, &num);

        switch(letra){
            case 'N':
                if(num == 11 || num==12 || num == 21 || num ==22){
                    printf("***COMANDO CORRECTO***\n");

                    return num;
                } else {
                    printf("\ncomando inválido");
                } 
                break;

            case 'F':
                if(strcmp(comando, "FIN") != 0){
                    printf("\nFIN\n");
                    return num; 
                }else{ 
                    printf("\ncomando inválido\n");
                } 
                break;

            default: 
                printf("comando invalido\n");
                break;
        }
    }
    


}


