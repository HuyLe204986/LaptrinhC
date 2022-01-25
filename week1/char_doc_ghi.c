#include <stdio.h>
void docghi_tungkitu(FILE *fin, FILE *fout)
{
    int c;
    while ((c = fgetc(fin)) != EOF)
    {
        fputc(c, fout); //ghi vao 1 file
        putchar(c);     //hien ki tu ra man hinh
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