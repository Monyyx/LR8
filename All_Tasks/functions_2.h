#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

/*В справочной автовокзала хранится расписание движения автобусов.
Для каждого рейса указаны его номер, тип автобуса, пункт назначения,
время отправления и прибытия. Вывести информацию о рейсах, которыми
можно воспользоваться для прибытия в пункт назначения раньше
заданного времени.*/

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
} BusInfo;

void InputArrStruct(BusInfo*& input, size_t& size);

void OutputArrStruct(BusInfo* my_struct, size_t size);

void OutputInterestingStruct(BusInfo* my_struct, size_t size);

//func desription in cpp

void DeleteFlightData(BusInfo** my_struct, size_t& size);

void ExplainTask2();

