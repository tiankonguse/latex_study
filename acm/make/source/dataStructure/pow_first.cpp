//`A\^{}B=10\^{}(A*log(B) ),即可以转化求10*（A*log(B)）的首位数字。`
//`对于10\^{}X，X为一个实数，可以分解成一个整数加一个小数的和，X=Z+P。即 `
//`10\^{}X=10\^{}(Z+P)=10\^{}Z+10\^{}P,其中（0<=P<1）`
//`显然这里的10\^{}Z是不会影响到10*X的首位数字。`
int GetHighest(double a,double b){
    double intpart;
    double fractpart = modf(b*log10(a),&intpart);
    double temp=pow((double)10,fractpart);
    modf(temp,&intpart);
    return (int)intpart;  
}
