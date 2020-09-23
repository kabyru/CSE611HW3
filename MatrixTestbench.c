#include <stdio.h>
#include <stdlib.h>

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

static int* matrix_row(struct Matrix* m, int row)
{
    return m->ptr + row * m->width;
}

int main()
{
    int r = 0;
    int c = 0;
    struct Matrix m = matrix_create(80, 24);

    for (r = 0; r < m.height; ++r)
    {
        int* row = matrix_row(&m, r);
        for (c = 0; c < m.width; ++c)
        {
            row[c] = c;
            printf("%d ", c);
        }
        printf("\n");
            
    }
    matrix_destroy(&m);
}
