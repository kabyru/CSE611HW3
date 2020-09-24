#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Matrix
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

//Matrices in C are treated like one-dimensional arrays with a layer of abstraction
static int* matrix_row(struct Matrix* m, int row)
{
    return m->ptr + row * m->width;
}

//Returns the (i,j) location in the specified matrix. ROW MAJOR
static int* matrix_location(struct Matrix* m, int row, int col)
{
    return m->ptr + row * m->width + col;
}


//Returns the (i,j) element in the specified matrix. ROW MAJOR
static int matrix_element(struct Matrix* m, int row, int col)
{
    return *(m->ptr + row * m->width + col);
}

//static int* matrix_location_col_major(struct Matrix* m, int row, int col)
//{
//    return m->ptr + row * m->width + col;
//}

////Prints the desired matrix to the console in a pretty form.
//void print_matrix(struct Matrix* m, char nm)
//{
//    struct Matrix* itr = m;
//    printf("Matrix %c:\n", nm);
//    for (int r = 0; r < m->height; ++r)
//    {
//        itr->ptr = r * itr->width;
//        for (int c = 0; c < m->width; ++c)
//        {
//            printf("%d ", itr->ptr[c]);
//        }
//        printf("\n");
//    }
//}

int main()
{
    int r = 0;
    int c = 0;
    //The first step is to create the two matrices that will be multiplied.
    int n = 5000;

    struct Matrix A = matrix_create(n, n); //Creating the first 5000x5000 matrix
    struct Matrix B = matrix_create(n, n); //Creating the second 5000x5000 matrix

    struct Matrix C = matrix_create(n, n); //This will contain the product 5000x5000 matrix.

    //Next, fill in Matrices A and B with values.
    //for (r = 0; r < A.height; ++r)
    //{
    //    int* row = matrix_row(&A, r); //Summons the r-th row in Matrix A
    //    for (c = 0; c < A.width; ++c)
    //    {
    //        row[c] = c;
    //    }
    //}

    //for (r = 0; r < B.height; ++r)
    //{
    //    int* row = matrix_row(&B, r); //Summons the r-th row in Matrix B
    //    for (c = 0; c < B.width; ++c)
    //    {
    //        row[c] = c;
    //    }
    //}

    printf("Generating Matrix A...\n");
    for (long itr = 0; itr < A.height * A.width; itr++)
    {
        A.ptr[itr] = itr % n;
        //printf("%ld\n", itr);
    }

    printf("Generating Matrix B...\n");
    for (long itr = 0; itr < B.height * B.width; itr++)
    {
        B.ptr[itr] = itr % n;
        //printf("%ld\n", itr);
    }

    clock_t t;
    t = clock();
    //n x n is the size of the a b c matrices
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
            {
                //need to access matrices in column major form.
                C.ptr[i + j * n] += A.ptr[i + k * n] * B.ptr[k + j * n];
            }
        }
    }
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; //In seconds.

    printf("This loop configuration took %f seconds to execute.\n", time_taken);

    matrix_destroy(&A); matrix_destroy(&B); matrix_destroy(&C);

    return 0;

}