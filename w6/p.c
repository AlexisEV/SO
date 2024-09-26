#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sighandler(int signum){
	if(signum == 2){
		//SIGINT
		printf("Señal SIGINT(2) recibida\n");
		signal(SIGINT,SIG_DFL);
		raise(SIGINT);
	}
	else if(signum == 20){
		//SIGTSTP
		printf("Señal SIGTSTP(20) recibida\n");
		signal(SIGTSTP,SIG_DFL);
		//raise(SIGSTOP);		
	}
	else if(signum == 18){
		//SIGCONT
		printf("Señal SIGCONT(18) recibida\n");
		signal(SIGCONT,SIG_DFL);
		raise(SIGCONT);
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
	struct sigaction sa;
	sa.sa_handler = sighandler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTSTP, &sa, NULL);
	sigaction(SIGCONT, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	
	printf("ID: %d\n",(int)getpid());
	while(1){
		printf("Esperando señal..\n");
		sleep(15);
	}
}
