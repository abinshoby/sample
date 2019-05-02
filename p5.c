#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct message1{
    long mesg_type;
    char msg[10];

}message;

void main(){
    int pid;
    
    pid=fork();
    if(pid<0){
        printf("error");
    }
    else if(pid==0){
        execvp("./reader2",NULL);
        
    }
    else{
        wait(NULL);
        key_t token=ftok("progfile",66);
        int msgid=msgget(token,0666|IPC_CREAT);
        if(msgid==-1)
            printf("error");
        int a=msgrcv(msgid,&message,sizeof(message.msg)+1,1,0);
        printf("recieved %s ",message.msg);
   
        msgctl(msgid,IPC_RMID,NULL);
       
        
    }

}


