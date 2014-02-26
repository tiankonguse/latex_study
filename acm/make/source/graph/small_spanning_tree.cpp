#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
const int
MAXN=501,MAXM=MAXN*MAXN*4,INF=0x7FFFF
                              FFF;
using namespace std;
struct edge {
    edge *next,*op;
    int t,c;
    bool mst;
}
ES[MAXM],*V[MAXN],*MST[MAXN],*CLS[MAXN
                                 ];
int N,M,EC=-1,MinST,Ans,NMST;
int DM[MAXN],F[MAXN];
inline void addedge(edge **V,int a,int b,int c) {
    ES[++EC].next=V[a];
    V[a]=ES+EC;
    V[a]->t=b;
    V[a]->c=c;
    ES[++EC].next=V[b];
    V[b]=ES+EC;
    V[b]->t=a;
    V[b]->c=c;
    V[a]->op=V[b];
    V[b]->op=V[a];
    V[a]->mst=V[b]->mst=false;
}
void init() {
    int i,a,b,c;
    freopen("conf.in","r",stdin);
    freopen("conf.out","w",stdout);
    scanf("%d%d",&N,&M);
    for (i=1; i<=M; i++) {
        scanf("%d%d%d",&a,&b,&c);
        addedge(V,a,b,c);
    }
    Ans=INF;
}
void prim() {
    int i,j,Mini;
    for (i=1; i<=N; i++)
        DM[i]=INF;
    for (i=1; i;) {
        DM[i]=-INF;
        for (edge *e=V[i]; e; e=e->next) {
            if (e->c < DM[j=e->t]) {
                DM[j]=e->c;
                CLS[j]=e->op;
            }
        }
        Mini=INF;
        i=0;
        for (j=1; j<=N; j++)
            if (DM[j]!=-INF && DM[j]<Mini) {
                Mini=DM[j];
                i=j;
            }
    }
    for (i=2; i<=N; i++) {
        MinST+=CLS[i]->c;
        CLS[i]->mst=CLS[i]->op->mst=true;
        addedge(MST,CLS[i]->t,CLS[i]->op->t,CLS[i]->c);
    }
}
void dfs(int i) {
    for (edge *e=MST[i]; e; e=e->next) {
        int j=e->t;
        if (F[j]==-INF) {
            F[j]=F[i];
            if (e->c > F[j])
                F[j]=e->c;
            dfs(j);
        }
    }
}
void smst() {
    int i,j;
    for (i=1; i<=N; i++) {
        for (j=1; j<=N; j++)
            F[j]=-INF;
        F[i]++;
        dfs(i);
        for (edge *e=V[i]; e; e=e->next) {
            if (!e->mst) {
                NMST=MinST + e->c -F[e->t];
                if (NMST < Ans)
                    Ans=NMST;
            }
        }
    }
}
int main() {
    init();
    prim();
    smst();
    if (Ans==INF)
        Ans=-1;
    printf("Cost: %d\nCost: %d\n",MinST,Ans);
    return 0;
}
