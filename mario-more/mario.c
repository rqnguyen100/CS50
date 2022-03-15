#include <stdio.h>

void block_builder(int width);

int main(void){
    // initialize variables
    int height;

    // ask for height until user returns an integer[1,8]
    do {
        printf("What height do you want? ");
        scanf("%i",&height);
    } while (height < 1 || height > 8);

    // makes pyramid based on height
    for (int i = 1; i <= height; i++){
        // left spacing
        if (i != height) {
            printf("%*c", height-i, ' ');
        }

        // left hashtags
        block_builder(i);

        // middle spacing
        printf("%*c", 2, ' ');

        // right hashtags
        block_builder(i);
        printf("\n");
    }
}

void block_builder(int width){
    char block = '#';
    for (int i = 1; i <= width; i++) {
        printf("%c",block);
    }
}