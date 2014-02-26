Matrix Matrix::operator*(Matrix& B){
    Matrix ret;
    for(int i=0;i<sz;i++)
    for(int j=0;j<sz;j++)
    for(int k=0;k<sz;k++)
        ret.a[i][j]=(ret.a[i][j]+a[i][k]*B.a[k][j]) %MOD;
    return ret;  
} 
