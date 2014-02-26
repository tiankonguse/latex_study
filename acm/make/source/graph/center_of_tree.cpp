int treeSize; //` treeSize 树的大小`
int best_size;//` 子树平均大小，初始值是树的大小`
int center;//`最优根，初始值随意`

inline int centerOfGravity(int const u,int const p) {
    int max_sub = 0,size = 1,v,t;
    for(int son=head[u]; son!=-1; son=nodes[son].next) {
        v=nodes[son].v;
        if(vi[v] || v==p)continue;
        t = centerOfGravity(v,u);
        size += t;
        if(t > max_sub)max_sub = t;
    }
    max_sub = max(max_sub, treeSize - size);

    if(max_sub < best_size) {
        center = u;
        best_size = max_sub;
    }
    return size;
}
