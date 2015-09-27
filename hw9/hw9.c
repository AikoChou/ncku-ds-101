#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdint.h>  
#include <string.h> 

typedef enum {FALSE, TRUE} bool;
 
void storeINC(void);
void dfs(int v);
int acrossVertex(int v, int e);

int INC[5][5] = {0};
int printedEdge[5] = {FALSE};
int walker, numVertex, numEdge;
char const *next_integer;
FILE *fptr;

int main(void)
{
    fptr = fopen("m1.txt", "r");
    storeINC();
    printf("\nM1:\n");
    dfs(0);
    
    fptr = fopen("m2.txt", "r");
    storeINC();
    printf("\nM2:\n");
    dfs(0);
    
    fptr = fopen("m3.txt", "r");
    storeINC();
    printf("\nM3:\n");
    dfs(0);    
    
    fclose(fptr);
    
    getchar();
    return 0;
}

void storeINC(void)
{
     char row[10];
     int m, n;
     
     /*��l��*/
     for(m = 0; m < numVertex; m++){
          for(n = 0; n < numEdge; n++){
                INC[m][n] = 0;
                printedEdge[n] = FALSE; 
                }
          }
     walker = 0;
     numVertex = 0;
     
     /*Ū��data ��matrix�s�iINC 2D array*/
     while(fgets(row, 10, fptr) != NULL){ 
                     numEdge = 0;
                     next_integer = row;
                     do{
                        sscanf( next_integer, "%d", &INC[numVertex][numEdge++] ); 
                        next_integer = strchr( next_integer+1, '\t' ); //���Ltab�� 
                     }while( next_integer != NULL );  
                     numVertex++;        
                     }
     
}
/*Recursive ��ҳsedge�ƹF��numVertex-1�ɧ���*/
void dfs(int v)
{
     int i, j;
     for(j = 0; j < numEdge; j++){
            if(walker == numVertex - 1) break;
            if((INC[v][j] == 1)&&(printedEdge[j] == FALSE)){
                         printf("e%d", j);
                         printedEdge[j] = TRUE;
                         if((walker++) != numVertex - 2) printf("->");
                         dfs(acrossVertex(v, j));
                         }
      }                                    
}
/*�M��v���@���I�����He(edge)�s�����t�@�ӳ��I*/
int acrossVertex(int v, int e)
{
    int i;
    for( i = 0; i < numVertex; i++){
         if((INC[i][e] == 1) && (i != v)){
                       return i;
         }
    }        
}






