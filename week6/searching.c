#include<stdio.h>
int duyet(int a[],int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%3d",a[i]);
    }
}
//tìm kiếm tuần tự (squential/linear search)
//tra ve vi tri neu duoc tim thay,-1 neu k tim thay
int linearsearch(int M[],int n,int x){
    int k=0;
    while (k<n && M[k]!=x)
        k++;
    if(k<n) return k;
    else return -1;
}
//tim kiem linh canh(sentinel)
int sentinelSearch(int a[],int n,int x){
    int k=0;
    a[n]=x;
    while (a[k]!=x)
        k++;
    return k;
}

//tim kiem chuyen len dau Self organizing search(move to front)
int search(int key,int r[],int n){
    int i,j;
    int tmp;
    for ( i=0; i<n&& r[i] != key; i++ );
    if(r[i]==key){
        tmp=r[i];
        for(j=i;j>0;j--){
            r[j]=r[j-1];
        }
        r[0]=tmp;
        return i;
    }else return -1;
}


int main(){
    int a[]={4,3,6,1,2,7,9,10};
    int kq=search(6,a,8);
    printf("\nVi tri tim duoc:%d",kq);
    printf("\n");
    printf("\nDay sau khi tim kiem Self organizing: ");
    duyet(a,8);
}
