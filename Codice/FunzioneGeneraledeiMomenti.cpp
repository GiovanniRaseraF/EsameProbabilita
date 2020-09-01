/*
@author Giovanni Rasera
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

string pulisci(string& str) {
	string pulita{};

	for (auto c : str) {
		if (c == '(') pulita += "%28";
		else if (c == ')') pulita += "%29";
		else pulita += c;
	}

	return pulita;
}

int main() {
	cout << "Funzione generatrice dei momenti" << endl;
	string Myt = "exp(", gt = "", gtpulita = "";
	string url = "xdg-open https://www.wolframalpha.com/input/?i=";

	//Input della funzione
	cout << "Durante l'inserimeto essere piu espliciti possibili senza utilizzare spazi, possibilmente parentesi" << endl;
	cout << endl;

	//Inserimento di Y
	int n = 0;
	vector<double> ci_Yi;
	cout << "Inserisci il numero di Y: "; cin >> n;
	double ci;
	for (int i = 0; i < n; i++) {
		cin >> ci;
		ci_Yi.push_back(ci);
	}

	//Calcolo di Mw(t)
	cout << "Funzione generatrice dei momenti" << endl;
	cout << "Mw(t)= E(e^(tW)) --> ";
	cout << endl;
	for (double c : ci_Yi) {
		cout << "e^(g(" << c << "*t)) * ";
	}
	cout << endl;

	cout << "Ora devi valcolarti Mw(t) inserendo i valori di ogni ci" << endl;


	//Calcolo della derivata seconda
	string Mwt = "";
	cout << "Inserisci Mw(t): "; cin >> Mwt;

	//Derivata prima
	cout << "Calcolo la Derivata Prima";
	string derivataprima = "D(" + Mwt + ")";
	string url_prima = url + derivataprima;
	cout << derivataprima<<endl;
	string d = pulisci(url_prima);
	system(d.c_str());

	//Derivata seconda
	cout << "Calcolo la Derivata Prima";
	string derivataseconda = "D(D(" + Mwt + "))";
	string url_seconda = url + derivataseconda;
	cout << derivataseconda << endl;
	string d2 = pulisci(url_seconda);
	system(d2.c_str());
	

	//Mt'(0)
	cout << "E(X) = Mw'(t)   --> E(X)^2";
	string Dmw0 = url+"\"(lim(t->0," + derivataprima + "))^2\"";
	cout << Dmw0 << endl;
	string ex2 = pulisci(Dmw0);
	system(ex2.c_str());

	//Mt''(0)
	cout << "E(X^2) = Mw''(t)   --> ";
	string DDmw0 = url + "\"(lim(t->0," + derivataseconda + "))\"";
	cout << DDmw0 << endl;
	string e2x = pulisci(DDmw0);
	system(e2x.c_str());
	
	
	return 0;
}
