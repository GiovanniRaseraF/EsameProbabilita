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
		cout << "ES: Urna e Palline:\n";
		//Dati
		int N1 = 0, B1 = 0, N2 = 0, B2 = 0, N3 = 0, B3 = 0, N4 = 0, B4 = 0;
		int n = 0, nE = 0, Nj = 0, NE = 0, BE = 0, CE = 0;
		int Aj = 0;
		int ni = 0;
		int Ci = 0, negCi = 0;
		//Input
		cout << "N1: "; cin >> N1;
		cout << "B1: "; cin >> B1;
		cout << "N2: "; cin >> N2;
		cout << "B2: "; cin >> B2;
		cout << "N3: "; cin >> N3;
		cout << "B3: "; cin >> B3;
		cout << "N4: "; cin >> N4;
		cout << "B4: "; cin >> B4;
		cout << "Urne Completate\n";

		cout << "n: "; cin >> n;
		cout << "nE: "; cin >> nE;
		cout << "Aj: ";	cin >> Aj;
		cout << "NE: ";	cin >> NE;
		cout << "BE: ";	cin >> BE;
		cout << "Completati di dati ausiliari\n - Scielta l'urna " << Aj << endl;

		//Calcolo dati utili
		CE = NE;
		int b = bin(nE, CE);

		double PEA1 = b * pow(((double)N1 / (double)(N1 + B1)), CE) * pow(((double)B1 / (double)(N1 + B1)), (nE - CE));
		double PEA2 = b * pow(((double)N2 / (double)(N2 + B2)), CE) * pow(((double)B2 / (double)(N2 + B2)), (nE - CE));
		double PEA3 = b * pow(((double)N3 / (double)(N3 + B3)), CE) * pow(((double)B3 / (double)(N3 + B3)), (nE - CE));
		double PEA4 = b * pow(((double)N4 / (double)(N4 + B4)), CE) * pow(((double)B4 / (double)(N4 + B4)), (nE - CE));

		double sommaPEAi = PEA1 + PEA2 + PEA3 + PEA4;
		cout << " PEA1: " << PEA1;
		cout << " \tPEA2: " << PEA2;
		cout << " \tPEA3: " << PEA3;
		cout << " \tPEA4: " << PEA4;
		cout << " \tsommaPEAi " << sommaPEAi << endl;

		//Trovo l'urna interessata
		double PEAj = 0;
		switch (Aj) {
		case 1:
			PEAj = PEA1;
			break;
		case 2:
			PEAj = PEA2;
			break;
		case 3:
			PEAj = PEA3;
			break;
		case 4:
			PEAj = PEA4;
			break;
		}

		//FINALE
		double PAjE = PEAj / sommaPEAi;
		cout << " PAjE FINALE: " << PAjE << endl;

		return 0;
	
}