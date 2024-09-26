#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE     128

void die(char *s)
{
  perror(s);
  exit(1);
}

struct msgbuf
{
    long    mtype;
    char    mtext[MAXSIZE];
};

char get_opt(int* numsig, int* id, long* tipo){
	char opcion;
    do{
	    printf("Seleccione el signal a enviar y digite el PID:\n");
	    printf("a) signal 2 SIGINT\n");
	    printf("b) signal 10 SIGUSR1\n");
	    printf("c) signal 12 SIGUSR2\n");
	    printf("d) signal 18 SIGCONT\n");
	    printf("e) signal 20 SIGTSTP\n");
	    printf("Ingrese su opcion y PID: ");

	    if(scanf(" %c %d", &opcion, id) != 2){
	   	printf("ENTRADA INVALIDA, VUELVA A INGRESAR SU ELECCION\n");
		while(getchar() != '\n');
		continue;
	    } 
	    opcion = tolower(opcion);

	    if(opcion <'a' || opcion > 'e'){
	   	printf("OPCION INVALIDA. INGRESE DE NUEVO SU OPCION\n");
	    }
	    else if(*id<0){
	   	printf("PID INVALIDO. INGRESE DE NUEVO SU OPCION\n");
	    }
    }while(opcion<'a' || opcion >'e' || *id<0);

    switch(opcion){
    	case 'a':
		*numsig = 2;
		*tipo = 1;
		break;
	case 'b':
		*numsig = 10;
		*tipo = 1;
		break;
	case 'c':
		*numsig = 12;
		*tipo = 1;
		break;
	case 'd':
		*numsig = 18;
		*tipo = 2;
		break;
	case 'e':
		*numsig = 20;
		*tipo = 2;	
		break;
	default:
		printf("ERROR SWITCH\n");
		break;
    }
}

main()
{
    int msqid;
    int msgflg = IPC_CREAT | 0666;
    key_t key;
    struct msgbuf sbuf;
    size_t buflen;

    key = 1234;

    if ((msqid = msgget(key, msgflg )) < 0)   //Get the message queue ID for the given key
      die("msgget");

    long tipo;
    int numsig;
    int pid;

    get_opt(&numsig, &pid, &tipo);

    //Message Type
    sbuf.mtype = tipo;
    sprintf(sbuf.mtext, "%d %d", numsig, pid);
    buflen = strlen(sbuf.mtext) + 1 ;

    if (msgsnd(msqid, &sbuf, buflen, IPC_NOWAIT) < 0)
    {
        printf ("%d, %ld, %s, %d \n", msqid, sbuf.mtype, sbuf.mtext, (int)buflen);
        die("msgsnd");
    }

    else
        printf("mensaje enviado\n");

    exit(0);
}
