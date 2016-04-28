
#include <malloc.h>


using namespace std;

_int64 countLeng(char* ST);
char findSimbolVigener(char symbolText, char symbolKey, bool trueforEncode);
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

// spisok[0]==' '; because 149%149=0
char spisok[] = " 1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ!@#$%^&*()_ +;:<>,.-=";
__int64 spisokLeng = countLeng(spisok);

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

char* encoderVigener(char* textPlain, //Plain text/незашифрованный текст
	char* key) { //key/ключ
	
	_int64 textLeng = countLeng(textPlain);//text's length/длина текста  
	_int64 keyLeng = countLeng(key);//key's length/длина ключа
	char* textChiper = (char*)malloc(textLeng + 1);// encrypted text/зашифрованный текст
	char* keykey = (char*)malloc(textLeng+1); //extended key/расширенный ключ

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
	return textChiper;// return pointer/возвращает указатель
}

char* decoderVigener(char* textChiper, //encrypted text/зашифрованный текст
	char* key) { //key/ключ

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
	return textPlain;//требуются правки/require edit
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