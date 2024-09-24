#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
	pid_t pid;
	int ret = 1;
	int status;
	pid = fork();
	char* arg[] = {"./pp.exe",NULL};

	if(pid == -1){
		printf("Error en el fork\n");
		exit(EXIT_FAILURE);
	}

	else if (pid == 0){
		int fileI = open("file_i.txt", O_RDONLY);
		int fileO = open("file_o.txt", O_WRONLY | O_APPEND | O_CREAT,0644); 
		if(fileI < 0 || fileO < 0){
			perror("Error al abrir los archivos");
			exit(EXIT_FAILURE);
		}
		dup2(fileI,0);
		dup2(fileO,1);
		execv(arg[0],arg);
		perror(0);
		_exit(127);
		exit(0);
	}

	else{
		printf("Padre del padre, pid = %u\n",getppid());
		printf("Proceso padre, pid = %u\n", getpid());

		if(waitpid(pid,&status,0)>0){
			if(WIFEXITED(status) && !WEXITSTATUS(status)){
				printf("ejecucion del programa exitosa\n");
			}
			else if (WIFEXITED(status) && WEXITSTATUS(status)){
				if(WEXITSTATUS(status) == 127){
					printf("execv failed\n");
				}
				else{
					printf("El programa termino correctamente\n");
				}
			}
			else{
				printf("El programa no termino normalmente\n");
			}
		}
		else{
			printf("waitpid() fallo\n");
		}
		exit(0);

	}
	return 0;
}
