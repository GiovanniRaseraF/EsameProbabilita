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
//Utilizzo della miglior libreria per estrazione di dati csv
//Carico la tabella
rapidcsv::Document doc("tavola_normale.csv", rapidcsv::LabelParams(0, 0));

/*
Estrae i valori dalle tavole della funzione di ripartizione della legge normale standard
(che nome lungo per nulla !!)
*/
double trova(double zd) {
	string z{};
	z = to_string(zd);
	string yaxis = z.substr(0, 3);
	string xaxis = "0.0"+z.substr(3, 1);

	cout << "\nEstrazione delle tavole:\n";
	cout << endl << "y= " << yaxis;
	cout << endl << "x= " << xaxis;
	cout << endl;
	cout << "//////////////////////\n";
	
	//Straggo dal csv
	double estrazioneTavola = doc.GetCell<double>(xaxis, yaxis);
	
	return estrazioneTavola;
}

int main() {
	
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
	//Estrazione del valore dalle tavole
	double t = A, sigma = 0;
	double dacercare = abs((t - u)/a);
	if (t - u < 0)	sigma = 1 - trova(dacercare);
	else			sigma = trova(dacercare);
	
	double PYnA = 1 - sigma;
	cout << "P(Y" << n << " > " << A << ")= "; cout << PYnA<<endl;


	//Parcellizzo il risultato
	//Estrazione del valore dalle tavole
	t = B; sigma = 0;
	dacercare = abs((t - u) / a);
	if (t - u < 0)	sigma = 1 - trova(dacercare);
	else			sigma = trova(dacercare);

	double PYnB = sigma;
	cout << "P(Y" << n << " < " << B << ")= "; cout << PYnB << endl;
	
	return 0;
}
