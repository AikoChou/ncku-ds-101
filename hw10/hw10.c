#include <stdio.h>
#include <stdlib.h>

typedef struct{
       int key;
       } element;

void buildFlag(void);
void mergeSort(element initList[], int n);
void mergePass(element initList[], element mergedList[], int n, int s);
void merge(element initList[], element mergeList[], int i, int m, int n);
void printList(void);

element initList[30], mergedList[30];
int accu[10] = {0}, part[10] = {0};
int num = 1, n = 1;

int main(void)
{   
    FILE *fptr;
    fptr = fopen("set.txt", "r");
    while(1){/*讀檔，把list存進initList array中  */
             fscanf(fptr, "%d%*c", &initList[num++]);
             if(feof(fptr)) break;
             }
    fclose(fptr);
    num--; /*num is # of records*/
                    
    buildFlag();
    mergeSort(initList, n);
    printList();
    
    getchar();
    return 0;                   
}

void buildFlag(void)
{
     int i;
     for(i = 1; i < num; i++){/*prevailing order within the input list*/
           if(initList[i].key > initList[i+1].key){
                              accu[n++] = i;
                                        }
                              }/*n is # of ordered sublists*/
     accu[n] = num; /*accu array 紀錄sublists的最後一個index */
     for(i = 1; i <= n ; i++){/*part array 紀錄目前每個sublist中record的個數*/
           part[i] = accu[i] - accu[i-1];
           }
}

void mergeSort(element initList[], int n)
{
     int s = 1;
     int i, j;
     while(s < n){
             mergePass(initList, mergedList, n, s);
             
             s *= 2;
             j = 1;
             /* update part array */
             for(i = 1; i <= (n/s)+1 ; i++){
                   part[i] = part[j] + part[j+1];
                   j+=2;
                   }
             /* update initList */
             for(i = 0; i < num; i++)      
                   initList[i] = mergedList[i];
             
             }   
}

void mergePass(element initList[], element mergedList[], int n, int s)
{
     int i, j, k;
     for(i = 1; i <= n-2*s+1; i +=2*s){/*兩兩一組*/
           merge(initList, mergedList, accu[i], accu[i]+part[i]-1, accu[i+2*s-1]);
           }
     if(i+s-1 < n)/*最後一組*/
              merge(initList, mergedList, accu[i], accu[i]+part[i]-1, accu[n]);
     else/*沒有組的*/
         for(j = i; j <= n; j++)
               mergedList[accu[j]] = initList[accu[j]];             
}

void merge(element initList[], element mergeList[], int i, int m, int n)
{
     int j, k, t;
     j = m+1;
     k = i;
     while(i <= m && j <= n){
             if(initList[i].key <= initList[j].key)
                                mergedList[k++] = initList[i++];
             else
                                mergedList[k++] = initList[j++];
             }
     if(i > m)
          for(t = j; t <= n; t++)
                mergedList[k++] = initList[t];
     else
         for(t = i; t <= m; t++)
                mergedList[k++] = initList[t];
    
}

void printList(void)
{/*印出mergedList*/
     int i;
     for(i = 1; i < num; i++){
           printf("%d,", mergedList[i]);
           }      
     printf("%d", mergedList[i]);
}                                                
                          
          
                
                                
             
