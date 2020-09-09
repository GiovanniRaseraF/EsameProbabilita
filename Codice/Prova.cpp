/*
@author Giovanni Rasera
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <tuple>
#include <stack>
#include "exprtk.hpp"
using namespace std;


string traduce(string& fun, int x) {
	string ret = "";
	for (char c : fun) {
		if (c == 'x') ret += to_string(x);
		else ret += c;
	}
	return ret;
}

int fac(int val) {
	int f = 1;
	for (int i = 1; i <= val; i++) f *= i;
	return f;
}

double bin(int n, int k) {
	if (k == 0) return 1;
	if (k == 1) return n;
	return (fac(n) / (fac(k) * fac(n - k)));
}


int main() {
	//Variabili Bivariate e Binomiali
	int nx = 0; double px = 0;
	cout << "Variabili bivariate e binomiali" << endl;
	cout << "X - Bi(nx, px): " << endl;
	cout << "nx: "; cin >> nx;
	cout << "px: "; cin >> px;
	cout << "X - Bi(" << nx << ", " << px << ")" << endl << endl;
	string ny{}; double py = 0;
	cout << "Y|X - Bi(ny, py): " << endl;
	cout << "ny: "; cin >> ny;
	cout << "py: "; cin >> py;
	cout << "Y|X - Bi(" << ny << ", " << py << ")" << endl << endl;

	//Trovo il supporto di X in Sx
	cout << endl << "Supporto di Sx" << endl;
	vector<int> Sx{};
	vector<double> Sx_res{};
	for (int i = 0; i <= nx; i++) Sx.push_back(i);
	for (int x : Sx) {
		int binx = bin(nx, x);				double px_pow_x = pow(px, x);    double one_px_pow_nxx = pow(1.0 - px, (nx - x));
		cout << "x: " << x << "   C(" << nx << " " << x << ") * (" << px << ")^" << x << "  *(1-" << px << ")^(" << (nx - x) << ")= ";
		double res_px = binx * px_pow_x * one_px_pow_nxx;
		cout << binx << " * " << px_pow_x << " * " << one_px_pow_nxx << "  = ";
		cout << res_px << endl;
		Sx_res.push_back(res_px);
	}
	cout << "Sx={"; for (int x : Sx) cout << x << ","; cout << "}"; cout << endl;

	typedef double T; // numeric type (float, double, mpfr etc...)
	typedef exprtk::symbol_table<T> symbol_table_t;
	typedef exprtk::expression<T>     expression_t;
	typedef exprtk::parser<T>             parser_t;

	symbol_table_t symbol_table;
	double nx_value = (double)nx;
	symbol_table.add_variable("x", nx_value);

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	if (!parser.compile(ny, expression)) {
		cout << "Parsing error";
		return -1;
	}

	T result = expression.value();

	cout << result << endl;

}