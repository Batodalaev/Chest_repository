#pragma once
// MathFuncsLib.h

namespace TPBG
{
	// spisok[0]==' '; because 149%149=0
	char spisok[] = " 1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ!@#$%^&*()_ +;:<>,.-=";
	

	/*
	UK fast algorithm for counting the line length
	RU быстрый подсчет длины строки
	*/
	_int64 countLeng(char* ST);


	/*
	UK length of spisok[]
	RU длина списка
	*/
	__int64 spisokLeng = countLeng(spisok);
	/*
	UK function find symbol in matrix of chiper of Vigener
	RU функция поиска символа в матрице шифра Виженера
	*/
	char findSimbolVigener(char symbolText, char symbolKey, bool trueforEncode);
		
	/*
	UK this function is encode text
	RU эта функция шифрует текст
	FR cette fonction est encodage du texte
	DE Diese Funktion verschlusselt Text
	*/
	char* encoderVigener(char* textPlain, char* key);

	/*
	UK this function is decode text
	RU эта функция дешифрует текст
	FR cette fonction est decodage du texte
	DE Diese Funktion entschlusselt Text
	*/
	char* decoderVigener(char* textChiper, char* key);
}