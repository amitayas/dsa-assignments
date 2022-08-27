#include<stdio.h>
#include<stdlib.h>

#define DEFAULT_SIZE 15

typedef struct {
  int *pointer;
  int len;
} Array;

void display(Array arr){
  printf("\n");
  for(int i = 0 ; i < arr.len ; i++){
    printf("%d\t", arr.pointer[i]);
  }
  printf("\n");
}

Array delete(Array arr) {
  for(int i = 0 ; i < arr.len ; i++) {
    if(arr.pointer[i] % 2 == 0) {
      for(int j = i+1 ; j < arr.len ; j++) {
        arr.pointer[j - 1] = arr.pointer[j];
      }
      arr.len--;
    }
  }
  return arr;
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

int main() {
  printf("enter the array: ");
  Array arr = populate();
  printf("array after deleting: ");
  display(delete(arr));
}


