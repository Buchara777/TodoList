#pragma once
#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string name;
    std::string description;
    bool completed;

    Task(std::string name, std::string description): name(name), description(description), completed(false) {}

    void changeMark() {
        completed = !completed;
    }

    void setName(std::string newName) {
        name = newName;
    }

    void setDescription(std::string newDescription) {
        description = newDescription;
    }

    std::string getName() const {
        return name;
    }

    std::string getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }
};


class ToDoList {
    private:
    std::vector<Task> tasks;
    public:
    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    void removeTask(int);

    void editTask(int index, const std::string& newName, const std::string& newDescription);

    void changeMarkTask(int index);

    std::vector<Task> getTasks() const {
        return tasks;
    }

};