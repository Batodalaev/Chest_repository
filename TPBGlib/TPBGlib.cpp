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


	char* encoderVigener(char* textPlain, //Plain text/незашифрованный текст
		char* key) { //key/ключ

		_int64 textLeng = countLeng(textPlain);//text's length/длина текста  
		_int64 keyLeng = countLeng(key);//key's length/длина ключа
		char* textChiper = (char*)malloc(textLeng + 1);// encrypted text/зашифрованный текст
		char* keykey = (char*)malloc(textLeng + 1); //extended key/расширенный ключ

		/*length(keykey)==textLeng/длина ключа равна длине сообщения*/
		for (__int64 i = 0; i < textLeng; i++) {
			*(keykey + i) = *(key + i%keyLeng);
		}

		for (__int64 i = 0; i < textLeng; i++) {
			*(textChiper + i) = findSimbolVigener(*(textPlain + i), *(keykey + i), 1);
		}

		free(keykey);//clear memory
		keykey = 0; //NULL pointer

		*(textChiper + textLeng) = '\0';
		return textChiper;// return pointer on encrypted text
	}


	char* decoderVigener(char* textChiper, //encrypted text/зашифрованный текст
		char* key) {

		_int64 textLeng = countLeng(textChiper);//text's length/длина текста  
		_int64 keyLeng = countLeng(key);//key's length/длина ключа
		char* textPlain = (char*)malloc(textLeng + 1);// encrypted text/зашифрованный текст
		char* keykey = (char*)malloc(textLeng + 1); //extended key/расширенный ключ

		/*length(keykey)==textLeng/длина ключа равна длине сообщения*/
		for (__int64 i = 0; i < textLeng; i++) {
			*(keykey + i) = *(key + i%keyLeng);
		}

		for (__int64 i = 0; i < textLeng; i++) {
			*(textPlain + i) = findSimbolVigener(*(textChiper + i), *(keykey + i), 0);
		}

		free(keykey);//clear memory
		keykey = 0; //NULL pointer


		*(textPlain + textLeng) = '\0';
		return textPlain;//return pointer on decrypted text
	}

	char* encoderCaesar(char* textPlain, //Plain text
		int key) {

		int turnKey = key % 26;
		_int64 textLeng = countLeng(textPlain);//text's length
		char* textChiper = (char*)malloc(textLeng + 1);// memory for  encrypted text

		for (unsigned int i = 0; i < textLeng; i++) {
			*(textChiper + i) = *(textPlain + i) + turnKey;
			if (*(textChiper + i) > 'Z') {
				*(textChiper + i) -= 26;
			}
		}
		*(textChiper + textLeng) = '\0';
		return textChiper;// return pointer on encrypted text
	}

	char* decoderCaesar(char* textChiper, //encrypted text
		int key) {

		int turnKey = key % 26;
		_int64 textLeng = countLeng(textChiper);//text's length
		char* textPlain = (char*)malloc(textLeng + 1);// memory for decrypted text

		for (unsigned int i = 0; i < textLeng; i++) {
			*(textPlain + i) = *(textChiper + i) - turnKey;
			if (*(textPlain + i) < 'A') {
				*(textPlain + i) += 26;
			}
		}

		*(textPlain + textLeng) = '\0';
		return textPlain;//return pointer on decrypted text
	}


	char* generatePassword(__int64 lengPassword) {

		char* password = (char*)malloc(lengPassword + 1);
		*(password + lengPassword) = '\0';
		
		srand(lengPassword);

		for (int i = 0; i < lengPassword; i++) {
			*(password+i)=spisok[rand()%spisokLeng];
		}

		return password;
	}
}