題目一: 
Text    P.343 EXERCISE.5 
Quick sort is an unstable sorting method. Give an example of an input list 
in which the order of records with equal keys is not preserved. 

Before quicksort:
R1 R2 R3 R4 R5 R6 R7 R8
7    5    4    8    3    5    9    1

After quicksort:
R8 R5 R3 R6 R2 R1 R4 R7
1    3    4    5    5    7    8    9

K2 = K6
But R6 precedes R2 in the sorted list. ->unstable

題目二  : 
Implement natural merge sort. Use natural merge sort to sort different 
length of unsorted sequences, then output the sorted sequence. 

[程式架構]

一、主程式
	讀檔，把list存進initList array中    
	call buildFlag function
    	call mergeSort function
    	call printList function

二、副程式
void buildFlag(void);
	找出prevailing order within the input list
	accu array 紀錄sublists 的最後一個index
	part array 紀錄目前每個sublists record的個數
void mergeSort(element initList[], int n);
	參數n是input list中ordered sublists的個數
	call mergePass function
	update part array and initList 
void mergePass(element initList[], element mergedList[], int n, int s);
	call merge function
	傳入參數i, m, n改為
	i = accu[i]
	m = accu[i]+part[i]-1
	n = accu[i+2*s-1]
void merge(element initList[], element mergeList[], int i, int m, int n);
	和textbook相同
void printList(void);
	印出mergedList

[程式語言]

C

[編譯環境]

Dev-C++ 4.9.9.2


