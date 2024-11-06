#ifndef CHECKFORMULA_EXTENDFORMULA_H
#define CHECKFORMULA_EXTENDFORMULA_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include"stack.h"
#include"periodic_table.h"
typedef struct {
    char symbol[4];  
    int numbers;       
} ELEMENT;


/**
 * @brief Extracts a number from a string starting at a given index.
 * 
 * @param buf The string buffer containing the number.
 * @param i A pointer to the index in the buffer. It is updated to the end of the number.
 * @return The extracted integer value.
 */
int number(char *buf,int *i);



/**
 * @brief Advances through a numeric sequence in a string.
 * 
 * @param buf The string buffer containing the sequence.
 * @param i A pointer to the current index, which will be updated.
 * @param num The number being processed.
 * @param sizeOfLine The total length of the buffer.
 */
void advanceNumber(char *buf,int *i,int *num,int sizeOfLine);



/**
 * @brief Checks if a given element exists in the periodic table.
 * 
 * @param El The symbol of the element to check.
 * @param table The periodic table array.
 * @param n The number of elements in the periodic table.
 * @return true if the element is found in the periodic table, false otherwise.
 */
bool checkIfElementsAreCorrect(char *El,PIECE *table,int n);

/**
 * @brief Checks for balanced parentheses and validates other syntax rules.
 * 
 * @param txt The name of the text file to check.
 * @return true if the formula in the file is syntactically valid, false otherwise.
 */
bool validParenthesesAndDiktes(char *txt);


/**
 * @brief Creates a blank file with a single space if validation fails.
 * 
 * @param out The name of the output file.
 */
void makeFileBlank(char *out);


/**
 * @brief Extends a chemical formula by interpreting nested groups and expanding them.
 * 
 * @param txt The input file name with the original formula.
 * @param out The output file name for the expanded formula.
 * @param table The periodic table array used to check element symbols.
 * @param n The number of elements in the periodic table.
 */
void extend(char *txt,char *out,PIECE *table,int n);
#endif 
