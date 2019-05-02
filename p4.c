#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

void main(){

    char read1[100],oth[100];
    int pid;

    int fd[2];

    int s=pipe(fd);
    if(s<0)
        fprintf(stderr,"pip failed");
    else{
        pid=fork();
        if(pid<0){
           fprintf(stderr,"fork failed");
        }
        else if(pid==0){
            scanf("%s",read1);
            write(fd[1],read1,strlen(read1));
            close(fd[1]);
            exit(0);
            
        }
        else{
            wait(NULL);
            read(fd[0],oth,100);
            printf("read string is; %s",oth);
            close(fd[0]);
        }
    }
    

}