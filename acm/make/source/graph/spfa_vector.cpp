
typedef struct {
    int from,to,dis;
} E;
int N,M,X;
vector< vector<E> > map;
queue<int> que;
vector<bool> inQue;
vector<int> dis;

{
    /*`X 为源点`*/
    map.clear();
    while(!que.empty())que.pop();
    inQue.clear();
    dis.clear();
    map.resize(N+1);
    inQue.resize(N+1,false);
    dis.resize(N+1,INF);
    map2.resize(N+1);//`初始化 map2`
    for(i=0; i<M; i++) {
        scanf("%d%d%d",&e.from,&e.to,&e.dis);
        map[e.from].push_back(e);
    }
    que.push(X);
    inQue[X]=true;
    dis[X]=0;
    while(!que.empty()) {
        w=que.front();
        que.pop();
        inQue[w]=false;
        for(i=0; i<map[w].size(); i++) {
            if(dis[map[w][i].to]>dis[w]+map[w][i].dis) {
                dis[map[w][i].to]=dis[w]+map[w][i].dis;
                if(!inQue[map[w][i].to]) {
                    que.push(map[w][i].to);
                    inQue[map[w][i].to]=true;
                }
            }
        }
    }
}
