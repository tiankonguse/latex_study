int gauss() {
     int i,j,k;
     j=0;
     for (i=m-1;i>=0;i--)
     {
           for (k=j;k<n;k++)
                    if ( (a[k]>>i)&1 )
                             break;
           if (k<n)
           {
                    swap(a[k],a[j]);
                    for (k=0;k<n;k++)
                             if (k!=j && ( (a[k]>>i)&1 ))
                                       a[k]^=a[j];
                    j++;
           }
     }
     return j;
}
//the Kth Xor
inline int fun(int k) {
    int res=0;
    for (int i=0;i<r;i++) {
             if ((k>>i)&1) {
                  res ^= a[r-i-1];
             }
    }
    return res;
}

//exist x?
bool find(int x) {
    if (x == 0) return true;
    int now = 0;
    for (int i = 0; i < r; ++i) {
        now ^= a[i];
        if (now == x) return true;
        else if (now > x) {
            now ^= a[i];
        }
    }
    return false;
}
