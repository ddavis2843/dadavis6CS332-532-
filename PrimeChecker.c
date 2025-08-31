#include <stdio.h>

#include <math.h>


int main() {

    int given_number; // 1. Define an integer variable as given_number.

    int is_prime = 1; 

    printf("Enter a value: ");

 
    scanf("%d", &given_number); // 2. Use the C function scanf to read the integer variable given_number.


    if (given_number <= 1) {

        is_prime = 0; 

    } 

    else {

        for (int i = 2; i <= sqrt(given_number); i++) {

            if (given_number % i == 0)  { // 3. Use the conditional statement to find out given_number is prime or not prime.

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
// 4. Print the final output as The number is prime or The number is not prime.
    return 0; 
}
