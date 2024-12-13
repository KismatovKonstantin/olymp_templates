double a, b;
const int n = 1000*1000;
double s = 0;
double h = (b - a) / N;
fi(0, n) {
	double x = a + h * i;
	s += f(x) * ((i==0 || i==N) ? 1 : ((i&1)==0) ? 2 : 4);
}
s *= h / 3;