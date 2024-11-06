#ifndef PERIODIC_TABLE_H
#define PERIODIC_TABLE_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
    char *element;  
    int atomic;    
} PIECE;

/**
 * @brief Loads periodic table data from a file into a dynamically allocated array.
 * 
 * This function reads elements and atomic numbers from a specified file, dynamically
 * allocating and resizing memory as needed. It checks for valid element symbols and
 * atomic numbers before storing them in an array of PIECE structs.
 * 
 * @param txt The filename from which to load the periodic table data.
 * @param size A pointer to an integer indicating the initial size of the periodic table array. 
 *             This value is updated if the array is resized.
 * 
 * @return A pointer to an array of PIECE structs containing periodic table data.
 */
PIECE *load(char *txt, int *size);

/**
 * @brief Frees the memory allocated for the periodic table array.
 * 
 * This function releases the memory for each element's symbol as well as the
 * main array holding the periodic table data.
 * 
 * @param Periodic_table Pointer to the array of PIECE structs to be freed.
 * @param n The number of elements in the periodic table array.
 */
void free_periodic_table(PIECE *Periodic_table,int n);
#endif
