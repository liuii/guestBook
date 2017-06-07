#include <IOSTREAM>
#include <CSTDLIB>
#include <CTIME>
using namespace std;
const int M = 3;
const int N = 2;
const int P = 5;
int main() {
	srand((unsigned int)time(NULL));
	cout << endl;
	double A[M][N],B[N][P],C[M][P]={0};
	int i, j;
	cout << "=======A=======" << endl;
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j ++){
			A[i][j] = 0.01 * (rand() % 100 + 1);
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "=======B=======" << endl;
	for(i = 0; i < N; i++){
		for(j = 0; j < P; j ++){
			B[i][j] = 0.01 * (rand() % 100 + 1);
			cout << B[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "=======C=======" << endl;
	for(i = 0; i < M; i++){
		for(j = 0; j < P; j ++){
			for(int k = 0; k < N; k ++){
				C[i][j] += A[i][k]*B[k][j];
			}
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}


	return 0;
}