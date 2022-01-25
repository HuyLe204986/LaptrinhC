#include<stdio.h>
typedef struct week2
{
    double x;
    double y;
}diem;
typedef struct abc
{
   diem tam;
   double R;
}duongtron;
int is_in_circle(diem *p,duongtron *q){
    double x_dist,y_dist;
    x_dist=p->x -q->tam.x;
    y_dist=p->y -q->tam.y;
    if(x_dist*x_dist+y_dist*y_dist<(q->R)*(q->R)) return 1;
    else return 0;
}
int main(){
    diem p;
    duongtron q;
    printf("Nhap toa do diem:");scanf("%lf %lf",&p.x,&p.y);
    printf("\nNhap tam va ban kinh:");scanf("%lf %lf %lf",&q.tam.x,&q.tam.y,&q.R);
    int d=is_in_circle(&p,&q);
    printf("%d",d);
}