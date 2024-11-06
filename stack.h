#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;                
    struct Node *next;        
} Node;

typedef struct {
    Node *top;               
} Stack;


/**
 * @brief Pushes a new value onto the stack.
 * 
 * This function allocates memory for a new node, stores the provided value,
 * and updates the stack's top pointer to the new node.
 * 
 * @param stack Pointer to the Stack structure.
 * @param value The string to be stored in the new node.
 */

void push(Stack *stack, char *value);

/**
 * @brief Removes and returns the top value from the stack.
 * 
 * This function pops the top value from the stack, freeing the node's memory 
 * and returning a copy of the string stored in it.
 * 
 * @param stack Pointer to the Stack structure.
 * @return char* A copy of the popped string. 
 *         Returns NULL if the stack is empty.
 */
char *pop(Stack *stack);

/**
 * @brief Checks if the stack is empty.
 * 
 * @param stack Pointer to the Stack structure.
 * @return int Returns 1 if the stack is empty, 0 otherwise.
 */
int is_empty(Stack *stack); 


/**
 * @brief Prints the contents of the stack from top to bottom.
 * 
 * This function traverses the stack and prints each string stored
 * in the nodes. If the stack is empty, it outputs a message indicating
 * that the stack is empty.
 * 
 * @param stack Pointer to the Stack structure to be printed.
 * 
 * @note This function does not modify the stack or free any nodes.
 */
void printStack(Stack *stack);
#endif 
