#include<stdio.h>
#include<string.h>
int BruteForceMatch(char T[],int n,char P[],int m){
    int i,j;
    for(i=0;i<=n-m;i++){
        j=0;
        while (j<m && T[i+j]==P[j])
        {
            j=j+1;
        }
        if(j==m) return i;
    }
    return -1;
}
//KMP
void FailureFunction(char P[],int F[],int m){
    int i=1,j=0;
    F[0]=0;
    while (i<m)
    {
        if(P[i]==P[j]){
            F[i]=j+1;
            i++;
            j++;
        }else if(j>0){
            j=F[j-1];
        }else{
            F[i]=0;
            i++;
        }
    }
}
int KMP(char T[],char P[]){
    int i,j,F[100];
    int m=strlen(P);
    int n=strlen(T);
    FailureFunction(P,F,m);
    i=0;
    j=0;
    while (i<n)
    {
        if(T[i]==P[j]){
            if(j==m-1) return i-j;
            else{
                i++;
                j++;
            }
        }else if(j>0){
            j=F[j-1];
        }else{
            i++;
        }
    }
    return -1;
}

int main(){
    char T[200];
    char P[200];
    fgets(T,200,stdin);
    T[strlen(T)-1]='\0';
    fgets(P,200,stdin);
    P[strlen(P)-1]='\0';
    int n=strlen(T);
    int m=strlen(P);
    int kq=BruteForceMatch(T,n,P,m);
    printf("\nBat dau khop o vi tri:%d",kq);
    int pos=KMP(T,P);
    printf("\nBat dau khop o vi tri %d",pos);
}
