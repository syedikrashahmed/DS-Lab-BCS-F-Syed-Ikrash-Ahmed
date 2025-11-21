/*Task 7 – Application of Stack & Queue (Advanced)
Design a job scheduling system where:
1. Processes (with IDs & priorities) arrive and are stored in a queue.
2. Execution order is determined using a stack (LIFO execution of high-priority tasks).
3. Demonstrate how both queue (arrival order) and stack (execution handling) are
combined.*/
#include <iostream>
using namespace std;

struct Task {
    int taskID;
    int urgency;
    Task* nextTask;
    Task(int tid, int urg) : taskID(tid), urgency(urg), nextTask(nullptr) {}
};

class TaskList {
private:
    Task* first;
    Task* last;
public:
    TaskList() : first(nullptr), last(nullptr) {}
    void insertTask(int tid, int urg) {
        Task* newTask = new Task(tid, urg);
        if (last == nullptr) {
            first = last = newTask;
        } else {
            last->nextTask = newTask;
            last = newTask;
        }
        cout << "Added task " << tid << " with urgency " << urg << endl;
    }
    
    bool listEmpty() {
        return first == nullptr;
    }
    
    Task* removeFirstTask() {
        if (listEmpty()) return nullptr;
        Task* temp = first;
        first = first->nextTask;
        if (first == nullptr) last = nullptr;
        temp->nextTask = nullptr;
        return temp;
    }
    
    void displayTasks() {
        if (listEmpty()) {
            cout << "No tasks in list";
            return;
        }
        
        Task* current = first;
        cout << "Current tasks: ";
        while (current != nullptr) {
            cout << "T" << current->taskID << "(U" << current->urgency << ") ";
            current = current->nextTask;
        }
        cout << endl;
    }
};

class PriorityContainer {
private:
    Task* topElement;
public:
    PriorityContainer() : topElement(nullptr) {}
    void addToContainer(Task* task) {
        if (task == nullptr) return;
        
        if (topElement == nullptr || task->urgency > topElement->urgency) {
            task->nextTask = topElement;
            topElement = task;
        } else {
            Task* current = topElement;
            while (current->nextTask != nullptr && 
                   current->nextTask->urgency >= task->urgency) {
                current = current->nextTask;
            }
            task->nextTask = current->nextTask;
            current->nextTask = task;
        }
        cout << "Task " << task->taskID << " added to container\n";
    }
    
    Task* removeTopTask() {
        if (topElement == nullptr) return nullptr;
        Task* temp = topElement;
        topElement = topElement->nextTask;
        temp->nextTask = nullptr;
        return temp;
    }
    
    bool containerEmpty() { 
        return topElement == nullptr; 
    }
    
    void showContainer() {
        if (containerEmpty()) {
            cout << "Container is empty" << endl;
            return;
        }
        
        Task* current = topElement;
        cout << "Tasks in container (by priority): ";
        while (current != nullptr) {
            cout << "T" << current->taskID << "(U" << current->urgency << ") ";
            current = current->nextTask;
        }
        cout << endl;
    }
};

class TaskManager {
private:
    TaskList incomingTasks;
    PriorityContainer processingContainer;
    
public:
    void receiveNewTask(int tid, int urg) {
        incomingTasks.insertTask(tid, urg);
    }
    
    void transferTasks() {
        cout << "Transferring tasks" << endl;
        while (!incomingTasks.listEmpty()) {
            Task* task = incomingTasks.removeFirstTask();
            processingContainer.addToContainer(task);
        }
    }
    
    void processTasks() {
        cout << "Processing tasks" << endl;
        while (!processingContainer.containerEmpty()) {
            Task* task = processingContainer.removeTopTask();
            cout << "processing: task " << task->taskID << " with urgency " << task->urgency << endl;
            delete task;
        }
    }
    
    void showCurrentStatus() {
        cout << "status:" << endl;
        incomingTasks.displayTasks();
        processingContainer.showContainer();
        cout << endl;
    }
};

int main() {
    TaskManager systemManager;
    systemManager.receiveNewTask(101, 2);
    systemManager.receiveNewTask(102, 1);
    systemManager.receiveNewTask(103, 3);
    systemManager.receiveNewTask(104, 2);
    systemManager.showCurrentStatus();
    systemManager.transferTasks();
    systemManager.showCurrentStatus();
    systemManager.processTasks();
    systemManager.showCurrentStatus();
    systemManager.receiveNewTask(201, 5);
    systemManager.receiveNewTask(202, 1);
    systemManager.receiveNewTask(203, 4);
    systemManager.showCurrentStatus();
    systemManager.transferTasks();
    systemManager.showCurrentStatus();
    systemManager.processTasks();
}
