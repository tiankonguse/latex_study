#define eps 1e-8
double fgcd(double a, double b) {
	if(b > -eps && b < eps) {
		return a;
	} else {
		return fgcd( b, fmod(a, b) );
	}
}
