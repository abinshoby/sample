#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct message{
    int msg_type;
    char msg[100];

}message;
void main(){
    int pid;
    key_t token=ftok("progfile",65);
    int msgid=msgget(token,0666|IPC_CREAT);
    printf("Enter:");;
    gets(message.msg);
msgsnd(msgid,&message,sizeof(message),0);
        // printf("recieved %s",message.msg);
        //
    pid=fork();
    if(pid<0){
        printf("error");
    }
    else if(pid==0){
        execvp("./reader2",NULL);
        //msgctl(msgid,IPC_CREAT,NULL);
    }
    else{
        wait(NULL);
        //printf("\n Hello");
        msgctl(msgid,IPC_RMID,NULL);
        
    }

}


