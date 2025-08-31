#include "ToDoList.h"


void ToDoList::removeTask(int index) {
    if (index >= 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index);
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}

void ToDoList::editTask(int index, const std::string& newName, const std::string& newDescription) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].setName(newName);
        tasks[index].setDescription(newDescription);
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}

void ToDoList::changeMarkTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].changeMark();
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}

