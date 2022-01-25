#include<stdio.h>
#define NotFound (-1)
void sapxep(int a[],int n){
    int i,j;
    for ( i = 0; i < n-1; i++)
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int tg=a[i];
                a[i]=a[j];
                a[j]=tg;
            }
        }
    
}
int binary_search(int a[],int x,int L,int R){
    if(L>R) return NotFound;
    int mid=(L+R)/2;
    if(a[mid]>x) return binary_search(a,x,L,mid-1);
    else if(a[mid]<x) return binary_search(a,x,mid+1,R);
    else return mid;
    return NotFound;
}
int main(){
    int i;
    int a[]={3,4,51,6,2,35,7,8,9};
    sapxep(a,9);
    for ( i = 0; i < 9; i++)
    {
        printf("%3d",a[i]);
    }
    
    int x;
    printf("\nNhap so can tim:");
    scanf("%d",&x);
    int kq=binary_search(a,x,0,8);
    if(kq==-1) printf("\nKhong tim thay!");
    else{
        printf("\nTim thay o vi tri:a[%d]",kq);
    }
}