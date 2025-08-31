#pragma once
#include "ToDoList.h"

class ConsoleUI {
    private:
    ToDoList todoList;
    public:
    
    void displayMenu(); 

    void handleUserInput();

    void displayTasks();

    void addTask();

    void removeTask();

    void editTask();

    void changeMarkTask();
};