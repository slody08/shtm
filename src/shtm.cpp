// !ready

#include <shtm.hpp>

/*  Terminal clearing */
void shtm::clear() {
  std::wcout << L"\033[H\033[J";
  fflush(stdout);
}

/*  Moves terminal cursor to X, Y

  params:
  + x - int
  + y - int
*/
void shtm::move(int x, int y) {
  std::wcout << L"\033[" << y << L";" << x << L"H";
}

std::string shtm::format(std::string f, ...) {
  va_list list;

  va_start(list, f);

  char *buffer = (char *)malloc(64);
  vsprintf(buffer, f.c_str(), list);

  va_end(list);

  return buffer;
}

/* Program class initializer */
shtm::shtm::shtm() {
  winsize size;
  ioctl(0, TIOCGWINSZ, &size);
  width = size.ws_col, height = size.ws_row;
}

void shtm::shtm::close(int param) {
  clear();
  cast_rc();
  save(source);
  exit(0);
}