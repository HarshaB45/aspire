//Libraries
#include <stdio.h>		//for scanf and printf

/**	Calculates the remainder when a binary number is divided by 5.
 * The function reads the binary number character by character from left to right.
 *
 * @param binaryNumber A null-terminated string representing the binary number to be processed.
 * @return The remainder after dividing the binary number by 5.
 *         If the input is invalid, returns -1.
 */
int calculateRemainder(char *binaryNumber) {

		//Setting the remainder to 0 initially
    int remainder = 0;

		//Index position
    int i = 0;

		//While we are not at the end of the binaryNumber string
    while (binaryNumber[i] != '\0') {
				//If the bit is a character that is neither 0 nor 1
        if (binaryNumber[i] != '0' && binaryNumber[i] != '1') {
            printf("Invalid input! Please enter a binary number.\n");
            return -1;
        }
        
				/** Mechanism
				 * If the bit is 0, then we know that the remainder is simply
				 * multiplied by 2
				 * 
				 * Example.
				 * 1 - is 1
				 * 10 - is 2 which is 1*2
				 * 100 - is 4 which is 2*2 and so on
				 * 
				 * If the bit is 1, then we know that the remainder is
				 * multiplied by 2, and then we add 1
				 * 
				 * Example.
				 * 1 - is 1
				 * 11 - is 3 which is 1*2 + 1
				 * 111 -  is 7 which is 3*2 + 1 and so on
				 * 
				 * 
				*/
        remainder = (remainder * 2 + (binaryNumber[i] - '0')) % 5;
        
				/** .*s
				 * first argument specifies the maximum number of characters
				 * to be printed from the input number
				 * second argument prints the actual string itself
				*/
        printf("The remainder after reading %.*s is: %d\n", i + 1, binaryNumber, remainder);

				//Tells us if the current number is divisible by 5
				if (remainder == 0) {
					printf("%.*s is divisible by 5\n", i + 1, binaryNumber);
				}        

				//Increment
        i++;
    }
    
		//Returns the current remainder
    return remainder;
}

/** The main function, reads the binary number from the user
 * and returns the remainder to the user
*/
int main() {

		//Declaration
    char binaryNumber[100];

		//Reading the binary number
    printf("Enter a binary number: ");
    scanf("%s", binaryNumber);

		//Calling above function
    int remainder = calculateRemainder(binaryNumber);
    
		//Returning
    return 0;
}

