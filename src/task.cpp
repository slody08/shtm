#include <shtm.hpp>

void shtm::cast_tasks() {
  vector<wstring> segment_list = split(source, L"\\;");

  for (int i = 0; i < segment_list.size(); i += 2) {
    tasks.push_back(
      {segment_list[i], segment_list[i+1][0] == L'1'}
    );
  }
}

void shtm::list() {
  bool all_task_done = true;
  for (int i = 0; i < tasks.size(); i++) {
    if (tasks[i].state) {
      wcout << " . ";
      all_task_done = false;
    } else
      wcout << " x ";
    
    wcout << i+1 << L". " << tasks[i].data << endl;
  }

  if (tasks.size() == 0) {
    all_task_done = false;
  }
  
  if (all_task_done && error == EmptyErrorException)
    set_error(AllTasksDoneException);
}

void shtm::operator+(wstring data) {
  tasks.push_back(
    {data, true}
  );
}

void shtm::operator-(int id) {
  if (tasks.size() == 0)
    return;
  
  if (id < 0 || id > tasks.size()-1) {
    set_error(TaskDoesntExistException);
    return;
  }
  tasks.erase(tasks.begin() + id);
}

void shtm::operator=(int id) {
  if (tasks.size() == 0)
    return;
  
  if (id < 0 || id > tasks.size()-1) {
    set_error(TaskDoesntExistException);
    return;
  }
  tasks[id].state = !tasks[id].state;
}