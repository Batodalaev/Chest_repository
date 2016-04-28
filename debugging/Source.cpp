//it is a first file in repozitory(may be)
//libraries
#include <iostream>
#include <stdlib.h>

using namespace std;

_int64 countLeng(char* ST);
void printString(char* ST);
char findsymbolinMatrixVigener(char symbolText, char symbolKey, bool trueforEncode);
char* encoderCaesar(char* textPlain, int key);
char* decoderCaesar(char* textChiper, int key);
char* encoderVigener(char* textPlain, char* key);
char* decoderVigener(char* textChiper, char* key);
/*
char spisoknumbers[] = "1234567890";
char spisokeng[] = "abcdefghijklmnopqrstuvwxyz";
char spisokENG[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char spisokrus[] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
char spisokRUS[] = "АБВГДЕЁЖЗИКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
char spisoksymbols[] = "!@#$%^&*()_ +;:<>,.-=";
*/

// spisok[0]=='='; because 148%148=0
char spisok[] = "=1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ!@#$%^&*()_ +;:<>,.-";
int spisokLeng = countLeng(spisok);

/*
UK fast algorithm for counting the line length
RU быстрый подсчет длины строки
*/
_int64 countLeng(char* ST) {
	char* UM = ST;
	while (*UM != '\0') ++UM;
	_int64 n = (UM - ST);
	return n;
}

/* 
UK print in console
RU выводит в консоль
*/
void printString(char* ST) {
	char* UM = ST;
	while (*UM != '\0') {
		cout << *UM;
		++UM;
	};
}

char findsymbolinMatrixVigener(char symbolText, char symbolKey, bool isEncode) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (symbolText != *(spisok+i))i++;
	while (symbolKey != *(spisok + j))j++;
	if (isEncode)k=(i+j)%spisokLeng;
	else k = (i - j) % spisokLeng;

	return spisok[k];
}
////////////////////////////////////////////////////////////////////
/*
UK this function is encode text with using the Caesar cipher
RU эта функция шифрует текст с помощью шифра Цезаря

the next texts is just to fun->
FR cette fonction est encodage du texte en utilisant le chiffrement C?sar
DE Diese Funktion verschlusselt Text mit dem Caesar-Chiffre
*/
char* encoderCaesar(char* textPlain, //Plain text/незашифрованный текст
						int key) { //key/ключ

	int turnKey = key % 26;
	_int64 textLeng = countLeng(textPlain);//text's length/длина текста  
	char* textChiper = (char*)malloc(textLeng + 1);// encrypted text/зашифрованный текст

	for (unsigned int i = 0; i < textLeng; i++) {
		*(textChiper + i) = *(textPlain + i) + turnKey;
		if (*(textChiper + i) > 'Z') {
			*(textChiper + i) -= 26;
		}
	}
	*(textChiper + textLeng) = '\0';
	return textChiper;// return pointer/возвращает указатель
}
/*
UK this function is decode text with using the Caesar cipher
RU эта функция дешифрует текст с помощью шифра Цезаря

the next texts is just to fun->
FR cette fonction est decodage du texte en utilisant le chiffrement C?sar
DE Diese Funktion entschlusselt Text mit dem Caesar-Chiffre
*/
char* decoderCaesar(char* textChiper, //encrypted text/зашифрованный текст
						int key) { //key/ключ 

	int turnKey = key % 26;
	_int64 textLeng = countLeng(textChiper);//text's length/длина текста  
	char* textPlain = (char*)malloc(textLeng + 1);// encrypted text/зашифрованный текст
	
	for (unsigned int i = 0; i < textLeng; i++) {
		*(textPlain + i) = *(textChiper + i) - turnKey;
		if (*(textPlain + i) < 'A') {
			*(textPlain + i) += 26;
		}
	}

	*(textPlain + textLeng) = '\0';
	return textPlain;//требуются правки/require edit
}
///////////////////////////////////////////////////////////////////////////////////////
/*
UK this function is encode text
RU эта функция шифрует текст

the next texts is just to fun->
FR cette fonction est encodage du texte
DE Diese Funktion verschlusselt Text
*/
char* encoderVigener(char* textPlain, //Plain text/незашифрованный текст
	char* key) { //key/ключ
	
	_int64 textLeng = countLeng(textPlain);//text's length/длина текста  
	_int64 keyLeng = countLeng(key);//key's length/длина ключа
	char* textChiper = (char*)malloc(textLeng + 1);// encrypted text/зашифрованный текст
	char* keykey = (char*)malloc(textLeng+1);

	for (int i = 0; i < textLeng; i++) {
		*(keykey + i) = *(key + i%keyLeng);
	}
	for (unsigned int i = 0; i < textLeng; i++) {
		*(textChiper + i) = findsymbolinMatrixVigener(*(textPlain + i), *(keykey + i), 1);
	}

	free(keykey);//clear memory
	keykey = 0; //NULL pointer

	*(textChiper + textLeng) = '\0';
	return textChiper;// return pointer/возвращает указатель
}

/*
UK this function is decode text
RU эта функция дешифрует текст

the next texts is just to fun->
FR cette fonction est decodage du texte
DE Diese Funktion entschlusselt Text
*/
char* decoderVigener(char* textChiper, //encrypted text/зашифрованный текст
	char* key) { //key/ключ

	_int64 textLeng = countLeng(textChiper);//text's length/длина текста  
	_int64 keyLeng = countLeng(key);//key's length/длина ключа
	char* textPlain = (char*)malloc(textLeng + 1);// encrypted text/зашифрованный текст
	char* keykey = (char*)malloc(textLeng + 1);

	for (int i = 0; i < textLeng; i++) {
		*(keykey + i) = *(key + i%keyLeng);
	}
	for (unsigned int i = 0; i < textLeng; i++) {
		*(textPlain + i) = findsymbolinMatrixVigener(*(textChiper + i), *(keykey + i), 0);
	}

	free(keykey);//clear memory
	keykey = 0; //NULL pointer

	
	*(textPlain + textLeng) = '\0';
	return textPlain;//требуются правки/require edit
}

int main()
{
 char textInput[101];
 char key[101];
 char* chiper;
 char*  unchiper;

 cout << "Please, intput only big english letters" << endl
	 <<"Please, input text, which you want to encode:"<< endl;
 cin >> textInput;
 cout << "Please, input key:" << endl;
 cin >> key;

 chiper = encoderVigener(textInput, key);
 cout	<< "Encrypted text:";
 printString(chiper);
 cout << endl;
 unchiper = decoderVigener(chiper, key);
 cout << "Decrypted text:";
 printString(unchiper);
 cout << endl;

 system("pause");
	return 0;
}