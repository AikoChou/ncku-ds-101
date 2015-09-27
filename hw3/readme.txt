[程式架構]

一、主程式

/*Get information from user*/
取得陣列n x m的值及starting point 

/*Set two-dimensional arrays*/ 
除了最後要顯示出來的Count array, 
另外建立了一個相同size的Check array,
用來紀錄走過的瓷磚,是初次走到的瓷磚就把值設為1,
並把計數的flags加1,直到flags等於n*m
表示全部皆已至少走過一次

/*While loop*/
跳出的條件是moves大於50000
Loop裡面執行
1)隨機數取得蟲蟲的下一步
2)檢驗是否穿牆
3)修改Count array
4)總步數加1
5)檢驗是否是初次走到的瓷磚→修改Check array
6)檢驗是否全部走過(flags)
    
/*Output the result*/
1) The total number of legal moves that the cockroach makes. 
2) The final count array. 

/*Release the blocks of memory*/

二、建立2維陣列的funtion


[程式語言]

C

[編譯環境]

Dev-C++ 4.9.9.2

[程式操作方法]

輸入陣列n x m的值及starting point 
*starting point 若為(10, 10)
 是要輸入initial X: 9 及initial Y: 9 

[額外功能] 

無

