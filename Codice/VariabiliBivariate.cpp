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

int main() {
	//Variabili Bivariate e Binomiali
    cout<<"Variabili bivariate e binomiali"<<endl;
    cout<<(bin(1,0)*(1.0-1.0/4.0))<<endl;
    cout<<(bin(1,1)*(1.0/4.0))<<endl;


	return 0;
}