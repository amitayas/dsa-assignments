#include<stdio.h>
#include<stdlib.h>

void rotate(int *mat, int rows, int columns, int gap) {
  int tmp1 = mat[0 * gap + columns - 1];
  for(int i = columns - 2 ; i >= 1 ; i--) {
    mat[0 * gap + (i+1)] = mat[0 * gap + i];
  }
  int tmp2 = mat[(rows - 1) * gap + columns - 1];
  for(int i = rows - 1 ; i >= 1 ; i--) {
    mat[(i+1) * gap + columns - 1] = mat[i * gap + columns - 1];
  }
  int tmp3 = mat[(rows - 1) * gap + 0];
  for(int i = 1 ; i < columns - 1 ; i++) {
    mat[(rows - 1) * gap + i - 1] = mat[(rows - 1) * gap + i];
  }
  int tmp4 = mat[0];
  for(int i = 1 ; i < rows - 1 ; i++){
    mat[(i-1) * gap + 0] = mat[i * gap + 0];
  }
  mat[1 * gap + columns - 1] = tmp1;
  mat[(rows - 1) * gap + columns - 2] = tmp2;
  mat[(rows - 2) * gap + 0] = tmp3;
  mat[1] = tmp4;
  if(rows > 3) {
    rotate((mat + 1 * gap + 1), (rows - 2), (columns - 2), gap);
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
  int *mat = (int*)malloc(sizeof(int) * 16);
  for(int i = 0 ; i < 16 ; i++) {
    scanf("%d", (mat + i));
  }
  rotate(mat, 4, 4, 4);
  display(mat, 4, 4, 4);
}
