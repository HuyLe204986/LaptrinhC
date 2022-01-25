/*
ctr đọc 2 hay nhiều dòng trong 1 mảng xâu kí tụ 
mỗi dòng trong file output in ra có dạng (chieu dai dong)(kí tự)
*/
#include<stdio.h>
#include<string.h>
enum{
    success,
    fail,
    max_len=80
};
void LineReadWrite(FILE *fin,FILE *fout){
    char s[max_len];
    int len;
    while (fgets(s,max_len,fin)!=NULL)
    {
        len=strlen(s);
        fprintf(fout,"%d %s",len,s);
    }
}
int main(){
    FILE *f1, *f2;
    char filename1[] = "lab1a.txt";
    char filename2[] = "lab1.txt";
    int reval = success;
    if ((f1 = fopen(filename1, "w")) == NULL)
    {
        printf("\nKhong the mo file");
        reval = fail;
    }
    else if ((f2 = fopen(filename2, "r")) == NULL)
    {
        printf("Cannot open %s.\n", filename2);
        reval = fail;
    }else {
        LineReadWrite(f2,f1);
        fclose(f1);
        fclose(f2);
    }
    return reval;
}