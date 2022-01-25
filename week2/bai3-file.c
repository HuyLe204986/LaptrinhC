#include<stdio.h>
enum {success,fail,max_len=80};
void blockreadwrite(FILE *f_in,FILE *f_out){
    int num;
    char buff[max_len+1];
    while (!feof(f_in)) //f_in kp cuối của file 
    {
        num=fread(buff,sizeof(char),max_len,f_in);
        buff[num*sizeof(char)]='\0';
        printf("\n%s",buff);
        fwrite(buff,sizeof(char),num,f_out);
    }
    
}
int main(){
    FILE *f1,*f2;
    char filename1[]="lab1a.txt";
    char filename2[]="lab1.txt";
    int reval=success;
    if((f1=fopen(filename1,"w"))==NULL){
        printf("\nCannot open %s",filename1);
        reval=fail;
    }else if((f2=fopen(filename2,"r"))==NULL){
        printf("\nCannot open %s",filename2);
        reval=fail;
    }else{
        blockreadwrite(f1,f2);
        fclose(f1);
        fclose(f2);
    }
    return reval;
}