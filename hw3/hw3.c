#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int** make2dArray(int rows, int cols);

int main(void)
{
    int n, m, i, j, k;
    int moves = 0, flags = 1;
    int ibug, jbug;
    int imove[8] = {-1, 0, 1, 1,  1,  0, -1, -1};
    int jmove[8] = { 1, 1, 1, 0, -1, -1, -1,  0};
    int **countArray, **checkArray;

    srand((unsigned) time(NULL));

/*Get information from user*/
    printf("Input n: ");
    scanf("%d", &n);
    printf("Input m: ");
    scanf("%d", &m);
    printf("Input initial X: ");
    scanf("%d", &ibug);
    printf("Input initial Y: ");
    scanf("%d", &jbug);
    
/*Set two-dimensional array of count and check*/   
    countArray = make2dArray(n, m);
    checkArray = make2dArray(n, m);
    countArray[ibug][jbug] = 1; //The bug is already standing 
    checkArray[ibug][jbug] = 1; //on the starting point

/*Loop of the bug walk through certain tiles randomly */
    while(moves <= 50000)
    {
       k = rand() % 8;

       ibug = ibug + imove[k];
       jbug = jbug + jmove[k];

       if( ibug < 0 || ibug >= n || jbug < 0 || jbug >= m ){ 
           ibug = ibug - imove[k]; //When ehe coordinates lead up a wall,
           jbug = jbug - jmove[k]; //ignore this move
           continue; }
         
       countArray[ibug][jbug]++;
       moves++;
  
       if(checkArray[ibug][jbug] == 0){ //Record the tile which is toched first time
                                checkArray[ibug][jbug] = 1;
                                flags++; }
       if(flags == (n * m)) //Every tile is touched by the bug              
               break;                
    }
    
/*Output the result*/
    printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n");
    if(moves == 50001){
        printf("Mission failed!\n");
        printf("Total number of legal moves is 50000.\n");          
        }
    else
        printf("Total number of legal moves is %d.\n", moves);
    
    printf("\nFinal Count Array:\n");     
    for(i = 0; i < n; i++){
          for(j = 0; j < m; j++)
                printf("%3d ", countArray[i][j]);
          printf("\n");                                                     
          }
          
/*Release the blocks of memory*/
    free(countArray);
    free(checkArray);

    getch();
    return 0;
}

int** make2dArray(int rows, int cols)
{
      int **x, i, j;
      x = calloc(rows , sizeof (*x));
      for(i = 0; i < rows; i++)
           x[i] = calloc(cols , sizeof(**x));
      return x;
}
