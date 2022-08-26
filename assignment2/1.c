#include<stdio.h>

typedef struct Array {
  int *pointer;
  int length;
} Array;


void display(Array arr){
  printf("\n");
  for(int i = 0 ; i < arr.length ; i++){
    printf("%d\t", arr.pointer[i]);
  }
  printf("\n");
}


Array delete(int n, Array arr) {
  Array ret;
  ret.length = 0;
  for(int i = 0 ; i < arr.length; i++){
    if(arr.pointer[i] == n) continue;
    ret.pointer[ret.length] = arr.pointer[i];
    ret.length++;
  }
  return ret;
}


int main() {
  Array arr = { (int[]){1,2,3,4,3}, 5 };
  display(arr);
  display(delete(3, arr));

}
