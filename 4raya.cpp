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

void filler(lm4r& tabla, int col, int id, int & fil) {

	bool asignado = false;
	int i = 5;

	while (!asignado && (0 <= i)) {
		if (tabla.mat[i][col - 1] == 404) {
			tabla.mat[i][col - 1] = id;
			fil = i;
			asignado = true;
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


int fAnalyzer(lm4r tabla, int fil, int col, int ficha) {
	////horizontal
	//bool coinciden = false;
	//int opciones = 7;
	//int i = 5;
	//int j = 0;
	//int raya = 0;
	//int v_anterior = -1;
	//int v_puntero = -1;

	//while (i >= 0 && !coinciden) {
	//	
	//	while (!coinciden && ((opciones >= 4) || raya > 1)) {
	//		if (tabla.mat[i][j] == v_anterior && (tabla.mat[i][j] != 404)) {
	//			if (raya == 2) {
	//				coinciden = true;
	//				v_puntero = tabla.mat[i][j];
	//			}
	//			raya++;
	//		}
	//		else {
	//			raya = 0;
	//		}

	//		//cout << "valor: " << v_anterior << " raya: " << raya << " valor en la matriz: " << tabla.mat[i][j] << endl;
	//		v_anterior = tabla.mat[i][j];
	//		opciones--;
	//		j++;
	//	}

	//	i--;
	//}

	////vertical
	//opciones = 6;
	//i = 5;
	//j = 0;
	//raya = 0;
	//v_anterior = -1;

	//while (j < 7 && !coinciden) {

	//	while (!coinciden && (tabla.mat[i][j] != 404) && ((opciones >= 4) || raya > 1)) {
	//		if (tabla.mat[i][j] == v_anterior) {
	//			if (raya == 2) {
	//				coinciden = true;
	//				v_puntero = tabla.mat[i][j];
	//			}
	//			raya++;
	//		}
	//		else {
	//			raya = 0;
	//		}

	//		cout << "valor: " << v_anterior << " raya: " << raya << " valor en la matriz: " << tabla.mat[i][j] << endl;
	//		v_anterior = tabla.mat[i][j];
	//		opciones--;
	//		i--;
	//	}

	//	i = 5;
	//	j++;

	/*}*/

	int dir_x[] = { 0, 1, 1, 1 };
	int dir_y[] = { 1, 0, -1, 1 };
	int n_puntero = ficha;
	int r = 0;
	int conteo = 1;

	while(r < 4 && conteo < 4) {
		
		conteo = 1;
		int nf = fil + dir_x[r];
		int nc = col + dir_y[r];

		while (nf >= 0 && nf < 6 && nc >= 0 && nf < 7 && tabla.mat[nf][nc] == ficha) {
			nf += dir_x[r];
			nc = dir_y[r];
			conteo++;
		}

		nf = fil - dir_x[r];
		nc = col - dir_y[r];

		while (nf >= 0 && nf < 6 && nc >= 0 && nf < 7 && tabla.mat[nf][nc] == ficha) {
			nf -= dir_x[r];
			nc -= dir_y[r];
			conteo++;
		}
		r++;
	}

	if (conteo < 4) {
		n_puntero = -1;
	}

	return n_puntero;
	

}

// 0 rojo y 1 amarillo y 404 espacio vacio 
int main() {

	lm4r tabla;

	bool finalizado = false;
	int casos = 0, intentos = 0, col;
	cin >> casos;

	while (casos > intentos) {

		fInicializador(tabla);
		int i = 1;
		int id = 404;
		int fil = 0;

		while (!finalizado && (i < 42)) {
			if (i % 2 == 0) {
				
				cin >> col;
				id = 1;
				// id: 1
				filler(tabla, col, id, fil);
			}
			else {
				cin >> col;
				// id: 0
				id = 0;
				filler(tabla, col, id, fil);
			}

			int ganador = fAnalyzer(tabla, col, fil, id);

			cout << ganador << endl;

			if (ganador == 0) {
				cout << "Ganan rojas" << endl;
				finalizado = true;
			}
			else if (ganador == 1) {
				cout << "Ganan amarillas" << endl;
				finalizado = true;
			}

			i++;
		}


		intentos++;
	}

	if (!finalizado) {
		cout << "Empate" << endl;
	}

	mostrar(tabla);


	return 0;
}