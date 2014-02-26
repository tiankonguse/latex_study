double pi = 3.14159265358...; // no 'f' appended
#define maxn 200 + 20 // it's not safe
int const mod = 1000000007; // use "const" to accelerate
judge mp.find(x) != mp.end()" is better than ret += mp[x]" directly

0x3f3f3f3f   =   1061109567  (recommended)
0x7f7f7f7f   =   2139062143
0x3FFFFFFFFFFFFFFFLL    =   4611686018427387903    (recommended)
0x7FFFFFFFFFFFFFFFLL    =   9223372036854775807

//memset
memset(dpMin, 0x3f, sizeof(dpMin)); //  inf
memset(dpMax, 0xc0, sizeof(dpMax)); // -inf

//for_bit
for (int i = a ; i != 0 ; i = (i - 1) & a)

//count bit
static int countbit[1024];
for (int i = 1; i < 1024; ++i) countbit[i] = 1 + countbit[i - ((i ^ (i - 1)) & i)];

//sort by lexicographic
int cmp(const void *a, const void *b) {
	char *x = (char *)a;
	char *y = (char *)b;
	return strcmp(x, y);
}
qsort(str, n, sizeof(str[0]), cmp);
