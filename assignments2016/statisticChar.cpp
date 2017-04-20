#include <IOSTREAM>
#include <CMATH>
using namespace std;
int main() {
	char article[5000];
	cin.getline(article, 5000);
	int timesOfChar[26] = {0};
	int sumOfChars = 0;
	for(int i = 0; article[i] != '\0'; i ++){
		char ch = article[i];
		ch = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
		if (ch >= 'a' && ch <= 'z') {
			timesOfChar[ch - 'a'] ++;
			sumOfChars ++;
		}
	}
	double freq[26];
	for (i = 0; i < 26; i++){
		freq[i] = (double)(timesOfChar[i]) / (double)sumOfChars;
	}
	for(i = 0; i < 26; i ++) {
		cout << (char)(i + 'a') << ',' << freq[i] << endl;
	}

	double referFreq[26] = {
		0.082, 0.015, 0.028, 0.043, 0.127, 
		0.022, 0.02, 0.061, 0.07, 0.002, 
		0.008, 0.04, 0.024, 0.067, 0.075, 
		0.019, 0.001, 0.06, 0.063, 0.091, 
		0.028, 0.01, 0.024, 0.002, 0.02, 
		0.001
	};

	double lengthOfRef = 0;
	double lengthOfFreq = 0;
	double innerProduct = 0;
	for(i = 0; i < 26; i ++){
		lengthOfFreq += freq[i] * freq[i];
		lengthOfRef += referFreq[i] * referFreq[i];
		innerProduct += freq[i] * referFreq[i];
	}
	lengthOfFreq = sqrt(lengthOfFreq);
	lengthOfRef = sqrt(lengthOfRef);

	double similarity = innerProduct / (lengthOfFreq * lengthOfRef);
	
	cout << "The similarity is " << similarity << endl;
	cout << "Theta " << 180 * acos(similarity) / 3.1415926 << endl;
	return 0;
}