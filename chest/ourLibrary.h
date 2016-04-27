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
