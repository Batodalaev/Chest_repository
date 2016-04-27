#pragma once

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