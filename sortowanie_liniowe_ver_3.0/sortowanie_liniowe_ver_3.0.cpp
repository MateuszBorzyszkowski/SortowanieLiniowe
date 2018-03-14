#include <iostream>
using namespace std;

int ile, test;
int **tablica;
int **pom;

int main()
{
	cin >> ile;													//ile par liczb

	tablica = new int*[ile];
	pom = new int*[ile];
																//wczytywanie tablicy
	for (int i = 0; i < ile; i++)														//tablica wczytujaca
	{
		tablica[i] = new int[2];
		for (int j = 0; j < 2; j++)
		{
			cin >> tablica[i][j];
		}
	} 
	for (int i = 0; i < ile; i++)														//tablica do której wpisuje
	{
		pom[i] = new int[2];
		for (int j = 0; j < 2; j++) {}
	}


	int *tmp = new int[ile + 1];								//tablica pomocnicza do sortowania przez zliczanie

	for (int i = 0; i < ile; i++) tmp[i] = 0;					//zerowanie tablicy pomocniczej
	for (int i = 0; i < ile; i++) tmp[(tablica[i][0])]++;		// tablica tmp zawiera liczbe wystapien danej liczby i w ciagu wejsciowym
	for (int i = 1; i <= ile; i++) tmp[i] += tmp[i - 1];		// tablica tmp zawiera liczbe elementow mniejszych lub rownych liczby i
	for (int i = ile - 1; i >= 0; i--)
	{
		pom[(tmp[(tablica[i][0])]) - 1] = tablica[i];			// wpisanie do tablicy wyjsciowej pod okreslony indeks tablicy wejsciowej
		tmp[(tablica[i][0])]--;									//zmniejszamy tmp
	}
															
	cin >> test;												//wczytanie testu

	if (test == 0)
	{														
		for (int i = 0; i < ile; i++, cout << endl)				// wypisanie posortowanej tablicy
		{
			cout << pom[i][0];
		}
	}

	if (test == 1)
	{
		for (int i = 0; i < ile; i++, cout << endl)				// wypisanie posortowanej tablicy
		{
			cout << pom[i][0] << "," << pom[i][1];
		}
	}

	delete[] tablica;											//zwalnianie pamieci po kolei
	delete[] pom;
	delete[] tmp;

	return 0;
}