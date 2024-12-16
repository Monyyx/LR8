#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

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
    void InputStruct() {
        std::cout << "Enter 1 or 2 to input (airplane type) / (airplane code): ";
        InputUnion();
        std::cout << "Enter flight number: ";
        std::cin >> flight_number_;
        std::cout << "Enter class of your flight (first, business, etc.): ";
        std::cin >> class_of_flight_;
        std::cout << "Enter your plane destination: ";
        std::cin >> destination_;
        std::cout << "Enter arrival time (hh:mm): ";
        std::cin.ignore();
        InputTime(arrival_time_);
    }
} flightInfo;

void InputArrStruct(FlightInfo*& input, size_t& size);

void OutputArrStruct(FlightInfo* my_struct, size_t size);

void OutputInterestingStruct(FlightInfo* my_struct, size_t size);

void DeleteFlightData(FlightInfo** my_struct, size_t& size);

void AuthorInfo();

void ExplainTask1();

void DisplayMenuTask();