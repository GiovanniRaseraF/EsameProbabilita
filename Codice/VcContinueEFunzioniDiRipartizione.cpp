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
		else if(c == '.') pulita += "%2E";
		else if(c == '+') pulita += "%2B";
		else if(c == ',') pulita += "%2C";
		else pulita += c;
	}

	return pulita;
}

int main() {
	string url = "xdg-open 'https://www.wolframalpha.com/input/?i=";

	//Vc continue e funzioni di ripartizione
	int a = 0, b = 0;
	string pxx_function{};
	cout<<"Vc continue e funzioni di ripartizione"<<endl;
	cout<<"Abbiamo X e il supporto Sx=[a , b] "<<endl;
	//Inserimeto delle variabili utili
	cout<<"a: ";cin>>a; cout<<"b: ";cin>>b;
	cout<<"La funzione px(x) = cf(x)"<<endl;
	cout<<"px(x): ";cin>>pxx_function;

	//Trovare la costante k 
	//Calcolo l'integrale definito tra a e b della funzione che mi hanno dato
	string prefisso = "∫("+to_string(a)+","+to_string(b)+")";
	string funzione = "("+pxx_function+")dx=1";
	string integral_for_k = prefisso+funzione;
	string integral_for_k_clean = pulisci(integral_for_k);
	string find_k = integral_for_k_clean;
	string open_url = url + integral_for_k_clean + "'";
	//Open
	system(open_url.c_str());
	cout<<"\nCalcolo della costante:\n"<<integral_for_k<<endl;
	cout<<endl<<"Inseriere l'integrale in worfram alpha"<<endl;
	
	//Prendere k
	double k = 0;
	cout<<"Worfram ha dato un risultato per k"<<endl;
	cout<<"k: ";cin>>k;

	//Esplicitazione della funzione in t
	prefisso = "k=("+to_string(k)+")∫("+to_string(a)+",t)";
	funzione = "("+pxx_function+")dx";
	string integral_for_t = prefisso+funzione;
	string integral_fot_t_clean = pulisci(integral_for_t);
	open_url = url + integral_fot_t_clean + "'";
	//Open
	system(open_url.c_str());
	cout << "\nCalcolo dell'integrale per t";
	cout<<endl<<integral_for_t<<endl;



	return 0;
}