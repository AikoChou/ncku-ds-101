@程式架構:
int main(void) //主程式
讓user輸入二數m,n
呼叫Ack_Rec和Ack_Iter
print出結果

int Ack_Rec(int m, int n) //副程式1
遞迴版本計算Ackerman's function的值
幾乎和A(m,n)型式相同
因為不停要呼叫本身,花費時間比疊代版本多很多

int Ack_Iter(int m, int n) //副程式2
疊代版本計算Ackerman's function的值
因A(m,n)是當m=0時才會有值出來,
所以用一個array存放m的變化 
用一個do-while迴圈,
變數t記錄算到第幾層複合函數
當t=0時跳出迴圈

@程式語言: C

@編譯環境: Dev-C++ 4.9.9.2

@程式操作方法: 
在"請輸入 m,n"後輸入兩數,兩數間要空space,再按enter
