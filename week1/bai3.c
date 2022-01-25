#include<stdio.h>
void split(double num,int *int_part,double *frac_part){//tach so num thanh phan thuc +phan nguyen
    *int_part=(int)num;
    *frac_part=num-*int_part;
}
int main(){
    double num,fraction;
    int interger;
    printf("\nNhap so:");scanf("%lf",&num);
    split(num,&interger,&fraction);
    printf("\nPhan nguyen:%d, phan thap phan:%lf",interger,fraction);
}