#include<stdio.h>


void display(int *arr, int len){
  printf("\n");
  for(int i = 0 ; i < len ; i++){
    printf("%d  ", *(arr+i));
  }
  printf("\n");
}


void swap(int *arr2, int* arr4){
  int tmp = 0;
  for(int i =0 ; i < 8 ; i++){
    tmp = *(arr2+i);
    *(arr2+i) = *(arr4+i);
    *(arr4+i) =  tmp;
  }
}


int main(){
  int arr[40];
  for(int i = 0 ; i < 40 ; i++){
    arr[i] = i;
  }
  
  display(arr, 40);

  int (*arr1)[4] = (int (*)[4])arr;
  int (*arr2)[4] = (int (*)[4])(arr+8);
  int (*arr3)[4] = (int (*)[4])(arr+16);
  int (*arr4)[4] = (int (*)[4])(arr+24);
  int (*arr5)[4] = (int (*)[4])(arr+32);

  swap(arr2, arr4);

  display(arr, 40);
}
