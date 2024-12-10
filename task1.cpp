#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    void displayTask(int index) {
        cout << index + 1 << ". " << description << " - "
             << (completed ? "Completed" : "Pending") << endl;
    }
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void markTaskCompleted(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks[taskIndex].markCompleted();
            cout << "Task '" << tasks[taskIndex].description << "' marked as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
        } else {
            for (int i = 0; i < tasks.size(); ++i) {
                tasks[i].displayTask(i);
            }
        }
    }
};

void displayMenu() {
    cout << "\nTo-Do List Menu:" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. Mark task as completed" << endl;
    cout << "3. View tasks" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    TodoList todoList;
    int choice;

    while (true) {
        displayMenu();
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();  // To ignore any newline characters left in the input buffer

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }

            case 2: {
                todoList.viewTasks();
                int taskIndex;
                cout << "Enter task number to mark as completed: ";
                cin >> taskIndex;
                todoList.markTaskCompleted(taskIndex - 1); // Adjust for 0-based index
                break;
            }

            case 3: {
                todoList.viewTasks();
                break;
            }

            case 4: {
                cout << "Goodbye!" << endl;
                return 0;
            }

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
