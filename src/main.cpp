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

  std::wstring input_buffer, undef_buffer;

  while (true) {
    shtm::clear();
    shtm::move(0, 0);
    tm.list();
    shtm::move(0, tm.height-1);

    std::wcout << L" shtm " << tm.get_error() << L"\n : ";
    tm.set_error(shtm::error_t::EmptyErrorException);
    getline(std::wcin, input_buffer);

    int id = 0;

    switch (input_buffer[0]) {
      case L'+':
        input_buffer.erase(input_buffer.begin());
        if (input_buffer == L"") {
          tm.set_error(shtm::error_t::EmptyInputDataException);
          break;
        }
        tm +input_buffer;
        break;
      
      case L'-':
        input_buffer.erase(input_buffer.begin());
        if (input_buffer == L"") {
          tm.set_error(shtm::error_t::EmptyInputDataException);
          break;
        }
        id = std::stoi(input_buffer) - 1;
        tm -id;
        break;
      
      case L'=':
        input_buffer.erase(input_buffer.begin());
        if (input_buffer == L"") {
          tm.set_error(shtm::error_t::EmptyInputDataException);
          break;
        }
        id = std::stoi(input_buffer) - 1;
        tm =id;
        break;
      
      case L'q':
        tm.close();
        break;
      
      case L'?':
        tm.set_error(shtm::error_t::InformationException);
        shtm::move(0, 0);
        shtm::clear();
        std::wcout << tm.get_error() << std::endl;
        getline(std::wcin, undef_buffer);
        tm.set_error(shtm::error_t::EmptyErrorException);
        break;

      default:
        tm.set_error(shtm::error_t::UndefinedCommandException);
        break;
    }
    input_buffer = L"";
  }
}