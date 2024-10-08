#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

#define KEY 0x1111

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

struct sembuf p = {0, -1, SEM_UNDO};
struct sembuf v = {0, +1, SEM_UNDO};

int main()
{
    int id = semget(KEY, 1, 0666 | IPC_CREAT);
    if (id < 0)
    {
        perror("semget");
        exit(11);
    }
    union semun u;
    u.val = 0;
    if (semctl(id, 0, SETVAL, u) < 0)
    {
        perror("semctl");
        exit(12);
    }
    while(1){
        if (semop(id, &p, 1) < 0){
            perror("semop p");
            exit(13);
        }
        for(int i = 0; i<4000;i++){
            printf("Hola mundo\n");
            sleep(0.5);
        }
        system("clear");
        if (semop(id, &v, 1) < 0){
            perror("semop p");
            exit(13);
        }
    }
}