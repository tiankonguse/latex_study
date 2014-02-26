//调用 ksort(0,n,s)
void ksort(int l, int h, int a[]) {
    if (h < l + 2) return;
    int e = h, p = l;
    while (l < h) {
        while (++l < e && a[l] <= a[p]);
        while (--h > p && a[h] >= a[p]);
        if (l < h) swap(a[l], a[h]);
    }
    swap(a[h], a[p]);
    ksort(p, h, a);
    ksort(l, e, a);
}
