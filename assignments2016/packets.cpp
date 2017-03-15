#include <IOSTREAM>
using namespace std;
const int N = 7;
int main() {
	double weight[N] = {35,30,60,50,40,10,25};
	double price[N] = {10,40,30,50,35,40,30};
	double pricePerKg[N];

	int i, j;
	for (i = 0; i < N; i++) {
		pricePerKg[i] = price[i] / weight[i];
	}
	
	/*
	int imax = 0;
	for(i = 1; i < N; i ++){
		if (pricePerKg[imax] < pricePerKg[i]){
			imax = i;
		}
	}
	cout << pricePerKg[imax] << endl;
	*/

	for (i = 0; i < N - 1; i ++){
		int flag = 0;
		for (j = 0; j < N - 1 - i; j ++){
			if (pricePerKg[j] < pricePerKg[j+1]){
				flag = 1;
				double t;
				t = pricePerKg[j];
				pricePerKg[j] = pricePerKg[j+1];
				pricePerKg[j+1] = t;

				t = price[j];
				price[j] = price[j+1];
				price[j+1] = t;

				t = weight[j];
				weight[j] = weight[j+1];
				weight[j+1] = t;
			}
		}
		if (flag == 0) break;
	}

	return 0;
}