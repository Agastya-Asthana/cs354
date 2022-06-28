#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
    // Complete the code to print the pattern.
    int total_width = (n*2) - 1;    // width = height of the cube
    int buff_width = 2*(total_width+1);   //the buffer needs to include space for whitespaces
    char buffer[buff_width];    //creating an empty buffer of length buff_width
    for (int i = 0; i < total_width; i++) {
        int focus_digit = ((n-i < 1)) ? i-3 : n-i;  //if i is in the upper half do Math A but if its in the lower half do math b
        if (focus_digit == n) { //first and last line of the square
            for (int j = 0; j < buff_width-1; j++) {  //looping over every available spot in the buffer
                buffer[j] = focus_digit + '0';
                buffer[++j] = ' ';
            }
        }
        else if (focus_digit < n) { //rest of the lines of the square
            int num_of_repeats = (focus_digit*2) - 1;   //number of times the digit in focus has to be repeated
            char repeat_mode = 2;     //repeat modes |2 = pre-repeating|3 = post-repeating|
            int curr_digit = n;   //the digit we are currently looking at
            for (int j = 0; j < buff_width-1; ++j) {      //for each cell in the buffer
                if (curr_digit == focus_digit){     //if we are on the focus digit
                    if (num_of_repeats){
                        buffer[j] = curr_digit+'0';
                        buffer[++j] = ' ';
                        --num_of_repeats;
                    }
                }
                else if(repeat_mode == 2){      //focus digit has not arrived yet
                    buffer[j] = curr_digit+'0';
                    buffer[++j] = ' ';
                    --n;
                } else if (repeat_mode == 3){   //focus digit has already arrived

                }
            }
        }
        buffer[buff_width-1] = '\0';   //terminate the buffer with \0
        printf("%s\n", buffer); //printing out the buffer
    }
    return 0;
}
