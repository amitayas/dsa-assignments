#include<stdio.h>
#include<stdlib.h>

#define DEFAULT_SIZE 15


typedef struct {
  int *arr;
  int len;
} Array;

int does_contain(int n, int *arr, int len) {
  for(int i = 0 ; i < len ; i++) {
    if(arr[i] == n) return 1;
  }
  return 0;
}

Array intersection(int *arr1, int len1, int *arr2, int len2) {
  int len = (len1 < len2) ? len1 : len2;
  int *intersectional_array = (int *)malloc(sizeof(int) * len);
  int flag = 0;
  for(int i = 0  ; i < len1 ; i++ ){
    if(does_contain(arr1[i], arr2, len2)) {
      intersectional_array[flag++] = arr1[i];
    }
  }
  return (Array){intersectional_array, flag};
}

Array intersection_wrapper(int *arr1, int len1, int *arr2, int len2) {
  int len = (len1 < len2) ? len1 : len2;
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
  printf("enter a fucking array: ");
  Array array1 = populate();
  printf("enter another fucking array: ");
  Array array2 = populate();

  printf("your fookin' intersectional array is here:- \n");
  Array intersectional_array = intersection(
    array1.arr,
    array1.len,
    array2.arr,
    array2.len
  );

  display(intersectional_array.arr, intersectional_array.len);
}
