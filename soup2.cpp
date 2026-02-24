#include <iostream>
#include <string>
using namespace std;


int const NM = 50;
int const MAX_PALABRAS = 100;
typedef char lSOPA[NM][NM];
typedef string lPalabras[MAX_PALABRAS];

void fillerSoup(lSOPA sopa, int n, int m) {

	for (int i = 0; i < n; i++) {
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

	for (int i = 0; i < q; i++) {
		cin >> lista[i];
		int len = lista[i].size();
		for (int j = 0; j < len; j++) {
			lista[i][j] = toupper(lista[i][j]);
		}
	}

}

void fAnalyzer(lPalabras lista, lSOPA sopa, int n, int m, int q) {


	int dir_x[] = {1, 0, 1, -1};
	int dir_y[] = {0, 1, -1, -1 };

	int palabras_encontradas = 0;

	int i = 0;


	while (i < q) {
		bool encontrado = false;
		int l = 0;

		while (l < n && !encontrado) {
			int k = 0;

			while (k < m && !encontrado) {

				int n_palabra = 0;
				int conteo = 0;


				if (lista[i][n_palabra] == sopa[l][k]) {


					cout << lista[i] << endl;
					n_palabra++;
					conteo++;

					for (int d = 0; d < 4; d++) {

						int nf = l + dir_x[d];
						int nc = k + dir_y[d];

						while (nf >= 0 && nf < n && nc >= 0 && nc < m && lista[i][n_palabra] == sopa[nf][nc]) {
							nf += dir_x[d];
							nc += dir_y[d];
							n_palabra++;
							conteo++;
						}

						nf = l - dir_x[d];
						nc = k - dir_y[d];

						while (nf >= 0 && nf < n && nc >= 0 && nc < m && lista[i][n_palabra] == sopa[nf][nc]) {
							nf -= dir_x[d];
							nc -= dir_y[d];
							n_palabra++;
							conteo++;
						}

					}
					if (conteo == lista[i].size()) {
						encontrado = true;
						palabras_encontradas++;
					}
				}

				k++;
			}

			l++;
		}

		i++;
	}


	cout << "Palabras encontradas: " << palabras_encontradas << endl;

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

	cout << endl;
}

int main() {

	int casos = 0, intentos = 0;

	lSOPA sopa;
	lPalabras lista;

	cin >> casos;

	while (casos > intentos) {

		int q = 0, n = 0, m = 0;

		cin >> n >> m;
		
		fillerSoup(sopa, n, m);

		cin >> q;
		fillerWords(lista, q);

		mostrar(lista, sopa, n, m, q);

		fAnalyzer(lista, sopa, n, m, q);


		intentos++;
	}


	return 0;
}