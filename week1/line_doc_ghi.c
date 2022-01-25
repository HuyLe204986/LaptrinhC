//doc ki tu theo tung dong
#include <stdio.h>
enum
{
    SUCCESS,
    FAIL,
    MAX_LEN = 81
};
void LineReadWrite(FILE *fin, FILE *fout)
{
    char buff[MAX_LEN];
    while (fgets(buff, MAX_LEN, fin) != NULL)
    {
        fputs(buff, fout);
        printf("%s", buff);
    }
}
int main(){
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
        LineReadWrite(f2,f1);
        fclose(f1);
        fclose(f2);
    }
    return reval;
}