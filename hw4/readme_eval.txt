[程式架構]

一、主程式

/*Get information from file*/
以讀檔方式取得Prefix expresion

/*Create a modify expression*/
因為程式規定數字不只個位數。
我的做法是先全部存為字元，一個一個scan
用isdigit()判斷是不是0~9的數字，是先存在暫時的字串中
再scan下一個，如果是十位數中間就不會存到空白鍵
再用atoi()把字串轉回十位數

modify expression是指把原expression的operators保留，
數字部分(包含個位數及其他)用'#'表示，
再把operands用另一個int array存起來。

/*Calculate while Loop*/ 
從modify expression的右邊開始scan 
  1)若是'#'→把一個數字push進stack
  2)若是operator→pop出兩個數字做運算再push回去
  
/*印出Prefix*/
最後pop出答案

二、副程式

/*stack 的 pop 和 push*/
int pop(void)
void push(int calc)

[程式語言]

C

[編譯環境]

Dev-C++ 4.9.9.2

[程式操作方法]

更改set.txt內的Prefix expresion再執行

[額外功能] 

無

