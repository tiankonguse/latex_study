unsigned countbits(unsigned x){
unsigned mask[]={0x55555555,0x33333333, 0x0F0F0F0F,  0x00FF00FF, 0x0000FFFF};
	for(unsigned i=0,j=1;i<5;i++,j<<=1)
x=(x & mask[i]) + ((x>>j) & mask[i]);
	return x;
} 
