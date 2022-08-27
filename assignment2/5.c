#include<stdio.h>
#include<stdlib.h>

#define DEFAULT_SIZE 15

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


void bootstrap(Array arr) {
  for(int i =  0; i < arr.len - 2 ; i++) {
    for(int j = i+1 ; j < arr.len ; j++) {
      if(condition((Array){(arr.pointer + i), (j - i + 1)}))
        printf("\n%d at position %d\n", arr.pointer[j], j);
    }
  }
}

int main() {
  Array arr = populate();
  printf("\nsuch nos in the array if any:\n");
  bootstrap(arr);
}
