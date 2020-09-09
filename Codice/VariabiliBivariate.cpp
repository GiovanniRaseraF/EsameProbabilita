/*
@author Giovanni Rasera
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <tuple>
#include <stack>
using namespace std;

// CPP program to evaluate a given 
// expression where tokens are  
// separated by space. 
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
		int binx = bin(nx, x);				double px_pow_x = pow(px, x);    double one_px_pow_nxx = pow(1.0-px, (nx-x));
		cout << "x: "<< x << "   C(" << nx << " " << x << ") * (" << px << ")^" << x << "  *(1-" << px << ")^(" << (nx-x) << ")= ";
		double res_px = binx * px_pow_x * one_px_pow_nxx;
		cout << binx << " * " << px_pow_x << " * " << one_px_pow_nxx << "  = ";
		cout << res_px << endl;
		Sx_res.push_back(res_px);
	}
	cout << "Sx={"; for (int x : Sx) cout << x << ","; cout << "}"; cout << endl;

    //Trovo il supporto di Sy
	cout << endl << "Supporto di Sy" << endl;
    string ny_x = traduce(ny, nx);
	int nyx = 0;
    cout << "ny|x: " << ny_x << endl;
	cout << "inserisci ny|x: "; cin >> nyx;
	//Creazione del supporto di Sy
	vector<int> Sy{};
	vector<double> Sy_res{};
	for (int i = 0; i <= nyx; i++) Sy.push_back(i);
	for (int y : Sy) {
		int biny = bin(nyx, y);				double py_pow_y = pow(py, y);    double one_py_pow_nyx = pow(1.0 - py, (nyx - y));
		cout << "y: " << y << "   C(" << nyx << " " << y << ") * (" << py << ")^" << y << "  *(1-" << py << ")^(" << (nyx - y) << ")= ";
		double res_py = biny * py_pow_y * one_py_pow_nyx;
		cout << biny << " * " << py_pow_y << " * " << one_py_pow_nyx << "  = ";
		cout << res_py << endl;
		Sy_res.push_back(res_py);
	}
	cout << "Sy={"; for (int y : Sy) cout << y << ","; cout << "}"; cout << endl;

	//Tabella dei supporti
	const int c_y = nyx, c_x = nx;
	double** SupportoCongiunto = new double*[c_y+1];
	for (int i = 0; i <= c_y; i++) SupportoCongiunto[i] = new double[c_x + 1];
	int y_pos = 0;
	for (double y : Sy_res) {
		int x_pos = 0;
		for (double x : Sx_res) {
			SupportoCongiunto[y_pos][x_pos] = (y * x);
			x_pos++;
		}
		y_pos++;
	}
	//Tabella
	cout << endl << "Tabella:" << endl << "  ";
	for (int i = 0; i <= c_x; i++) cout << i << "\t"; cout << endl;
	for (int y = 0; y <= c_y; y++) {
		cout << y << " ";
		for (int x = 0; x <= c_x; x++) {
			cout << SupportoCongiunto[y][x] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}