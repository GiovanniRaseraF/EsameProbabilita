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

string x_alla_seconda(string& str) {
	string ret{};

	for (char c : str) {
		if (c == 'x' || c == 'X') ret += "x^(2)";
		else ret += c;
	}

	return ret;
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

	//Menu delle richieste
	cout << "\n\nMenu delle Richieste\n";
	//Valore atteso
	prefisso = "∫(" + to_string(a) + "," + to_string(b) + ")";
	funzione = "(x*(" + pxx_function + "))";
	string integral_for_valore_atteso = prefisso + funzione + "dx";
	string integral_for_valore_atteso_clean = pulisci(integral_for_valore_atteso);
	//Open
	cout << "Valore atteso: E(x)= " << integral_for_valore_atteso << endl;
	string url_valore_atteso = url + integral_for_valore_atteso_clean + "'";
	system(url_valore_atteso.c_str());

	//Varianza
	string x2 = prefisso + x_alla_seconda(funzione) + "dx";
	string valore_atteso_alla_2 = "(" + integral_for_valore_atteso + ")^(2)";
	string x2_clean = pulisci(x2);
	string valore_atteso_alla_2_clean = pulisci(valore_atteso_alla_2);
	//Open
	string url_x2 = url + x2_clean + "'";
	string url_valore_atteso_alla_2 = url + valore_atteso_alla_2_clean + "'";
	cout << "Varianza= " << x2 << " - "<< valore_atteso_alla_2 << endl;
	system(url_x2.c_str());
	system(url_valore_atteso_alla_2.c_str());

	//Moda
	cout << "Guarda il grafico di px(x) se è creasciente la moda è b=" << b << " altrimenti è a=" << a << endl;

	//Mediana
	prefisso = "∫(" + to_string(a) + ",t)";
	funzione = "(" + pxx_function + ")dx";
	string integral_mediana = prefisso + funzione;
	string integral_mediana_clean = pulisci(integral_mediana);
	string find_mediana = integral_mediana_clean;
	string url_median = url + find_mediana + "'";
	//Open
	system(url_median.c_str());

	

	return 0;
}