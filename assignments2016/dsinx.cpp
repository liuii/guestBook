/*
使用控制台的步骤：
1. 按下“Win”键和“R”键，然后输入“cmd”，后回车。
2. 然后转到debug所在的文件夹。
3. 命令格式，其中xxx是可执行文件的文件名，xx是要保存文件的文件名：
   xxx.exe > xx.cvs
4. 用Excel打开cvs文件。
*/
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
