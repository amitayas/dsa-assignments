#include<stdio.h>
#include<stdlib.h>

#define DEFAULT_SIZE 15

typedef struct {
  int *pointer;
  int len;
} Array;

Array insert(int n, int pos, Array arr) {
  if(pos >= arr.len) pos = arr.len;
  arr.pointer = realloc(arr.pointer, (++arr.len));
  for(int i = arr.len - 2 ; i >= pos ; i--) {
    arr.pointer[i + 1] = arr.pointer[i];
  }
  arr.pointer[pos] = n;
  return arr;
}

void display(Array arr){
  printf("\n");
  for(int i = 0 ; i < arr.len ; i++){
    printf("%d\t", arr.pointer[i]);
  }
  printf("\n");
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

  char c;
  int n, pos;
  while(1) {
    printf("enter the number you wish to insert followed by its position: ");
    scanf("%d", &n);
    scanf("%d", &pos);
    while((c = getchar()) != '\n');
    arr = insert(n, pos, arr);
    display(arr);
    printf("\ndo you wish to continue: (Y/n) ");
    while((c = getchar()) == ' ');
    if(c == 'n') break;
  }
}
