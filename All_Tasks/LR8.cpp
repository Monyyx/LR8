#include "functions_1.h"
#include "functions_2.h"


void Task_1(){
size_t size = 0;
flightInfo* scheldue = new flightInfo[5];
int choice;
    do {
        DisplayMenuTask();
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice < 0 || choice > 5) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";
            } else {
                break;
            }
        }
        switch (choice) {
            case 1:
                ExplainTask1();
                break;
            case 2:
                AuthorInfo();
                break;
            case 3:
                InputArrStruct(scheldue, size);
                break;
            case 4:
                if(size != 0) OutputInterestingStruct(scheldue, size);
                else std::cout << "First you need to add info about flights!/n";
                break;
            case 5:
                if (size != 0) OutputArrStruct(scheldue, size);
                else std::cout << "First you need to add info about flights!/n";
                break;
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << '\n';
    } while (choice != 0);

    delete[] scheldue;
}


/*
void Task_2(){
int choice;
    do {
        DisplayMenuTask();
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice < 0 || choice > 3) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";
            } else {
                break;
            }
        }
        switch (choice) {
            case 1:
                ExplainTask2();
                break;
            case 2:
                AuthorInfo();
                break;
            case 3:
                InputValues2();
                break;
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << '\n';
    } while (choice != 0);
}*/


void DisplayMenu() {
    std::cout << "--- Context menu ---\n"
              << "1. Here you can check the whole\n"
              << "2. Go to task-1\n"
              << "3. Go to task-2\n"
              << "0. Exit\n"
              << "Choose an option: ";
}

void WhatISIt() {
    std::cout << "Here you can check the whole LR8.\n";
}

int main() {
    
    int choice;
    do {
        DisplayMenu();
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice < 0 || choice > 6) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-6): ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-6): ";
            } else {
                break;
            }
        }
        switch (choice) {
            case 1:
                WhatISIt();
                break;
                case 2:
                //Task_1();
                break;
                case 3:
                //Task_2();
                break;
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << '\n';
    } while (choice != 0);

    return 0;
}