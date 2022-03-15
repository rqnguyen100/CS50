// Libraries
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Helper Functions
void plain2cipher(string text, string key);
int hasDigits(string arg);
int hasDuplicates(string arg);

// Main Function
int main(int argc, string argv[]) {
    // Failed Arguments
        // User doesn't provide key
        if (argc != 2){
            printf("Usage: ./substitution key\n");
            return 1;
        }
        // User provides multiple keys
        else if (strlen(argv[1]) != 26){
            printf("Usage: ./substitution key\n");
            return 1;
        }
        // User provides key with invalid characters
        else if (hasDigits(argv[1])){
            printf("Usage: ./substitution key\n");
            return 1;
        }
        // User provides key with duplicate characters
        else if (hasDuplicates(argv[1])){
            printf("Usage: ./substitution key\n");
            return 1;
        }

    // Asks User for Plain Text
    string plainText = get_string("plaintext:  ");

    // Converts Plain Text to Cipher Text and Prints
    plain2cipher(plainText, argv[1]);

    // Return Statement
    return 0;
}

// Converts Plain Text to Cipher Text
void plain2cipher(string text, string key){
    // Declare Variables
    int textLength = strlen(text);
    char cipher[textLength];

    // Original Key
    string alphaUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphaLower = "abcdefghijklmnopqrstuvwxyz";

    // Substitutes Text
    for (int i = 0; i < textLength; i++){
        // Returns non-alphabetical characters
        if (!isalpha(text[i])){
            cipher[i] = text[i];
        }
        // Returns substituted lower case characters
        else if (islower(text[i])){
            string point = strchr(alphaLower, text[i]);
            int index = (int)(point-alphaLower);
            cipher[i] = tolower(key[index]);
        }
        // Returns substituted upper case characters
        else {
            string point = strchr(alphaUpper, text[i]);
            int index = (int)(point-alphaUpper);
            cipher[i] = toupper(key[index]);
        }
    }

    // Print Statement
    printf("ciphertext: %s\n", cipher);
}

// Checks if string has digits
int hasDigits(string arg){
    // Declare Variables
    int textLength1 = strlen(arg);

    // Checks each character for digits
    for (int i = 0; i < textLength1; i++){
        if isdigit(arg[i]){
            return 1;
        }
    }

    return 0;
}

// Checks if string has digits
int hasDuplicates(string arg){
    // Declare Variables
    int textLength2 = strlen(arg);

    // 2 For-Loops to check each character
    for (int i = 0; i < textLength2 - 1; i++){
        for (int j = i + 1; j < textLength2; j++){
            if (arg[i] == arg[j]){
                return 1;
            }
        }
    }

    return 0;
}