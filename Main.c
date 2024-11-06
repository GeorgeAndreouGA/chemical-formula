#include "periodic_table.h"
#include<stdio.h>
#include"checkFormula_extendFormula.h"
#include"formulaProton.h"
#include<string.h>
int main(int argc,char *argv[]){

if(argc<4)
printf("Give correct data\n");

else{

if(strcmp(argv[2],"-v")==0 &&(argc==4)){
 
  printf("Verify balanced parentheses and numbers in %s\n",argv[3]);
   if (validParenthesesAndDiktes(argv[3]))
    printf("Parentheses and numbers are balanced for all chemical formulas\n");
}

else if(strcmp(argv[2],"-ext")==0 && argc==5){
printf("Compute extended version of formulas in %s\n",argv[3]);
int n=1;
 PIECE  *periodic_table =load(argv[1],&n);
 extend(argv[3],argv[4],periodic_table,n);
 printf("Writing formulas to %s\n",argv[4]);
  free_periodic_table(periodic_table,n);
}
else if(strcmp(argv[2],"-pn")==0 && argc==5){
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