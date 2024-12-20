#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <fstream>

void InputCheck(auto& number);

typedef struct FlightInfo {
    union {
        double airplane_type_code_;
        long long airplane_type_;
    } add_info_;
    
    bool is_code_;
    long long flight_number_;
    std::string class_of_flight_;
    std::string destination_;
    std::string arrival_time_;

private:
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
            std::cout << "Enter airplane number: ";
            InputCheck(add_info_.airplane_type_);
            is_code_ = false;
        } else {
            std::cout << "Enter airplane code: ";
            InputCheck(add_info_.airplane_type_code_);
            is_code_ = true;
        }
    }

public:
    void EditStructPoles(FlightInfo* my_struct) {
        char choice;
        std::cout << "Would you like to edit this flight data? (1 - yes, 0 - no): ";
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
        std::cout << "1 - Airplane Type / Number\n";
        std::cout << "2 - Flight Number\n";
        std::cout << "3 - Class of Flight\n";
        std::cout << "4 - Destination\n";
        std::cout << "5 - Arrival Time\n";

        size_t field_choice;
        while (true) {
            std::cin >> field_choice;
            if (std::cin.fail() || field_choice < 1 || field_choice > 5) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid field number (1 to 5): ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid field number (1 to 5): ";
            } else {
                break;
            }
        }

        switch (field_choice) {
            case 1:
                std::cout << "Enter 1 to input airplane type code or 2 to input airplane type: ";
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
                    std::cout << "Enter airplane type code: ";
                    InputCheck(my_struct->add_info_.airplane_type_code_);
                    my_struct->is_code_ = true;
                } else {
                    std::cout << "Enter airplane type: ";
                    InputCheck(my_struct->add_info_.airplane_type_);
                    my_struct->is_code_ = false;
                }
                break;
            case 2:
                std::cout << "Enter flight number: ";
                InputCheck(my_struct->flight_number_);
                break;
            case 3:
                std::cout << "Enter class of flight: ";
                std::cin.ignore();
                std::getline(std::cin, my_struct->class_of_flight_);
                break;
            case 4:
                std::cout << "Enter destination: ";
                std::getline(std::cin, my_struct->destination_);
                break;
            case 5:
                std::cout << "Enter arrival time (hh:mm): ";
                my_struct->InputTime(my_struct->arrival_time_);
                break;
            default:
                std::cout << "Invalid choice.\n";
                break;
        }
    }

    void InputStruct() {
        std::cout << "Enter 1 or 2 to input (airplane type) / (airplane code): ";
        InputUnion();
        std::cout << "Enter flight number: ";
        InputCheck(flight_number_);
        std::cout << "Enter class of your flight (first, business, etc.): ";
        std::cin.ignore();
        std::getline(std::cin, class_of_flight_);
        std::cout << "Enter your plane destination: ";
        std::cin.ignore();
        std::getline(std::cin, destination_);
        std::cout << "Enter arrival time (hh:mm): ";
        std::cin.ignore();
        InputTime(arrival_time_);
    }
} flightInfo;

void InputArrStruct(FlightInfo*& input, size_t& size, size_t& capacity);

void OutputArrStruct(FlightInfo* my_struct, size_t size);

void OutputInterestingStruct(FlightInfo* my_struct, size_t size);

void CorrectStruct(flightInfo* my_struct, size_t size);

void DeleteFlightData(FlightInfo** my_struct, size_t& size);

void BinaryFile(const std::string &filename, FlightInfo *&my_struct, size_t &size);

void AuthorInfo();

void ExplainTask1();

void DisplayMenuTask();