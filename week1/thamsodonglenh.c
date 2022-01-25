/*  Viết chương trinh nhận vao 2 số dưới
    dạng tham số dòng lệnh, biểu diễn
chiều dài và chiều rộng của 1 hình chữ
nhật.(số ở dưới dạng dấu phẩy động)*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
    double width,height;
    if (argc != 3)
    {
        printf("Wrong number of arguments!\n");
        return 1;
    }
    width = atof(argv[1]);
    height = atof(argv[2]);
    printf("The rectangle's area is %f\n", width * height);
    printf("The rectangle's perimeter is %f\n", 2 * (width + height));
    return 0;
}