`sum=SUM( $|$ai - k$|$ ),使 sum 最小`
int kth_element(int n,int* str,int k) {
    int t,key;
    int l=0,r=n-1,i,j;
    while (l<r) {
        for (key=str[((i=l-1)+(j=r+1))>>1]; i<j;) {
            for (j--; key<str[j]; j--);
            for (i++; str[i]<key; i++);
            if (i<j) t=str[i],str[i]=str[j],str[j]=t;
        }
        if (k>j) l=j+1;
        else r=j;
    }
    return str[k];
}
