#include <iostream>
#include <cstring>
using namespace std;
int main(){
	
	double s = 1;
	for (int k = 1; k <= 26; k++){
		s *= k;
	}
	cout << s << endl;

	char message[100];
	int cipher = 3;
	cin.getline(message, 100);

	for(int i = 0; message[i]; i++){
		if (message[i] >= 'a' && message[i] <= 'z'){
			message[i] = (message[i] - 'a' + cipher) % 26 + 'a';
		}else if (message[i] >= 'A' && message[i] <= 'Z'){
			message[i] = (message[i] - 'A' + cipher) % 26 + 'A';
		}
	}

	cout << message << endl;
	
	char encoded[100];	
	for (int ci = 0; ci <= 25; ci++){
		strcpy(encoded, message);
		for(i = 0; encoded[i]; i++){
			if (encoded[i] >= 'a' && encoded[i] <= 'z'){
				encoded[i] = (encoded[i] - 'a' + 26 - ci) % 26 + 'a';
			}else if (encoded[i] >= 'A' && encoded[i] <= 'Z'){
				encoded[i] = (encoded[i] - 'A' + 26 - ci) % 26 + 'A';
			}
		}
		cout << ci << ": " << encoded << endl;
	}
	return 0;	
}