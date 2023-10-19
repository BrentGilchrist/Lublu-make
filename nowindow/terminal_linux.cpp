#include <locale>
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

int get_column(){
  struct winsize size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
  return size.ws_col;
}
int get_row(){
  struct winsize size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
  return size.ws_row;
}

void wprintf_s(const wchar_t *input) {
  std::wcout << input;
}
void _setmode(int a, int b){
  setlocale(LC_CTYPE,"");
}
int _fileno(FILE* a){
  return 0;
}