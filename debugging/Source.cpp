


using namespace std;
#include <malloc.h>
#include <iostream>
#include <stdlib.h>
#include "TPBGlib.h"

/*
UK print in console
RU вывод в консоль
*/
void printString(char* ST) {
	char* UM = ST;
	while (*UM != '\0') {
		cout.put(*UM);
		++UM;
	};
}

int main()
{
	char textInput[101];
	char key[101];
	char* chiper;
	char*  unchiper;
	int isencode;
	cout << "If you want to encrypt text, please input 0" << endl <<
		"If you want to decrypt text, please input 1" << endl;
	cin >> isencode;
	cout << "Please, input text(A..Z):" << endl;
	cin >> textInput;
	if (isencode == 0) {

		cout << "Please, input key(A..Z):" << endl;
		cin >> key;
		chiper = TPBG::encoderVigener(textInput, key);
		cout << "Encrypted text:" << endl;
		printString(chiper);
		cout << endl;
	}
	else{ 
		bool isFind = false;
		char response;
		while (!isFind) {
			cout << "Please, input key(A..Z):" << endl;
			cin >> key;
			unchiper = TPBG::decoderVigener(textInput, key);
			cout << "Decrypted text:" << endl;
			printString(unchiper);
			cout << endl<<
				"Do you find response?"<<endl<<
				"If you  find response input 0 else input any symbol"<<endl;
			cin >> response;
			if (response == '0')isFind = true;

		}
	}

	system("pause");
	return 0;
}
/*
int main(char* text,char* result,char* key,bool isEncode)
{
	//setlocale(LC_ALL, "Russian");
	long long textLeng = TPBG::countLeng(text);
	result = (char*)malloc(textLeng + 1);
	*(result + textLeng) = '\0';

	if (isEncode) {
		result = TPBG::encoderVigener(text, key);
	}
	else result = TPBG::decoderVigener(text, key);

	return 0;
}
*/