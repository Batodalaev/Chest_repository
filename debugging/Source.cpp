//it is a first file in repozitory(may be)
//libraries
#include <iostream>
#include <stdlib.h>

using namespace std;

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
int printString(char* ST) {
	char* UM = ST;
	while (*UM != '\0') {
		cout << *UM;
		++UM;
	};
	
	return 0;
}
/*
UK this function is encode text
RU эта функция шифрует текст

the next texts is just to fun->
FR cette fonction est encodage du texte
DE Diese Funktion verschlusselt Text
*/
char* encoder(char* textPlain, //Plain text/незашифрованный текст
	char* key) { //key/ключ

	_int64 textLeng = countLeng(textPlain);//text's length/длина текста  
	_int64 keyLeng = countLeng(key);//key's length/длина ключа
	char* textChiper = (char*)malloc(textLeng + 1);// encrypted text/зашифрованный текст
		
	int turnKey = keyLeng% 26;
	for (unsigned int i = 0; i < textLeng; i++) {
		*(textChiper+i) = *(textPlain+i)+turnKey;
		if (*(textChiper+i) > 'z') {
			*(textChiper+i) -= 26;
		}
		
	}
	*(textChiper+textLeng) = '\0';
	return textChiper;// return pointer/возвращает указатель
}



/*
UK this function is decode text
RU эта функция дешифрует текст

the next texts is just to fun->
FR cette fonction est decodage du texte
DE Diese Funktion entschlusselt Text
*/
char* decoder(char* textChiper, //encrypted text/зашифрованный текст
	char* key) { //key/ключ

	_int64 textLeng = countLeng(textChiper);//text's length/длина текста  
	_int64 keyLeng = countLeng(key);//key's length/длина ключа
	char* textPlain = (char*)malloc(textLeng + 1);// encrypted text/зашифрованный текст

	int turnKey = keyLeng % 26;
	for (unsigned int i = 0; i < textLeng; i++) {
		*(textPlain + i) = *(textChiper + i) - turnKey;
		if (*(textPlain + i) < 'a') {
			*(textPlain + i) += 26;
		}
	}
	
	*(textPlain + textLeng) = '\0';
	return textPlain;//требуются правки/require edit
}

int main()
{
 char textInput[100];
 char key[100];
 char* chiper;
char*  unchiper;

 cout << "Please, intput only small english letters" << endl
	 <<"Please, input text, which you want to encode:"<< endl;
 cin >> textInput;
 cout << "Please, input key:" << endl;
 cin >> key;

 chiper = encoder(textInput, key);
 
 cout	<< "Encrypted text:";
 printString(chiper);
 unchiper = decoder(chiper, key);
 cout	<< endl
		<< "Decrypted text:";
 printString(unchiper);
 cout << endl;

 system("pause");
	return 0;
}