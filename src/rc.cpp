#include <shtm.hpp>

std::string shtm::shtm::rc_path() {
  return format("%s/%s", HOME_DIR, SHTM_RC);
}

bool shtm::shtm::load() {
  std::string path = rc_path();
  std::wifstream file(rc_path());
  if (file.fail())
    return false;

  file.imbue(
    std::locale(std::locale(), new std::codecvt_utf8<wchar_t>)
  );
  
  std::wstringstream stream;
  stream << file.rdbuf();

  file.close();

  source = stream.str();
  std::wcout << source << std::endl;

  return true;
}

bool shtm::shtm::save(std::wstring data) {
  std::wofstream file(rc_path());
  if (file.fail())
    return false;

  file.imbue(
    std::locale(std::locale(), new std::codecvt_utf8<wchar_t>)
  );
  
  file << source;
  file.close();

  return true;
}

void shtm::shtm::cast_rc() {
  source = L"";

  for (task_t task : tasks) {
    source.append(task.data + L";");
    if (task.state)
      source += L"1;";
    else
      source += L"0;";
  }
}