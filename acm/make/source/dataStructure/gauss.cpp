class Gauss {
    int var,equ;//有 equ 个方程，var 个变元。
    int matrix[N][N],free_x[N],ans[N];// matrix 为增广矩阵，ans 为解集,free_x 判断是否是不确定的变元.
public:
    void init(int n,int m);
    int getanswer();
//高斯消元法解方程组(Gauss-Jordan elimination).
//(-2 表示有浮点数解，但无整数解，-1 表示无解，0表示唯一解，大于 0 表示无穷解，并返回自由变元的个数)
};
void Gauss::init(int n,int m) {
    this->equ=m;
    this->var=n;
    memset(matrix,0,sizeof(matrix));
}
int Gauss::getanswer() {
    int tmp;
    int max_r,ta,tb,k,col=0;
// 转换为阶梯阵.
    for(k=0; k<equ && col<var ; k++,col++) {
        max_r=k;
//找到该 col 列元素绝对值最大的那行与第 k 行交换
        for(int i=k+1; i<equ; i++)
            if(abs(matrix[i][col])> abs(matrix[max_r][col]))max_r=i;
        if(max_r != k) { // 与第 k 行交换
            for(intj=k; j<var+1; j++)
                swap(matrix[k][j],matrix[max_r][j]);
        }
// 说明 col 列第 k 行以下全是 0 了，则处理下一列
        if(matrix[k][col] == 0) {
            k--;
            continue;
        }
        ta=matrix[k][col];
//之后列的要化为 0
        for(int i=k+1; i<equ ; i++) {
            if(matrix[i][col] != 0) {
                tb=matrix[i][col];
                for(int j=col; j<=var; j++)
                    matrix[i][j]=matrix[i][j]*ta-matrix[k][j]*tb;
            }
        }
    }
// 1. 无解的情况: 化简的增广阵中存在(0, 0, ..., a)这样
    的行(a != 0).
    for(int i=k; i<equ; i++) {
        if(matrix[i][var]!=0)return -1;//无解
    }
// 无穷解的情况:
    if(k!=col || col<var) {
        int free_x_num=0,free_index;
        for(int i=k-1; i>=0; i--,free_x_num=0) {
            for(int j=0; j<var; j++) {
                if(matrix[i][j]&&free_x[j])
                    free_x_num++,free_index=j;
            }
            if(free_x_num>1)continue;
            tmp=matrix[i][var];
            for(int j=0; j<var; j++) {
                if(matrix[i][j]&& j!=free_index)
                    tmp-=matrix[i][j]*ans[j];
            }
            ans[free_index]=tmp/matrix[i][free_index];
            free_x[free_index]=0;
        }
        return var - k;// 自由变元有 var - k 个.
    }
// 3. 唯一解: 在增广阵中形成严格的上三角阵.
    for(int i=var-1; i>=0; i--) {
        tmp=matrix[i][var];
        for(int j=i+1; j<var; j++) {
            tmp-=matrix[i][j]*ans[j];
        }
        if(tmp % matrix[i][i])return -1;// 说明有浮点数解
        ans[i]=tmp/matrix[i][i];
    }
    return 0;
}
