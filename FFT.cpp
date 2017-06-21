//Si la base es un numero complejo en lugar de una clase propia es algo mas lento

#include <vector>
#include <iostream>
#include <complex>
#include <math.h>
#include <set>
#include <string.h>

using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

//typedef complex<double> base;
struct base{
 	double r,i;
	base(double r=0, double i=0):r(r), i(i){}
	double real()const{return r;}
	void operator/=(const int c){r/=c, i/=c;}
};

base operator*(const base &a, const base &b){ return base(a.r*b.r-a.i*b.i, a.r*b.i+a.i*b.r); }
base operator+(const base &a, const base &b){ return base(a.r+b.r, a.i+b.i); }
base operator-(const base &a, const base &b){ return base(a.r-b.r, a.i-b.i); }

const int MAXN = 10000000;
int rev[MAXN];
base wlen_pw[MAXN];

void fft (base a[], int n, bool invert) {
	for (int i=0; i<n; ++i)
		if (i < rev[i])
			swap (a[i], a[rev[i]]);
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*M_PI/len * (invert?-1:+1);
		int len2 = len>>1;
 
		base wlen (cos(ang), sin(ang));
		wlen_pw[0] = base (1, 0);
		for (int i=1; i<len2; ++i)
			wlen_pw[i] = wlen_pw[i-1] * wlen;
 
		for (int i=0; i<n; i+=len) {
			base t,
				*pu = a+i,
				*pv = a+i+len2, 
				*pu_end = a+i+len2,
				*pw = wlen_pw;
			for (; pu!=pu_end; ++pu, ++pv, ++pw) {
				t = *pv * *pw;
				*pv = *pu - t;
				*pu = *pu + t;
			}
		}
	}
 
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}
 
void calc_rev (int n, int log_n) {
	for (int i=0; i<n; ++i) {
		rev[i] = 0;
		for (int j=0; j<log_n; ++j)
			if (i & (1<<j))
				rev[i] |= 1<<(log_n-1-j);
	}
}

inline static void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
  int n=1; 
	int logn = 0;
	while(n < max(a.size(), b.size()))
		n <<= 1, logn++;
	n <<= 1, logn++;
	calc_rev(n, logn);
	fa.resize (n),  fb.resize (n);
	fft (&fa[0], n, false),  fft (&fb[0], n, false);
	for (int i = 0; i < n; i++){
		fa[i] = fa[i] * fb[i];
	}
	fft (&fa[0], n, true);
	res.resize(n);
	for (int i = 0; i < n; i++){
		res[i] = int (fa[i].real() + 0.5);
	}
}
