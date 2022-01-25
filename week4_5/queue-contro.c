#include<stdio.h>
#include<stdlib.h>
typedef struct Qnode_
{
    int key;
    struct Qnode_ *next;
}Qnode;

typedef struct Q{
    Qnode *front, *rear;
}queue;


queue *createQueue(){
    queue *q=(queue*)malloc(sizeof(queue));
    q->rear=NULL;
    q->front=NULL;
    return q;
}
 int isEmpty(queue *q){
     if(q==NULL || q->front==NULL) return 1;
     else return 0;
 }
void enQueue(queue *q,int k){
    if(q==NULL) return;
    Qnode *temp=(Qnode*)malloc(sizeof(Qnode));
    temp->key=k;
    temp->next=NULL;
    if(q->rear==NULL){
        q->front=q->rear=temp;
        return;
    }
    q->rear->next=temp;
    q->rear=temp;
}

int deQueue(queue *q){
    if(isEmpty(q)) return -10000;
    int a=q->front->key;
    Qnode *temp=q->front;
    q->front=q->front->next;
    /*Nếu phía trước trở thành NULL, 
    thì thay đổi phía sau cũng là NULL*/
    if(q->front==NULL) q->rear=NULL;
    free(temp);
    return a;
}
int topQueue(queue *q){
    return q->front->key;
}
int afterQueue(queue *q){
    return q->rear->key;
}
void queueDestroy(queue *q){
    while (!isEmpty(q))
    {
        deQueue(q);
    }
    free(q);
}
int main(){
    queue *q=NULL;
    q=createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    enQueue(q, 60);
    deQueue(q);
    printf("Queue Front : %d \n", topQueue(q));
    printf("Queue Rear : %d", afterQueue(q));
     while (!isEmpty(q))
    {
        printf("\n%d ",deQueue(q));
    } 
    queueDestroy(q);
    return 0;
}