#include <stdio.h>
#include<string.h>
int main() {
   char data[100];
   printf("Enter Bit String :");
   scanf("%s",data);
   printf("After Stuffing :01111110");
   int count=0;
   for(int i=0;i<strlen(data);i++){
       printf("%c",data[i]);
       if(data[i]=='1'){
           count++;
           if(count==5){
               printf("0");
               count=0;
           }
       }
       else{
           count=0;
       }
   }
   printf("01111110");
    return 0;
}
