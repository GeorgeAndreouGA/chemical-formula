#include"formulaProton.h"

void calculateProtons(char *output,PIECE *table,int n){
    
    

    FILE *readOut=fopen(output,"r");

    char buf[1024];

 Stack *stack = (Stack *)malloc(sizeof(Stack));  
    stack->top = NULL;

    while(fgets(buf,sizeof(buf),readOut)!=NULL){
        char str[1024]="";
    int sizeOfLine=strlen(buf);
      char *currelement=(char *)malloc(4*sizeof(char));
      int k=0;
      int add=0;
    for(int i=0;i<sizeOfLine;i++){

        if(buf[i]!=' '){
          currelement[k]=buf[i];
          k++;
        }
        else{
            currelement[k]='\0';
            
    for(int s=0;s<n;s++)
    if(strcmp(table[s].element,currelement)==0){
           add+=table[s].atomic;
         break;
    }
            free(currelement);
        currelement=(char *)malloc(4*sizeof(char));
        k=0;
        }

    }
    free(currelement);
      sprintf(str, "%d", add);
    push(stack,str);
    str[0]='\0';
    }
    fclose(readOut);
     FILE *writeOut=fopen(output,"w");

Stack *tempStack= (Stack *)malloc(sizeof(Stack));  
    tempStack->top = NULL;

     while(!is_empty(stack)){
          char *popped = pop(stack);
          push(tempStack,popped);
            free(popped);
     }
     free(stack);
  


      while(!is_empty(tempStack)){
          char *popped = pop(tempStack);
          fprintf(writeOut,"%s\n",popped);
            free(popped);
     }
     printf("Writing formulas to %s\n",output);
      free(tempStack);
     fclose(writeOut);
}


#ifdef Test_formulaProton
int main(int argc,char *argv[]){
  if(argc<4){
    printf("Give correct data\n");
  }
  else{
  if(strcmp(argv[2],"-pn")==0 && argc==5){
  printf("Compute total proton number of formulas in %s\n",argv[3]);
   int n=1;
  PIECE  *periodic_table =load(argv[1],&n); 
  extend(argv[3],argv[4],periodic_table,n);
  calculateProtons(argv[4],periodic_table,n);
  free_periodic_table(periodic_table,n);
}
else
printf("Give correct data\n");
  }
return 0;
}
#endif