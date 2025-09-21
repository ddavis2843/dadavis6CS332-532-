#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // check for # of arguments
    if (argc != 3) {

        fprintf(stderr, "Usage: %s <first_file> <second_file>\n", argv[0]);

        return 1;
    }

    char *first_file_path = argv[1];
    char *second_file_path = argv[2];

    // check if file names and the same
    if (strcmp(first_file_path, second_file_path) == 0) {

        fprintf(stderr, "Error: The two filenames cannot be the same.\n");

        return 1;
    }

    // open second file, read
    FILE *second_file = fopen(second_file_path, "r");

    if (second_file == NULL) {

        perror("Error opening second file");

        return 1;
    }

    // open first file, append
    FILE *first_file = fopen(first_file_path, "a");
    if (first_file == NULL) {

        perror("Error opening first file");

        fclose(second_file); // Ensure the first file is closed before exiting

        return 1;
    }

    int character;
    //read contents of second file, write to first
    while ((character = fgetc(second_file)) != EOF) {
        
        fputc(character, first_file);
    }

    // close files
    fclose(first_file);
    fclose(second_file);

    printf("File concatenation successful. The contents of '%s' have been appended to '%s'.\n", second_file_path, first_file_path);

    return 0; // indicate successful execution
}
