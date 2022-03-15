// libraries
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// global variables
float wordCount = 1;

// helper functions
float avgLet100(string);
float avgSen100(string);

// main function
int main(void) {
    // gets string from user
    string text = get_string("Text: ");

    // calculates grade level
    float L = avgLet100(text);
    float S = avgSen100(text);

    // returns grade level
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1){
        printf("Before Grade 1\n");
    }
    else if (index > 16){
        printf("Grade 16+\n");
    }
    else {
        printf("Grade %i\n", index);
    }

    return 0;
}

// outputs average number of letters per 100 words in text
float avgLet100(string text){
    // declare variables
    float avgLet;
    float letCount = 0, textLen = 0;
    textLen = strlen(text);

    // find number of letters in text
    for (int i = 0; i <= textLen; i++){
        if (isalnum(text[i])){
            letCount++;
        }
        else if (isspace(text[i])){
            wordCount++;
        }
    }

    // multiply by scalar for average per 100 words
    avgLet = (letCount / wordCount) * 100.;

    // returns value
    return avgLet;
}

// outputs average number of sentences per 100 words in text
float avgSen100(string text){
    // declare variables
    float avgSen;
    float senCount = 0, textLen = 0;
    textLen = strlen(text);

    // find number of sentences in text
    for (int i = 0; i <= textLen; i++){
        if (text[i] == '.') {
            senCount++;
        }
        else if (text[i] == '!'){
            senCount++;
        }
        else if (text[i] == '?'){
            senCount++;
        }
    }

    // multiply by scalar for average per 100 words
    avgSen = senCount / wordCount * 100.;

    // returns value
    return avgSen;
}