#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int *pointer;
  int len;
} Array;

Array test() {
  int pointer[] = {1,2,3};
  return (Array){pointer, 3};
}


void test2(Array arr) {
  arr.pointer[2] = 9;
}

void display(Array arr) {
  printf("\n\n");
  for(int i = 0 ; i < arr.len ; i++){
    printf("%d\t", arr.pointer[i]);
  }
  printf("\n\n");
}

void sort(Array arr) {
  int tmp;
  for(int i = 0 ; i < arr.len  - 1 ; i++){
    for(int j = 0 ; j < arr.len - i - 1 ; j++) {
      if(arr.pointer[j] > arr.pointer[j+1]){
        tmp = arr.pointer[j];
        arr.pointer[j] = arr.pointer[j+1];
        arr.pointer[j+1] = tmp;
      }
    }
  }
}



int main() {
  //display(test());
  Array arr = {(int []){1,2,4,3}, 4};
  sort(arr);
  display(arr);
}
