[程式架構]

一、主程式
	open file
    	call storeINC function
    	call dfs function
二、副程式
void storeINC(void);
	初始化一些dfs會用到的flag: numVertex,numEdge,printedEdge[],walker
	讀檔，把incidence matrix存進INC的2D array中
void dfs(int v);
	用Recursive的方式，參數為某個vertex，第一次call為0
	尋找此vertex row 中為1的位置，印出所屬edge
	call  acrossVertex function 算出以此edge連接的另一個vertex(=descendant)
	再Recursive call dfs，參數為descendant
	當所連edge數達到numVertex-1時完成
int acrossVertex(int v, int e);
	算出以此edge連接的另一個vertex(=descendant)

[程式語言]

C

[編譯環境]

Dev-C++ 4.9.9.2


