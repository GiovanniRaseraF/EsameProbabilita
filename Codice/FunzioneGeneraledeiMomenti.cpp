/*
@author Giovanni Rasera
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

int fac(int val) {
	int res = val + 1, f = 1;
	while (res-- > 1) f *= res;
	return f;
}

int bin(int n, int k) { return (int)(fac(n) / (fac(k) * fac(n - k))); }

void p(const char* s) {
	cout << s;
}
void pln(const char* s) {
	cout << s << endl;
}
void p(double s) {
	cout << s;
}
void pln(double s) {
	cout << s << endl;
}

int main() {
	
	return 0;
}
