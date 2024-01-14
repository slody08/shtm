#include <shtm.hpp>

string shtm::rc_path() {
  return format("{}/{}", HOME_DIR, SHTM_RC);
}

bool shtm::load() {
  string path = rc_path();
  wifstream file(rc_path());
  if (file.fail())
    return false;

  file.imbue(
    locale(locale(), new codecvt_utf8<wchar_t>)
  );
  
  wstringstream stream;
  stream << file.rdbuf();

  file.close();

  source = stream.str();
  wcout << source << endl;

  return true;
}

bool shtm::save(wstring data) {
  wofstream file(rc_path());
  if (file.fail())
    return false;

  file.imbue(
    locale(locale(), new codecvt_utf8<wchar_t>)
  );
  
  file << source;
  file.close();

  return true;
}

void shtm::cast_rc() {
  source = L"";

  for (task_t task : tasks) {
    source.append(task.data + L"\\;");
    if (task.state)
      source += L"1\\;";
    else
      source += L"0\\;";
  }
}