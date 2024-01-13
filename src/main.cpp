#include <shtm.hpp>

shtm::shtm tm;

void tmclose(int param) {
  tm.close();
}

int main() {
  setlocale(LC_CTYPE, "");
  signal(SIGINT, tmclose);

  if (!tm.load()) {
    tm.save();
  }

  tm.cast_tasks();

  std::wstring input_buffer;

  while (true) {
    shtm::clear();
    shtm::move(0, 0);
    tm.list();
    shtm::move(0, tm.height-1);

    std::wcout << " shtm\n : ";
    getline(std::wcin, input_buffer);

    int id = 0;

    switch (input_buffer[0]) {
      case L'+':
        input_buffer.erase(input_buffer.begin());
        tm +input_buffer;
        break;
      
      case L'-':
        input_buffer.erase(input_buffer.begin());
        id = std::stoi(input_buffer) - 1;
        tm -id;
        break;
      
      case L'=':
        input_buffer.erase(input_buffer.begin());
        id = std::stoi(input_buffer) - 1;
        tm =id;
        break;
      
      case L'q':
        tm.close();
        break;

      default:
        break;
    }
    input_buffer = L"";
  }
}