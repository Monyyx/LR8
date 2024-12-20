#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

void InputCheck(auto& number);


typedef struct BusInfo {
    union {
        double bus_type_;
        long long bus_number_;
    } add_info_;
    bool is_type_;
    std::string destination_;
    std::string arrival_time_;
    std::string departure_time_;

private:
    void InputUnion() {
        char choice;
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || (choice != '1' && choice != '2')) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter '1' or '2': ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter '1' or '2': ";
            } else {
                break;
            }
        }
        if (choice == '1') {
            std::cout << "Enter bus type: ";
            InputCheck(add_info_.bus_type_);
            is_type_ = false;
        } else {
            std::cout << "Enter bus number: ";
            InputCheck(add_info_.bus_number_);
            is_type_ = true;
        }
    }

    bool IsTime(const std::string& time) const {
        if (time.length() != 5 || time[2] != ':') return false;
        int hour = std::stoi(time.substr(0, 2));
        int minute = std::stoi(time.substr(3, 2));
        return (hour >= 0 && hour <= 24) && (minute >= 0 && minute < 60);
    }

    void InputTime(std::string& time) {
        while (true) {
            std::cin >> time;
            if (!IsTime(time)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid time: ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid time: ";
            } else {
                break;
            }
        }
    }

    bool CheckArrivDepart(const std::string arriaval, const std::string department){
        long long timeArrive = (10 * arriaval[4] + arriaval[3]) * 3600 + (10 * arriaval[1] + arriaval[0]) * 60;
        long long timeDepartment = (10 * department[4] + department[3]) * 3600 + (10 * department[1] + department[0]) * 60;
        return (timeDepartment > timeArrive) ? 1 : 0;
    }

public:
    void InputStruct() {
        std::cout << "Enter 1 or 2 to input (bus type) / (bus number): ";
        InputUnion();
        std::cout << "Enter your plane destination: ";
        std::cin >> destination_;
        std::cout << "Enter arrival time (hh:mm): ";
        std::cin.ignore();
        InputTime(arrival_time_);
        std::cout << "Enter departure time (hh:mm): ";
        while(true){
            std::cin.ignore();
            InputTime(departure_time_);
            if(CheckArrivDepart(arrival_time_, departure_time_)) break;
        }
    }

    void EditStructPoles_2(BusInfo* my_struct) {
    if (!my_struct) return;

    char choice;
    std::cout << "Would you like to edit this bus data? (1 - yes, 0 - no): ";
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || (choice != '1' && choice != '0')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter '1' or '0': ";
        } else if (std::cin.peek() != '\n') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter '1' or '0': ";
        } else {
            break;
        }
    }
    if (choice == '0') {
        return;
    }

    std::cout << "Enter the number of the field to edit:\n";
    std::cout << "1 - Bus Type / Number\n";
    std::cout << "2 - Destination\n";
    std::cout << "3 - Arrival Time\n";
    std::cout << "4 - Departure Time\n";

    size_t field_choice;
    while (true) {
        std::cin >> field_choice;
        if (std::cin.fail() || field_choice < 1 || field_choice > 4) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid field number (1 to 4): ";
        } else if (std::cin.peek() != '\n') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid field number (1 to 4): ";
        } else {
            break;
        }
    }

    switch (field_choice) {
        case 1:
            std::cout << "Enter 1 to input bus type or 2 to input bus number: ";
            char type_choice;
            while (true) {
                std::cin >> type_choice;
                if (std::cin.fail() || (type_choice != '1' && type_choice != '2')) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter '1' or '2': ";
                } else if (std::cin.peek() != '\n') {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter '1' or '2': ";
                } else {
                    break;
                }
            }
            if (type_choice == '1') {
                std::cout << "Enter bus type: ";
                InputCheck(my_struct->add_info_.bus_type_);
                my_struct->is_type_ = true;
            } else {
                std::cout << "Enter bus number: ";
                InputCheck(my_struct->add_info_.bus_number_);
                my_struct->is_type_ = false;
            }
            break;
        case 2:
            std::cout << "Enter bus destination: ";
            std::cin >> my_struct->destination_;
            break;
        case 3:
            std::cout << "Enter arrival time (hh:mm): ";
            std::cin.ignore();
            my_struct->InputTime(my_struct->arrival_time_);
            break;
        case 4:
            std::cout << "Enter departure time (hh:mm): ";
            while (true) {
                std::cin.ignore();
                my_struct->InputTime(my_struct->departure_time_);
                if (my_struct->CheckArrivDepart(my_struct->arrival_time_, my_struct->departure_time_)) break;
            }
            break;
        default:
            std::cout << "Invalid choice.\n";
            break;
    }

    std::cout << "Updated bus information:\n";
    OutputStruct(*my_struct);
}
} BusInfo;

void InputArrStruct_2(BusInfo*& input, size_t& size);

void OutputStruct(const BusInfo& my_struct, size_t index);

void OutputArrStruct_2(BusInfo* my_struct, size_t size);

void OutputInterestingStruct_2(BusInfo* my_struct, size_t size);

//func desription in cpp

void DeleteBusData_2(BusInfo** my_struct, size_t& size);

void ExplainTask2();

void DisplayMenuTask2();