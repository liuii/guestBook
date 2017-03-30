#include <IOSTREAM>
using namespace std;
int main() {
	const int N = 10;
	int v[N] = {1, 2, 3, 4, 5,
				6, 7, 8, 9, 10};
	int x;
	cout << "Please input a number: ";
	cin >> x;

	for(int i = 0; i < N; i ++) {
		if (v[i] == x){
			break;
		}
	}

	if (i < N){
		cout << "Found it." << endl;
	} else {
		cout << "Not found." << endl;
	}


	return 0;
}