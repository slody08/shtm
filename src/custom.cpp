#include <shtm.hpp>

void shtm::add_function(token_t token, void (*func)(shtm *, wstring)) {
  function_map[token] = (*func);
}

void shtm::mainloop() {
  set_error(EmptyErrorException);
  wstring input_buffer, buffer;

  while (true) {
    clear();
    move(0, 0);
    list();
    move(0, get_height()-1);

    wcout << L" shtm " << get_error() << L"\n : ";
    set_error(EmptyErrorException);
    getline(wcin, input_buffer);

    buffer = input_buffer;
    buffer.erase(buffer.begin());

    wchar_t *command = const_cast<wchar_t*>(&input_buffer[0]);

    if (!token_table.contains(*command)) {
      set_error(UndefinedCommandException);
      continue;
    }

    token_t token = token_table.at(*command);

    function_map[token](this, buffer);
  }
}