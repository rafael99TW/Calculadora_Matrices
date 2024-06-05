#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
private:
	double** matriz;

	int n_filas;
	int n_columnas;

public:

	/* Constructor por defecto
		   Parámetro: No tiene.
		   Precondicion: Ninguno.
		   Complejidad Temporal: O(1)
		   Complejidad Espacial: O(1)
	*/

	Matriz();

	/* Constructor por parametros
		   Parámetro: Numero de filas, Numero de columnas.
		   Precondicion: Ninguno.
		   Complejidad Temporal: O(1)
		   Complejidad Espacial: O(1)
	*/

	Matriz(int n_filas, int n_columnas);

	/* Constructor por copia
		   Parámetro: Matriz existente.
		   Precondicion: Ninguno.
		   Complejidad Temporal: O(1)
		   Complejidad Espacial: O(1)
	*/

	Matriz(Matriz& m);

	/* Destructor
	   Parámetro: Ninguno.
	   Precondición: Ninguna.
	   Complejidad Temporal: O(1)
	   Complejidad Espacial: O(1)
	*/

	~Matriz();

	/* Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz  con el resultado.
		   Parámetro: la matriz que se va a asignar
		   Retorno: una nueva matriz con la matriz pasada como parámetro.
		   Precondicion: Ninguno.
		   Complejidad Temporal: O(n_filas*n_columnas)
		   Complejidad Espacial: O(n_filas*n_columnas)


	*/

	Matriz& operator= (const Matriz& m);

	/* Realiza la suma entre dos matrices. Crea una nueva matriz con el resultado.
	   Parámetro: la matriz con la que se va a operar.
	   Retorno: una nueva matriz con la operación aplicada.
	   Precondición: Ninguna.
	   Complejidad Temporal: O(n_filas * n_columnas)
	   Complejidad Espacial: O(n_filas * n_columnas)


	*/


	Matriz operator+ (const Matriz& m) const;

	/* Realiza la resta entre dos matrices. Crea una nueva matriz con el resultado.
	   Parámetro: la matriz con la que se va a operar.
	   Retorno: una nueva matriz con la operación aplicada.
	   Precondición: Ninguna.
	   Complejidad Temporal: O(n_filas * n_columnas)
	   Complejidad Espacial: O(n_filas * n_columnas)


	*/

	Matriz operator- (const Matriz& m) const;

	/* Realiza la multiplicacion de la matriz con el scalar. Crea una nueva matriz con el resultado.
	   Parámetro: el scalar.
	   Retorno: una nueva matriz con la operación aplicada.
	   Precondición: Ninguna.
	   Complejidad Temporal: O(n_filas * n_columnas)
	   Complejidad Espacial: O(n_filas * n_columnas)


	*/

	Matriz operator* (double scalar) const;

	/* Realiza la multiplicacion entre dos matrices. Crea una nueva matriz con el resultado.
	   Parámetro: la matriz con la que se va a operar.
	   Retorno: una nueva matriz con la operación aplicada.
	   Precondición: Ninguna.
	   Complejidad Temporal: O(n_filas * n_columnas)
	   Complejidad Espacial: O(n_filas * n_columnas)


	*/

	Matriz operator* (const Matriz& m) const;

	/* Permite rellenar todos los elementos de la matriz del objeto actual preguntando al usuario
		   Parámetro: Ninguno
		   Retorno: Ninguno
		   Precondicion: La matriz no debe estar vacía
		   Complejidad Temporal: O(n_filas*n_columnas)
		   Complejidad Espacial: O(1)


	*/

	void rellenarManual();

	/* Verifica si la matriz es simétrica.
	   Parámetro: Ninguno.
	   Retorno: Verdadero si la matriz es simétrica, falso de lo contrario.
	   Precondición: La matriz debe ser cuadrada.
	   Complejidad Temporal: O(n_filas * n_columnas)
	   Complejidad Espacial: O(1)


	*/


	bool esSimetrica();

	/* Calcula la traspuesta de la matriz.
	   Parámetro: Ninguno.
	   Retorno: Una nueva matriz que es la traspuesta de la matriz actual.
	   Precondición: Ninguna.
	   Complejidad Temporal: O(n_filas * n_columnas)
	   Complejidad Espacial: O(n_filas * n_columnas)


	*/


	Matriz calcularTraspuesta();

	/* Obtiene el valor máximo en la matriz.
	   Parámetro: Ninguno.
	   Retorno: El valor máximo encontrado en la matriz.
	   Precondición: La matriz no debe estar vacía.
	   Complejidad Temporal: O(n_columnas * n_filas)
	   Complejidad Espacial: O(1)


	*/

	double obtenerMaximo();

	/* Obtiene el valor mínimo en la matriz.
	   Parámetro: Ninguno.
	   Retorno: El valor mínimo encontrado en la matriz.
	   Precondición: La matriz no debe estar vacía.
	   Complejidad Temporal: O(n_filas * n_columnas)
	   Complejidad Espacial: O(1)


	*/

	double obtenerMinimo();

	/* Permite rellenar todos los elementos de la matriz del objeto actual de forma aleatoria
		   Parámetro: semilla que se utiliza para el generador aleatorio
		   Retorno: Ninguno
		   Precondicion: La matriz no debe estar vacía
		   Complejidad Temporal: O(n_filas*n_columnas)
		   Complejidad Espacial: O(1)


	*/

	void rellenarAleatorio(long seed);



	/* Imprime por pantalla todos los elementos de la matriz del objeto actual
		   Parámetro: Ninguno
		   Retorno: Ninguno
		   Precondicion: La matriz no debe estar vacía
		   Complejidad Temporal: O(n_filas*n_columnas)
		   Complejidad Espacial: O(1)


	*/

	void mostrarMatriz();

};

#endif // MATRIZ_H
