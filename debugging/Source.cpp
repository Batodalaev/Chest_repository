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
DE Diese Funktion verschlsselt Text
*/
char* encoder(char* textPlain, //Plain text/незашифрованный текст
	unsigned int textLeng, //text's length/длина текста  
	char* key, //key/ключ
	unsigned int keyLeng) { //key's length/длина ключа

	char* textChiper = (char*)malloc(textLeng + 1);

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
DE Diese Funktion entschlsselt Text

*/
int decoder() {


	return 0;//требуются правки/require edit
}

int main()
{
 char str[100];
 char key[100];
 _int64 stringLeng;
 unsigned int keyLeng;
 char* chiper;

 cout << "only small english letters" << endl;
 cin >> str;
 cin >> keyLeng;//key

  stringLeng = countLeng(str);
 //keyLeng = countLeng(key);
 chiper=encoder(str,stringLeng,key,keyLeng);

 cout << keyLeng << endl
 << stringLeng << endl
 << endl;
 printString(chiper);
 cout << endl;

 system("pause");
	return 0;
}