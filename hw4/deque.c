#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void addright(int item);
void addleft(int item);
void showArray(void);
int testFull(void);

int *arr;
int maxSize, front = 0, rear = 0;

int main(void)
{
    int ad, k, lr, item; 
    srand((unsigned) time(NULL));

/*Dequeue Size from user*/
    printf("Enter array size: ");
    scanf("%d", &maxSize);
    arr = malloc((maxSize+1) * sizeof(int));
    
/*While Loop*/        
    while(1){
             printf("choice 1)add  2)delete: ");
             scanf("%d", &ad);
    
             if(ad == 1){  
                   if(testFull() == 1){
                            printf("Queue Full!\n");
                            continue;
                            }
                   printf("input sequence(**PLEASE END LINE WITH '-1'**): ");
                   for(;;){
                           k = rand() % 2;
                           scanf("%d", &item);
                           if(item == -1) break;
                           else if(testFull() == 1){ 
                                printf("Queue Full!\n");
                                break; }  
                           else{
                                if(k == 0) addright(item);
                                else addleft(item);
                                }
                           }
             }else if(ad == 2){
                   if(front == rear){
                            printf("Queue Empty!\n");
                            continue;
                            }
                   printf("delete 1)left  2)right: ");
                   scanf("%d", &lr);
                   switch(lr){
                     case 1: if(front == maxSize) front = 0;
                             else front++;
                             break;
                     case 2: if(rear == 0) rear = maxSize;
                             else rear--;
                             }
                   }
             showArray();
             fflush(stdin);
            }       
    free(arr); 
    return 0;
}

void addleft(int item)
{
     arr[front] = item;
     if(front == 0) front = maxSize;
     else front--;
}

void addright(int item)
{
     rear = (rear+1) % (maxSize+1);
     arr[rear] = item; 
}

void showArray(void)
{
     if(front == rear){
              printf("Queue Empty!\n");
              return;
              }

     int i = front;
     printf("show array: ");
     while(1){ 
          if(i == maxSize) i = 0;
          else i++;
          printf("%d ", arr[i]);
          if(i == rear) break;
          }
     printf("\n\n");
}    

int testFull(void)
{
    if(rear+1 == front) return 1;
    else if(rear == maxSize && front == 0) return 1;
    else return 0;
}
    
     
