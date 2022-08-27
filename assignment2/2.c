#include<stdio.h>
#include<stdlib.h>

#define DEFAULT_SIZE 15


typedef struct {
  int *pointer;
  int len;
} Array;


int reverse_number(int n) {
  int cp = n;
  int rev = 0;
  while(cp > 0) {
    rev = rev * 10 + cp % 10;
    cp = cp / 10;
  }
  return rev;
}

void reverse_array_elements(Array arr, int (*condition)(int)){
  for(int i = 0 ; i < arr.len ; i++) {
    if(condition(i)){
      arr.pointer[i] = reverse_number(arr.pointer[i]);
    }
  }
}

int condition_even(int n) {
  if(n%2 == 0) return 1;
  return 0;
}

int condition_odd(int n) {
  if(n%2 == 0) return 0;
  return 1;
}

Array populate(){
  int *arr = (int*)malloc(sizeof(int) * DEFAULT_SIZE);
  int len = 0;
  int capacity_left = DEFAULT_SIZE;
  char c;
  while((c=getchar()) != '\n'){
    ungetc(c, stdin);
    if(capacity_left == 0) {
      arr = realloc(arr, sizeof(int) * (len + DEFAULT_SIZE));
      capacity_left = DEFAULT_SIZE;
    }
    scanf("%d", (arr+len++));
    capacity_left--;
  }
  return (Array){arr, len};
}

void display(Array arr) {
  printf("\n");
  for(int i = 0 ; i < arr.len ; i++) {
    printf("%d\t", arr.pointer[i]);
  }
  printf("\n");
}

int main() {
  printf("enter the fucking array: ");
  Array arr = populate();
  int (*condition)(int) = (arr.len % 2 ==0) ? &condition_even : &condition_odd;
  reverse_array_elements(arr, condition);
  printf("modified array:-\n");
  display(arr);
}
