#include <shtm.hpp>

void shtm::shtm::cast_tasks() {
  std::wcout << source << std::endl;

  std::wstringstream stream(source);
  std::wstring segment;
  std::vector<std::wstring> segment_list;

  while(std::getline(stream, segment, L';')) {
    std::wcout << segment << std::endl;
    segment_list.push_back(segment);
  }

  for (int i = 0; i < segment_list.size(); i += 2) {
    tasks.push_back(
      {segment_list[i], segment_list[i+1][0] == L'1'}
    );
  }
}

void shtm::shtm::list() {
  bool all_task_done = true;
  for (int i = 0; i < tasks.size(); i++) {
    if (tasks[i].state) {
      std::wcout << " . ";
      all_task_done = false;
    } else
      std::wcout << " x ";
    
    std::wcout << i+1 << L". " << tasks[i].data << std::endl;
  }

  if (tasks.size() == 0) {
    all_task_done = false;
  }
  
  if (all_task_done && error == error_t::EmptyErrorException)
    set_error(error_t::AllTasksDoneException);
}

void shtm::shtm::operator+(std::wstring data) {
  tasks.push_back(
    {data, true}
  );
}

void shtm::shtm::operator-(int id) {
  if (tasks.size() == 0)
    return;
  
  if (id < 0 || id > tasks.size()-1) {
    set_error(error_t::TaskDoesntExistException);
    return;
  }
  tasks.erase(tasks.begin() + id);
}

void shtm::shtm::operator=(int id) {
  if (tasks.size() == 0)
    return;
  
  if (id < 0 || id > tasks.size()-1) {
    set_error(error_t::TaskDoesntExistException);
    return;
  }
  tasks[id].state = !tasks[id].state;
}