#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <Windows.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void red();
void black();
void GotoXY(int X, int Y);
void top();
void bottom();
void ViewCard(int m, int n, int x, int y);

void main() {

	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	system("color F4");
	
	// левый верхний угол 250с
	// горизонтальная линия 2500
	// правый верхний угол 250с
	// вертикальная линия 2502
	// левый нижний угол 2514
	// правый нижний угол 2518
	// черви - 2665, буби - 2666, крести - 2663, пики - 2660
	
	int x = 0, y = 0;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 2; j < 15; j++)
		{
			ViewCard(i, j, x, y);
			x += 8;
		}
		x = 0;
		y += 8;
	}	

	system("pause");

}

void red()
{
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
}

void black()
{
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
}

void GotoXY(int X, int Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hConsole, coord);
}

void top()
{
	wcout << L"\u250c";
	for (size_t i = 0; i < 5; i++)
	{
		wcout << L"\u2500";
	}
	wcout << L"\u2510\n";
}

void bottom()
{
	wcout << L"\u2514";
	for (size_t i = 0; i < 5; i++)
	{
		wcout << L"\u2500";
	}
	wcout << L"\u2518\n";
}

void ViewCard(int m, int n, int x, int y)
{
	wstring mast;
	if (m == 0)
	{
		mast = L"\u2663";
		black();
	}
	else if (m == 1)
	{
		mast = L"\u2665";
		red();
	}
	else if (m == 2)
	{
		mast = L"\u2660";
		black();
	}
	else if (m == 3)
	{
		mast = L"\u2666";
		red();
	}
	wstring Cstr = L"\u2502\     \u2502\n";
	wstring Jstr = L"\u2502\jack \u2502\n";
	wstring Qstr = L"\u2502\queen\u2502\n";
	wstring Kstr = L"\u2502\king \u2502\n";
	wstring Astr = L"\u2502\ ace \u2502\n";
	wstring str1 = L"\u2502\  ";
	str1 += mast;
	str1 += L"  \u2502";
	wstring str2 = L"\u2502";
	str2 += mast;
	str2 += L"   ";
	str2 += mast;
	str2+= L"\u2502";
	
	if (n == 2)
	{
		GotoXY(x, y);
		top();
		y++;
		GotoXY(x, y);
		wcout << str1;
		for (size_t i = 0; i < 3; i++)
		{
			y++;
			GotoXY(x, y);
			wcout << Cstr;
		}
		y++;
		GotoXY(x, y);
		wcout << str1;
		y++;
		GotoXY(x, y);
		bottom();
	}
	else if (n == 3)
	{
		GotoXY(x, y);
		top();
		for (size_t i = 0; i < 2; i++)
		{
			y++;
			GotoXY(x, y);
			wcout << str1;
			y++;
			GotoXY(x, y);
			wcout << Cstr;
		}		
		y++;
		GotoXY(x, y);
		wcout << str1;
		y++;
		GotoXY(x, y);
		bottom();
	}
	else if (n == 4)
	{
		GotoXY(x, y);
		top();
		y++;
		GotoXY(x, y);
		wcout << str2;
		for (size_t i = 0; i < 3; i++)
		{
			y++;
			GotoXY(x, y);
			wcout << Cstr;
		}
		y++;
		GotoXY(x, y);
		wcout << str2;
		y++;
		GotoXY(x, y);
		bottom();
	}
	else if (n == 5)
	{
		GotoXY(x, y);
		top();
		y++;
		GotoXY(x, y);
		wcout << str2;
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		wcout << str1;
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		wcout << str2;
		y++;
		GotoXY(x, y);
		bottom();
	}
	else if (n == 6)
	{
		GotoXY(x, y);
		top();
		for (size_t i = 0; i < 2; i++)
		{
			y++;
			GotoXY(x, y);
			wcout << str2;
			y++;
			GotoXY(x, y);
			wcout << Cstr;
		}
		y++;
		GotoXY(x, y);
		wcout << str2;
		y++;
		GotoXY(x, y);
		bottom();
	}
	else if (n == 7)
	{
		GotoXY(x, y);
		top();
		y++;
		GotoXY(x, y);
		wcout << str2;
		y++;
		GotoXY(x, y);
		wcout << str1;
		y++;
		GotoXY(x, y);
		wcout << str2;
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		wcout << str2;
		y++;
		GotoXY(x, y);
		bottom();
	}
	else if (n == 8)
	{
		GotoXY(x, y);
		top();
		y++;
		GotoXY(x, y);
		wcout << str2;
		y++;
		GotoXY(x, y);
		wcout << str1;
		y++;
		GotoXY(x, y);
		wcout << str2;
		y++;
		GotoXY(x, y);
		wcout << str1;
		y++;
		GotoXY(x, y);
		wcout << str2;
		y++;
		GotoXY(x, y);
		bottom();
	}
	else if (n == 9)
	{
		GotoXY(x, y);
		top();
		y++;
		GotoXY(x, y);
		wcout << str2;
		y++;
		GotoXY(x, y);
		wcout << str2;
		y++;
		GotoXY(x, y);
		wcout << str1;
		y++;
		GotoXY(x, y);
		wcout << str2;
		y++;
		GotoXY(x, y);
		wcout << str2;
		y++;
		GotoXY(x, y);
		bottom();
	}
	else if (n == 10)
	{
		GotoXY(x, y);
		top();
		for (size_t i = 0; i < 5; i++)
		{
			y++;
			GotoXY(x, y);
			wcout << str2;
		}
		y++;
		GotoXY(x, y);
		bottom();
	}
	else if (n == 11)
	{
		GotoXY(x, y);
		top();
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		wcout << str1;
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		wcout << Jstr;
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		bottom();
	}
	else if (n == 12)
	{
		GotoXY(x, y);
		top();
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		wcout << str1;
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		wcout << Qstr;
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		bottom();
	}
	else if (n == 13)
	{
		GotoXY(x, y);
		top();
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		wcout << str1;
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		wcout << Kstr;
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		bottom();
	}
	else if (n == 14)
	{
		GotoXY(x, y);
		top();
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		wcout << str1;
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		wcout << Astr;
		y++;
		GotoXY(x, y);
		wcout << Cstr;
		y++;
		GotoXY(x, y);
		bottom();
	}
}