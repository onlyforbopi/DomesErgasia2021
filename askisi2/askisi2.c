#include <stdio.h>


// Ορίζουμε ένα struct node το οποίο να περιέχει το πλήθος των τιμών που περιλαμβάνει ο πίνακας Α(1:2,1:3,3:3,1:2).
struct node{

    int dim1[2];
    int dim2[3];
    int dim3[1];
    int dim4[2];
};


void print2d(int arr[][4], int total)
{

    for (int i = 0; i < total; i++)
    {
        printf("Elem1: [");
        for (int j = 0; j < 4; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("]\n");
    }

}

void calc2d(int arr[][4], int total, int c[])
{

    for (int i = 0; i < total; i++)
    {
        printf("\n---\nElem1: [");
        printf("C0: %d\n", c[0]);
        int total1 = c[0];
        for (int j = 0; j < 4; j++)
        {

            printf("%d|%d\n", arr[i][j], c[j]);
            total1 += arr[i][j] * c[j+1];


        }
        
        printf("\nA[%d,%d,%d,%d] ==> %d\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3], total1);
        printf("]\n");
    }

}





int main()
{
    struct node j1 = {
        {1,2},
        {1,2,3},
        {3},
        {1,2}
    };

    int L;
    printf("Enter L: ");
    scanf(" %d", &L);

    int b;
    printf("Enter b: ");
    scanf(" %d", &b);



    int size1 = sizeof j1.dim1 / sizeof j1.dim1[0];
    int size2 = sizeof j1.dim2 / sizeof j1.dim2[0];
    int size3 = sizeof j1.dim3 / sizeof j1.dim3[0];
    int size4 = sizeof j1.dim4 / sizeof j1.dim4[0];


    int u[4] = { j1.dim1[1], j1.dim2[2], j1.dim3[0], j1.dim4[1] };

    printf("Upper limits: \n");
    printf("u1: %d \n", u[0]);
    printf("u2: %d \n", u[1]);
    printf("u3: %d \n", u[2]);
    printf("u4: %d \n", u[3]);



    int d[4] = { j1.dim1[0], j1.dim2[0], j1.dim3[0], j1.dim4[0] };


    printf("Lower limits: \n");
    printf("d1: %d \n", d[0]);
    printf("d2: %d \n", d[1]);
    printf("d3: %d \n", d[2]);
    printf("d4: %d \n", d[3]);

    int c[5];

    for (int i=4; i>=0; i--)
    {
        if (i==4)
        {
            printf("Index: %d\n", i);
            c[i] = L;
            printf("\nc:%d \n", c[i]);
        }
        else if (i != 0)
        {
            printf("\nIndex: %d", i);
            printf("\nu: %d", u[i]);
            printf("\nd:%d", d[i]);
            printf("\nc+1:%d", c[i+1]);
            c[i] = (u[i] - d[i] + 1) * c[i+1];
            printf("\nc:%d \n", c[i]);
        } 
        else if ( i == 0)
        {
            printf("\n");
            printf("%d\n",c[i+1]*d[i]);
            c[i] = b - (c[i+1]*d[i]) - (c[i+2]*d[i+1]) - (c[i+3]*d[i+2]) - (c[i+4] * d[i+3]); 
        
        }
    }


    printf("-----------\n");
    printf("c0: %d\n", c[0]);
    printf("c1: %d\n", c[1]);
    printf("c2: %d\n", c[2]);
    printf("c3: %d\n", c[3]);
    printf("c4: %d\n", c[4]);


    int total = size1 * size2 * size3 * size4;

    printf("-----------\n");
    printf("size1: %d\n", size1);
    printf("size2: %d\n", size2);
    printf("size3: %d\n", size3);
    printf("size4: %d\n", size4);

    printf("Total size: %d\n", total);

    int a[total][4]; 
    int current[4];

    int i, j, k, l;
    int counter = 0;
    
    for(i=1;i<=size1;i++)
    {
        for(j=1;j<=size2; j++)
        {
            for (k=3;k<=3;k++)
            {
                for (l=1;l<=size4;l++)
                {

                    current[0] = i;
                    current[1] = j;
                    current[2] = k;
                    current[3] = l;

                    for (int x = 0; x<4; x++)
                    {
                        a[counter][x] = current[x];   
                    }
                    counter++;
                }
            }
        }
        printf("----------\n");
    }


    print2d(a, total);
    calc2d(a, total, c);
}