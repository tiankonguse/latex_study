int cnt=0;
int str[N],tmp[N];
//`调用 MergeSort（0，n）`
void Merger(int l,int mid,int r) {
    int i, j, tmpnum=l;
    for( i=l, j=mid; i < mid && j < r; ) {
        if( str[i] > str[j] ) {
            tmp[tmpnum++] = str[j++];
            cnt += mid-i;
        } else tmp[tmpnum++] = str[i++];
    }
    if( j < r ) for( ; j < r; ++j ) tmp[tmpnum++] =
                str[j];
    else for( ; i < mid; ++i ) tmp[tmpnum++] = str[i];
    for ( i=l; i < r; ++i ) str[i] = tmp[i];
}
void MergeSort(int l, int r) {
    int mid;
    if( r > l+1 ) {
        int mid = (l+r)/2;
        MergeSort(l, mid);
        MergeSort(mid, r);
        Merger(l,mid,r);
    }
}
