#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}


//Constructor de una matriz vacia
Matriz::Matriz() {
	this->n_filas = 0;
	this->n_columnas = 0;

	this->matriz = NULL;
}

//Construccion de una matriz manualmente
Matriz::Matriz(int n_filas, int n_columnas)
{
	this->n_filas = n_filas;
	this->n_columnas = n_columnas;

	this->matriz = new double* [n_filas];
	for (int i = 0; i < n_filas; ++i) {
		this->matriz[i] = new double[n_columnas];
	}
}

// Constructor por copia de una matriz existente
Matriz::Matriz(Matriz& m)
{
	this->n_filas = m.n_filas;
	this->n_columnas = m.n_columnas;

	this->matriz = new double* [this->n_filas];
	for (int i = 0; i < this->n_filas; ++i) {
		this->matriz[i] = new double[this->n_columnas];
	}

	for (int i = 0; i < this->n_filas; ++i) {
		for (int j = 0; j < this->n_columnas; ++j) {
			this->matriz[i][j] = m.matriz[i][j];
		}
	}
}

// Destructor de matrices
Matriz::~Matriz()
{
	for (int i = 0; i < n_filas; ++i) {
		delete[] matriz[i];
	}

	delete[] matriz;
}


//Asignacion de matrices
Matriz& Matriz::operator= (const Matriz& m)
{
	assertdomjudge(&m != NULL);
	if (matriz != NULL)
	{
		for (int i = 0; i < n_filas; i++)
			delete[] matriz[i];

		delete[] matriz;
		matriz = NULL;
	}

	this->n_filas = m.n_filas;
	this->n_columnas = m.n_columnas;
	this->matriz = NULL;
	if (n_filas > 0 && n_columnas > 0)
	{
		matriz = new double* [n_filas];

		for (int i = 0; i < n_filas; i++)
		{
			matriz[i] = new double[n_columnas];
			for (int j = 0; j < n_columnas; j++)
				matriz[i][j] = m.matriz[i][j];
		}
	}

	return(*this);
}

// Sumar valores de las matrices
Matriz Matriz::operator+ (const Matriz& m) const
{
	assertdomjudge(this->n_filas == m.n_filas && this->n_columnas == m.n_columnas);

	Matriz suma(this->n_filas, this->n_columnas);

	for (int i = 0; i < this->n_filas; ++i) {
		for (int j = 0; j < this->n_columnas; ++j) {
			suma.matriz[i][j] = this->matriz[i][j] + m.matriz[i][j];
		}
	}

	return suma;
}

// Restar valores de las matrices
Matriz Matriz::operator- (const Matriz& m) const
{
	assertdomjudge(this->n_filas == m.n_filas && this->n_columnas == m.n_columnas);

	Matriz resta(this->n_filas, this->n_columnas);

	for (int i = 0; i < this->n_filas; ++i) {
		for (int j = 0; j < this->n_columnas; ++j) {
			resta.matriz[i][j] = this->matriz[i][j] - m.matriz[i][j];
		}
	}

	return resta;
}

// Multiplicar matriz por scalar
Matriz Matriz::operator* (double scalar) const
{
	Matriz resultado(this->n_filas, this->n_columnas);

	for (int i = 0; i < this->n_filas; ++i) {
		for (int j = 0; j < this->n_columnas; ++j) {
			resultado.matriz[i][j] = this->matriz[i][j] * scalar;
		}
	}

	return resultado;
}

// Multiplicar matrices
Matriz Matriz::operator* (const Matriz& m) const
{
	assertdomjudge(this->n_columnas == m.n_filas);

	Matriz resultado(this->n_filas, m.n_columnas);

	for (int i = 0; i < this->n_filas; ++i) {
		for (int j = 0; j < m.n_columnas; ++j) {
			resultado.matriz[i][j] = 0;
			for (int k = 0; k < this->n_columnas; ++k) {
				resultado.matriz[i][j] += this->matriz[i][k] * m.matriz[k][j];
			}
		}
	}

	return resultado;
}

// Obtener el valor maximo de la matriz
double Matriz::obtenerMaximo()
{
	double maximo = matriz[0][0];

	for (int i = 0; i < n_filas; i++) {
		for (int j = 0; j < n_columnas; j++) {
			if(matriz[i][j] > maximo) {
				maximo = matriz[i][j];
			}
		}
	}

	return maximo;
}

// Obtener el valor minimo de la matriz
double Matriz::obtenerMinimo()
{
	double minimo = matriz[0][0];

	for (int i = 0; i < n_filas; i++) {
		for (int j = 0; j < n_columnas; j++) {
			if (matriz[i][j] < minimo) {
				minimo = matriz[i][j];
			}
		}
	}

	return minimo;
}

// Ver si la matriz es simetrica
bool Matriz::esSimetrica()
{
	assertdomjudge(n_columnas == n_filas);
	
	for (int i = 0; i < n_filas; i++) {
		for (int j = 0; j < n_columnas; j++) {
			if (matriz[j][i] != matriz[i][j]) {
				return false;
			}
		}
	}

	return true;
}

// Calcular Traspuesta
Matriz Matriz::calcularTraspuesta()
{
	assertdomjudge(this->n_filas > 0 && this->n_columnas > 0);

	Matriz resultado(this->n_columnas, this->n_filas);

	for (int i = 0; i < this->n_columnas; i++) {
		for (int j = 0; j < this->n_filas; j++) {
			resultado.matriz[i][j] = this->matriz[j][i];
		}
	}

	return resultado;

}


// Leer matriz
void Matriz::rellenarManual()
{
	double elemento;
	for (int i = 0; i < n_filas; i++)
	{
		cout << "Fila " << i << endl;
		for (int j = 0; j < n_columnas; j++)
		{
			cout << "Elemento " << j << endl;
			cin >> elemento;
			matriz[i][j] = elemento;
		}
		cout << endl;
	}

}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed)
{
	srand(seed);
	for (int i = 0; i < n_filas; i++)
		for (int j = 0; j < n_columnas; j++)
			matriz[i][j] = rand();

}



// Imprimir Matriz
void Matriz::mostrarMatriz()
{
	for (int i = 0; i < n_filas; i++)
	{
		for (int j = 0; j < n_columnas; j++)
			cout << matriz[i][j] << " ";
		cout << endl;
	}
}

