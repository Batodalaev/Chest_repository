


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
		cout << *UM;
		++UM;
	};
}

int main()
{
	char textInput[101];
	char key[101];
	char* chiper;
	char*  unchiper;

	cout << "Please, input text without russian symbols" << endl
		<< "Please, input text, which you want to encode:" << endl;
	cin >> textInput;
	cout << "Please, input key:" << endl;
	cin >> key;

	chiper = TPBG::encoderVigener(textInput, key);
	cout << "Encrypted text:";
	printString(chiper);
	cout << endl;
	unchiper = TPBG::decoderVigener(chiper, key);
	cout << "Decrypted text:";
	printString(unchiper);
	cout << endl;

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