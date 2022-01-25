#include<stdio.h>
void merge(int a[],int l,int m,int r){
    int i,k,j;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1];
    int R[n2];
    for(i=0;i<n1;i++)
        L[i]=a[l+i];
    for(j=0;j<n2;j++)
        R[j]=a[m+1+j];
    i=0;
    k=l;
    j=0;
    while (i<n1 && j<n2)
    {
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }else{
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
     while (j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    } 
}
void merge_sort(int a[],int l,int r){
    if (l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
    
}
void duyet(int a[],int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%3d",a[i]);
    }
    
}
int main(){
    int a[]={3,66,51,23,87,9,1,25};
    merge_sort(a,0,7);
    duyet(a,8);
}