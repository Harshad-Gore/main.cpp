#include <iostream>
#include <vector>
#include <string>
#include <limits>

std::vector<std::string> collectTasks()
{
    std::vector<std::string> tasks;

    std::string task;
    char choice;
    do
    {
        std::cout << "Enter your task: ";
        std::getline(std::cin, task);

        if (!task.empty())
        {
            tasks.push_back(task);
            task.clear();
        }
        else
        {
            std::cout << "Task cannot be empty. Please enter a valid task.\n";
        }

        std::cout << "Would you like to enter another task? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return tasks;
}

void displayTasks(const std::vector<std::string> &tasks)
{
    std::cout << "\nYour Tasks:\n";
    for (const auto &task : tasks)
    {
        std::cout << "- " << task << "\n";
    }
}

int main()
{
    std::vector<std::string> tasks = collectTasks();
    displayTasks(tasks);
    return 0;
}