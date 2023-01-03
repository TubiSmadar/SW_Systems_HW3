#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 50

/*the finction will shift all element 1 place right */ 

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


int main() {
    // printf("Pick numbers to sort\n"); // pick the number for sorting
    int arr[ARRAY_SIZE];    
    //int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < ARRAY_SIZE; i++)
        scanf("%d", &arr[i]);
    insertion_sort(arr, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE-1; i++) {
        printf("%d,", arr[i]);
    }
    printf ("%d", arr[ARRAY_SIZE-1]);
    printf("\n");

    return 0;
}
