#include <stdio.h>
#include <conio.h>

int main(void)
{
    int m, n;
    printf("請輸入 m,n: ");
    scanf("%d %d", &m, &n);
    
    printf("遞迴版本 A(%d,%d)= %d\n", m, n, Ack_Rec(m, n));  
    printf("迴圈版本 A(%d,%d)= %d\n", m, n, Ack_Iter(m, n));
 
    getch();
    return 0;
}

int Ack_Rec(int m, int n)
{
    if(m == 0)
         return n + 1;
    else if( n == 0)
         return Ack_Rec( m - 1, 1 );
    else 
         return Ack_Rec( m - 1, Ack_Rec( m, n - 1 ));   
}

int Ack_Iter(int m, int n)
{
    int t = 1;
    int s[100000];
    s[0] = m;   
    
    do
    {
        if( s[t-1] == 0)
            { n++;
              t--;
            }
        else if( n == 0)
            {  s[t-1] = s[t-1] - 1;
               n = 1;
            }
        else 
        { s[t] = s[t-1];
          s[t-1] = s[t-1] - 1;
          n--;
          t++;
        }
        
    }while( t != 0);
    
    return n;
}   
    
    
