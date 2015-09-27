[程式架構]

Global variable
-Array heap[200]
-n: heap中node的總個數

一、主程式

宣告變數
讀取檔案

/*Create Max Heap*/
依序fscanf value
並呼叫pushHeap副程式

呼叫printHeap副程式印出Max Heap

while迴圈: 不停詢問是否要Change priority?

	if 'Y': 向User取得oldPriority及newPriority
		此時獲得硬體內部計時器的值(BeginTime)
		for loop 找到oldPriority所在位置
			 並改成newPriority
		/*Max Heapify*/
		while loop 從這個node呼叫max_heapify副程式
			   及它的parent node直到root
  			   (因max_heapify只確保以此node以下為max heap)	
		此時獲得硬體內部計時器的值(EndTime)
		呼叫printHeap副程式印出Max Heap
		計算Spend time並印出
				
	if 'N': 任意鍵結束程式


二、pushHeap 副程式
parameter是要加入heap的item
令變數i是最後一個的位置
先檢查heap是否滿了
while loop 比較item是否比它的parent大
若大於則讓parent到child的位置
變數i更改為parent的index再和它的grandparent比較
依此類推直到root
若不大於則跳出loop 讓此位置填入item的值
最後每加入一個node則n值加1

三、printHeap 副程式
依序印出node

四、max_heapify 副程式
parameter是更動過Priority的index
令它的left child的index為l
      right child的index為r
比較此Priority和它的左右孩子 找出最大值
若最大值是出現在孩子就交換位置
  再呼叫本身(Recursion) 
  parameter更改為出現最大值的index
如此可以確保以newPriority為root為max heap

[程式語言]

C

[編譯環境]

Dev-C++ 4.9.9.2

[程式操作方法]

Input Yes(Y) or No(N)

Input old priority and new priority

[額外功能] 

無