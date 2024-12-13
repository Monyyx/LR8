#include "functions_1.h"
// 1 -- ввод значений в структру
    /* основная функция - принять структура и сделать проверку на ввод там где int, double
    1.1 -- ввод заранее заданнаго количества стурктур(в начале спросить
    вы сколько полетов вы хотите занести в структуру и потом вводитьБ после 
    последней итерации спросить ввод закончен и предложить опять вводить )
    1.2 --если не знает сколько стурктур то принимать по 1 и спрашивать "хотите продолжить?"
    ***1.3 воодить пока не найдем структуру с определенным параметром
    */
// 2 -- вывод всех структур *пусть будет переменная которая зранит количество введенных
// 3 -- дополнить (в 1 уже есть такой функционал)
// 4 -- вывод номер рейсов которыые выдетаю(куда пользователь скажет) quick sort to upper (для 1 буквы города куда летит)
// 5 -- менять что-то в структуре(может и удалять)
// 6 --  quick sort to upper(для номеров рейсов) из 4 задания 


/*functions
1 + inputStruct
2 + outputStruct
3 - outputFlightNumber
    3.1  quick sort to upper(для 1 буквы города куда летит)
4 - correctingStruct
    4.1 deleteStruct
*/

/*
size_t capacity = 20;
    flight* input = new flight[capacity];
    size_t size = 0;

        if (size >= capacity - 1) {
            capacity *= 2;
            flight* newInput = new flight[capacity];
            std::copy(input, input+size, newInput);
            delete[] input;
            input = newInput;
*/

#include <iostream>
#include <limits>
#include <string>

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

    void InputCheck(auto &number) {
        while (true) {
            std::cin >> number;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid number: ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid number: ";
            } else {
                break;
            }
        }
    }

    bool IsTime(const std::string &time) {
        if (time.length() != 5 || time[2] != ':') return false; 
        int hour = std::stoi(time.substr(0, 2)); 
        int minute = std::stoi(time.substr(3, 2)); 
        return (hour >= 0 && hour <= 24) && (minute >= 0 && minute < 60); 
    }

    void InputTime(std::string &time) {
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

    void InputStruct() {
        std::cout << "Enter 1 or 2 to input (airplane type) / (airplane code): ";
        InputUnion();
        std::cout << "Enter flight number: ";
        std::cin >> flight_number_;
        std::cout << "Enter class of your flight(first, business etc.): ";
        std::cin >> class_of_flight_;
        std::cout << "Enter your plane destination: ";
        std::cin >> destination_;
        std::cout << "Enter arrival time(hh:mm): ";
        std::cin.ignore();
        InputTime(arrival_time_);
    }
} flight;


void arrStruct(flight* &input, size_t &size) {
    char choice;
    size_t capacity = 5;
    std::cout << "Would you like to input a structure? 1 - yes, 2 - no: ";
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
    if (choice == '2') {
        return;
    }

    if (size >= capacity - 1) {
        capacity *= 2;
        flight* newInput = new flight[capacity];
        std::copy(input, input + size, newInput);
        delete[] input;
        input = newInput;
    }
    std::cout << "Input data for flight " << (size + 1) << ":\n";
    input[size].InputStruct();
    ++size;
    arrStruct(input, size);
}

void outputStruct(flight* myStruct, size_t size){
    for(size_t i = 0; i < size; ++i){
        std::cout << "Output data for flight  " << i + 1 << ":\n";
        if(myStruct[i].is_code_){
            std::cout << "Code of the airplane: " << myStruct[i].add_info_.airplane_type_code_ << '\n';
        } else{
            std::cout << "Airplane: " << myStruct[i].add_info_.airplane_type_ << '\n';
        }
        std::cout << "Number of the flight :  " << myStruct[i].flight_number_ << '\n';
        std::cout << "Class of the flight: " << myStruct[i].class_of_flight_ << '\n';
        std::cout << "Your destination: " << myStruct[i].destination_ << '\n';
        std::cout << "Flight arrival time: " << myStruct[i].arrival_time_ << '\n' << '\n';
    }
}

int main(){
    size_t size = 0;
    flight* scheldue = new flight[5];
    arrStruct(scheldue, size);
    outputStruct(scheldue, size);
    
    delete[] scheldue;

    return 0;
}