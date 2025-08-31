#include "ConsoleUI.h"
#include "functions.h"
#include <limits>

void ConsoleUI::displayMenu() {
    std::cout << "-----------------To-Do List Menu START-----------------------" << std::endl;
    std::cout << "\t1. Add Task" << std::endl;
    std::cout << "\t2. Remove Task" << std::endl;
    std::cout << "\t3. Edit Task" << std::endl;
    std::cout << "\t4. View Tasks" << std::endl;
    std::cout << "\t5. Change Mark On Task" << std::endl;
    std::cout << "\t6. Exit" << std::endl;
    std::cout << "-----------------To-Do List Menu END-----------------------" << std::endl;
}

void ConsoleUI::handleUserInput()
{
    int choice;
    while (true) {
        system("cls");
        displayMenu();
        std::cout << "Enter your choice: ";

        try {
            choice = getIntegerInput();
        } catch (const std::invalid_argument& e) {
            std::cout<< e.what() << std::endl;
            continue;
        }
        
        switch (choice) {
            case 1: {
                system("cls");
                addTask();
                requestEnter();
                break;
            }
            case 2: {
                system("cls");
                removeTask();
                requestEnter();
                break;
            }
            case 3: {
                system("cls");
                editTask();
                requestEnter();
                break;
            }
            case 4: {
                system("cls");
                displayTasks();
                requestEnter();
                break;
            }
            case 5:
                system("cls");
                changeMarkTask();
                requestEnter();
                break;
            case 6:
                std::cout << "Exiting..." << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                requestEnter();
                system("cls");
        }
    }
}

void ConsoleUI::displayTasks() {
    std::cout << "--------------------View Tasks--------------------\n" << std::endl;
    std::vector<Task> tasks = todoList.getTasks();
    for (size_t i = 0; i < tasks.size(); i++) {
        std::cout << i << ". " << (tasks[i].isCompleted() ? "[X] " : "[ ] ") << tasks[i].getName() << " - " << tasks[i].getDescription() << std::endl;
    }
    std::cin.ignore();
}

void ConsoleUI::addTask() {
    std::string name, description;
    std::cout << "--------------------Add New Task--------------------\n" << std::endl;
    std::cout << "Enter task name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);
    Task newTask(name, description);
    todoList.addTask(newTask);
}

void ConsoleUI::removeTask() {
    std::cout << "--------------------Remove Task--------------------\n" << std::endl;
    std::cout << "Enter task index to remove: ";
    
    int index;
    try {
        index = getIntegerInput();
    } catch (const std::invalid_argument& e) {
        std::cout<< e.what() << std::endl;
        return;
    }

    todoList.removeTask(index);
    std::cin.ignore();
}

void ConsoleUI::editTask() {
    std::cout << "--------------------Edit Task--------------------\n" << std::endl;
    std::string newName, newDescription;
    std::cout << "Enter task index to edit: ";
    
    int index;
    try {
        index = getIntegerInput();
    } catch (const std::invalid_argument& e) {
        std::cout<< e.what() << std::endl;
        return;
    }

    std::cin.ignore();

    if (index < 0 || index >= todoList.getTasks().size()) {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    newName = todoList.getTasks()[index].getName();
    newDescription = todoList.getTasks()[index].getDescription();

    std::cout << "Current name:  \"" << newName << "\"  DO YOU WANT CHANGE IT? Enter '1' to change or any else key to not" << std::endl;

    if (std::cin.get() == '1') {
        std::cout << "Enter new task name: ";
        std::getline(std::cin, newName);
    }
    
    std::cout << "Current description:  \"" << newDescription << "\"  DO YOU WANT CHANGE IT? Enter '1' to change or any else key to not" << std::endl;
    std::cin.ignore();
    if (std::cin.get() == '1') {
        std::cout << "Enter new task description: ";
        std::getline(std::cin, newDescription);
    }
    todoList.editTask(index, newName, newDescription);
}

void ConsoleUI::changeMarkTask() {
    std::cout << "--------------------Change State Of Task--------------------\n" << std::endl;
    std::cout << "Enter task index to change mark: ";

    int index;
    try {
        index = getIntegerInput();
    } catch (const std::invalid_argument& e) {
        std::cout<< e.what() << std::endl;
        return;
    }

    std::vector<Task> tasks = todoList.getTasks();
    if (index >= 0 && index < tasks.size()) {
        todoList.changeMarkTask(index);
    } else {
        std::cout << "Invalid index" << std::endl;
    }
    std::cin.ignore();
}