#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;
    

    // WRITE YOUR CODE HERE
    if (argc != 3){
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2", argc -1);
    }
    else{
        
        for (int i = 1; i < 3; i++) {  
            for (int j = 0; argv[i][j] > 0; j++) { 
                if (!isdigit(argv[i][j])) {
                    printf("Incorrect usage. The parameters you provided are not positive integers.");
                    return 1;  
                }
            }
        }
            
        int rows = atoi(argv[1]);
        int columns = atoi(argv[2]);
        int *matrix = (int*)malloc(rows * columns * sizeof(int));
           
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                matrix[i * columns + j] = minrand + rand() % (maxrand - minrand + 1);
            }
        }
        FILE *file = NULL;
        file = fopen("matrix.txt", "w");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                fprintf(file, "%d", matrix[i * columns + j]); 
                if (j < columns - 1) {
                    fprintf(file, " "); 
                }
            }   
            fprintf(file, "\n");
        }

        fclose(file); 
        free (matrix);
    return 0;

    }
}


