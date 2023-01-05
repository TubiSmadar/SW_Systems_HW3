#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 50

/*the function will shift all element 1 place right */ 

void shift_element(int *arr, int i) {
    int *q = arr + i;
    int temp = *q;
    for (; q > arr && *(q - 1) > temp; q--) {
        *q = *(q - 1);
    }
    *q = temp;
}



void insertion_sort(int *arr, int len) {
    int i;
    for (i = 1; i < len; i++) {
        shift_element(arr, i);
    }
}


int main(void) {

int arr[ARRAY_SIZE];
int *p = arr; // Pointer to the first element of the array
for (int i = 0; i < ARRAY_SIZE; i++) 
{
    scanf("%d", p + i); // Read value into the array using the pointer
}
insertion_sort(arr, ARRAY_SIZE); // Pass the array using its address
for (int i = 0; i < ARRAY_SIZE-1; i++) 
{
    printf("%d,", *(p + i)); // Print the value at each element using the pointer
}
printf("%d", *(p + ARRAY_SIZE-1)); // Print the last element
printf("\n"); // Make the test pass............
return 0;
}
