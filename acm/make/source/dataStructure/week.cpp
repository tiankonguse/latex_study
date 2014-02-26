\subsection{星期几}
\begin{lstlisting}
//`返回 1~7`
int getday(int y,int m,int d) {
//` 1 月 2 月当作前一年的 13,14 月`
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    int ansa= d + 2*m + 3*(m+1)/5 + y + y/4;
    int ansb= (ansa - y/100 + y/400)%7 +1;
    ansa= (ansa+5)%7 +1;
    if(y<1752)return ansa;
    if(y == 1752 && m < 9)return ansa;
    if(y == 1752 && m == 9 && d < 3)return ansa;
