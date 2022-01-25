//Noi 2 chuoi s1 s2
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *my_strcat(char *s1,char *s2){
   char *result;
   int l1=strlen(s1);
   int l2=strlen(s2);
   result=(char*)malloc((l1+l2+1)*sizeof(char));
   if(result==NULL) {
       printf("\nKhong co day");
       return NULL;
   }
   strcpy(result,s1);
   strcpy(result+l1,s2); //copy s2 từ vị trí thứ L1 của s1;
    return result;
}
int main(){
    char s1[20],s2[20];
    char *result;
    fgets(s1,20,stdin);
    s1[strlen(s1)-1]='\0';
    fgets(s2,20,stdin);
    s2[strlen(s2)-1]='\0';
    result=my_strcat(s1,s2);
    printf("\n%s",result);
}
