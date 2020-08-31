/*
@author Giovanni Rasera
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <tuple>
using namespace std;
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
		pln("Resistenze");

		//Input
		int N = 0;
		p("Xi (1..N)   N:"); cin >> N; pln("");
		char jori = 0;
		p("TESTO: dice E(Xj) oppure E(Xi) (j or i)?  ");
		while (jori != 'j' && jori != 'i') {
			cin >> jori;
			if (jori != 'j' && jori != 'i') p("inserisci (j or i) :");
		}

		//Adesso faccio inserire i valori se j o i
		double lambda = 0.0;
		int EX = 0;
		vector<double> EXi;
		switch (jori) {
		case 'j':

			//Inserimeto del valore
			p("\nInserito j  >> E(Xj) = "); cin >> EX; pln(" anni");
			//Calcolo lambda
			lambda = (double)N / (double)EX;
			//Stampo
			p("E(Xj)= "); pln(EX);
			p("lambda= "); pln(lambda);
			break;
		case 'i':

			//Inserisco i vari Xi
			for (int i = 1; i <= N; i++) {
				double xi = 0.0;
				p("E(X"); p(i); p(") : "); cin >> xi;
				EXi.push_back(xi);
			}
			//Calcolo lambda
			for (double xi : EXi) lambda += 1 / xi;
			//Stampo
			for (double xi : EXi) { p("Xi= "); pln(xi); }
			p("lambda= "); pln(lambda);
			break;
		default:
			pln("ERRORE! j or i");
			return 1;
		}

		//Sezione di selezione MIN o MAX per T
		//Esplicitazione della funzione T
		char aort = 0;
		p("TEST: Almeno una / Tutte (a per almeno una   / t per tutte): ");
		while (aort != 'a' && aort != 't') {
			cin >> aort;
			if (aort != 'a' && aort != 't') p("inserisci (a or t) :");
		}
		//Esplicitazione di T
		switch (aort) {
		case 'a':
			p("T = MIN(X1,...X"); p(N); pln(")");
			pln("Siccome: utilizzo il minimo siccome basta il gusto di una per\ncompromettere tutto il sistema");
			pln("/////////");
			break;
		case 't':
			p("T = MAX(X1,...X"); p(N); pln(")");
			pln("Siccome: utilizzo il massimo siccome quando quella che è durata di piu si guasta\nallora il sistema è compromesso");
			pln("/////////");
			break;
		default:
			pln("ERRORE! j or i");
			return 1;
		}

		//Calcolo della Funzione di ripartizione
		double FTt = 0.0;
		pln("Calcolo funzione di ripartizione");
		p("FT(t) = 1-e^(-t*"); p(lambda); pln(")");

		//Calcolo della funzione di densita di probabilita
		pln("Calcolo funzione di densita di probabilita");
		p("PT(t) = DERIVATA(1-e^(-t*"); p(lambda); pln("))");
		pln("PT(t) = DERIVATA(FT(t))");
		p("PT(t) = DERIVATA("); p(lambda); p(" * e ^ (-t * "); p(lambda); pln("))");


		//Trovo il quantile
		double quantile = 0.0, n = 0.0;
		p("n del Quantile: "); cin >> n;
		quantile = n / 100;
		p("Quantile= "); pln(quantile);
		double tp = -(log(1 - quantile) / lambda);
		p("tp= "); pln(tp);

		//probabilita condizionata
		double A = 0.0, B = 0.0;
		pln("P(T > or = B | T > A)");
		p("B: "); cin >> B;
		p("A: "); cin >> A;
		double PTAB = exp((A - B) * lambda);
		p("P(T > or = B | T > A) = "); pln(PTAB);
		
		return 0;
	}