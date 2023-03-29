#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <chrono>
using namespace std;

//alokuje matici n*m
void allocate(double**& matrix, int n, int m)
{
	matrix = new double*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[m];
}

//dealokuje matici n*m (vsimnete si ze druhy rozmer neni potreba)
void deallocate(double**& matrix, int n)
{	
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
}

//naplni matici n*m nahodnymi cisly
void fill(double** matrix, int n, int m)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <m; j++)
			matrix[i][j] = rand()%10;
	}
}

void fill2(double** matrix, int n, int m)
{
	srand(time(NULL));
	for (int i = 0; i < n/2; i++)
	{
		for (int j = 0; j <m/2; j++){
			matrix[i][j] = rand()%10;
			matrix[j][i] = matrix[i][j];
		}
	}
}

//tisk matice n*m
void print(double** matrix, int n, int m)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

//funkce pro demonstraci mereni casu
long long pointlessFunction(long long x)
{
	long long res = 0;
	for (long long i = 0; i < x; i++)
		res += i%10;
	return res;
}


double** multiply(double** a, double** b, double** res, int N)
{
    for (int i = 0; i <= N-1; i++)
    {
        for (int j = 0; j <= N-1; j++)
        {
            res[i][j] = 0.0;
            for (int k = 0; k <= N-1; k++)
            {
                res[i][j] = res[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    return b;
}

bool Enigma(double** matrix, int n)
{
    for (int i = 0; i <= n-2; i++)
    {
        for (int j = i + 1; j <= n-1; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }   
        }
    }
	return true;
}


int main()
{
	//ukazka mereni casu v milisekundach 
	// chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    // double **maticeFirst, **maticeSecond, **vyslednaMatice;
    // int N = 1600;

    // allocate(maticeFirst,N,N);
    // allocate(maticeSecond,N,N);
    // fill(maticeFirst,N,N);
    // fill(maticeSecond,N,N);
    // allocate(vyslednaMatice,N,N);

    // multiply(maticeFirst,maticeSecond,vyslednaMatice,N);

	// chrono::steady_clock::time_point end = chrono::steady_clock::now();

	// cout << "Elapsed time: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " milliseconds." << endl;

    // deallocate(maticeFirst,N);
    // deallocate(maticeSecond,N);
    // deallocate(vyslednaMatice,N);


	//ukazka mereni casu v mikrosekundach

	chrono::steady_clock::time_point begin = chrono::steady_clock::now();

	double **maticeStejna;
	int n = 100;

	allocate(maticeStejna,n,n);
	fill2(maticeStejna,n,n);

	cout << Enigma(maticeStejna,n) << endl;

	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	cout << "Elapsed time: " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " microseconds." << endl;


	deallocate(maticeStejna,n);
	return 0;
}