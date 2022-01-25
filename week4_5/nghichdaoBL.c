/*
Biểu thức:5*(7-4) +4*(5-3)   :biểu thức trung tố //infix
          5 7 4 - * 4 5 3 _ * + :biểu thức hậu tố //postfix
                               


Độ ưu tiên: ^  >   *,/,%   >   +-   > =
Quy ước:
-Nếu là toán hạng =>them vào queue
-Neu là toán tử(B1) +Stack rỗng =>them vào stack
                    +Nếu toán tử ngoài cùng stack là '(' thì thêm vào stack
                    +Nếu toán tử đang xét>toán tử ngoài cùng stack=>thêm toán tử đang xét vào stack
                    +Nếu toán tử đang xét<=toán tử ngoài cùng stack=>thêm toán tử ngoài cùng stack vào queue rồi quay lại B1
+Nếu là '(' =>thêm vào stack
+Nếu là ')' (B2)=> +Nếu toán tử ngoài cùng stack là '(' thì xóa dấu (
                    +nếu toán tử ngoài cùng stack kp '(' =>chuyển toán tử ngoài cùng stack vào queue rồi quay lại B2

+biểu thức hết ptu=>chuyển lần lượt các pt ở stack sang queue 


Xét         stack             queue
5                               5
*           *                   5
(           *(                  5
7           *(                  5 7
-           *(-                 5 7
4           *(-                 5 7 4
)           *                   5 7 4 -
+           +                   5 7 4 - *
4           +                   5 7 4 - * 4
*           + *                 5 7 4 - * 4
(           + * (               5 7 4 - * 4
5           + * (               5 7 4 - * 4 5
-           + * ( -             5 7 4 - * 4 5
3           + * ( -             5 7 4 - * 4 5 3
)            + *                5 7 4 - * 4 5 3 -
             biểu thức:         5 7 4 - * 4 5 3 - * +
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#define Infinity 'x' 
 
typedef struct _StackNode {
    char item;
    struct _StackNode *next;
}StackNode;
 
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
 
 
void push(Stack *s,char X){
    if(s==NULL) return;
    StackNode *newnode = (StackNode*)malloc(sizeof(StackNode));
    if(newnode==NULL) {printf("Error in memory allocation\n");exit(0);}
    newnode->item=X;
    newnode->next=NULL;

    newnode->next=s->top;
    s->top=newnode;
}
char pop(Stack *s){
    if(s==NULL) return Infinity;
    if(isEmpty(s)) return Infinity;
    char X = s->top->item;
    StackNode *tg = s->top;
    s->top=s->top->next;
    free(tg);
    return X;
}
char top(Stack *s){
    return s->top->item;
}
void StackDestroy(Stack *s) {
    while (!isEmpty(s)) {
        pop(s);
    }
    free(s);
}
int do_uu_tien(char c)
{
    if (c == '*' || c == '/')
        return 5;
    return 4;
}
int main()
{
    char s[100];
    char kq[100];
    int i;
    printf("\nNhap chuoi:");
    fgets(s,sizeof(s),stdin);
    s[strlen(s)-1]='\0';
    Stack *a=createStack();
    int j=0;
    for ( i = 0; i < strlen(s); i++)
        if (s[i] >= '0' && s[i] <= '9'){
            printf("%2c",s[i]);
            kq[j]=s[i];
            j++;
        }   
        else
        {
            if (isEmpty(a) || do_uu_tien(top(a)) < do_uu_tien(s[i]))
                push(a,s[i]);
            else
            {
                while (do_uu_tien(top(a)) >= do_uu_tien(s[i]))
                {
                    printf("%2c",top(a));
                    kq[j]=top(a);
                    j++;
                    pop(a);
                    if(isEmpty(a)) break;
                }
                push(a,s[i]);
            }
        }
    while (!isEmpty(a))
    {
        printf("%2c",top(a));
        kq[j]=top(a);
        j++;
        pop(a);
    }
    Stack *b=createStack();
    int k;
    for(k=0;k<strlen(kq);k++){
        if(isdigit(kq[k]))
            push(b,kq[k]-'0');
        else{
            int val1=pop(b);
            int val2=pop(b);
             switch (kq[k])
            {
            case '+': push(b, val2 + val1); break;
            case '-': push(b, val2 - val1); break;
            case '*': push(b, val2 * val1); break;
            case '/': push(b, val2/val1); break;
            }
        }
    }
    printf("\n%d", pop(b));
    StackDestroy(a);
    StackDestroy(b);

}
