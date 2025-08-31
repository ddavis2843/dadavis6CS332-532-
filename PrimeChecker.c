#include <stdio.h>
#include <math.h>


int main() {

    int given_number;

    int is_prime = 1; 

    printf("Enter a value: ");

 
    scanf("%d", &given_number);


    if (given_number <= 1) {

        is_prime = 0; 

    } 

    else {

        for (int i = 2; i <= sqrt(given_number); i++) {
            if (given_number % i == 0) {
                is_prime = 0; 
                break;       
            }
        }
    }

// final output
    if (is_prime) {

        printf("The number is prime.\n");

    } 
    
    else {
        printf("The number is not prime.\n");
    }

    return 0; 
}
