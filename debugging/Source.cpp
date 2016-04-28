//it is a first file in repozitory(may be)
//libraries
#include <iostream>
#include <stdlib.h>

using namespace std;

char spisoknumbers[] = "1234567890";
char spisokeng[] = "abcdefghigklmnopqrstuvwxyz";
char spisokENG[] = "ABCDEFGHIGKLMNOPQRSTUVWXYZ";
char spisokrus[] = "��������������������������������";
char spisokRUS[] = "�����Ũ�������������������������";
char spisoksymbols[] = "!@#$%^&*()_ +;:<>,.-=";

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
UK print in console
RU ������� � �������
*/
int printString(char* ST) {
	char* UM = ST;
	while (*UM != '\0') {
		cout << *UM;
		++UM;
	};
	
	return 0;
}
////////////////////////////////////////////////////////////////////
/*
UK this function is encode text with using the Caesar cipher
RU ��� ������� ������� ����� � ������� ����� ������

the next texts is just to fun->
FR cette fonction est encodage du texte en utilisant le chiffrement C?sar
DE Diese Funktion verschlusselt Text mit dem Caesar-Chiffre
*/
char* encoderCaesar(char* textPlain, //Plain text/��������������� �����
						int key) { //key/����

	int turnKey = key % 26;
	_int64 textLeng = countLeng(textPlain);//text's length/����� ������  
	char* textChiper = (char*)malloc(textLeng + 1);// encrypted text/������������� �����

	
	for (unsigned int i = 0; i < textLeng; i++) {
		*(textChiper + i) = *(textPlain + i) + turnKey;
		if (*(textChiper + i) > 'Z') {
			*(textChiper + i) -= 26;
		}

	}
	*(textChiper + textLeng) = '\0';
	return textChiper;// return pointer/���������� ���������
}
/*
UK this function is decode text with using the Caesar cipher
RU ��� ������� ��������� ����� � ������� ����� ������

the next texts is just to fun->
FR cette fonction est decodage du texte en utilisant le chiffrement C?sar
DE Diese Funktion entschlusselt Text mit dem Caesar-Chiffre
*/
char* decoderCaesar(char* textChiper, //encrypted text/������������� �����
						int key) { //key/���� 

	int turnKey = key % 26;
	_int64 textLeng = countLeng(textChiper);//text's length/����� ������  
	char* textPlain = (char*)malloc(textLeng + 1);// encrypted text/������������� �����
	
	for (unsigned int i = 0; i < textLeng; i++) {
		*(textPlain + i) = *(textChiper + i) - turnKey;
		if (*(textPlain + i) < 'A') {
			*(textPlain + i) += 26;
		}
	}

	*(textPlain + textLeng) = '\0';
	return textPlain;//��������� ������/require edit
}
///////////////////////////////////////////////////////////////////////////////////////
/*
UK this function is encode text
RU ��� ������� ������� �����

the next texts is just to fun->
FR cette fonction est encodage du texte
DE Diese Funktion verschlusselt Text
*/
char* encoderVigener(char* textPlain, //Plain text/��������������� �����
	char* key) { //key/����
	
	_int64 textLeng = countLeng(textPlain);//text's length/����� ������  
	_int64 keyLeng = countLeng(key);//key's length/����� �����
	char* textChiper = (char*)malloc(textLeng + 1);// encrypted text/������������� �����

		

	*(textChiper + textLeng) = '\0';
	return textChiper;// return pointer/���������� ���������
}

/*
UK this function is decode text
RU ��� ������� ��������� �����

the next texts is just to fun->
FR cette fonction est decodage du texte
DE Diese Funktion entschlusselt Text
*/
char* decoderVigener(char* textChiper, //encrypted text/������������� �����
	char* key) { //key/����

	_int64 textLeng = countLeng(textChiper);//text's length/����� ������  
	_int64 keyLeng = countLeng(key);//key's length/����� �����
	char* textPlain = (char*)malloc(textLeng + 1);// encrypted text/������������� �����
		
	
	*(textPlain + textLeng) = '\0';
	return textPlain;//��������� ������/require edit
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