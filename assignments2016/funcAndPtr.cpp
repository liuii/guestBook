#include <iostream>
#include <CSTDLIB>
#include <ctime>
using namespace std;

void initArray(int *a, int n);
void sortArray(int *a, int n);
void outputArray(int *a, int n);

int main() {	
	cout << "\n\n\n"; // avoid the light.
	srand((unsigned int)time(NULL));
	int a[100];
	initArray(a, 100);
	outputArray(a, 100);
	for(int i = 0; i < 10; i ++){
		sortArray(a+i*10, 10);
	}
	outputArray(a, 100);

	return 0;
}


void initArray(int *a, int n){
	for(int i = 0; i < n; i++){
		a[i] = rand() % 90 + 10;
	}
}

void sortArray(int *a, int n){
	for(int i = 0; i < n - 1; i ++){
		for (int j = 0; j < n - 1 - i; j ++){
			if (a[j] < a[j+1]){
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}	
}

void outputArray(int *a, int n){
	cout << "=============================" << endl;	
	for(int i = 0; i < n; i ++) {
		cout << a[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}
	cout << endl;
}