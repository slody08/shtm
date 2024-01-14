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

  char *buffer = (char *)malloc(512);
  vsprintf(buffer, f.c_str(), list);

  va_end(list);

  return buffer;
}

std::vector<std::wstring> shtm::split(std::wstring source, std::wstring delim) {
  size_t position = 0;
  std::vector<std::wstring> segments;

  while ((position = source.find(delim)) != std::string::npos) {
    segments.push_back(source.substr(0, position));
    source.erase(0, position + delim.size());
  }

  return segments;
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