#include<stdio.h>
#include<stdlib.h>


int meets_condition(int n, int *mat, int order, int gap){
  int sum = 0;
  for(int i = 0 ; i < order ; i++){
    for(int j = 0 ; j < order ; j++){
      sum += mat[i * gap + j];
    }
  }
  if(sum == n) return 1;
  return 0;
}

void display(int *mat, int order, int gap) {
  printf("\n");
  for(int i = 0 ; i < order ; i++) {
    for(int j = 0 ; j < order ; j++) {
      printf("%d\t", *(mat + i * gap + j)); 
    }
    printf("\n");
  }
}

void bootstrap(int n, int *mat, int rows, int columns, int gap) {
  
  int order_max = (rows < columns) ? rows : columns;

  for(int order = 2 ; order <=  order_max ; order++) {
    for(int i = 0 ; i < rows ; i++) {
      for(int j = 0 ; j < columns ; j++) {
        if(meets_condition(n, (mat + i * gap + j), order, gap)){
          display((mat + i * gap + j), order, gap);
        }
      }
    }
  }
} 


int main() {

  int mat[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  
  int n = 12;

  bootstrap(12, mat, 3, 3 , 3);
}
