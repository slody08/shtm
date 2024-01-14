#include <shtm.hpp>
#include <functions.hpp>

int main() {
  shtm tm;
  tm.init();

  if (!tm.load()) {
    tm.save();
  }

  tm.cast_tasks();

  tm.add_function(AddTask, add_task);
  tm.add_function(RemoveTask, remove_task);
  tm.add_function(ToggleTask, toggle_task);
  tm.add_function(Quit, on_quit);
  tm.add_function(HelpMenu, help);

  tm.mainloop();

  return 0;
}