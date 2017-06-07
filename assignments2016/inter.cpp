#include <iostream.h>

double f(double x){
	return x*x;
}

int main(){
	double N = 1000000;
	double b = 3, a= 2, intervel =  (b - a) / N;

	double s = 0;
	for(int i = 0 ; i < N; i ++){
		s+= intervel * f(a + i * intervel);
	}

	cout << s << endl;

	return 0;
}