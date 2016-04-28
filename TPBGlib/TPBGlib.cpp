// MathFuncsLib.cpp
// compile with: cl /c /EHsc MathFuncsLib.cpp
// post-build command: lib MathFuncsLib.obj

#include "TPBGlib.h"

#include <stdexcept>

using namespace std;

namespace TPBG
{
	__int64 countLeng(char* ST) {
		char* UM = ST;
		while (*UM != '\0') ++UM;
		_int64 n = (UM - ST);
		return n;
	}

	char findSimbolVigener(char symbolText, char symbolKey, bool isEncode) {
		int i = 0;
		int j = 0;
		int k = 0;
		while (symbolText != *(spisok + i))i++;
		while (symbolKey != *(spisok + j))j++;

		if (isEncode) k = (i + j) % spisokLeng;
		else k = (i - j) % spisokLeng;

		return spisok[k];
	}

	
	char* encoderVigener(char* textPlain, //Plain text/��������������� �����
							char* key) { //key/����

		_int64 textLeng = countLeng(textPlain);//text's length/����� ������  
		_int64 keyLeng = countLeng(key);//key's length/����� �����
		char* textChiper = (char*)malloc(textLeng + 1);// encrypted text/������������� �����
		char* keykey = (char*)malloc(textLeng + 1); //extended key/����������� ����
		/*length(keykey)==textLeng/����� ����� ����� ����� ���������*/
		for (__int64 i = 0; i < textLeng; i++) {
			*(keykey + i) = *(key + i%keyLeng);
		}

		for (__int64 i = 0; i < textLeng; i++) {
			*(textChiper + i) = findSimbolVigener(*(textPlain + i), *(keykey + i), 1);
		}

		free(keykey);//clear memory
		keykey = 0; //NULL pointer

		*(textChiper + textLeng) = '\0';
		return textChiper;// return pointer/���������� ���������
	}

	
	char* decoderVigener(char* textChiper, //encrypted text/������������� �����
							char* key) { //key/����

		_int64 textLeng = countLeng(textChiper);//text's length/����� ������  
		_int64 keyLeng = countLeng(key);//key's length/����� �����

		char* textPlain = (char*)malloc(textLeng + 1);// encrypted text/������������� �����
		char* keykey = (char*)malloc(textLeng + 1); //extended key/����������� ����

													/*length(keykey)==textLeng/����� ����� ����� ����� ���������*/
		for (__int64 i = 0; i < textLeng; i++) {
			*(keykey + i) = *(key + i%keyLeng);
		}

		for (__int64 i = 0; i < textLeng; i++) {
			*(textPlain + i) = findSimbolVigener(*(textChiper + i), *(keykey + i), 0);
		}

		free(keykey);//clear memory
		keykey = 0; //NULL pointer


		*(textPlain + textLeng) = '\0';
		return textPlain;//��������� ������/require edit
	}
}