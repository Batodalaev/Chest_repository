//it is a first file in repozitory(may be)
//libraries
#include <iostream>
#include <stdlib.h>

using namespace std;


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
int printString(char* ST) {
char* UM = ST;
while (*UM != '\0') {
++UM;
cout << *UM;
};
return 0;
}*/

/*
UK this function is encode text
RU ��� ������� ������� �����

the next texts is just to fun->
FR cette fonction est encodage du texte
DE Diese Funktion verschl?sselt Text
*/
char* encoder(char* textPlain, //Plain text/��������������� �����
	unsigned int textLeng, //text's length/����� ������  
	char* key, //key/����
	unsigned int keyLeng) { //key's length/����� �����
	char* textChiper = (char*)malloc(textLeng + 1);

	return textChiper;
}

/*
UK this function is decode text
RU ��� ������� ��������� �����

the next texts is just to fun->
FR cette fonction est decodage du texte
DE Diese Funktion entschl?sselt Text

*/
int decoder() {


	return 0;//��������� ������/require edit
}
int main()
{
	/*char str[100];
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
	system("pause");*/
	return 0;
}