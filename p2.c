#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int  call(int n){
    if(n==0)
        return;
    
       int pid=fork();
          
        if(pid==0){
            printf("child: %d parent: %d\n",getpid(),getppid());
            
           call(n-1);
           exit(0);
            //exit(0);
        }
        else{
            wait(NULL);
            //call(n-1);
            call(n-1);
            
        }
        return;
    
}
int main(){

    int n;
    printf("root parent %d",getpid());
    scanf("%d",&n);

    call(n);
    return 0;
}