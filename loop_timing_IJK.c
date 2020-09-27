/*

CSE 611 HW4 Matrix Multiplication Latency Experiment
Configured for IJK Loop Order.

By Kaleb Byrum
9/26/20

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Matrix //Structure used to generate matrices
{
    int width;
    int height;
    int* ptr;
};

static struct Matrix matrix_create(int width, int height)
{
    struct Matrix new_matrix;
    new_matrix.width = width;
    new_matrix.height = height;
    new_matrix.ptr = malloc(width * height * sizeof(int));
    return new_matrix;
}

static void matrix_destroy(struct Matrix* m)
{
    free(m->ptr);
}

int main()
{
    int r = 0;
    int c = 0;

    //The first step is to create the two matrices that will be multiplied.
    int n = 5000; //5000x5000 matrices will be created.

    struct Matrix A = matrix_create(n, n); //Creating the first 5000x5000 matrix
    struct Matrix B = matrix_create(n, n); //Creating the second 5000x5000 matrix

    struct Matrix C = matrix_create(n, n); //This will contain the product 5000x5000 matrix.

    printf("Generating Matrix A...\n"); //Generates Matrix A full of example data. In this case, its itr % n.
    for (long itr = 0; itr < A.height * A.width; itr++)
    {
        A.ptr[itr] = itr % n;
    }

    printf("Generating Matrix B...\n"); //Generates Matrix B full of example data. In this case, its itr % n.
    for (long itr = 0; itr < B.height * B.width; itr++)
    {
        B.ptr[itr] = itr % n;
    }

    printf("Generating Matrix C...\n"); //Matrix C is what holds the multiplication matrix.
    clock_t t; //Timer variable
    t = clock(); //Snapshots the timer variable.
    //n x n is the size of the a b c matrices
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                //Need to access matrices in column major form. Results are stored in the retrieved element in C.
                C.ptr[i + j * n] += A.ptr[i + k * n] * B.ptr[k + j * n];
            }
        }
    }
    t = clock() - t; //Calculates the latency of this loop operation.
    double time_taken = ((double)t) / CLOCKS_PER_SEC; //Converts into seconds.

    printf("This loop configuration took %f seconds to execute.\n", time_taken);

    matrix_destroy(&A); matrix_destroy(&B); matrix_destroy(&C); //Frees the mallocs.

    return 0;

}