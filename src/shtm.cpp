// !ready

#include <shtm.hpp>

/*  Terminal clearing */
void clear() {
  std::wcout << L"\033[H\033[J";
  fflush(stdout);
}

/*  Moves terminal cursor to X, Y

  params:
  + x - int
  + y - int
*/
void move(int x, int y) {
  std::wcout << L"\033[" << y << L";" << x << L"H";
}

std::string format(std::string f, ...) {
  va_list list;

  va_start(list, f);

  char *buffer = (char *)malloc(512);
  vsprintf(buffer, f.c_str(), list);

  va_end(list);

  return buffer;
}

std::vector<std::wstring> split(std::wstring source, std::wstring delim) {
  size_t position = 0;
  std::vector<std::wstring> segments;

  while ((position = source.find(delim)) != std::string::npos) {
    segments.push_back(source.substr(0, position));
    source.erase(0, position + delim.size());
  }

  return segments;
}

bool only_numbers(wstring str) {
  bool has_only_numbers = true;

  for (wchar_t c : str) {
    if (find(digits.begin(), digits.end(), c) == digits.end())
      has_only_numbers = false;
  }

  return has_only_numbers;
}

/* Program class initializer */
shtm::shtm() {}

void shtm::init() {
  setlocale(LC_CTYPE, "");
  signal(SIGINT, close);
  winsize size;
  ioctl(0, TIOCGWINSZ, &size);
  width = size.ws_col, height = size.ws_row;
  self = this;
}

void shtm::close(int param) {
  clear();
  self->cast_rc();
  self->save(self->source);
  exit(0);
}

int shtm::get_width() {return width;}
int shtm::get_height() {return height;}