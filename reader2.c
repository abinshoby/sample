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
int main(){
    key_t token=ftok("progfile",65);
    int msgid=msgget(token,0666|IPC_CREAT);
    message.msg_type = 1; 
     msgrcv(msgid,&message,sizeof(message),1,0);
        printf("recieved %s",message.msg);
    //     msgctl(msgid,IPC_RMID,NULL);
    msgctl(msgid,IPC_RMID,NULL);
    return 0;
    
}


