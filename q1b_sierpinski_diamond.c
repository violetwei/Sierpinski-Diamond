/* COMP206_Assignment2    Part B) Sierpinski Diamond */


/* This is a program which prints a modified diamond, such that each of the top and bottom half are Sierpiński Triangles. 
 * Your program should take two arguments: the height of the diamond, H, and the fractal level, L. 
 *
 * the diamond has a precise format:
 * The level L=1 diamond must be identical to the simple diamond with the given height, H.
 * For each level beyond 1, you must sub-divide top and bottom triangles using Sierpiński’s rule. 
 * Replace a H/2 triangle whose tip touches the bottom of the original with spaces. 
 * This leaves 3 triangles, each with height H/2 and level L-1, one above the missing triangle, and two beside it.
 * We must continue recursively sub-dividing each remaining triangle until we reach level L=1.
 *
 * input checking must be performed:
 * Height H must meet all the same conditions as above, with the same error messages.
 * Height H must allow us to perfectly divide the triangle each time. 
 * This means that tri_height=ceil(H/2) must be a power of 2, with tri_height >= 2L-1. 
 * Otherwise print “ERROR: Height does not allow evenly dividing requested number of levels.”
 */

#include <stdio.h>
#include <stdlib.h>

int x_to_the_n(int x, int n);
int check_power_of_two(int num);
void get_diamond_shape (int h, char ** arr);
void cut_top_triangle(int row_index, int column_index, int cut_height, int cut_length, char ** arr, int fractal_level);
void cut_bottom_triangle(int row_index, int column_index, int cut_height, int cut_length, char ** arr, int fractal_level);
//void cut_all_triangle(int row_index, int column_index, int cut_height, int cut_length, char ** arr, int fractal_level);

