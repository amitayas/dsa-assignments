#include<stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 15


int *insert(int n, int pos, int *arr, int len) {
  arr = realloc(arr, sizeof(int) * (len+1));
  for(int i = len-1 ; i >= 0 ; i--) {
    arr[i+1] = arr[i];
  }
  arr[pos] = n;
  return arr;
}

void display(int *arr, int len) {
  printf("\n");
  for(int i = 0 ; i < len ; i++){
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

int main(){
  int *arr = (int*)malloc(sizeof(int) * MAX_LENGTH);
  int len = 0;
  char c;
  while((c=getchar()) != '\n'){
    ungetc(c, stdin);
    scanf("%d", (arr+len));
    len++;
  }

  printf("\nArray you entered:- ");
  display(arr, len);

  int n, pos;
  while(1) {
    printf("enter the number you wish to insert followed by its position: ");
    scanf("%d", &n);
    scanf("%d", &pos);
    while((c = getchar()) != '\n');
    insert(n, pos, arr, len);
    len++;
    display(arr, len);
    printf("\ndo you wish to continue: (Y/n) ");
    while((c = getchar()) == ' ');
    if(c == 'n') break;
  }
}
