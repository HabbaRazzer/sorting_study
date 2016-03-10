/*
 * Implementation of mergesort functions.
 * Programmer - Nick Martinez
 * CSC371 - Design and Analysis of Algorithms
 */
#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

/*
 * Sorts an array of integers in nondecreasing order.
 * Precondition: a is a pointer to an array of integers.
 * Postcondition: The array of integers that a points to is sorted in 
 *     nondecreasing order.
 * Returns nothing.
 */
void mergesort(int *a, int length)
{
    if( length > 1 )
    {
	int *b = int_copy(a, (length/2)-1);
	int *c = int_copy(a+(length/2), (length/2));
	mergesort(b, (length/2)-1)
	mergesort(c, (length/2))
	// merge(b,c,a)
    }
}

void merge(const int *b, const int *c, int *a)
{

}

/*
 * Copies an array of integers.
 * Returns the copied array of integers.
 */
int *int_copy(const int *src, int length)
{
	int *dest = (int *)malloc(sizeof(int)*length);
	memcpy(dest, src, sizeof(int)*length);
	return dest;
}
