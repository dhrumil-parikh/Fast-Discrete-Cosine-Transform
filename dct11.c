#include <stdio.h>
#include <stdlib.h>
 
#define ROWS 671
#define COLS 1185
#define FILENAME "filename.txt"
 
int main() {
    float m[ROWS][COLS]; // should presumably be a char array
    int r, c, n;
    FILE *f;
    int count = 0, oldI = 0, oldJ = 0, i = 0, j = 0, k = 0;
    f = fopen(FILENAME, "r");
    if (f == NULL) {
        printf("Can't open %s.\n", FILENAME);
        exit(EXIT_FAILURE);
    }   
 
    // read in the matrix
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
             fscanf(f, " %f", &m[r][c]); // note the extra space

    
    // print out the matrix
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++)
           printf("%10.1f", m[r][c]);
        printf("\n");
    }
    
    printf("DCT algorithm");
    while (i < ROWS)
    {
        /* code */
        while (j < COLS)
        {
            double vec[8];
            /* code */
            for (k = 0; k < 8; k++)
            {
                vec[k] = m[i][j];

                printf("%c", m[i][j]);
                //printf("%d",k);
                j++;
            }
            //FastDct8_transform(vec);
            printf("********");
            if(count < 8 ){
                i++;
                j = oldJ;
                count++;
            }else{
                i = oldI;
                count = 0;
                oldJ = j + 1;
                j = oldJ;
            }
        }
        oldI = oldI + 8;
        }
    
    return 0;
}