#pragma once

#include <ctime> //for srand(time(0)) in generatePassword()
#include <fstream> //for save/load in/from file
#include <stdexcept>
namespace TPBG
{
	
	/*
	UK It's symbols, which he can encoding
	RU �������, ������� ����� ���������
	
	spisok[0]==' '; because 149%149=0
	
	static char spisok[] = "=1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ�������������������������������������Ũ�������������������������";
	*/
	static char spisok[] = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_ +;:<>,.-";
	/*
	UK fast algorithm for counting the line length
	RU ������� ������� ����� ������
	*/
	 _int64 countLeng(char* ST);
	 
	/*
	UK length of spisok[]
	RU ����� ������
	*/
	 static __int64 spisokLeng = countLeng(spisok);


	/*
	UK function find symbol in matrix of chiper of Vigener
	RU ������� ������ ������� � ������� ����� ��������
	*/
	char findSimbolVigener(char symbolText, char symbolKey, bool isEncode);	
	/*
	UK this function is encode text
	RU ��� ������� ������� �����
	*/
	char* encoderVigener(char* textPlain, char* key);
	/*
	UK this function is decode text
	RU ��� ������� ��������� �����
	*/
	char* decoderVigener(char* textChiper, char* key);


	/*
	UK this function is encode text with using the Caesar cipher
	RU ��� ������� ������� ���� � ������� ����� ������
	only big english letters
	*/
	char* encoderCaesar(char* textPlain, int key);
	/*
	UK this function is decode text with using the Caesar cipher
	RU ��� ������� ��������� ���� � ������� ����� ������
	only big english letters
	*/
	char* decoderCaesar(char* textChiper, int key);


	/*
	UK It is the simple password's generator
	RU ������� ��������� �������
	*/
	char* generatePassword(__int64 lengPassword);

	/*
	UK save password in file
	RU ���������� ������� � ����
	*/
	bool isSavedPasswords(char** passwords);

	/*
	UK load passwords from file
	RU �������� ������� �� �����
	*/
	char** loadPasswords();
}