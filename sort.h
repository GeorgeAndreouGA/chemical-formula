#ifndef SORT_H
#define SORT_H
#include"periodic_table.h"

/**
 * @brief Sorts an array of PIECE structs representing elements in the periodic table by atomic number.
 * 
 * This function uses the selection sort algorithm to arrange elements in ascending order 
 * based on their atomic number.
 * 
 * @param periodic_table Pointer to an array of PIECE structs that will be sorted.
 * @param n The number of elements in the periodic_table array.
 */
void sort(PIECE *periodic_table, int n);

#endif 
