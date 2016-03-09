/*
 * Generates files.
 * 
 * Programmer - Nick Martinez
 * CSC310 - Design and Analysis of Algorithms
 */
#include <stdio.h>
#include <stdlib.h>

#define UPPER_BOUND 10000
#define LIST_SIZE 10000
#define NUM_FILES 30

#define BUFFER_SIZE 16

int get_random(int upper_bound);	// returns a random integer
int comparison(const void *a, const void *b);	// comparison function needed for stdlib qsort function
int r_comparison(const void *a, const void *b); // comparison function needed for stdlib qsort function - reversed  

int main(void)
{
	int i = 0;
//	for( i = 0; i < NUM_FILES; i++ )
//	{
		/* open new file for writing */
		char file_name[BUFFER_SIZE+1];
		snprintf(file_name, BUFFER_SIZE, "unsorted_%d", i);
		FILE *fp_unsorted = fopen(file_name, "w+");
		
		snprintf(file_name, BUFFER_SIZE, "sorted_%d", i);
		FILE *fp_sorted = fopen(file_name, "w+");

		snprintf(file_name, BUFFER_SIZE, "r_sorted_%d", i);
		FILE *fp_r_sorted = fopen(file_name, "w+");

		/* generate list of integers */
		int *data_list = (int *)malloc(sizeof(int)*LIST_SIZE);
		int j;
		for( j = 0; j < LIST_SIZE; j++ )
		{
			data_list[j] = get_random(UPPER_BOUND);
		}

		for( j = 0; j < LIST_SIZE; j++ )
		{
			fprintf(fp_unsorted, "%d\n", data_list[j]);
		}

		/* sort the list of integers */
		qsort(data_list, LIST_SIZE, sizeof(*data_list), comparison);
		for( j = 0; j < LIST_SIZE; j++ )
		{
			fprintf(fp_sorted, "%d\n", data_list[j]);
		}

		/* reverse sort the list of integers */
		qsort(data_list, LIST_SIZE, sizeof(*data_list), r_comparison);
		for( j = 0; j < LIST_SIZE; j++ )
		{
			fprintf(fp_r_sorted, "%d\n", data_list[j]);
		}

		fclose(fp_unsorted);
		fclose(fp_sorted);
		fclose(fp_r_sorted);

		free(data_list);
//	}

	return EXIT_SUCCESS;
}

/**
 * Generates a random integer between 0 and upper_bound, exclusive.
 * Implmentation ensures a more uniform distribution.
 * Returns the randomly generated integer.
 */
int get_random(int upper_bound)
{
	int divisor = RAND_MAX/(upper_bound);
	int retval;

	do {
		retval = rand() / divisor;
	} while( retval > upper_bound );

	return retval;
}

/*
 * Compares two integers.
 * Returns 1 if a > b, -1 if a < b, and 0 if a = b.
 */
int comparison(const void *a, const void *b)
{
	int int_a = *((int*)a);
	int int_b = *((int*)b);
	return ( int_a > int_b ? 1 : ( int_a < int_b ? -1 : 0 ) );
}

/*
 * Compares two integers.
 * Returns 1 if a < b, -1 if a > b, and 0 if a = b.
 */
int r_comparison(const void *a, const void *b)
{
	int int_a = *((int*)a);
	int int_b = *((int*)b);
	return ( int_a < int_b ? 1 : ( int_a > int_b ? -1 : 0 ) );
}
