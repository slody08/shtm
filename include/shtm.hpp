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

#define SHTM_VERSION  L"0.2"
#define HOME_DIR getpwuid(getuid())->pw_dir
#define SHTM_RC  ".shtmrc"

namespace shtm {
  void clear();
  void move(int x, int y);

  std::string format(std::string f, ...);

  struct task_t {
    std::wstring data;
    bool state;
  };

  enum class error_t {
    EmptyErrorException,
    UndefinedCommandException,
    AllTasksDoneException,
    InformationException,
    EmptyInputDataException,
    TaskDoesntExistException,
  };

  class shtm {
  private:
    std::string rc_path();
    std::wstring source;
    std::vector<task_t> tasks;
    error_t error;
  
  public:
    int width;
    int height;

    shtm();

    bool load();
    bool save(std::wstring data = L"");

    void cast_tasks();
    void cast_rc();

    void list();
    void operator+(std::wstring data);
    void operator-(int id);
    void operator=(int id);

    std::wstring get_error();
    void set_error(error_t err);

    void close(int param = 0);
  };
}

#endif