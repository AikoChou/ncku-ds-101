�D�ؤ@: 
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

�D�ؤG  : 
Implement natural merge sort. Use natural merge sort to sort different 
length of unsorted sequences, then output the sorted sequence. 

[�{���[�c]

�@�B�D�{��
	Ū�ɡA��list�s�iinitList array��    
	call buildFlag function
    	call mergeSort function
    	call printList function

�G�B�Ƶ{��
void buildFlag(void);
	��Xprevailing order within the input list
	accu array ����sublists ���̫�@��index
	part array �����ثe�C��sublists record���Ӽ�
void mergeSort(element initList[], int n);
	�Ѽ�n�Oinput list��ordered sublists���Ӽ�
	call mergePass function
	update part array and initList 
void mergePass(element initList[], element mergedList[], int n, int s);
	call merge function
	�ǤJ�Ѽ�i, m, n�אּ
	i = accu[i]
	m = accu[i]+part[i]-1
	n = accu[i+2*s-1]
void merge(element initList[], element mergeList[], int i, int m, int n);
	�Mtextbook�ۦP
void printList(void);
	�L�XmergedList

[�{���y��]

C

[�sĶ����]

Dev-C++ 4.9.9.2


