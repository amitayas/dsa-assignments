#include<stdio.h>
#include<stdlib.h>

#define DEFAULT_SIZE 15

typedef struct {
  int *pointer;
  int len;
} Array;

int delete(int value, int *arr, int len) {
  for(int i = 0 ; i < len ; i++) {
    if(arr[i] == value) {
      for(int j = i+1 ; j < len ; j++) {
        arr[j-1] = arr[j];
      }
      len--;
    }
  }
  return len;
}

int delete_duplicates(int *arr, int len) {
  for(int i = 0 ; i < len ; i++) {
    len = delete(arr[i], (arr+i+1), (len-i-1)) + i + 1;
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
  Array array = populate();
  int *arr = array.pointer;
  int len = array.len;
  len = delete_duplicates(arr, len);

  display(arr, len);
}
