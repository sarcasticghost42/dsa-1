#include<stdio.h>
#include<stdlib.h>
#define max 3
char q[max];
int front=-1,rear=-1;
void enqueue(){
    char ele;
    printf("enter ele\n");
    scanf("%s",&ele);
    if((rear+1)%max==front){
        printf("queue overflow\n");
    }
    else if(front==-1 && rear==-1){
        front=0;
        rear=0;
        q[rear]=ele;
    }
    else{
        rear=(rear+1)%max;
        q[rear]=ele;
    }
}
void dequeue(){
    char item;
    if(front==-1 && rear==-1){
        printf("queue underflow\n");
 }   else if(front==rear){
        item=q[front];
        rear=front=-1;
       // printf("%c",item);}
 }
    else{
        item=q[front];
        front=(front+1)%max;
       // printf("%d",item);
    }
}
void dis(){
    if(front==-1 && rear==-1){
        printf("Queue underflow\n");
    }
  else if(front>rear){
        for(int i=front;i<max;i++) 
        printf("%s\t",q[i]);
        for(int i=0;i<=rear;i++)
        printf("%s\t",q[i]);
    }
    else if(rear>front){
        for(int i=front;i<=rear;i++) 
        printf("%s\t",q[i]);
    }
}
int main(){
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    dis();
    printf("\n");
    dequeue();
        printf("\n");

    dis();
    enqueue();
    dis();
    return 0;
} 