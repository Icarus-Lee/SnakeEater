#include "ConsoleClear.h"
#include <windows.h>

void ClearConsole() {
  HANDLE                     hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(hConsole, &csbi);
  COORD coord = {0, 0};
  SetConsoleCursorPosition(hConsole, coord);
}