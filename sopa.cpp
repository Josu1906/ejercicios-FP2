#include <iostream>
#include <string>
using namespace std;


int const NM = 50;
int const MAX_PALABRAS = 100;
typedef char lSOPA[NM][NM];
typedef string lPalabras[MAX_PALABRAS];

void fillerSoup(lSOPA sopa, int n, int m) {

	bool asignado = false;
	int i = 5;

	for(int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char word;  
			cin >> word; 
			sopa[i][j] = toupper(word);
		}
	}

}

void fillerWords(lPalabras lista, int q) {

	bool asignado = false;
	int i = 5;

	for (int i = 0; i < q; i++){ 
		cin >> lista[i];
		int len = lista[i].size();
		for (int j = 0; j < len; j++) {
			lista[i][j] = toupper(lista[i][j]);
		}
	}

}


void mostrar(lPalabras lista, lSOPA sopa, int n, int m, int q) {

	cout << "Palabras: ["; 
	for (int i = 0; i < q; i++) {
		if (i == (q - 1)) cout << lista[i] << "";
		else cout << lista[i] << ", ";
	}	
	cout << "]" << endl << "Sopa: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << sopa[i][j] << " ";
		}
		cout << endl;
	}


}

int main() {

	int casos = 0, intentos = 0;

	cin >> casos;
	
	while (casos > intentos) {

		int q = 0, n = 0, m = 0;

		cin >> n >> m;

		cin >> q;


		intentos++;
	}


	return 0;
}