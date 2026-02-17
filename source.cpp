#include <iostream>
using namespace std;

typedef int m4r[6][7];

typedef struct {
	m4r mat;
	int cont;
} lm4r;

void fInicializador(lm4r& tabla) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			tabla.mat[i][j] = 404;
		}
	}
}

//1
//1
//1
//1
//1
//1
//2
//2
//2
//2
//2
//2
//3
//3
//3
//3
//3
//3
//4
//4
//4
//4
//4
//4
//5
//5
//5
//5
//5
//5
//6
//6
//6
//6
//6
//6
//7
//7
//7
//7
//7
//7

void filler(lm4r & tabla, int col, int id) {

	bool asignado = false;
	int i = 5;

	while (!asignado && (0 <= i)) {
		if (tabla.mat[i][col - 1] == 404) {
			tabla.mat[i][col - 1] = id;
			asignado = true;
			cout << i << endl;
		}
		i--;
	}

}

void mostrar(lm4r tabla) {

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {

			cout << tabla.mat[i][j] << " ";

		}
		cout << endl;
	}
}


// 0 rojo y 1 amarillo y 404 espacio vacio 
int main() {

	lm4r tabla;

	int casos = 0, intentos = 0, col;
	cin >> casos;

	while (casos > intentos) {

		fInicializador(tabla);	
		bool finalizado = false;
		int i = 0;

		while (!finalizado && (i < 42)) {
			if (i % 2 == 0) {
				cin >> col;
				// id: 1
				filler(tabla, col, 1);
			}
			else {
				cin >> col;
				// id: 0
				filler(tabla, col, 0);
			}
			i++;
		}



		intentos++;
	}

	mostrar(tabla);


	return 0;
}