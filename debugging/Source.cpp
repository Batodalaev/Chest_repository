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
		++UM;
		cout << *UM;
	};
	
	return 0;
}
/*
UK this function is encode text
RU эта функция шифрует текст

the next texts is just to fun->
FR cette fonction est encodage du texte
DE Diese Funktion verschlsselt Text
*/
char* encoder(char* textPlain, //Plain text/незашифрованный текст
	unsigned int textLeng, //text's length/длина текста  
	char* key, //key/ключ
	unsigned int keyLeng) { //key's length/длина ключа

	char* textChiper = (char*)malloc(textLeng + 1);
	for (int i = 0; i < textLeng; i++) {

	}

	return textChiper;// return pointer/возвращает указатель
}



/*
UK this function is decode text
RU эта функция дешифрует текст

the next texts is just to fun->
FR cette fonction est decodage du texte
DE Diese Funktion entschlsselt Text

*/
int decoder() {


	return 0;//требуются правки/require edit
}

int main()
{
 char str[100];
 char key[100];
 cin >> str;
 cin >> key;
 unsigned int stringLeng = countLeng(str);
 unsigned int keyLeng = countLeng(key);
 char* chiper;
 chiper=encoder(str,stringLeng,key,keyLeng);

 cout << keyLeng << endl
 << stringLeng << endl
 << endl;
 printString(str);
 cout << endl;
 system("pause");
	return 0;
}