#include <stdio.h>
enum{success,fail,max_len=80};
void block_cat(FILE *fin)
{
    int num;
    char buff[max_len + 1];
    while (!feof(fin))
    {
        num = fread(buff, sizeof(char), max_len, fin);
        buff[num * sizeof(char)] = '\0'; 
        printf("%s", buff);
    }
}
int main(int argc,char *argv[])
{
    FILE *fptr1, *fptr2;
    int reval = success;
    if (argc!=2){
        printf("The correct syntax should be: cat1 filename \n");
        reval = fail;
    }
    if ((fptr1 = fopen(argv[1], "r")) == NULL){
        printf("Cannot open %s.\n", argv[1]);
        reval = fail;
    }else{
        block_cat(fptr1);
        fclose(fptr1);
    }
}