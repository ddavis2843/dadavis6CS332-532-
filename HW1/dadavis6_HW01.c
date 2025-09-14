#include <stdio.h>
#include <stdlib.h> // Required for malloc and free
#include <string.h> // Required for strlen and strcpy
#include <ctype.h>  // Required for tolower
#include <math.h>   // Required for sqrt

// func 1: sumOfDigits(n)
// function takes a positive integer n and returns the sum of its digits.
// Returns -1 if n is less than or equal to 0
int sumOfDigits(int n) {

    if (n <= 0) {

        return -1;
    }
    int sum = 0;
    while (n > 0) {

        sum += n % 10;
        n /= 10;
    }

    return sum;
}

// func 2: UABMaxMinDiff(arr, size)
// function takes an array of integers and its size, then returns the difference
// between the maximum and minimum elements in the array
int UABMaxMinDiff(int arr[], int size) {
    
    if (size <= 0) {
        return 0; //empty or invalid array
    }

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {

        if (arr[i] < min) {

            min = arr[i];
        }
        if (arr[i] > max) {

            max = arr[i];
        }
    }
    return max - min;
}

// func 3: replaceEvenWithZero(arr, size)
// takes an array of integers and its size, and returns a new array
// with all even numbers replaced by 0

int* replaceEvenWithZero(int arr[], int size) {
    if (size <= 0) {

        return NULL;
    }
    int* newArr = (int*)malloc(size * sizeof(int));

    if (newArr == NULL) {

        return NULL; // null in case memory allocation fails
    }
    for (int i = 0; i < size; i++) {

        if (arr[i] % 2 == 0) {
            newArr[i] = 0;

        } else {
            newArr[i] = arr[i];
        }
    }
    return newArr;
}

// func 4: perfectSquare(n)
// takes an integer n and returns True (1) if it is a perfect square,
_Bool perfectSquare(int n) {
    if (n < 0) {
        return 0; 
    }
    if (n == 0) {
        return 1; 
    }
    int root = (int)sqrt(n);

    return (root * root == n);
}

// func 5: countVowels(s)
// Takes a string s and returns the number of vowels (a, e, i, o, u)
int countVowels(char* s) {
    if (s == NULL) {

        return 0;
    }

    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {

        char ch = tolower(s[i]);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

// function to print int arrays
void printIntArray(int arr[], int size) {
    if (arr == NULL) {

        printf("NULL");

        return;
    }
    printf("[");
    for (int i = 0; i < size; i++) {

        printf("%d", arr[i]);
        if (i < size - 1) {

            printf(", ");
        }
    }
    printf("]");
}

// main

int main() {
    printf("--- sumOfDigits ---\n");
    printf("n=123, Expected: 6, Output: %d\n", sumOfDigits(123));
    printf("n=405, Expected: 9, Output: %d\n", sumOfDigits(405));
    printf("n=0, Expected: -1, Output: %d\n", sumOfDigits(0));
    printf("n=7, Expected: 7, Output: %d\n", sumOfDigits(7));
    printf("n=-308, Expected: -1, Output: %d\n", sumOfDigits(-308));
    printf("\n");

    printf("--- UABMaxMinDiff ---\n");

    int arr1[] = {3, 7, 2, 9};
    int arr2[] = {5, 5, 5, 5, 5, 5, 5};
    int arr3[] = {-2, 4, -1, 6, 5};

    printf("arr=[3,7,2,9], Expected: 7, Output: %d\n", UABMaxMinDiff(arr1, 4));
    printf("arr=[5,5,5,5,5,5,5], Expected: 0, Output: %d\n", UABMaxMinDiff(arr2, 7));
    printf("arr=[-2,4,-1,6,5], Expected: 8, Output: %d\n", UABMaxMinDiff(arr3, 5));
    printf("\n");

    printf("--- replaceEvenWithZero ---\n");

    int arr4[] = {1, 2, 3, 4};
    int arr5[] = {2, 4, 6};
    int arr6[] = {1, 3, 5};

    int* newArr4 = replaceEvenWithZero(arr4, 4);
    int* newArr5 = replaceEvenWithZero(arr5, 3);
    int* newArr6 = replaceEvenWithZero(arr6, 3);

    printf("arr=[1,2,3,4], Expected: [1, 0, 3, 0], Output: ");
    printIntArray(newArr4, 4);
    printf("\n");
    printf("arr=[2,4,6], Expected: [0, 0, 0], Output: ");
    printIntArray(newArr5, 3);
    printf("\n");
    printf("arr=[1,3,5], Expected: [1, 3, 5], Output: ");
    printIntArray(newArr6, 3);
    printf("\n\n");

    // free up DAM
    
    free(newArr4);
    free(newArr5);
    free(newArr6);

    printf("--- perfectSquare ---\n");
    printf("n=16, Expected: True, Output: %s\n", perfectSquare(16) ? "True" : "False");
    printf("n=15, Expected: False, Output: %s\n", perfectSquare(15) ? "True" : "False");
    printf("n=25, Expected: True, Output: %s\n", perfectSquare(25) ? "True" : "False");
    printf("n=36, Expected: True, Output: %s\n", perfectSquare(36) ? "True" : "False");
    printf("\n");

    printf("--- countVowels ---\n");
    char s1[] = "Hello World";
    char s2[] = "UAB CS";
    char s3[] = "Python";
    char s4[] = "aeiou";
    printf("s=\"Hello World\", Expected: 3, Output: %d\n", countVowels(s1));
    printf("s=\"UAB CS\", Expected: 2, Output: %d\n", countVowels(s2));
    printf("s=\"Python\", Expected: 1, Output: %d\n", countVowels(s3));
    printf("s=\"aeiou\", Expected: 5, Output: %d\n", countVowels(s4));

    return 0;
}