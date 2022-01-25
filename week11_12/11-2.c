#include <stdio.h>
#include <time.h>
float insertsort(int a[], int n)
{
	clock_t time1,time2;
	time1=clock();
    int i, j;
    int next;
    for (i=1; i<n; i++){
        next= a[i];
        for (j=i-1;j>=0 && a[next]< a[j];j--) 
            a[j+1] = a[j];
        a[j+1] = next;
    }
	time2=clock();
	return (float)(time2-time1);
}
float quicksort(int a[], int left, int right)
{
	float time1,time2;
	time1=clock();
	int i, j,pivot;
    if (left < right){
    i = left; j = right+1;
    pivot=a[left];
    do {
        do i++; while (a[i]<pivot);
        do j--; while (a[j]>pivot>0);
        if (i < j) {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    } while (i < j);
    int tmp=a[left];
    a[left]=a[j];
    a[j]=tmp;
    quicksort(a, left, j-1);
    quicksort(a, j+1, right);
    }
	time2=clock();
	return (float)(time2-time1);
}
void nhapmang(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
int main()
{
	int a[100];
	int i;
	int n;
	float inserttime, quicktime;
	do
	{
		printf("Nhap n: ");
		scanf("%d",&n);
		if (n<1) printf("Nhap sai.Hay thu lai\n");
	} while (n<1);
	printf("Nhap mang :");
	nhapmang(a,n);
	inserttime=insertsort(a,n);
	quicktime=quicksort(a,0,n);
	if (inserttime==quicktime)
		printf("Bang thoi gian\n");
	else if (inserttime<quicktime)
		printf("Insert sort nhanh hon quick sort.\n");
	else printf("Quick sort  nhanh hon insert sort.\n");
	return 0;	
} 
