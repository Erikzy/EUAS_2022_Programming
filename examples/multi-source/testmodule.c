#include<stdio.h>

void test(char * string){
  printf("%s",string);
}

int factorial(int num){
   if(num > 1){
     return num * factorial(num - 1);
   }else{
     return 1;
   }
}
