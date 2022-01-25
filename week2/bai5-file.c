/*
viet chuong trinh su dung cac thao tác khối với file
để sao chép nội dung file lab1.txt-> lab1a.txt
dùng fread,fwrite,feof
*/
#include<stdlib.h>
#include<stdio.h>
enum{success,fail,max_len=80};
//    Khối 
void BlockReadWrite(FILE *fin,FILE *fout){
    int num;
    char buff[max_len];
    while (!feof(fin))
    {
        num=fread(buff,sizeof(char),max_len,fin);
        buff[num*sizeof(char)]='\0';
        printf("%s",buff);
        fwrite(buff,sizeof(char),num,fout);
    }
}
int main(){
    char filename1[]="lab1a.txt";
    char filename2[]="lab1.txt";
    int reval=success;
    FILE *f1=fopen(filename1,"w");
    FILE *f2=fopen(filename2,"r");
    if(f1==NULL){
        printf("\nKhong the mo file1");
        reval=fail;
    }else if (f2==NULL){
        printf("\nKhong the mo file2");
        reval=fail;
    }else {
        BlockReadWrite(f2,f1);
        fclose(f1);
        fclose(f2);
    }
    return reval;
}