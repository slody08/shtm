#include <shtm.hpp>

std::wstring shtm::shtm::get_error() {
  std::string info = format("shtm:\n  version: %s\n  home_path: %s\n  shtm_rc: %s\n\nusage:\n  +[task] - add task\n  -[task-id] - remove task\n  =[task-id] - toggle task\n  q (or Ctrl + C) - quit shtm\n", SHTM_VERSION, HOME_DIR, SHTM_RC);
  switch (error) {
    case error_t::EmptyErrorException:
      return L"";
    
    case error_t::AllTasksDoneException:
      return L"- All tasks are done!";
    
    case error_t::EmptyInputDataException:
      return L"- No input!";

    case error_t::InformationException:
      return std::wstring(info.begin(), info.end());
    
    case error_t::UndefinedCommandException:
      return L"- Unknown command!";
    
    case error_t::TaskDoesntExistException:
      return L"- Invalid task ID!";

    default:
      return L"UNDEFINED_SHTM_ERROR";
  }
}

void shtm::shtm::set_error(error_t err) {
  error = err;
}