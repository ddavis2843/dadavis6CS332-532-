#include <stdio.h>
#include <stdlib.h>


void print_array(int arr[], int size) {

    printf("[");

    for (int i = 0; i < size; i++) {

        printf("%d", arr[i]);

        if (i < size - 1) {
            
            printf(", ");
        }
    }
    printf("]\n");
}

//insertion sort algorithimn
int main() {

    int n, i;

    // user input

    printf("enter # of elements : ");

    // display number of elements

    scanf("%d", &n);

    // check for correct # of elements

    if (n <= 0) {
        printf("the number of elements must be greater than 0.\n");

        return 1;
    }


    int arr[n];

    printf("Enter %d integers, pressing Enter after each one:\n", n);

    
    for (i = 0; i < n; i++) {

        scanf("%d", &arr[i]);
    }

    printf("og array: ");

    print_array(arr, n);

    // implementation
    for (int j = 1; j < n; j++) {

        int key = arr[j];

        int i = j - 1;

        
        while (i >= 0 && arr[i] > key) {

            arr[i + 1] = arr[i];

            i = i - 1;
        }
        arr[i + 1] = key;
    }

    // print
    printf("sorted array: ");

    print_array(arr, n);


    return 0;
}
