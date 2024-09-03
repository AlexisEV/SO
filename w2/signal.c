#include<signal.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	int mi_sig = atoi(argv[1]);
	pid_t mi_pid =(pid_t)atoi(argv[2]);
	kill(mi_pid,mi_sig);
}
