#include "functions_1.h"
// 1 -- ввод значений в структру
    /* основная функция - принять структура и сделать проверку на ввод там где int, double
    -- если не знает сколько стурктур то принимать по 1 и спрашивать "хотите продолжить?"
    ???***1.3 воодить пока не найдем структуру с определенным параметром
    */
// 2 -- вывод всех структур *пусть будет переменная которая зранит количество введенных
// 3 -- дополнить (в 1 уже есть такой функционал)
// 4 -- вывод номер рейсов которыые выдетаю(куда пользователь скажет) quick sort to upper (для 1 буквы города куда летит)
// 5 -- менять что-то в структуре(может и удалять)
// 6 --  quick sort to upper(для номеров рейсов) из 4 задания 


/*functions
1 + inputStruct
2 + outputStruct
3 + outputFlightNumber
    + 3.1  quick sort to upper(для 1 буквы города куда летит)
4 - correctingStruct
    4.1 deleteStruct
*/


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

typedef struct FlightInfo {// 120 bite
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

    public:
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
} flightInfo;

void arrStruct(flightInfo* &input, size_t &size) {
    char choice;
    size_t capacity = 5;
    std::cout << "Would you like to input a data about flight? (1 - yes, 0 - no): ";
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

    if (size >= capacity - 1) {
        capacity *= 2;
        flightInfo* newInput = new flightInfo[capacity];
        std::copy(input, input + size, newInput);
        delete[] input;
        input = newInput;
    }
    std::cout << "Input data for flight " << (size + 1) << ":\n";
    input[size].InputStruct();
    ++size;
    arrStruct(input, size);
}

void outputStruct(flightInfo myStruct, size_t i){
        std::cout << "Output data for flight  " << i + 1 << ":\n";
        if(myStruct.is_code_){
            std::cout << "Code of the airplane: " << myStruct.add_info_.airplane_type_code_ << '\n';
        } else{
            std::cout << "Airplane: " << myStruct.add_info_.airplane_type_ << '\n';
        }
        std::cout << "Number of the flight :  " << myStruct.flight_number_ << '\n';
        std::cout << "Class of the flight: " << myStruct.class_of_flight_ << '\n';
        std::cout << "Your destination: " << myStruct.destination_ << '\n';
        std::cout << "Flight arrival time: " << myStruct.arrival_time_ << '\n' << '\n';
}

void outpurArrStruct(flightInfo* myStruct, size_t size){
    for(size_t i = 0; i < size; ++i){
        outputStruct(myStruct[i], i);
    }
}

bool compareByDestinationIgnoreRegistr(const FlightInfo &a, const FlightInfo &b) {///
    std::string destinationA = a.destination_;
    std::string destinationB = b.destination_;
    std::transform(destinationA.begin(), destinationA.end(), destinationA.begin(), ::tolower);
    std::transform(destinationB.begin(), destinationB.end(), destinationB.begin(), ::tolower);

    return a.destination_ < b.destination_;
}

void outputInterestingStruct(flightInfo* myStruct, size_t size){
    std::string interstCity;
    std::cout << "Enter the destination point of interesting flight: ";
    std::cin >> interstCity;
    std::transform(interstCity.begin(), interstCity.end(), interstCity.begin(), ::tolower);
    size_t count = 1;
    std::sort(myStruct, myStruct + size, compareByDestinationIgnoreRegistr);

    for(size_t i = 0; i < size; ++i){
        std::string destinationLower = myStruct[i].destination_;
        std::transform(destinationLower.begin(), destinationLower.end(), destinationLower.begin(), ::tolower);
        if (interstCity[0] > myStruct[i].destination_[0]) break;
        else {
            if (destinationLower == interstCity){
                outputStruct(myStruct[i], count);
                ++count;
            }
        }
    }
}

int main(){
    size_t size = 0;
    flightInfo* scheldue = new flightInfo[5];
    arrStruct(scheldue, size);// создание массива структур

    //std::sort(scheldue, scheldue + size, compareByDestination);
    outputInterestingStruct(scheldue, size);

    //outpurArrStruct(scheldue, size);// вывод массива структур 
    
    delete[] scheldue;

    return 0;
}