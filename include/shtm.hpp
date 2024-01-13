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

#define VERSION  L"0.2"
#define HOME_DIR getpwuid(getuid())->pw_dir
#define SHTM_RC  ".shtmrc"

namespace shtm {
  /*  Terminal clearing */
  void clear();

  /*  Moves terminal cursor to X, Y
  
    params:
    + x - int
    + y - int
  */
  void move(int x, int y);

  std::string format(std::string f, ...);

  /* Task structure */
  struct task_t {
    std::wstring data;
    bool state;
  };

  /*  Program class */
  class shtm {
  private:
    std::string rc_path();

    std::wstring source;

    std::vector<task_t> tasks;
  
  public:
    /*  Width of the terminal window */
    int width;
    /* Height of the terminal window */
    int height;

    /* Class initializer */
    shtm();

    /* File loading function */
    bool load();
    /* File saving function */
    bool save(std::wstring data = L"");

    void cast_tasks();
    void cast_rc();

    void list();
    void operator+(std::wstring data);
    void operator-(int id);
    void operator=(int id);

    void close(int param = 0);
  };
}

#endif