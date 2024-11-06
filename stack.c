#include "stack.h"



void push(Stack *stack, char *value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("Failed to allocate memory for new node");
        exit(-1);
    }
     
    new_node->data = (char*)malloc((strlen(value)+1)*sizeof(char));

    if (new_node->data == NULL) {
        perror("Failed to allocate string");
        exit(-1);
    }
    strcpy(new_node->data,value);


   
    new_node->next = stack->top;
    stack->top = new_node;
}


char *pop(Stack *stack) {
    if (is_empty(stack)) {
        return NULL;
    }
    Node *temp = stack->top;
    char *popped_value = (char*)malloc((strlen(temp->data)+1)*sizeof(char));
    if(popped_value==NULL){
        perror("can't allocate memory");
        exit(-1);
    }
    strcpy(popped_value,temp->data);
    stack->top = stack->top->next;
    free(temp->data);
    free(temp);
    return popped_value;
}

int is_empty(Stack *stack) {
    return stack->top == NULL;
}

void printStack(Stack *stack){
    Node *temp=stack->top;
    while(temp->next!=NULL){
        printf("%s\n",temp->data);
        temp=temp->next;
    }
      printf("%s\n",temp->data);
}

#ifdef TEST_STACK
int main() {
    
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        perror("Failed to allocate memory for the stack");
        exit(-1);
    }

   
    stack->top = NULL;

    printf("Pushing 'Hello' onto the stack...\n");
    push(stack, "Hello");

printf("printing the stack\n");
        printStack(stack);

    printf("Pushing 'World' onto the stack...\n");
    push(stack, "World");

printf("printing the stack\n");
        printStack(stack);

    printf("Pushing 'Stack' onto the stack...\n");
    push(stack, "Stack");

printf("printing the stack\n");
        printStack(stack);




  while(!is_empty(stack)){
    char *value=pop(stack);
    printf("Popping from the stack: %s\n", value);
    free(value);
  }
   
  
    if (is_empty(stack)) 
        printf("The stack is now empty.\n");
    

    
    free(stack);

    return 0;
}
#endif