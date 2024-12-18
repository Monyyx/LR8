#include "functions_1.h"
#include "functions_2.h"
#include <cstdlib>

void Task_1(){
size_t size = 0;
flightInfo* scheldue = new flightInfo[5];
flightInfo** arrStruct = &scheldue;
int choice;
    do {
        DisplayMenuTask();
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice < 0 || choice > 8) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<< "Invalid input. Please enter a valid option (0-8): ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-8): ";
            } else {
                break;
            }
        }
        system("clear");
        switch (choice) {
            case 1:
                system("clear");
                ExplainTask1();
                break;
            case 2:
                system("clear");
                AuthorInfo();
                break;
            case 3:
                system("clear");
                InputArrStruct(scheldue, size);
                break;
            case 4:
                system("clear");
                if(size != 0) OutputInterestingStruct(scheldue, size);
                else std::cout << "First you need to add info about flights!\n";
                break;
            case 5:
                system("clear");
                if (size != 0) OutputArrStruct(scheldue, size);
                else std::cout << "First you need to add info about flights!\n";
                break;
            case 6:
                system("clear");
                if (size != 0) CorrectStruct(scheldue, size);
                else std::cout << "First you need to add info about flights!\n";
                break;
            case 7:
                system("clear");
                DeleteFlightData(arrStruct, size);
                break;
            case 8:
                BinaryFile("task_1.bin", scheldue, size);
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

void Task_2(){
int choice;
    do {
        DisplayMenuTask();
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice < 0 || choice > 3) { //???
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";//???
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";// ???
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
                
                break;
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << '\n';
    } while (choice != 0);
}


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
        system("clear");
        switch (choice) {
            case 1:
                WhatISIt();
                break;
            case 2:
                system("clear");
                Task_1();
                break;
            case 3:
                system("clear");
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