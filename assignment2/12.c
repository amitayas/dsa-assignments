#include<stdio.h>
#include<stdlib.h>

#define DEFAULT_SIZE 15

typedef struct {
  int *pointer;
  int len;
} Array;


int no_of_digits(int n) {
  int cp = n;
  int digits = 0;
  while(cp>0) {
    cp = cp/10;
    digits++;
  }
  return digits;
}

Array to_array(int n) {
  int *pointer_digits = (int *)malloc(sizeof(int) * no_of_digits(n));
  //pointer_digits[0] = 0;
  int cp = n;
  int flag = 0;
  while(cp > 0) {
    pointer_digits[flag++] = cp % 10;
    cp = cp / 10;
  }
  return (Array){pointer_digits, flag};
}


int contains(Array digits, Array number) {
  if(digits.pointer == NULL) {
    digits = (Array){(int []){0}, 1};
  }
  int flag = 0;
  for(int i = 0 ; i < digits.len ; i++) {
    flag = 0;
    for(int j = 0 ; j < number.len ; j++) {
      if(digits.pointer[i] == number.pointer[j]) {
        flag = 1;
        break;
      }

    }
    if(!(flag)) {
      free(digits.pointer);
      free(number.pointer);
      return 0;
    }
  }
  free(digits.pointer);
  free(number.pointer);

  return 1;
}


int find_the_number(int prev, int original_next) {
  int next = prev;
  while(1) {
    if(contains(to_array(original_next), to_array(next))) return next;
    next++;
  }
}

void display(Array arr) {
  printf("\n");
  for(int i = 0 ; i < arr.len ; i++) {
    printf("%d\t", arr.pointer[i]);
  }
  printf("\n");
}


void bootstrap(Array arr) {
  for(int i = 1 ; i < arr.len ; i++) {
    arr.pointer[i] = find_the_number(arr.pointer[i-1], arr.pointer[i]);
  }
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
  //Array arr = {(int []){2,9,6,3,9,8,17,3,4,6,13,5}, 12};
  printf("enter the array: ");
  Array arr = populate();
  bootstrap(arr);
  printf("array after modification: ");
  display(arr);
}
