#include "helpers.h"
#include "math.h"
#include "string.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]){
    // loop through each row
    for (int i = 0; i <= height; i++){

        // loop through each column
        for (int j = 0; j <= width; j++){

            // initialize RGB values
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // find average
            int average = round((red + blue + green)/3);

            // set RGB values to average
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]){
    // loop through each row
    for (int i = 0; i <= height; i++){

        // loop through each column
        for (int j = 0; j <= (width / 2); j++){

            // initialize buffer
            RGBTRIPLE buffer;

            // save values to buffer
            buffer.rgbtRed = image[i][j].rgbtRed;
            buffer.rgbtBlue = image[i][j].rgbtBlue;
            buffer.rgbtGreen = image[i][j].rgbtGreen;

            // swap images on left
            image[i][j].rgbtRed = image[i][width-j].rgbtRed;
            image[i][j].rgbtBlue = image[i][width-j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width-j].rgbtGreen;

            // swap images on right
            image[i][width-j].rgbtRed = buffer.rgbtRed;
            image[i][width-j].rgbtBlue = buffer.rgbtBlue;
            image[i][width-j].rgbtGreen = buffer.rgbtGreen;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]){
    // make a copy to reference initial values
    RGBTRIPLE image_copy[height][width];
    memcpy(image_copy, image, width*height*sizeof(RGBTRIPLE));

    // loop through each row
    for (int i = 0; i <= height; i++){

        // loop through each column
        for (int j = 0; j <= width; j++){

            // initialize buffer and counter
            RGBTRIPLEOVERFLOW buffer; int count = 0;
            buffer.rgbtRed = 0; buffer.rgbtBlue = 0; buffer.rgbtGreen = 0;

            // find average of values nearby

            // loop through rows nearby
            for (int k = -1; k <= 1; k++){
                // top edge case
                if (i == 0 && k == -1){
                    continue;
                }
                // bottom edge case
                else if (i == height && k == 1){
                    continue;
                }

                // loop through columns near
                for (int l = -1; l <= 1; l++){
                    // left edge case
                    if (j == 0 && l == -1){
                        continue;
                    }
                    // right edge case
                    else if (j == width && l == 1){
                        continue;
                    }

                    // sum values near
                    count++;
                    buffer.rgbtRed  += image_copy[i+k][j+l].rgbtRed;
                    buffer.rgbtBlue  += image_copy[i+k][j+l].rgbtBlue;
                    buffer.rgbtGreen  += image_copy[i+k][j+l].rgbtGreen;
                }
            }

            // take average
            buffer.rgbtRed = round(buffer.rgbtRed / count);
            buffer.rgbtBlue = round(buffer.rgbtBlue / count);
            buffer.rgbtGreen = round(buffer.rgbtGreen / count);

            // insert values into image
            image[i][j].rgbtRed = buffer.rgbtRed;
            image[i][j].rgbtBlue = buffer.rgbtBlue;
            image[i][j].rgbtGreen = buffer.rgbtGreen;

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]){
    return;
}
