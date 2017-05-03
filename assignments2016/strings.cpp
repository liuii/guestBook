#include <IOSTREAM>
#include <CSTRING>

using namespace std;

void inputArray(char s[][20], int n);
void sortArray(char s[][20], int n);
void outputArray(char s[][20], int n);

int main() {
	cout << "\n\n\n"; // Avoid the light
	char cities[4][20];
	inputArray(cities, 4);
	sortArray(cities, 4);
	outputArray(cities, 4);
	return 0;
}

void inputArray(char s[][20], int n){
	for(int i =0; i < n; i++){
		cin.getline(s[i], 20);
	}
}

void sortArray(char s[][20], int n){
	for(int i =0; i < n - 1; i ++){
		for(int j = 0; j < n - 1 - i; j++){
			if (strcmp(s[j],s[j+1]) > 0){
				char t[20];
				strcpy(t,s[j]);
				strcpy(s[j],s[j+1]);
				strcpy(s[j+1],t);
			}
		}
	}
}

void outputArray(char s[][20], int n){
	cout << "=========================" << endl;
	for(int i =0; i < n; i++){
		cout << s[i] << endl;
	}
}
