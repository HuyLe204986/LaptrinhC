/* 
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
typedef struct Stack
{
    int top;
    unsigned capacity;
    int* array;
}Stack;
 
Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}
 
 
int Full(Stack* stack)
{   return stack->top == stack->capacity - 1; }
 
int Empty(Stack* stack)
{   return stack->top == -1;  }
void push(Stack* stack, int item)
{
    if (Full(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
int pop(Stack* stack)
{
    if (Empty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
int peek(Stack* stack)
{
    if (Empty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}
int main()
{
    Stack* stack = createStack(100);
 
    push(stack, 14);
    push(stack, 25);
    push(stack, 38);
    push(stack, 48);
    pop(stack);
    pop(stack);
    pop(stack);
    printf("Top item is %d\n", peek(stack));
 
    return 0;
}*/

//ngan xep-LIFO
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define Infinity -2000000000 
 
typedef struct _StackNode {
    int item;
    struct _StackNode *next;
} StackNode;
 
typedef struct _Stack {
    StackNode *top;
}Stack;
 

Stack *createStack(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    if(s==NULL) {printf("Error in memory allocation\n");exit(0);}
    s->top=NULL;
    return s;
}
 
int isEmpty(Stack *s){
    if(s==NULL) return 1;
    if(s->top==NULL) return 1;
    else return 0;
}
 
 
void push(Stack *s,int X){
    if(s==NULL) return;
    StackNode *newnode = (StackNode*)malloc(sizeof(StackNode));
    if(newnode==NULL) {printf("Error in memory allocation\n");exit(0);}
    newnode->item=X;
    newnode->next=NULL;

    newnode->next=s->top;
    s->top=newnode;
}
 

int pop(Stack *s){
    if(s==NULL) return Infinity;
    if(isEmpty(s)) return Infinity;
    int X = s->top->item;
    StackNode *tg = s->top;
    s->top=s->top->next;

    free(tg);
    return X;
}
 
void StackDestroy(Stack *s) {
    while (!isEmpty(s)) {
        pop(s);
    }
    free(s);
}
 
void chuyen_doi_co_so_b(Stack *s,int n,int b){
    while (n!=0)
    {
        push(s,n%b);
        n=n/b;
    }  
}

int main(){
    Stack *s=NULL;
    s = createStack();
    chuyen_doi_co_so_b(s,18,2);
    // // push(s,5);
    // // push(s,2);
    // // push(s,7);

     while(!isEmpty(s))
         printf("%d\n",pop(s));
    StackDestroy(s);
    return 1;
}