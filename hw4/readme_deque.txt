[程式架構]

一、主程式

/*Deque Size from user*/
我是使用circular queue的方式
所以若user輸入size為10
我會malloc 11個位置
用以區分Queue Empty和Queue Full

/*While loop*/
不停地詢問user要add還是delete並執行
--add
因為助教說Array的空間使用率會納入評分考量
我用一個for迴圈來scanf輸入的數字，加完一個再scanf下一個，
就不用array來先存全部的數字
但這樣必須要知道要scanf到什麼時候
所以user要在輸入的最後一個數字後打上"-1"
每加上一個數字之前要test是否已經滿了
--delete
(front == rear)是deque空的條件
每一次刪掉左邊一個或右邊一個

二、副程式


void addright(int item);
void addleft(int item);

void showArray(void);
我的deque是當加左邊時會移動front
加右邊時會移動rear，所以front到rear間是
整個deque的範圍
show array時就從i=front+1開始直到i=rear

int testFull(void);
(rear的下一個位置就是front)是deque滿的條件
有2種情形
1)當rear+1 == front
2)當rear == maxSize且front == 0

[程式語言]

C

[編譯環境]

Dev-C++ 4.9.9.2

[程式操作方法]

Enter array size: 10
choice 1)add  2)delete: 1 
input sequence(**PLEASE END LINE WITH '-1'**): 
1 2 3 4 5 6 7 -1

<<<輸入欲加整數串結尾要加上一個"-1">>>

[額外功能] 

無

