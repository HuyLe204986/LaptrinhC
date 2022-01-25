/*
doc ki tu tu 1 file va ghi ra 1 file khac 
ki tu viet hoa chuyen thanh viet thuong va nguoc lai
*/

#include <stdio.h>
void docghi_tungkitu(FILE *fin, FILE *fout)
{
    int c;
    while ((c = fgetc(fin)) != EOF)
    {   
        if(c>='A' && c<= 'Z'){
            c=c+32;
            fputc(c, fout); //ghi vao 1 file
            putchar(c);     //hien ki tu ra man hinh
        }else if(c>='a' && c<= 'z'){
            c=c-32;
            fputc(c,fout);
            putchar(c);
        }else if(c==' '){
            fputc(c, fout); 
            putchar(c); 
        }
       
    }
}
enum
{
    SUCCESS,
    FAIL
}; // cac gtri cua enum co the coi la const
int main()
{
    //printf("gia tri success:%d va fail:%d",SUCCESS,FAIL);(0,1)
    FILE *f1, *f2;
    char filename1[] = "lab1a.txt";
    char filename2[] = "lab1.txt";
    int reval = SUCCESS;
    if ((f1 = fopen(filename1, "w")) == NULL)
    {
        printf("\nKhong the mo file");
        reval = FAIL;
    }
    else if ((f2 = fopen(filename2, "r")) == NULL)
    {
        printf("Cannot open %s.\n", filename2);
        reval = FAIL;
    }else {
        docghi_tungkitu(f2,f1);
        fclose(f1);
        fclose(f2);
    }
    return reval;
}