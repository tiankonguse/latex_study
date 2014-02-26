/*
`对于任何正整数x,其约数的个数记做g(x).`
`例如g(1)=1,g(6)=4.`
`如果某个正整数x满足:对于任意i(0$<$i$<$x),都有g(i)$<$g(x),则称x为反素数.`
`反素数可以理解为对于x,在[1,x]中,x的约数最多,也就是当前约数最多的值.`
*/

int rprim[35][2] = {498960,200,332640,192,277200,180, 
221760,168,166320,160,110880,144,83160,128,55440,120,
50400,108,45360,100,27720,96,25200,90,20160,84,15120,
80,10080,72,7560,64,5040,60,2520,48,1680,40,1260,36,
840,32,720,30,360,24,240,20,180,18,120,16,60,12,48,
10,36,9,24,8,12,6,6,4,4,3,2,2,1,1};

typedef __int64 INT;
INT bestNum;   //`约数最多的数`
INT bestSum;   //`约数最多的数的约数个数`
const int M=1000; //`反素数的个数 `
INT n=500000;//`求n以内的所有的反素数`
INT rprim[M][2];
//`2*3*5*7*11*13*17>n，所以只需考虑到17即可`
INT sushu[14]={2,3,5,7,11,13,17,19,23,29};  

//`当前走到num这个数，接着用第k个素数，num的约数个数为sum，`
//`第k个素数的个数上限为limit`
void getNum(INT num,INT k,INT sum,INT limit)  {
 	if(num>n)return;
	if(sum>bestSum){
		bestSum = sum,bestNum = num;;
	}else if(sum == bestSum && num < bestNum){  
		//`约数个数一样时，取小数`
		bestNum = num;
	}

	//`只需考虑到素数17,即sushu[6]`
	if(k>=7) return; 
	
	//`素数k取i个`
	for(INT i=1,p=1;i<=limit;i++){   
		p*=sushu[k];
		getNum(num*p,k+1,sum*(i+1),i);
	}
}
//`求大于等于log2（n）的最小整数`
INT log2(INT n){  
	INT i = 0,p = 1;
	while(p<n){p*=2,i++;}
	return i;
}
int getrprim(){
	int i = 0;
	while(n>0){
		bestSum =bestNum = 1;
		getNum(1,0,1,log2(n));
		n = bestNum - 1;
		rprim[i][0]=bestNum;
		rprim[i][1]=bestSum;
		i++;
	}
	return i;	
}
