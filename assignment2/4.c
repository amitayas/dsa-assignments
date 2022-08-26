#include<stdio.h>
#include<stdlib.h>

#define MAXLENGTH 15
#define DEFAULT_SIZE 15

typedef struct {
  int *pointer;
  int len;
} Array;


void delete(int pos, int *arr, int len) {
  for(int i = pos+1 ; i < len ; i++){
    arr[i-1] = arr[i];
  }
}

int delete_all_even(int *arr, int len) {
  for(int i = 0 ; i < len ; i++){
    if(arr[i]%2==0) delete(i, arr, len--);
  }
  return len;
}


void display(int *arr, int len) {
  printf("\n\n");
  for(int i = 0 ; i < len ; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n\n");
}

Array populate() {
  int *arr = (int*)malloc(sizeof(int) * MAXLENGTH);
  int len = 0;
  int c;
  while((c=getchar()) != '\n'){
    ungetc(c, stdin);
    scanf("%d", (arr+len++));
  }
  return (Array){arr, len};
}

Array populate_v2() {
  int *pointer = (int*)malloc(sizeof(int) * DEFAULT_SIZE);
  int len = 0;
  int capacity_left = DEFAULT_SIZE;
  char c;
  while((c=getchar()) != '\n'){
    ungetc(c, stdin);
    if(capacity_left == 0){
      pointer = (int*)realloc(pointer, sizeof(int)*(len + DEFAULT_SIZE));
      capacity_left = DEFAULT_SIZE;
    }
    scanf("%d", (pointer + len++));
    capacity_left--;
  }
  return (Array){pointer, len};
}




int main(){
  printf("enter the fucking array:-\n");
  Array array = populate_v2();
  array.len = delete_all_even(array.pointer, array.len);
  display(array.pointer, array.len);
}
