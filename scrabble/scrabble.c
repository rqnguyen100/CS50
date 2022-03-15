#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Returns result
    if (score1 > score2) {
        printf("Player 1 wins with a score of %i over %i\n",score1,score2);
    }
    else if (score2 > score1) {
        printf("Player 2 wins with a score of %i over %i\n",score2,score1);
    }
    else {
        printf("Tie with a score of %i and %i\n",score1,score2);
    }
}

int compute_score(string word)
{
    int score = 0;
    int wordLen = strlen(word);

    // gives score for each letter in string
    for (int i = 0; i < wordLen; i++){
        // changes all letters to uppercase
        int wordLet = toupper(word[i]);

        // 0 points if not a letter
        if (wordLet < 65 || wordLet > 90) {
            continue;
        }

        // gives score based on letter
        wordLet -= 65; // maps from ASCII to POINTS list
        score += POINTS[wordLet];
    }

    return score;
}
