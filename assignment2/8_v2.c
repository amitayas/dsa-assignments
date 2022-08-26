#include<stdio.h>
#include<stdlib.h>


void rotate(int *mat, int order, int gap) {
  int tmp1 = mat[0 * gap + order - 1];
  //printf("\n%d\n", tmp1);
  for(int i = order - 2 ; i >= 1 ; i--) {
    mat[0 * gap + (i+1)] = mat[0 * gap + i];
  }
  int tmp2 = mat[(order - 1) * gap + order - 1];
  //printf("\n%d\n", tmp2);
  for(int i = order - 2 ; i >= 1 ; i--) {
    mat[(i+1) * gap + order - 1] = mat[i * gap + order - 1];
  }
  int tmp3 = mat[(order - 1) * gap + 0];
  //printf("\n%d\n", tmp3);
  for(int i = 1 ; i < order - 1 ; i++) {
    mat[(order - 1) * gap + i - 1] = mat[(order - 1) * gap + i];
  }
  int tmp4 = mat[0];
  //printf("\n%d\n", tmp4);
  for(int i = 1 ; i < order - 1 ; i++){
    mat[(i-1) * gap + 0] = mat[i * gap + 0];
  }
  mat[1 * gap + order - 1] = tmp1;
  mat[(order - 1) * gap + order - 2] = tmp2;
  mat[(order - 2) * gap + 0] = tmp3;
  mat[1] = tmp4;
  if(order > 3) {
    rotate((mat + 1 * gap + 1), (order - 2), gap);
  }
}

void display(int *mat, int rows, int columns, int gap) {
  for(int i = 0 ; i < rows ; i++ ) {
    for(int j = 0 ; j < columns ; j++) {
      printf("%d\t", mat[i * gap + j]);
    }
    printf("\n");
  }
}

int main() {
  ///int mat[3][3] = {
  ///  {1, 2, 3},
  ///  {4, 5, 6},
  ///  {7, 8, 9}
  ///};
  int *mat = (int*)malloc(sizeof(int) * 36);
  for(int i = 0 ; i < 36 ; i++) {
    scanf("%d", (mat + i));
  }
  rotate(mat, 6, 6);
  display(mat, 6, 6, 6);
}
