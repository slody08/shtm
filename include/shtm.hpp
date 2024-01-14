#ifndef shtm_hpp
#define shtm_hpp

#include <sys/ioctl.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdarg.h>
#include <csignal>
#include <codecvt>
#include <locale>
#include <uchar.h>
#include <map>
#include <format>
#include <algorithm>
using namespace std;

#define SHTM_VERSION  "0.3.1"
#define HOME_DIR getpwuid(getuid())->pw_dir
#define SHTM_RC  ".shtmrc"


void clear();
void move(int x, int y);

//string format(string f, ...);
vector<wstring> split(wstring source, wstring delim);

const vector<wchar_t> digits {
  L'0',
  L'1',
  L'2',
  L'3',
  L'4',
  L'5',
  L'6',
  L'7',
  L'8',
  L'9'
};

bool only_numbers(wstring str);

struct task_t {
  wstring data;
  bool state;
};

enum shtm_error_t {
  EmptyErrorException,
  UndefinedCommandException,
  AllTasksDoneException,
  InformationException,
  EmptyInputDataException,
  TaskDoesntExistException,
};

enum token_t {
  AddTask,
  ToggleTask,
  RemoveTask,
  HelpMenu,
  Quit
};

const map<wchar_t, token_t> token_table {
  {L'+', AddTask},
  {L'-', RemoveTask},
  {L'=', ToggleTask},
  {L'?', HelpMenu},
  {L'q', Quit}
};

class shtm {
private:
  string rc_path();
  wstring source;
  vector<task_t> tasks;
  shtm_error_t error;
  map<token_t, void (*)(shtm *, wstring)> function_map;
  int width;
  int height;

public:
  // Constructors
  shtm();
  void init();

  // Config managment
  bool load();
  bool save(wstring data = L"");
  
  // Casters
  void cast_tasks();
  void cast_rc();

  // Functional
  void add_function(token_t token, void (*func)(shtm *, wstring));
  void list();
  void operator+(wstring data);
  void operator-(int id);
  void operator=(int id);
  void mainloop();

  // Error handling
  wstring get_error();
  void set_error(shtm_error_t err);

  // Deinitialize program
  static void close(int param = 0);

  // Terminal size
  int get_width();
  int get_height();
};

static shtm *self;

#endif