#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void){
	FILE *archivoMensaje = fopen("mensajes","r");
	if(archivoMensaje == NULL){
		perror("ERROR");
		exit(1);
	}

	FILE *archivoRecibidos = fopen("recibidos","w");
	if(archivoRecibidos == NULL){
		perror("ERROR");
		exit(1);
	}

	FILE *archivoNum = fopen("num","w");
	if(archivoNum == NULL){
		perror("ERROR");
		exit(1);
	}
	
	int fd[2];
	int fd2[2];
	pid_t childpid;
	int c;
	pipe(fd);
	pipe(fd2);
	char readbuffer[1000];

	if((childpid = fork()) == -1){
		perror("fork");
		exit(1);
	}
	//Proceso hijo
	if(childpid == 0){
		char* linea = NULL;
		size_t longitud = 0;
		ssize_t tamLeido;
		close(fd[0]);
		close(fd2[1]);
		ssize_t ver;
		int veces;
		while((tamLeido = getline(&linea, &longitud,archivoMensaje))!=-1){
	         	write(fd[1],linea,tamLeido); 
			if(read(fd2[0],readbuffer,sizeof(readbuffer)) == -1){
				perror("ERROR, LA VERIFICACION DEL MENSAJE NO LLEGO");
			}
		}
		fclose(archivoMensaje);
		close(fd[1]);
		read(fd2[0], readbuffer, sizeof(readbuffer));
		fprintf(archivoNum,"%s",readbuffer);
		fclose(archivoNum);
		close(fd2[0]);
	}
	//Proceso padre
	else{
		int tamLeido;
		int numMensajes = 0;
		close(fd[1]);
		close(fd2[0]);
		while((tamLeido = read(fd[0],readbuffer,sizeof(readbuffer)-1))>0){
			readbuffer[tamLeido] = '\0';
			char c = '1';
			write(fd2[1],&c,1);
			numMensajes++;
			fprintf(archivoRecibidos,"%s",readbuffer);
		}
		fclose(archivoRecibidos);
		close(fd[0]);	
		char numMsj[80];
		sprintf(numMsj,"%d",numMensajes);
		write(fd2[1],numMsj,strlen(numMsj)+1);
		close(fd2[1]);
	}

}
