#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int isprime(int n){
    if(n==1)
        return 0;
    for(int i=2;i<n/2+1;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main(){
    
    int nos[10];
    int n;
    printf("\n enter n");
    scanf("%d",&n);
    printf("Enter values:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&nos[i]);
    }
    
    int pid=fork();
    if(pid<0)
        fprintf(stderr,"fork faliled\n");
    else if(pid==0){
        int t=0;
        
        for(int i=0;i<n;i++){
        if(isprime(nos[i])==1)
            t+=nos[i];
        
        }
    
    printf("child computes:%d",t);
    exit(0);

    }
    else{
        wait(NULL);
        printf("\n Child finished execution");
        int s=0;
    for(int i=0;i<n;i++){
        if(isprime(nos[i])==0)
            s+=nos[i];
    }
    printf("\n Parent compute value:%d",s);
    }

    return 0;
}