#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int *pointer;
  int len;
} Array;

int condition(Array arr) {
  int sum = 0 ;
  for(int i = 0 ; i < arr.len - 1 ; i++) {
    sum += arr.pointer[i];
  }
  return (arr.pointer[arr.len-1] == sum) ? 1 : 0;
}

void bootstrap(Array arr) {
  for(int i =  0; i < arr.len - 2 ; i++) {
    for(int j = i+1 ; j < arr.len ; j++) {
      if(condition((Array){(arr.pointer + i), (j - i + 1)}))
        printf("\n%d at position %d\n", arr.pointer[j], j);
    }
  }
}

int main() {
  Array arr = {(int []){2,9,6,3,9,8,17,3,6,4,13,17}, 12};
  bootstrap(arr);
}
