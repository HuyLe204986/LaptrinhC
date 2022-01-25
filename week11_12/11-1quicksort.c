#include<stdio.h>
#include<string.h>
 
typedef struct 
{
    char name[31];
    char phone[15];
    char email[31];

}address;
 
address L[100];

int loadfile(){
    FILE *f1=fopen("address.txt","r");
    if(f1==NULL){
        printf("\nError");
        return 0;
    }
    int i=0;
    while (i<10)
    {
        fgets(L[i].name,31,f1);
        fgets(L[i].phone,31,f1);
        fgets(L[i].email,31,f1);
        i++;
    }
    fclose(f1);
    return 1;
}

void quicksort(address a[],int left,int right){
    int i, j;
    char pivot[31];
    if (left < right){
    i = left; j = right+1;
    strcpy(pivot,a[left].name);
    do {
        do i++; while (strcmp(a[i].name,pivot)<0);
        do j--; while (strcmp(a[j].name,pivot)>0);
        if (i < j) {
            address temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    } while (i < j);
    address tmp=a[left];
    a[left]=a[j];
    a[j]=tmp;
    quicksort(a, left, j-1);
    quicksort(a, j+1, right);
    }
}
void printfile(int i){
    FILE *f2=fopen("sapxep.txt","a+");
    if(f2==NULL){
        printf("\nError");
        return;
    }
    while (i<10)
    {
        fprintf(f2,"%s",L[i].name);
        fprintf(f2,"%s",L[i].phone);
        fprintf(f2,"%s",L[i].email);
        fprintf(f2,"\n");
        i++;
    } 
    fclose(f2);
}
int main(){
    int i=0;
    if(loadfile()==0){
        printf("\nkhong the mo file");
        return 0;
    }
    quicksort(L,0,9);
    printfile(i);
	printf("Da sap xep!\n");
	return 0;
}