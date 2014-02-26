const int MAXSIZE=10000;
int a[MAXSIZE],size;
void PushDown(int now) {
    int l=now<<1;
    int r=l+1;
    if(l==size) {
        if(a[now]<a[l])
            swap(a[now],a[l]);
    } else if(r<=size) {
        int tmp=a[l]>a[r]?l:r;
        if(a[now]<a[tmp]) {
            swap(a[now],a[tmp]);
            PushDown(tmp);
        }
    }
}
void BuildMaxHeap() {
    for(int i=size>>1; i; i--)PushDown(i);
}
void HeapSort(int n) {
    size=n;
    BuildMaxHeap();
    for(int i=size; i; i--) {
        swap(a[i],a[1]);
        size--;
        PushDown(1);
    }
}
