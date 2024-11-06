#include "periodic_table.h"
#include"sort.h"



PIECE * load(char *txt,int *size){
    
  PIECE *Periodic_table=(PIECE*)malloc(*size *sizeof(PIECE));
  if(Periodic_table==NULL){
    perror("Can't allocate memory");
    exit(-1);
  }

  FILE *read=fopen(txt,"r");

  if(read==NULL|| strcmp(txt,"periodicTable.txt")!=0){
    perror("can't find file");
    exit(-1);
  }
int counter=0;
int Atomicnum=0;
char *bufElement = (char*)malloc(10*sizeof(char));


while(fscanf(read,"%s%d",bufElement,&Atomicnum)!=EOF){

if(counter==*size){
    *size *=2;
     PIECE *temp=(PIECE*)realloc(Periodic_table,*size *sizeof(PIECE));
      if(temp==NULL){
        perror("Can't reallocate memory");
        exit(-1);
      }
      else
      Periodic_table=temp;
}

  


    int sizeOfLine=strlen(bufElement);

 
for(int i=0;i<sizeOfLine;i++)
if((bufElement[i]<'A'||bufElement[i]>'Z')&&(bufElement[i]<'a'||bufElement[i]>'z')){
perror("Not a valid element");
exit(-1);
}

if(Atomicnum<=0||Atomicnum>118){
  perror("Not a valid atomic number");
exit(-1);
}
Periodic_table[counter].element=(char*)malloc(strlen(bufElement)+1*sizeof(char));
if(Periodic_table[counter].element==NULL){
  perror("Can't allocate memory");
  exit(-1);
}
strcpy(Periodic_table[counter].element,bufElement);
Periodic_table[counter].atomic=Atomicnum;


if(bufElement==NULL){
   perror("Can't allocate memory");
  exit(-1);
}
counter++;
}
free(bufElement);
*size=counter;
fclose(read);
sort(Periodic_table,*size);

FILE *write=fopen(txt,"w");

if(write==NULL){
  perror("Can't open file");
  exit(-1);
}

for(int i=0;i<*size;i++)
fprintf(write,"%s %d\n",Periodic_table[i].element,Periodic_table[i].atomic);
fclose(write);

return Periodic_table;
}

void free_periodic_table(PIECE *Periodic_table,int n){
    for(int i=0;i<n;i++)
    free(Periodic_table[i].element);

free(Periodic_table);
}



#ifdef Test_Periodic_Table_Andd_Sort
int main(int argc,char *argv[]){

int n=1;
 PIECE  *periodic_table =load(argv[1],&n);

 for(int i=0;i<n;i++)
 printf("%s %d\n",periodic_table[i].element,periodic_table[i].atomic);

 free_periodic_table(periodic_table,n);
return 0;
}
#endif