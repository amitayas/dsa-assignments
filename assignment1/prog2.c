#include<stdio.h>

int** middle_rows(int *mat, int rows, int columns){
//  for(int i = 0 ; i < rows ; i++){
//    for(int j = 0 ; j < columns ; j++){
//      
//    }
//  }
  
  int* mid_range[] = {(mat + columns), (mat+columns*(rows-2))};
  return mid_range;

}

int main(){
  int mat[4][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {4,5,3}
  };


}