int main(int argc, char * argv[]) {
	
    // first check if there are right number of arguments
	if(argc != 3){
        printf("ERROR: Wrong number of arguments. Two required.\n");
        exit(0);
  }    

    // get the input argument 
	int diamond_height = strtol(argv[1], NULL, 10);
	int fractal_level = strtol(argv[2], NULL, 10);
  //int fractal_level2 = strtol(argv[2], NULL, 10);

  //check if the fractal level is a positive integer and greter than 0
  if(fractal_level <= 0){
    printf("You must enter a fractal level positive integer.\n");
    exit(0);
  }

  int row = diamond_height;
  int column = diamond_height;
  int i, j;

  //int actual_cutting_times = fractal_level -1;

  //malloc 2D array memory -- using pointer to a pointer
  // create an array of pointers also dynamically using a double pointer
  char **arr = (char **)malloc(row * sizeof(char *));
  for(i=0; i<row; i++){
    arr[i] = (char *)malloc(column * sizeof(char));
  }


    // check if the input height is a positive odd integer, if not exit from program
	if(diamond_height <= 0 || (diamond_height%2) == 0){
		printf("Error: Bad argument. Height must be positive odd integer.\n");
        exit(0);
	}

  //number of rows of the triangle's height
  int tri_height=(diamond_height+1)/2;

    // pow() function returns the result of rasing x to power of y
    // pow(base value, power value)
	if( (check_power_of_two(tri_height) == 0) && tri_height >= x_to_the_n(2, fractal_level-1) ) {
		//do something
        //printf("success\n");
    get_diamond_shape(tri_height, arr);
    //cut_triangle(actual_cutting_times);

    cut_top_triangle(tri_height/2, tri_height/2, tri_height/2, (diamond_height-1)/2, arr, fractal_level);

    cut_bottom_triangle(tri_height/2+(diamond_height-1)/2-1, tri_height/2, tri_height/2, (diamond_height-1)/2, arr, fractal_level);

      //cut_all_triangle(tri_height/2, tri_height/2, tri_height/2, (diamond_height-1)/2, arr, fractal_level);

    for(int w=0; w<row; w++){
      for(int e=0; e<column; e++){
        //arr[w][e]='*'; 
        printf("%c", arr[w][e]);
      }
      printf("\n");
    }
    

	}else{
		printf("ERROR: Height does not allow evenly dividing requested number of levels. \n");
	}

}

    //this is a function to calculate power
    int x_to_the_n(int x, int n){
      int i;
      int number = 1;

      for(i=0; i<n; ++i){
        number *= x;
      }

      return number;

    }

    //if the return num if 0 then the input is a power of 2, else not a power of two
    int check_power_of_two(int num){

      int flag = 0;
      while(num != 1){
        if(num%2 != 0){
          flag =1;
          break;
        }
        num=num/2;
      }

      return flag;

    }



    // the function to print the whole diamond shape with the input height H
    void get_diamond_shape (int h, char ** arr) {
      //char arr[2*h-1][2*h-1];
      int i, j, next_j, next_q, k, q, p, count;
      for(i=0; i<2*h-1; i++){
        for(j=0; j<2*h-1; j++){
          arr[i][j] =' ';
        }
      }

      count = h - 1;
      for(i =0; i<h; i++){

        if(count == 0){
          for(p=0; p<2*h-1; p++){
            arr[i][p]='*';
          }
          break;
        }

        for(j=0; j<count; j++){
          arr[i][j] = ' ';  
        }
        next_j=j;
        count--;
        for(j=1; j<=2*(i+1)-1; j++){
          arr[i][next_j+j]='*';
        }
      }

      count = 1;
      for(k=1; k<=h-1; k++){
        for(q=1; q<=count; q++){
          arr[i+k][q-1]=' '; 
        }
        next_q = q-1;
        count++;
        for(q=1; q <=2*(h-k)-1; q++){
          arr[i+k][next_q+q]='*';
        }
      }
      
      
      for(i = 0; i < h - 1; i++)
      {
        arr[i][h - 1 - i] = '*';
        arr[i][h + i]     = ' ';
      }
      for(i = h; i < 2 * h - 1; i++)
      {
        for(int u = 0; u < 2 * h - 1; u++)
        {
          arr[i][u] = arr[2 * h - 2 - i][u];
        }
      }
      

    }

    //this is the function to cut the top part triangle
    void cut_top_triangle(int row_index, int column_index, int cut_height, int cut_length, char ** arr, int fractal_level){
      int i, j;
      if(fractal_level>1){
        for(i=0; i<cut_height; i++)
          {
             for(j=0; j<cut_length-2*i; j++)
             {
                  arr[row_index+i][column_index+i+j]=' ';
             }
          }
      }
      //arr[row_index+i-1][column_index+i+j-2]=' ';
	    //arr[row_index+i-1][column_index+i+j-1]='*';

      //fractal_level--;

      if(fractal_level > 1){
        //cut top triangle
        cut_top_triangle(row_index-cut_height/2, column_index+cut_height/2, cut_height/2, (cut_length-1)/2, arr, fractal_level-1);
        // cut left
        cut_top_triangle(row_index+cut_height/2, column_index-cut_height/2, cut_height/2, (cut_length-1)/2, arr, fractal_level-1);
        //cut right
        cut_top_triangle(row_index+cut_height/2, (column_index + cut_length - ((cut_height - 1)/2)), cut_height/2, (cut_length-1)/2, arr, fractal_level-1);
      }else{
        //exit(1);
      }

    }

    //this is the fuction to cut the bottom part triangle
    void cut_bottom_triangle(int row_index, int column_index, int cut_height, int cut_length, char ** arr, int fractal_level){
      int i, j;

      if(fractal_level > 1){
        for(i=0; i<cut_height; i++){
          for(j=0; j<cut_length-2*i; j++){
            arr[row_index-i][column_index+i+j]=' ';
          }
        }
      }

      //fractal_level--;

      if(fractal_level > 1){
        //cut bottom triangle
        cut_bottom_triangle(row_index+cut_height/2, column_index+cut_height/2, cut_height/2, (cut_length-1)/2, arr, fractal_level-1);
        // cut left
        cut_bottom_triangle(row_index-cut_height/2, column_index-cut_height/2, cut_height/2, (cut_length-1)/2, arr, fractal_level-1);
        //cut right
        cut_bottom_triangle(row_index-cut_height/2, (column_index + cut_length - ((cut_height - 1)/2)), cut_height/2, (cut_length-1)/2, arr, fractal_level-1);
      }else{

      }


    }

    /*void cut_all_triangle(int row_index, int column_index, int cut_height, int cut_length, char ** arr, int fractal_level){
      cut_bottom_triangle(row_index, column_index, cut_height, cut_length, arr, fractal_level);
      cut_top_triangle(row_index, column_index, cut_height, cut_length, arr, fractal_level);
    }*/


    // the function which will remove relative * according to Sierpinski triangle rule and the input fractal_level
   /*  void cut_triangle(int t, char ** arr){
      int k = 0;
      int g = 0;
      int mid_line = tri_height/2;

      for(int u=0; u<t; u++){

        for(int i = 1; i<=mid_line; i++){

          for(int j = 0; j < 2 * (mid_line - i) + 1; j++){

            arr[mid_line + k][mid_line + k + j]=" ";
          }       
          k++;
        }

        for(int a=1; a <= mid_line - 1; a++){

          for(int b=0; b < (2*a)+1; b++){
            arr[tri_height+g][tri_height-1-a+b]=" ";
          }
          g++;
        }

        k=g=0;

        mid_line=mid_line/2;
      }
    }

    */

    //cut top part triangles using recursively cut
    /*void cut_top_triangle(int left_row, int left_column, int right_column, int bottom_row, char ** arr){
      int i, j;
      for(i=0; i<=bottom_row-left_row; i++){
        for(j=0; j<=right_column-left_column-2*i; j++){
          arr[left_row+i][left_column+i+j]=' ';
        }
      }

    }*/
















