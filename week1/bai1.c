#include<stdio.h>
#include<string.h>
int main(){
    int i,j;
    char s[100];
    printf("\nNhap chuoi:");
    fgets(s,sizeof s,stdin);
    int a[200]={0};
    for( i=0;i<strlen(s);i++)
        if(s[i]>='a' && s[i]<='z')
            a[s[i]]++;
    for( j=0;j<200;j++)
        if(a[j]!=0)
            printf("\nChu %c xuat hien %d lan",j,a[j]);
}
/*
a[26]={0};
char c='\0;
printf("\nNhap chuoi:"); .....
c=getchar();
while(c!='\n' && c>=0){
    if(c>='a' && c<='z')  a[c-'a']++;
    if(c>='A' && c<='Z') a[z-'A']++;
    c=getchar();
}
*/
