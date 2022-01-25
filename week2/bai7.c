/*
Viết 1 chương trình nhập vào một lượng
dữ liệu danh bạ từ tệp tin (ví dụ, “dữ liệu
thứ 3 tới dữ liệu thứ 6” hoặc “dữ liệu thứu
2 tới dữ liệu thứ 3”), sửa một số dữ liệu và
lưu lại vào file.
• Nhưng,bạn phải phân phối lượng bộ nhớ
cần thiết tối thiểu để lưu trữ dữ liệu bằng
hàm malloc (kích thước cần thiết cho “dữ
liệu thứ 3 tới dữ liệu thứ 6” là 4, còn cho
“dữ liệu thứ 1 tới dữ liệu thứ 2” là 2).
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
enum {SUCCESS, FAIL, MAX_ELEMENT = 20};
// the phone book structure
typedef struct phoneaddress{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;
int main(){
    FILE *fp;
    phoneaddress *phonearr;
    int i,n, irc; // return code
    int reval = SUCCESS;
    printf("Read from 2sd data to 3rd data \n");
    if ((fp = fopen("phonebook.dat","r+b"))== NULL){
        printf("Can not open %s.\n", "phonebook.dat");
        reval = FAIL;
    }// Memory allocation
    phonearr = (phoneaddress *)malloc(2 * sizeof(phoneaddress));
    if (phonearr == NULL){
        printf("Memory allocation failed!\n");
        return FAIL;
    }if (fseek(fp,1*sizeof(phoneaddress),SEEK_SET) != 0){
        printf("Fseek failed!\n");
        return FAIL;
    }
    irc = fread(phonearr, sizeof(phoneaddress), 2, fp);
    for (i=0; i<2; i++){
        printf("%s-",phonearr[i].name);
        printf("%s-",phonearr[i].tel);
        printf("%s\n",phonearr[i].email);
        }
        // sửa dữ liệu
        strcpy(phonearr[1].name,"Lan Hoa");
        strcpy(phonearr[1].tel,"0923456");
        strcpy(phonearr[1].email,"lovelybuffalo@hut.edu.vn");
        fseek(fp,1*sizeof(phoneaddress),SEEK_SET);
        irc = fwrite(phonearr, sizeof(phoneaddress), 2, fp);
        printf(" fwrite return code = %d\n", irc);
        fclose(fp);
        free(phonearr);
        return reval;
}