#include<stdio.h>
#include<stdlib.h>


typedef struct {
  int *pointer;
  int len;
} Array;

void rotate_slice_right(Array arr) {
  int tmp = arr.pointer[arr.len-1];
  for(int i = arr.len - 2 ; i >= 0 ; i--) {
    arr.pointer[i+1] = arr.pointer[i];
  }
  arr.pointer[0] = tmp;
}

void rotate(Array arr, int start_index, int end_index, int n) {
  for(int i = 0 ; i < n ; i++) {
    rotate_slice_right((Array){
      (arr.pointer + start_index), (end_index - start_index + 1)
    });
  }
}

void display(Array arr) {
  printf("\n\n");
  for(int i = 0 ; i < arr.len ; i++) {
    printf("%d\t", arr.pointer[i]);
  }
  printf("\n\n");
}

int bootstrap() {
  Array arr = (Array){(int []){2,9,6,3,5,8,11,3,6,7,13,5}, 12};
  rotate(arr, 4, 9, 2);
  display(arr);
}

int main() {
  bootstrap();
}
