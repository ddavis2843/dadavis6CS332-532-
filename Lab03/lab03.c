#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** readStrings(int* numStrings) {

    printf("Enter the number of strings you want to sort: ");

    if (scanf("%d", numStrings) != 1 || *numStrings < 0) {

        printf("Invalid input. Exiting.\n");
        exit(1);
    }
  
    while (getchar() != '\n');


    char** arr = (char**)malloc(*numStrings * sizeof(char*));

    if (arr == NULL) {

        perror("Memory allocation failed for string array");
        exit(1);
    }

    printf("Enter strings:\n");
    for (int i = 0; i < *numStrings; i++) {

        char buffer[100]; // buffer time
        printf("String %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        

        buffer[strcspn(buffer, "\n")] = 0;

        // dynamically allocate memory
        arr[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        if (arr[i] == NULL) {

            perror("Memory allocation failed for individual string");
            exit(1);
        }
        strcpy(arr[i], buffer);
    }
    return arr;
}


void sortStrings(char** arr, int n) {
    int i, j;
    char* key;
    for (i = 1; i < n; i++) {

        key = arr[i];
        j = i - 1;


        while (j >= 0 && strcmp(arr[j], key) > 0) {

            arr[j + 1] = arr[j]; 
            j = j - 1;
        }
        arr[j + 1] = key; 
    }
}


void displayStrings(char** arr, int n) {
    printf("\nSorted strings:\n");

    for (int i = 0; i < n; i++) {

        printf("%s\n", arr[i]);
    }
}

int main() {
    
    int numStrings;
  
    char** strings = readStrings(&numStrings);

    sortStrings(strings, numStrings);
    displayStrings(strings, numStrings);


    for (int i = 0; i < numStrings; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}
