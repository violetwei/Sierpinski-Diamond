/*
 * COMP206_Assignment2--q1a_simple_diamond.c
 *
 *  Created on: Sep 26, 2018    Author: Wei Zhenzhou
 */

/* this a program which takes 1 argument, the height H of the diamond */
/*
 * Program description:
 * Prints a diamond which is made up of H rows of asterisk (*) characters and spaces following this specification:
 * The diamond’s top and bottom rows must both be a single asterisk (same line if H=1)
 * Subsequent rows must grow or shrink by 2 asterisks, according to the overall shape
 * A single row in the middle of the diamond must have exactly H asterisks (no spaces in this one)
 * The first asterisk in the middle row must appear at the very beginning of the line
 * The asterisks in all rows must be perfectly centered with respect to the middle row
 *
 *The program needs exactly one argument after the program name, no more and no less.
 * Otherwise print: “ERROR: Wrong number of arguments. One required.”
 * The height argument must be a positive integer and odd (ensures the overall shape works).
 * Otherwise print: “ERROR: Bad argument. Height must be positive odd integer.”
 */

#include <stdlib.h>
#include <stdio.h>

void print_diamond (int h);

int main(int argc, char * argv[]) {
    // strtol: string to long(string, endptr, base)
    // argv[1] is a pointer to a string
    
    if(argc == 1){
        printf("ERROR: Wrong number of arguments. One required.\n");
        exit(0);
    }

    int num_of_rows = strtol(argv[1], NULL, 10);

    //number of rows of triangle's height
    int tri_height=(num_of_rows+1)/2;

    //conditions where exactly one argument after the program name and the argument is positive and odd integer.
    if(argc == 2 && num_of_rows > 0 && (num_of_rows%2) != 0) {

        print_diamond(tri_height);

    }else if (argc > 2){
        printf("ERROR: Wrong number of arguments. One required.\n");
        //exit(0);
    }    
    else{
        printf("ERROR: Bad argument. Height must be positive odd integer.\n");
    }
    
    
}   
    
    // the print * function which will print the diamond shape as requested
    void print_diamond (int h) {
       int c, print_space;
       
       static int print_stars = -1;
       if(h<=0)
        return;
      
       print_space = h - 1;
       print_stars += 2;

       for (c = 0; c < print_space; c++){
          printf(" ");
       }

       for (c = 0; c < print_stars; c++){
          printf("*");
       }

       printf("\n");

       print_diamond(--h);

       print_space = h + 1;
       print_stars -= 2;

       for (c = 0; c < print_space; c++){
          printf(" ");
       }

       for (c = 0; c < print_stars; c++){
          printf("*");
       }

       printf("\n");
    }
    
    
    
    

