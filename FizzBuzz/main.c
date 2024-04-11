#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>


int main(int argc, char** argv) {
  if(argc != 2){
    printf("Usage: ./FizzBuzz Number\n");
    return 1;
  }
  
  int n = atoi(argv[1]);
  for(int i = 0; i<=n; i++){
    printf("[*]");
    if((i%3==0 && i%7==0)) printf("FIZZBUZZ\n");
    else if(i%7==0) printf("FIZZ\n");
    else if(i%3==0) printf("BUZZ\n");
    else printf("%d\n", i);
  }
  
  return 0;
}