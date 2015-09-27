#include <stdio.h>
#include <stdlib.h>

typedef enum {rparen, lparen, plus, minus, times, divide, 
             mod, eos, operand } precedence;
             
precedence getToken(void);
void storeToken(precedence token);
precedence pop(void);
void push(precedence token);

char expr[45];
char pref[45];
precedence stack[10];
int top = 0;
int i = 0, j = 0;
char symbol;
    
int main(void)
{
    precedence token;
    stack[0] = eos;
    int isp[] = {0,19,12,12,13,13,13,0};
    int icp[] = {20,19,12,12,13,13,13,0};
    FILE *fptr;

/*Get information from file*/    
    fptr = fopen("set2.txt", "r");
    if(!fptr){
              printf("Open failure!");
              exit(1);
              }
    while(fgets(expr, 45, fptr) != NULL){ 
    printf("Infix expresion: %s", expr); }    
    printf("\n");
    fclose(fptr);
    
/*從右至左scan*/    
    while(expr[i] != '\0') i++;
    for(token = getToken(); i >= 0; token = getToken()){ 
           if(token == operand)  pref[j++] = symbol; 
           else if(token == lparen){
                while(stack[top] != rparen)  storeToken(pop());
                pop();
                }
           else{ while(isp[stack[top]] > icp[token])  storeToken(pop());
                 push(token);
                 }
           }
/*處理剩下operators*/
    while((token = pop()) != eos)  storeToken(token);
    
/*倒著印出Prefix*/
    printf("Prifix expresion: ");
    for(j--; j >= 0; j--)
             printf("%c", pref[j]);

    getchar();
    return 0;
}

precedence getToken(void)
{
           symbol = expr[--i];
           switch(symbol){
                case '(' : return lparen;
                case ')' : return rparen;
                case '+' : return plus;
                case '-' : return minus;
                case '/' : return divide;
                case '*' : return times;
                case '%' : return mod;
                case ' ' : return eos;
                default : return operand;
                }
}   

void storeToken(precedence token)
{
     switch(token){
                case 2 : pref[j++] = '+'; break;
                case 3 : pref[j++] = '-'; break;
                case 4 : pref[j++] = '*'; break;
                case 5 : pref[j++] = '/'; break;
                case 6 : pref[j++] = '%'; break;
                default : ; printf("Error@@\n"); 
                }
}

precedence pop(void)
{
     return stack[top--];
}

void push(precedence token)
{
     stack[++top] = token;
}
