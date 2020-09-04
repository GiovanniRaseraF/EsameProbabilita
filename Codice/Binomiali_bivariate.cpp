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




	string derivataprima = "xdg-open https://www.wolframalpha.com/input/?i=D(D(e^(2*(4e^(t)-4))))";
	cout << derivataprima << endl;
	string d{};
	for (auto c : derivataprima) {
		if (c == '(') d += "%28";
		else if (c == ')') d += "%29";
		else d += c;
	}
	system(d.c_str());
	return 0;
}
