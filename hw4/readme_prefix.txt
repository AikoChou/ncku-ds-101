[程式架構]

一、主程式

/*Get information from file*/
以讀檔方式取得Infix數學式

/*小小的while*/
讓i跑到最後面

/*for迴圈*/
從右至左scan Infix數學式
  1)遇到operand→直接存入prefix
  2)遇到左括符→則stack中至右括符為止要依序pop出
  3)遇到其他運算符→比較stack頂端和目前token的優先序
    stack頂端為大時，pop出
  
/*小小的while*/
scan完Infix數學式，但stack中還有operantor時，依序pop出

/*印出Prefix*/
最後要把prefix中倒著印出才是正確的表示式

二、副程式

precedence getToken(void);
  用來把Infix中每一個字元型態的symbol
  轉換成precedence(enum type)

void storeToken(precedence token);
  在for中(2)(3)兩種情況要把pop出的token轉回字元型態
  存入prefix

precedence pop(void);
  使暫存operators的stack 
  pop出一個token(precedence型態)

void push(precedence token);
  把目前token(precedence型態)push進
  暫存operators的stack 

[程式語言]

C

[編譯環境]

Dev-C++ 4.9.9.2

[程式操作方法]

更改set2.txt內的Infix expresion再執行

[額外功能] 

無

