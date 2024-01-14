#ifndef prog_funcs
#define prog_funcs

#include <shtm.hpp>

void add_task(shtm *self, wstring buffer) {
  self->operator+(buffer);
}

void remove_task(shtm *self, wstring buffer) {
  if (only_numbers(buffer)) {
    int id = stoi(buffer) - 1;
    self->operator-(id);
  }
}

void toggle_task(shtm *self, wstring buffer) {
  if (only_numbers(buffer)) {
    int id = stoi(buffer) - 1;
    self->operator=(id);
  }
}

void on_quit(shtm *self, wstring buffer) {
  self->close();
}

void help(shtm *self, wstring buffer) {
  wstring undef_buffer;
  self->set_error(InformationException);
  move(0, 0);
  clear();
  wcout << self->get_error() << endl;
  getline(wcin, undef_buffer);
  self->set_error(EmptyErrorException);
}

#endif