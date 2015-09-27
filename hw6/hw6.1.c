#include <stdio.h>
#include <stdlib.h>
#include <windows.h>   
    
void pushHeap(int item);
void printHeap(void);
void max_heapify(int i);

int n = 1;
int heap[200];

int main(void)
{
    int i, value, oldPriority, newPriority;
	char YorN;

    LARGE_INTEGER Freq;  // 64-bit signed integer value
    LARGE_INTEGER BeginTime;  
    LARGE_INTEGER EndTime;  
    QueryPerformanceFrequency(&Freq);    //獲得硬體內部計時器震盪頻率 
    
    /*Get information from file*/
	FILE *fptr = fopen("hw6_set.txt", "r");
    if(!fptr){
              printf("Open failure!");
              exit(1);
              }
    /*Create Max Heap*/
    while (fscanf(fptr, "%d%*c", &value) != EOF)
          pushHeap(value);
	fclose(fptr);
	
	printf("Create Max Heap:\n");
    printHeap();
    
    while(1){
    printf("\nChange priority?(Y/N): ");
    scanf("%c", &YorN);
       
    if(YorN == 'Y'){
              printf("\nChoice priority: ");
              scanf("%d", &oldPriority);
              printf("\nChange priority to: ");
              scanf("%d", &newPriority);
    
              QueryPerformanceCounter(&BeginTime); //獲得硬體內部計時器的值(BeginTime)

              for(i = 1; i < n; i++)
                           if(heap[i] == oldPriority){
                                      heap[i] = newPriority;
                                      break;
                                      }   
              /*Max Heapify - 確保以此node以下為max heap*/
              while(i != 0){
                             max_heapify(i);
                             i /= 2;
                             }
              
              QueryPerformanceCounter(&EndTime);  //獲得硬體內部計時器的值(EndTime)
              printHeap();

              printf("\nSpend time: %f sec \n", 
              (double)(EndTime.QuadPart-BeginTime.QuadPart)*1000/Freq.QuadPart);
              getchar();
              }
    else{
        printf("\nPress any key to continue…\n");
        getchar();
        break;
        }
    }
	
	getchar();
	return 0;

}

void pushHeap(int item)
{
     int i = n;
     if( n == 199 ){ printf("Heap Full!");
                     exit(1);     
                     }
     while( (i != 1) && item > heap[i/2] ){
            heap[i] = heap[i/2];
            i /= 2;
            }
     heap[i] = item;
     n++;
}     

void printHeap(void)
{
     int i;
     printf("\nMax Heap: ");
     for(i = 1; i < n; i++)
           printf("%d ", heap[i]);
     printf("\n");
}

void max_heapify(int i)
{
     int l = 2*i;
     int r = 2*i+1;
     int largest, temp;
     
     if( (l <= n-1) && heap[l] > heap[i] )
         largest = l;
     else largest = i;
     
     if( (r <= n-1) && heap[r] > heap[largest] )
         largest = r;
     
     if(largest != i){
                temp = heap[i];
                heap[i] = heap[largest];
                heap[largest] = temp;
                max_heapify(largest);
                }
}

