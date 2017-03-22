#include <IOSTREAM>
#include <CMATH>
using namespace std;

double f(double x);
double deltaF(double x);

int main() {
	double intervel = 2 * 3.1415926 / 1e5;
	for (double x = 0; x < 2 * 3.1415926; x += intervel){
		double errorOfDeltaF = fabs(cos(x) - deltaF(x));
		cout << x << ',' << errorOfDeltaF << endl;
	}
	return 0;
}


double deltaF(double x){
	double result;
	double delta = 1e-3;
	result = (f(x + delta) - f(x))/delta;
	return result;
}

double f(double x) {
	return sin(x);
}