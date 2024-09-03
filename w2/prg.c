#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sighandler(int signum){
	if(signum == 2){
		//SIGINT
		printf("Señal SIGINT(2) recibida\n");
	}
	else if(signum == 20){
		//SIGINT
		printf("Señal SIGTSTP(20) recibida\n");		
	}
	else if(signum == 18){
		//SIGCONT
		printf("Señal SIGCONT(18) recibida\n");
	}
	else if(signum == 10){
		//SIGUSR1
		printf("Señal SIGUSR1(10) recibida\n");
	}
	else if(signum == 12){
		//SIGUSR2
		printf("Señal SIGUSR2(12) recibida\n");
	}
}

int main(){
	signal(SIGINT, sighandler);
	signal(SIGTSTP, sighandler);
	signal(SIGCONT, sighandler);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	printf("ID: %d\n",(int)getpid());
	while(1){
		printf("Esperando señal..\n");
		sleep(5);
	}
}
