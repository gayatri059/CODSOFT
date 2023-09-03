#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to add a task to the to-do list
void addTask(vector<Task>& todoList, const string& description) {
    Task task;
    task.description = description;
    task.completed = false;
    todoList.push_back(task);
    cout << "Task added: " << description << endl;
}

// Function to view the tasks in the to-do list
void viewTasks(const vector<Task>& todoList) {
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < todoList.size(); i++) {
        cout << "[" << (i + 1) << "] ";
        if (todoList[i].completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << todoList[i].description << endl;
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task>& todoList, size_t index) {
    if (index >= 1 && index <= todoList.size()) {
        todoList[index - 1].completed = true;
        cout << "Task marked as completed: " << todoList[index - 1].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

// Function to remove a task from the to-do list
void removeTask(vector<Task>& todoList, size_t index) {
    if (index >= 1 && index <= todoList.size()) {
        cout << "Task removed: " << todoList[index - 1].description << endl;
        todoList.erase(todoList.begin() + index - 1);
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> todoList;
    char choice;

    cout << "Welcome to the To-Do List Manager!" << endl;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                {
                    cin.ignore(); // Clear the newline character from the input buffer
                    cout << "Enter the task description: ";
                    string description;
                    getline(cin, description);
                    addTask(todoList, description);
                    break;
                }
            case '2':
                viewTasks(todoList);
                break;
            case '3':
                {
                    size_t index;
                    cout << "Enter the task number to mark as completed: ";
                    cin >> index;
                    markCompleted(todoList, index);
                    break;
                }
            case '4':
                {
                    size_t index;
                    cout << "Enter the task number to remove: ";
                    cin >> index;
                    removeTask(todoList, index);
                    break;
                }
            case '5':
                cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}
