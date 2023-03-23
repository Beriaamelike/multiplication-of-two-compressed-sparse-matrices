# multiplication-of-two-sparse-matrixes.



Preliminary information:
• Sparse matrix is a matrix with most of its elements equal to zero. If the number of 0's greater
than half of the total elements in a matrix, then the matrix can be called sparse matrix.

• 2D array is used to represent a sparse matrix. Leads to wastage of lots of memory as zeroes
in the matrix are of no use in most of the cases. Instead of storing zeroes with non-zero
elements, we only store non-zero elements (row, column, value).

• The sparse matrix used anywhere in the program is sorted according to its row values. Two
elements with the same row values are further sorted according to their column values.

1) Write a C program for multiplication of two sparse matrixes.

• Represent the sparse matrix using a 1D array structure, excluding zeros.

• Compress the size of the sparse matrixes without losing the information in the sparse
matrixes.

• Print the multiplication result matrix as a 1D array.
