bool eq(int i,int j,int sz){
    int tmp=0,k;
    for(k=0;k<sz;k++){
        tmp += A[i][k]*B[k][j];
    }
    return tmp == C[i][j];
}

const int L = 10000;
bool randTest(int sz){
    int i,j,k;
    for(k=0;k<L;k++){
        i = rand()%sz;
        j = rand()%sz;
        if(!eq(i,j,sz))return false;
    }

    return true;
}
