#include<stdio.h>
#include<stdlib.h>
void reverse(int* arr, int size) {
    int* start = arr;
    int* end = arr + size - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    } 
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
      }
    printf("\n");
}