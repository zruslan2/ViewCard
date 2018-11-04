#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void main() {

	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	system("color F4");
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
	// левый верхний угол 250с
	// горизонтальная линия 2500
	// правый верхний угол 250с
	// вертикальная линия 2502
	// левый нижний угол 2514
	// правый нижний угол 2518
	// черви - 2665, буби - 2666, крести - 2663, пики - 2660

	// 10 черви
	wcout << L"\u250c";
	for (size_t i = 0; i < 5; i++)
	{		
		wcout << L"\u2500";
	}		
	wcout << L"\u2510\n";
	for (size_t i = 0; i < 5; i++)
	{
		wcout << L"\u2502\u2665   \u2665\u2502\n";
	}
	wcout << L"\u2514";
	for (size_t i = 0; i < 5; i++)
	{
		wcout << L"\u2500";
	}
	wcout << L"\u2518\n";
	
	// 10 крести
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));

	wcout << L"\u250c";
	for (size_t i = 0; i < 5; i++)
	{
		wcout << L"\u2500";
	}
	wcout << L"\u2510\n";
	for (size_t i = 0; i < 5; i++)
	{
		wcout << L"\u2502\u2663   \u2663\u2502\n";
	}
	wcout << L"\u2514";
	for (size_t i = 0; i < 5; i++)
	{
		wcout << L"\u2500";
	}
	wcout << L"\u2518\n";

	// королева пики
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));

	wcout << L"\u250c";
	for (size_t i = 0; i < 5; i++)
	{
		wcout << L"\u2500";
	}
	wcout << L"\u2510\n";
	wcout << L"\u2502\     \u2502\n";
	wcout << L"\u2502\  \u2660  \u2502\n";
	wcout << L"\u2502\     \u2502\n";
	wcout << L"\u2502\queen\u2502\n";
	wcout << L"\u2502\     \u2502\n";	
	wcout << L"\u2514";
	for (size_t i = 0; i < 5; i++)
	{
		wcout << L"\u2500";
	}
	wcout << L"\u2518\n";

	// королева пики
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));

	wcout << L"\u250c";
	for (size_t i = 0; i < 5; i++)
	{
		wcout << L"\u2500";
	}
	wcout << L"\u2510\n";
	wcout << L"\u2502\     \u2502\n";
	wcout << L"\u2502\  \u2660  \u2502\n";
	wcout << L"\u2502\     \u2502\n";
	wcout << L"\u2502\king \u2502\n";
	wcout << L"\u2502\     \u2502\n";
	wcout << L"\u2514";
	for (size_t i = 0; i < 5; i++)
	{
		wcout << L"\u2500";
	}
	wcout << L"\u2518\n";

	system("pause");

}

