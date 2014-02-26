#define TT __int64
const int N=12;
const int MOD=2008512;
const int sz=10;
struct Matrix{
    TT a[N][N];
    TT Matrix(){memset(a,0,sizeof(a));}
    void _union(){int l=sz;while(l--)a[l][l]=1; }
    Matrix operator*(Matrix& B);
    Matrix pow(TT k); 

}; 
