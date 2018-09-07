// AnalisisMatematicoObtenerCoeficientes.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//Objetivo: Ingresar los puntos a estudiar, a partir de eso calcular coeficientes de las ecuaciones
// invertir la matriz, calcular (coeficientes de resultado * matriz invertida) e imprimir por pantalla.
//Funciones


//Planteando Ecuaciones: P de cada linea debe dar el punto de partida medido como resultado de ese y el Siguiente.
//						 P' de cada linea menos la siguiente valuada en el punto que tienen en comun debe dar cero.
//						 P'' de cada linea menos la siguiente valuada en el punto que tienen en comun debe dar cero.
//						 P'' de los extremos debe dar cero


void IngresarPuntosAEstudiar(float ListaDePuntos[], float ListaFuncionMedidadePuntos[], int SizeMatriz)
{
	for (int i = 0; i < SizeMatriz; i++)
	{
		cout << "Ingrese el Punto " << (i + 1) << " a estudiar: " << endl;
		cin >> ListaDePuntos[i];
		cout << "Ingrese la funcion valuada en el punto ingresado: " << endl;
		cin >> ListaFuncionMedidadePuntos[i];
	}
	cout << endl;

}

void DisplayMatriz(float Matriz[][50], int SizeMatriz)
{
	for (int i = 0; i < SizeMatriz; i++)
	{
		for (int j = 0; j < SizeMatriz; j++)
		{
			cout << Matriz[i][j];
		}
		cout << endl;
	}

}


void MultiplicarFila(float Fila1[], float Escalar)
{
	for (int i = 0; i < sizeof(Fila1); i++)
	{
		Fila1[i] *= Escalar;
	}
}

void SumarFila(float Fila1[], float Fila2[], float Escalar)
{
	for (int i = 0; i < sizeof(Fila1); i++)
	{
		Fila2[i] += (Fila1[i] * Escalar);
	}
}

void InvertirMatriz(float MatrizInicial[][50], float MatrizIdentidad[][50], int SizeMatriz)
{
	for (int j = 0; j < SizeMatriz; j++)
	{
		for (int i = 0; i < SizeMatriz; i++)
		{
			if (MatrizInicial[i][j] == 0)
			{
			}
			else if (MatrizInicial[i][j] != 1)
			{
				MultiplicarFila(MatrizInicial[i], (1 / MatrizInicial[i][j]));
				MultiplicarFila(MatrizIdentidad[i], (1 / MatrizInicial[i][j]));
			}
			if (MatrizInicial[i][j] == 1)
			{
				for (int l = 0; l < SizeMatriz; l++)
				{
					if (!(l == i))
					{
						SumarFila(MatrizInicial[i], MatrizInicial[l], (-MatrizInicial[l][j]));
						SumarFila(MatrizIdentidad[i], MatrizIdentidad[l], (-MatrizInicial[l][j]));  //TODO: NO ESTA TERMINADO GIL NO LO CORRAS
					}

				}
			}
		}
	}
}


float CalcularDeterminante(float Matriz[][50], int SizeMatriz)
{
	//NiPutaIdea

	return 0;
}

void CrearMatrizIdentidad(float MatrizObjetivo[][50], int SizeMatriz)
{
	for (int i = 0; i < SizeMatriz; i++)
	{
		for (int j = 0; j < SizeMatriz; j++)
		{
			if (i == j)
			{
				MatrizObjetivo[i][j] = 1;
			}
			else
			{
				MatrizObjetivo[i][j] = 0;
			}
		}
	}
}
void CalcularPolinomioEstandar(float NumeroIngresado, float MatrizCoeficientes[][50], int NumeroDeFila, int NumeroDeColumna)
{
	MatrizCoeficientes[NumeroDeFila][NumeroDeColumna] = NumeroIngresado*NumeroIngresado*NumeroIngresado;
	MatrizCoeficientes[NumeroDeFila][NumeroDeColumna + 1] =  NumeroIngresado*NumeroIngresado;
	MatrizCoeficientes[NumeroDeFila][NumeroDeColumna + 2] = NumeroIngresado;
	MatrizCoeficientes[NumeroDeFila][NumeroDeColumna + 3] = 1;

}

void CalcularPrimeraDerivada(float NumeroIngresado, float MatrizCoeficientes[][50], int NumeroDeFila, int NumeroDeColumna)
{
	MatrizCoeficientes[NumeroDeFila][NumeroDeColumna] = 3 * NumeroIngresado*NumeroIngresado;
	MatrizCoeficientes[NumeroDeFila][NumeroDeColumna + 1] = 2 * NumeroIngresado;
	MatrizCoeficientes[NumeroDeFila][NumeroDeColumna + 2] = 1;
	MatrizCoeficientes[NumeroDeFila][NumeroDeColumna + 3] = 0;
}

void CalcularSegundaDerivada(float NumeroIngresado, float MatrizCoeficientes[][50], int NumeroDeFila, int NumeroDeColumna)
{
	
	MatrizCoeficientes[NumeroDeFila][NumeroDeColumna] = 6 * NumeroIngresado;
	MatrizCoeficientes[NumeroDeFila][NumeroDeColumna + 1] = 2;
	MatrizCoeficientes[NumeroDeFila][NumeroDeColumna + 2] = 0;
	MatrizCoeficientes[NumeroDeFila][NumeroDeColumna + 3] = 0;
}

void CalcularPolinomio(float ListaDePuntos[], float PuntosTomados[], float MatrizCoeficientes[][50], int SizeMatriz)
{


}

void CalcularCoeficientes()
{

}


int main()
{	
	int PuntosEvaluados;
	cout << "Ingrese el Numero de Puntos Evaluados: " << endl;
	cin >> PuntosEvaluados;
	//float PuntosTomados[(PuntosEvaluados)], FuncionesDeLosPuntos[PuntosEvaluados], MatrizCoeficientes[PuntosEvaluados][PuntosEvaluados], MatrizCoeficientesInvertida[PuntosEvaluados][PuntosEvaluados];
	
	float* PuntosTomados = new float[PuntosEvaluados];						//Inicializacion de Las Matrices
	float* FuncionesDeLosPuntos = new float[PuntosEvaluados];					//ps: por que me odias C que te hice
	float** MatrizCoeficientes = new float*[4*PuntosEvaluados];
	for (int i = 0; i < 4*PuntosEvaluados; i++)
		MatrizCoeficientes[i] = new float[4*PuntosEvaluados];
	float** MatrizCoeficientesInvertida = new float*[4*PuntosEvaluados];
	for (int i = 0; i < 4*PuntosEvaluados; i++)
		MatrizCoeficientesInvertida[i] = new float[4*PuntosEvaluados];

	IngresarPuntosAEstudiar(PuntosTomados, FuncionesDeLosPuntos, PuntosEvaluados);
    return 0;
}

