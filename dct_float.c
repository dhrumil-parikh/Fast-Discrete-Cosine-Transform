#include <stdio.h>
#include <stdlib.h>

#define MWIDTH  100
#define MHEIGHT 100

int main(void){

    FILE* f;
    static int height=670;
    static int width=1185;
    int ii, jj;
    short array[height][width];
    int count = 0, oldI = 0, oldJ = 0, i = 0, j = 0, k = 0;

    if((f = fopen("filename.txt", "r")) == NULL)
        exit(1);

    /*if(fscanf(f, "%d%d", &height, &width) != 2)
        exit(1);
    printf("%d", height);
    printf("%d", width);
    if (height < 1 || height > MHEIGHT || width < 1 || width > MWIDTH)
        exit(1);*/

    for(jj=0; jj<height; jj++)
        for(ii=0; ii<width; ii++)
            if(fscanf(f, "%d", &array[jj][ii]) != 1)
                exit(1);
    fclose(f);

    printf("%d\n",sizeof(array)/sizeof(array[0]));
    printf("%d\n", sizeof(array[0]) / sizeof(array[0][0]));

   

    for (jj = 0; jj < height; jj++)
    {
        for(ii=0; ii<width; ii++)
            printf ("%d\t", array[jj][ii]);
        printf("\n");
    }
  

    printf("DCT algorithm");

    while (i < height)
    {
        /* code */
        while (j < width)
        {
            short vec[8];
            /* code */
            printf("\n");
            for (k = 0; k < 8; k++)
            {
                vec[k] = array[i][j];

                //printf("%d", array[i][j]);
               // printf("%d ", k);
                printf("%d\t",vec[k]);
               
                j++;
            }
            printf("\n");
            //FastDct8_transform(vec);
            printf("********");
            if (count < 8)
            {
                i++;
                j = oldJ;
                count++;
            }
            else
            {
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