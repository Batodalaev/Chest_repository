//it is a first file in repozitory(may be)
//libraries
#include <malloc.h>

using namespace std;

_int64 countLeng(char* ST);
void printString(char* ST);
char findSimbolVigener(char symbolText, char symbolKey, bool trueforEncode);
char* encoderVigener(char* textPlain, char* key);
char* decoderVigener(char* textChiper, char* key);
/*
char spisoknumbers[] = "1234567890";
char spisokeng[] = "abcdefghijklmnopqrstuvwxyz";
char spisokENG[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char spisokrus[] = "��������������������������������";
char spisokRUS[] = "�����Ũ�������������������������";
char spisoksymbols[] = "!@#$%^&*()_ +;:<>,.-=";
*/

// spisok[0]==' '; because 149%149=0
char spisok[] = " 1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ�������������������������������������Ũ�������������������������!@#$%^&*()_ +;:<>,.-=";
__int64 spisokLeng = countLeng(spisok);

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

char findSimbolVigener(char symbolText, char symbolKey, bool isEncode) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (symbolText != *(spisok+i))i++;
	while (symbolKey != *(spisok + j))j++;

	if (isEncode) k = (i + j) % spisokLeng;
	else k = (i - j) % spisokLeng;

	return spisok[k];
}
////////////////////////////////////////////////////////////////////
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
	char* keykey = (char*)malloc(textLeng+1); //extended key/����������� ����

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
/////////////////////////////////////////////////////////////////////////////////
int main(char* text,char* result,char* key,bool isEncode)
{
	//setlocale(LC_ALL, "Russian");
	long long textLeng = countLeng(text);
	result = (char*)malloc(textLeng + 1);
	*(result + textLeng) = '\0';

	if (isEncode) {
		result = encoderVigener(text, key);
	}
	else result = decoderVigener(text, key);

	return 0;
}