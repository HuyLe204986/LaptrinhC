/*
queue[]:mang mo phong hang doi
size:so ptu toi da
front:chi so ptu dang o dau queue
rear:chi so cua ptu tiep theo duoc them vao cuoi cua queue
*/
void Enqueue(char queue[], char element, int &rear, int size){
    if(rear == size) printf("\nfull");
    else{
        queue[rear]=element;
        rear++;
    }
}
void Dequeue(char queue[], int &front, int rear){
    if(front==rear) printf("\nrong");
    else{
        queue[front]=0;
        front++;
    }
}
char Front(char queue[], int front) {
    return queue[front];
}
bool IsEmpty(int front, int rear) {
    return (front == rear);
}
int Size(int front, int rear) {
    return (rear - front);
}
 
#include<stdio.h>

int main(){
     char queue[20] = {'a', 'b', 'c', 'd'};        
    int front = 0, rear = 4;                
    int arraySize = 20;                // Size of the array
    int N = 3;                    // Number of steps
    char ch;
    for(int i = 0;i < N;++i) {
        ch = Front(queue, front);
        Enqueue(queue, ch, rear, arraySize);
        Dequeue(queue, front, rear);
    }
    for(int i = front;i < rear;++i)
        printf("%c", queue[i]);
    printf("\n");
    return 0;
}