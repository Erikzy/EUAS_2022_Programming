#include <stdio.h>
#include "testmodule.h"


int main(){
 char * string = "Hello World";
 test(string);
 int factorialOfFive = factorial(5);
 printf("\nThe factorial of %d is %d\n",5,factorialOfFive);
 return 0;
}
