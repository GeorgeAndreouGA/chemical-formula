#ifndef FORMULA_PROTON_H
#define FORMULA_PROTON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "periodic_table.h"
#include "checkFormula_extendFormula.h"

/**
 * @brief Calculates the total protons for each line in the output file and writes them back to the same file.
 * 
 * This function reads an output file containing expanded chemical formulas line-by-line, calculates the total
 * protons based on the atomic values in the periodic table, and writes each total proton count to the output file.
 * 
 * @param output The name of the output file containing expanded formulas.
 * @param table The periodic table array used to determine atomic values.
 * @param n The number of elements in the periodic table.
 */
void calculateProtons(char *output, PIECE *table, int n);

#endif 
