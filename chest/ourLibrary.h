#pragma once

/*
UK fast algorithm for counting the line length
RU ������� ������� ����� ������
*/
_int64 countLeng(char* ST) {
	char* UM = ST;
	while (*UM != '\0') ++UM;
	_int64 n = (UM - ST);
	return n;
}

/*
UK this function is encode text
RU ��� ������� ������� �����

the next texts is just to fun->
FR cette fonction est encodage du texte
DE Diese Funktion verschlsselt Text
*/
char* encoder(char* textPlain, //Plain text/��������������� �����
	unsigned int textLeng, //text's length/����� ������  
	char* key, //key/����
	unsigned int keyLeng) { //key's length/����� �����

	char* textChiper = (char*)malloc(textLeng + 1);


	return textChiper;// return pointer/���������� ���������
}



/*
UK this function is decode text
RU ��� ������� ��������� �����

the next texts is just to fun->
FR cette fonction est decodage du texte
DE Diese Funktion entschlsselt Text

*/
int decoder() {


	return 0;//��������� ������/require edit
}