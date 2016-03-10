/*
 * Functions needed for mergesort of integer elements.
 * Programmer - Nick Martinez
 * CSC371 - Design and Analysis of Algorithms
 */

/* Sorts an array of integers in nondecreasing order. */
void mergesort(int *a, int length);

/* Merges two sorted arrays into one sorted array. */
void merge(const int *b, const int *c, int *a);

/* Copys an array. */
int *int_copy(const int *a, int length);
