#include <IOSTREAM>
using namespace std;
int main() {
	const int N = 10;
	int v[N] = {
		12, 25, 37, 46, 59,
		62, 78, 85, 93, 109
	};
	int x;
	cout << "Please input a number: ";
	cin >> x;

	int left = 0;
	int right = N - 1;

	while (left <= right){
		int middle = (left + right) / 2;
		if (v[middle] == x) {
			break;
		} else if (v[middle] > x) {
			right = middle - 1;
		} else {
			left = middle + 1;
		}
	}

	if (left <= right) {
		cout << "Found it!" << endl;
	} else {
		cout << "Not found!" << endl;
	}
	return 0;
}
