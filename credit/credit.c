#include <cs50.h>
#include <stdio.h>

int main(void) {
    // declare variables
    long num; int checkSum = 0;

    // asks for credit card number and accepts only numbers
    num = get_long("What is your credit card number? ");
    long numCopy1 = num;
    long numCopy2 = num;
    long numCopy3 = num;

    // calculates check sum step 1
    numCopy1 = (numCopy1 - (numCopy1 % 10)) / 10;
    while (numCopy1 > 0) {
        int digit = 2 * (numCopy1 % 10);
        if (digit >= 10) {
            checkSum += (digit % 10);
            checkSum += (digit / 10);
        }
        else {
            checkSum += digit;
        }
        numCopy1 /= 100;
    }

    // calculates check sum step 2
    while (numCopy2 >0) {
        checkSum += (numCopy2 % 10);
        numCopy2 /= 100;
    }

    // calculates card length and starting digits
    int numLength = 0; int firstDigit; int secondDigit;
    do {
        if (numCopy3 < 10) {
            firstDigit = numCopy3;
        }
        else if (numCopy3 < 100) {
            secondDigit = (numCopy3 % 10);
        }
        numCopy3 /= 10;
        numLength++;
    } while (numCopy3 != 0);

    // determines if AMEX, MASTERCARD, VISA, or INVALID
    int valid = checkSum % 10;
    if (valid != 0) {
        printf("INVALID\n");
    }
    else if (firstDigit == 4 && (numLength == 13 || numLength == 16)){
        printf("VISA\n");
    }
    else if (firstDigit == 3 && (secondDigit == 3 || secondDigit == 7) && numLength ==15){
        printf("AMEX\n");
    }
    else if (firstDigit == 5 && (secondDigit < 6 && secondDigit > 0) && numLength == 16){
        printf("MASTERCARD\n");
    }
    else {
        printf("INVALID\n");
    }
}