
bool state[513];
int _map[513];
int _map_num;
int str[513][513];
int _val_map[513];
//`第 bit 位置为 1 val,val 可以是 0 或 1，bit 是 1~8`
void setBit(int& now,int bit,int val = 1) {
    bit--;
    if(val == 1) {
        now |= (1<<bit);
    } else {
        now &= ~(1<<bit);
    }
}
//`得到第 bit 位的值`
int getBit(int now,int bit) {
    bit--;
    return (now>>bit)&1;
}
//`输出 c 的二进制`
void outputState(int c) {
    printf(",\"");
    for(int i=8; i; i--) {
        printf("%d",getBit(c,i));
    }
    printf("\"\n");
}
//`添加状态 c`
int addState(int c) {
    if(state[c] == false) {
        state[c] = true;
        _map[_map_num] = c;
        _val_map[c] = _map_num;
        _map_num++;
    }
    return _val_map[c];
}
//`判断 now 是否全 1`
bool isPutAll(int now) {
    return now == 255;
}
//`深搜得到状态`
void dfs(int lev,int now,int next) {
    int nextState,i;
    if(isPutAll(now)) {
        nextState = addState(next);
        str[lev][nextState]++;
        return ;
    }
//`视情况修改`
    if(getBit(now,8) == 0 && getBit(now,1) == 0) {
        setBit(now,8,1);
        setBit(now,1,1);
        dfs(lev,now,next);
        setBit(now,8,0);
        setBit(now,1,0);
    }
    for(i=8; i>0; i--) {
        if(getBit(now,i) == 0) {
            setBit(now,i,1);
            setBit(next,i,1);
            dfs(lev,now,next);
            setBit(now,i,0);
            setBit(next,i,0);
            break;
        }
    }
    for(i=8; i>1; i--) {
        if(getBit(now,i) == 0) {
            if(getBit(now,i-1) == 0) {
                setBit(now,i,1);
                setBit(now,i-1,1);
                dfs(lev,now,next);
                setBit(now,i,0);
                setBit(now,i-1,0);
            }
            break;
        }
    }
}
//`生成状态`
void bornState() {
    memset(state,false,sizeof(state));
    _map_num = 0;
    memset(str,0,sizeof(str));
    addState(0);
    for(int i=0; i<_map_num; i++) {
        dfs(i,_map[i],0);
    }
}
