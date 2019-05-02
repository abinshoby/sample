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
int main(){
    key_t token=ftok("progfile",66);
    int msgid=msgget(token,0666|IPC_CREAT);
    if(msgid==-1)
        printf("error");
    
    printf("Enter:");;
    gets(message.msg);
    message.mesg_type=1;
    if( (msgsnd(msgid,&message,sizeof(message.msg),0))==-1)
    {
        printf("eror");
        
    }
    msgctl(msgid,IPC_CREAT,NULL);
    return 0;
    
}


