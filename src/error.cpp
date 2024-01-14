#include <shtm.hpp>

wstring shtm::get_error() {
  string info = format("shtm:\n  version: %s\n  home_path: %s\n  shtm_rc: %s\n\nusage:\n  +[task] - add task\n  -[task-id] - remove task\n  =[task-id] - toggle task\n  q (or Ctrl + C) - quit shtm\n", SHTM_VERSION, HOME_DIR, SHTM_RC);
  switch (error) {
    case EmptyErrorException:
      return L"";
    
    case AllTasksDoneException:
      return L"- All tasks are done!";
    
    case EmptyInputDataException:
      return L"- No input!";

    case InformationException:
      return wstring(info.begin(), info.end());
    
    case UndefinedCommandException:
      return L"- Unknown command!";
    
    case TaskDoesntExistException:
      return L"- Invalid task ID!";

    default:
      return L"UNDEFINED_SHTM_ERROR";
  }
}

void shtm::shtm::set_error(shtm_error_t err) {
  error = err;
}