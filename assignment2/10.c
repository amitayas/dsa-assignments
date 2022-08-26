#include<stdio.h>
#include<stdlib.h>

#define DEFAULT_SIZE 15

typedef struct {
  int *arr;
  int len;
} Array;

int are_equal(int *arr1, int len1, int *arr2, int len2){
  if(len1 != len2) return 0;
  for(int i = 0 ; i < len1 ; i++){
    if(arr1[i] != arr2[i]) return 0;
  }
  return 1;
}

int is_subset(int *arr1, int len1, int *arr2, int len2){
  if(len1 > len2) return 0;
  for(int i = 0 ; i < (len2-len1) ; i++) {
    if(are_equal(arr1, len1, (arr2+i), len1)) return 1;
  }
  return 0;
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

void display(int *arr, int len) {
  printf("\n\n");
  for(int i = 0 ; i < len ; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n\n");
}

int main() {
  printf("enter the first array : ");
  Array array1 = populate();
  printf("enter the second array : ");
  Array array2 = populate();
  //printf("%d", is_subset(arr1, len1, arr2, len2));
  if(is_subset(
    array1.arr,
    array1.len,
    array2.arr,
    array2.len
  )) printf("\nYes, the first array is a subset of the second one\n");
  else printf("\nNo, the first array is not a subset of the second one\n");
}
