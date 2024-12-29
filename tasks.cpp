#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Define a Task struct to represent each task
struct Task {
    string description;
    bool isCompleted;
};

// Function declarations
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks);
void saveTasksToFile(const vector<Task>& tasks);
void loadTasksFromFile(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    loadTasksFromFile(tasks);

    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // to ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                markTaskCompleted(tasks);
                break;
            case 5:
                saveTasksToFile(tasks);
                cout << "Exiting. Your tasks are saved." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void displayMenu() {
    cout << "\nTo-Do List Menu:\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Mark Task as Completed\n";
    cout << "5. Exit\n";
}

void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter task description: ";
    getline(cin, description);

    Task newTask = {description, false};
    tasks.push_back(newTask);
    cout << "Task added!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\nYour Tasks:\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << (i + 1) << ". " << tasks[i].description;
        if (tasks[i].isCompleted) {
            cout << " [Completed]";
        }
        cout << endl;
    }
}

void deleteTask(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number." << endl;
    } else {
        tasks.erase(tasks.begin() + (index - 1));
        cout << "Task deleted!" << endl;
    }
}

void markTaskCompleted(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number." << endl;
    } else {
        tasks[index - 1].isCompleted = true;
        cout << "Task marked as completed!" << endl;
    }
}

void saveTasksToFile(const vector<Task>& tasks) {
    ofstream outFile("tasks.txt");

    if (!outFile) {
        cerr << "Could not open the file to save tasks!" << endl;
        return;
    }

    for (const auto& task : tasks) {
        outFile << task.description << " | " << task.isCompleted << endl;
    }
}

void loadTasksFromFile(vector<Task>& tasks) {
    ifstream inFile("tasks.txt");
    string description;
    bool isCompleted;

    while (getline(inFile, description)) {
        inFile >> isCompleted;
        inFile.ignore();  // ignore the newline after the bool

        Task task = {description, isCompleted};
        tasks.push_back(task);
    }
}
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Define a Task struct to represent each task
struct Task {
    string description;
    bool isCompleted;
};

// Function declarations
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks);
void saveTasksToFile(const vector<Task>& tasks);
void loadTasksFromFile(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    loadTasksFromFile(tasks);

    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // to ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                markTaskCompleted(tasks);
                break;
            case 5:
                saveTasksToFile(tasks);
                cout << "Exiting. Your tasks are saved." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void displayMenu() {
    cout << "\nTo-Do List Menu:\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Mark Task as Completed\n";
    cout << "5. Exit\n";
}

void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter task description: ";
    getline(cin, description);

    Task newTask = {description, false};
    tasks.push_back(newTask);
    cout << "Task added!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\nYour Tasks:\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << (i + 1) << ". " << tasks[i].description;
        if (tasks[i].isCompleted) {
            cout << " [Completed]";
        }
        cout << endl;
    }
}

void deleteTask(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number." << endl;
    } else {
        tasks.erase(tasks.begin() + (index - 1));
        cout << "Task deleted!" << endl;
    }
}

void markTaskCompleted(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number." << endl;
    } else {
        tasks[index - 1].isCompleted = true;
        cout << "Task marked as completed!" << endl;
    }
}

void saveTasksToFile(const vector<Task>& tasks) {
    ofstream outFile("tasks.txt");

    if (!outFile) {
        cerr << "Could not open the file to save tasks!" << endl;
        return;
    }

    for (const auto& task : tasks) {
        outFile << task.description << " | " << task.isCompleted << endl;
    }
}

void loadTasksFromFile(vector<Task>& tasks) {
    ifstream inFile("tasks.txt");
    string description;
    bool isCompleted;

    while (getline(inFile, description)) {
        inFile >> isCompleted;
        inFile.ignore();  // ignore the newline after the bool

        Task task = {description, isCompleted};
        tasks.push_back(task);
    }
}

