#include"checkFormula_extendFormula.h"

bool checkIfElementsAreCorrect(char *El,PIECE *table,int n){
  
for(int i=0;i<n;i++){
if(strcmp(table[i].element,El)==0)
return true;
}
return false;

return true;

}
int number(char *buf,int *i){
  int p=4;
  char *charNum=(char*)malloc(4*sizeof(char));
              if(charNum==NULL){
                perror("can't allocate\n");
                exit(-1);
              }
              int s=0,num=0,k;

               for( k=*i;isdigit(buf[k]);k++){
                if(s==p){
                     p*=2;
                    char *temp=(char*)realloc(charNum,p*sizeof(char));
                    if(temp==NULL){
                        perror("can't realloc\n");
                        exit(-1);
                    }
                    charNum=temp;
                   
                }
                     charNum[s]=buf[k];
                     s++;
               }
               charNum[s]='\0';
               num=atoi(charNum);
                free(charNum);
                *i=k-1;
                return num;
}


void advanceNumber(char *buf,int *i,int *num,int sizeOfLine){
 while (*i + 1 < sizeOfLine && isdigit(buf[*i + 1])) {
   
                        *num = (*num) * 10 + (buf[*i +1] - '0');
                         (*i)++;
                    }
}
  
  
  
 bool validParenthesesAndDiktes(char *txt){
   FILE *read = fopen(txt,"r");
   if(read==NULL){
    perror("File not found");
    exit(-1);
}

char buf[1024];
int line=1;
bool balanced=true;
bool numAfterPar=false;
Stack *stack = (Stack*)malloc(sizeof(Stack));
if(stack==NULL){
    perror("can't allocate memory");
    exit(-1);
}
stack->top=NULL;


while(fgets(buf,sizeof(buf),read)!=NULL){
  

int sizeOfLine=strlen(buf);

if (isdigit(buf[0])){
printf("There is a number on the start of the formula in line %d:\n ",line);
balanced=false;
line++;
continue;
}
for(int i=0;i<sizeOfLine;i++){
    
   
           if (buf[i] == '(') {
            char temp[2];

              sprintf(temp, "%c", buf[i]);

                push(stack, temp);
            
            if(isdigit(buf[i+1])){
                printf("There is a number after ( in line:%d\n ",line);
                balanced=false;
                numAfterPar=true;
            
            }

            }
           
            else if (buf[i] == ')') {
                  
                if (is_empty(stack)) {
                    balanced = false;
                    printf("Parentheses NOT balanced in line: %d\n", line);
                    break;
                }
                
               char* temp= pop(stack);
            free(temp); 
}
else  if(isdigit(buf[i])){
 int num=number(buf,&i);
               if(num<2||num>99){
               printf("Invalid number between currentElements in line:%d\n",line);
               balanced = false;
               break;
               }
               
    }  
}
 if (!is_empty(stack)) {
    balanced=false;
            printf("Parentheses NOT balanced in line: %d\n", line);
        }

        
        while (!is_empty(stack)) {
           char* temp= pop(stack);
            free(temp);
        }
        line++;  
}
free(stack);
fclose(read);

if(balanced && !numAfterPar)
return true;
else
return false;

}

void makeFileBlank(char *out){
 FILE *write = fopen(out, "w");
                fprintf(write,"%c",' ');
                fclose(write);
                     exit(-1);
}




 

void extend(char *txt, char *out,PIECE *table,int n) {
    
if(!validParenthesesAndDiktes(txt))
exit(-1);


FILE *read = fopen(txt, "r");
    FILE *write = fopen(out, "w");

    if (read == NULL) {
        perror("File not found");
        exit(-1);
    }
int line=1;

    char buf[1024];
    Stack *stack = (Stack *)malloc(sizeof(Stack));  
    stack->top = NULL;

    while (fgets(buf, sizeof(buf), read) != NULL) {
        char exVersiont[1024] = ""; 
        int sizeOfLine = strlen(buf);

        for (int i = 0; i < sizeOfLine; i++) {
            
     if(isalpha(buf[i])||isdigit(buf[i])||buf[i]=='('||buf[i]==')'){
            if (isalpha(buf[i])) {
                ELEMENT currentElement; 
                currentElement.symbol[0] = buf[i];  
                currentElement.symbol[1] = '\0';     
                currentElement.numbers = 1;

                if (i + 1 < sizeOfLine && islower(buf[i + 1])) {
                    currentElement.symbol[1] = buf[i + 1];  
                    currentElement.symbol[2] = '\0';        
                    i++;
                }
                
                if (i + 1 < sizeOfLine && islower(buf[i + 1])) {
                    currentElement.symbol[2] = buf[i + 1];  
                    currentElement.symbol[3] = '\0';        
                    i++;
                }
                if(!checkIfElementsAreCorrect(currentElement.symbol,table,n)){
                printf("Incorrect symbol in line:%d.Can't continue.",line);
                fclose(write);
               makeFileBlank(out);
               
                }
                
                if (i + 1 < sizeOfLine && isdigit(buf[i + 1])) {
                    currentElement.numbers = 0;
                    advanceNumber(buf, &i, &currentElement.numbers, sizeOfLine);
                }

               
                for (int j = 0; j < currentElement.numbers; j++) {
                    if (strlen(exVersiont) + strlen(currentElement.symbol) + 2 < sizeof(exVersiont)) {
                        strcat(exVersiont, currentElement.symbol);
                        strcat(exVersiont, " ");
                    }
                }
            }
            else if (buf[i] == '(') {
              if(buf[i+1]==')'){
                printf("There is ) after ( in line:%d\n",line);
                fclose(write);
                makeFileBlank(out);
              }
                push(stack, exVersiont);
                
                strcpy(exVersiont, "");
            }
            else if (buf[i] == ')') {
                int count = 1;
                if (i + 1 < sizeOfLine && isdigit(buf[i + 1])) {
                    count = 0;
                    advanceNumber(buf, &i, &count, sizeOfLine);
                }

                char multiplied[1024] = "";
                for (int j = 0; j < count; j++) {
                    if (strlen(multiplied) + strlen(exVersiont) < sizeof(multiplied)) {
                        strcat(multiplied, exVersiont);
                    } 
                }

                char *previous = pop(stack);
                if (previous != NULL) { 
                    char *combined = malloc(strlen(previous) + strlen(multiplied) + 1);
                    if (combined != NULL) {
                        strcpy(combined, previous);
                        strcat(combined, multiplied);
                        strcpy(exVersiont, combined);
                        free(combined); 
                    }
                    free(previous); 
                }
            }
          }
          else if(buf[i]!='\n'){
             printf("Not a digit or a %c number in line:%d\n",buf[i],line);
                 fclose(write);
               makeFileBlank(out);
        }
    }

       line++;
        fprintf(write, "%s\n", exVersiont);
      
        
        
        while (!is_empty(stack)) {
            char* temp= pop(stack);
            free(temp);
        }
        strcpy(exVersiont, "");
    }

    fclose(read);
    fclose(write);
    free(stack); 
}



#ifdef Test_checFormula_extendFormula

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
else
printf("Give correct data\n");


}
return 0;
    
}
#endif