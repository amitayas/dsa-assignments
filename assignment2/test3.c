#include<stdio.h>
#include<stdlib.h>

void display(int *mat, int rows, int columns) {
  printf("\n");
  for(int i = 0 ; i < 3 ; i++) {
    for(int j = 0 ; j < 3 ; j++) {
      printf("%d\t", *(mat + i * columns + j)); 
    }
    printf("\n");
  }
}


int main() {
  int *mat = (int*)malloc(sizeof(int) * 3 * 3);
  for(int i = 0 ; i < 3 ; i++) {
    for(int j = 0 ; j < 3 ; j++) {
      scanf("%d", (mat + i * 3 + j));
    }
  }
  display(mat, 3, 3);
}
