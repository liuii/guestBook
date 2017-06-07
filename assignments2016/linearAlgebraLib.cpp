#include <IOSTREAM>
#include <CSTDLIB>
#include <CTIME>

using namespace std;

void initMatrix(double a[], int m, int n);
void outputMatrix(double a[], int m, int n);
void transpose(double a[], double at[], int m, int n);
void multiMatrix(double a[], double b[], double c[], int m, int n, int p);
int main() {
	cout << endl;
	srand((unsigned int)time(NULL));
	double A[4*5],B[5*4],C[4*4];
	initMatrix(A, 4, 5);
	initMatrix(B, 5, 4);
	multiMatrix(A,B,C,4,5,4);
	outputMatrix(A,4,5);
	cout << "======================" << endl;
	outputMatrix(B,5,4);
	cout << "======================" << endl;
	outputMatrix(C,4,4);
	return 0;
}

void multiMatrix(double a[], double b[], double c[], int m, int n, int p){
	for(int i = 0; i < m ; i++){
		for(int j = 0; j < p; j ++){
			c[i * p + j] = 0;
			for(int k = 0; k < n; k ++){
				c[i * p + j] += a[i*n+k] * b[k * p + j];
			}
		}
	}
}

void transpose(double a[], double at[], int m, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j ++){
			at[i * m + j] = a[j * n + i];
		}
	}
}

void initMatrix(double a[], int m, int n){
	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j ++){
			a[i*n+j] = 0.1 * (rand() % 100);
		}
	}
}

void outputMatrix(double a[], int m, int n){
	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j ++){
			cout << a[i*n+j] << "\t";
		}
		cout << endl;
	}
}