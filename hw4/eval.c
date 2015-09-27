#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int pop(void);
void push(int calc);

int j = 0, m = 0;
int top = -1;
int stack[20];

int main(void)
{   
    int i, k = 0, n; 
    int op1, op2;
    char expr[30];
    char mofy[30];
    char temp[3];
    int num[10];
    FILE *fptr;
    
/*Get information from file*/      
    fptr = fopen("set.txt", "r");
    if(!fptr){
              printf("Open failure!");
              exit(1);
              }
    while(fgets(expr, 30, fptr) != NULL){ 
    printf("Prefix expresion: %s", expr); }    
    printf("\n");
    fclose(fptr);
    
/*Create a modify expression*/      
    for(i = 0; expr[i] != '\0'; i++){      
          if(isdigit(expr[i])) temp[k++] = expr[i];
          else if(isgraph(expr[i])) mofy[j++] = expr[i];
               else if(expr[i] == ' ' && k != 0){
                    num[m++] = atoi(temp);
                    mofy[j++] = '#';
                    for(n = 0; n < 3; n++) temp[n] = ' ';
                    k = 0;
                    }
          }
    if(k != 0){ num[m++] = atoi(temp);
                mofy[j++] = '#';
                }
    j--;    
    m--;
    
/*Calculate*/         
    while(j >= 0){
            if(mofy[j] == '#') { push(num[m--]); 
                                 j--;}
            else{   op1 = pop();
                    op2 = pop();
                    switch(mofy[j]){
                           case '+': push(op1+op2);
                                     break;
                           case '-': push(op1-op2);
                                     break;
                           case '*': push(op1*op2);
                                     break;                                         
                           case '/': push(op1/op2);
                                     break;
                           case '%': push(op1%op2);
                                     break;
                           default : printf("Wrong@@");
                           }
                    j--;
                }
            }
/*Output answer*/       
    printf("Ans = %d", pop());                                
    getchar();
    return 0;
} 

int pop(void)
{
    return stack[top--];
}

void push(int calc)
{
     stack[++top] = calc;
}
