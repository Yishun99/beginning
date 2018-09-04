#include <stdint.h>
#include <stdio.h>
void print_size(int32_t array[10]){
 printf("%d\n", sizeof(array));
}
int main () {
 int32_t myArray[10];
 printf("%d ", sizeof(myArray));
 print_size(myArray);
}
