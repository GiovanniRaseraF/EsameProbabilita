/*
@author Giovanni Rasera
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <tuple>
#include "rapidcsv.h"

using namespace std;

int main() {
	//Utilizzo della miglior libreria per estrazione di dati csv
	//Carico la tabella
	rapidcsv::Document doc("tavola_normale.csv", rapidcsv::LabelParams(0, 0));
	
	//Inserimento dei dati
	double u = 0, a2 = 0, n = 0, A = 0, B = 0;
	//Inserimento di u e a2
	cout << "Y1 = N(u, a2): \n";
	cout << "u: "; cin >> u;
	cout << "a2: "; cin >> a2;
	cout << "Yn = N(" << u << "," << a2 << "/n):\n";
	cout << "n: "; cin >> n;
	cout << endl<<endl;
	//Adesso inserisco il P(Yn><A,B)
	cout << "P(Y" << n << " > A):\n";
	cout << "A: "; cin >> A;
	cout << endl;
	cout << "P(Y" << n << " < B):\n";
	cout << "B: "; cin >> B;

	//Calcolo cio che mi serve
	double a = sqrt(a2/n);

	//Dimostrazione
	cout << "Dimostrazione di MYn(t)\n";
	cout << "MYn(t) = " << "exp(" << u << "t+0.5t^2 * " << a2 << "/n)"<<endl;

	//Parcellizzo il risultato


	
	//double estrazioneTavola = doc.GetCell<double>( "0.01", "0.1");

	//cout << estrazioneTavola;


	/*
	string derivataprima = "xdg-open https://www.wolframalpha.com/input/?i=D(D(e^(2*(4e^(t)-4))))";
	cout << derivataprima << endl;
	string d{};
	for (auto c : derivataprima) {
		if (c == '(') d += "%28";
		else if (c == ')') d += "%29";
		else d += c;
	}
	system(d.c_str());
	*/
	return 0;
}
