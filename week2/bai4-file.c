#include<stdio.h>
#include<stdlib.h>
enum{success,fail,max=80};
void doc_ghi(FILE *fin){
    char s[max+1];
    int num;
    num=fread(s,sizeof(char),max,fin);
    s[num*sizeof(char)]='\0';
    printf("%s",s);
}
int main(){
    int reval=success;
    char filename2[]="haiku.txt";
    FILE *f2=fopen(filename2,"r");
    if(f2==NULL){
        printf("\nkhong mo duoc file");
        reval=fail;
        exit(0);
    }else{
      doc_ghi(f2);
      fclose(f2);
    }
    return reval;
}