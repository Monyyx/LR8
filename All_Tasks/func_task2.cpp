#include "functions_2.h"

// functions "helpers" to main functions
void InputCheck(auto& number) {
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

bool IsTime(const std::string& time)  {
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

//main functions :)
void InputArrStruct_2(BusInfo*& input, size_t& size) {
    char choice;
    size_t capacity;
    std::cout << "Would you like to input data to bus scheldue? (1 - yes, 0 - no): ";
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
        BusInfo* new_input = new BusInfo[capacity];
        std::copy(input, input + size, new_input);
        delete[] input;
        input = new_input;
    }
    std::cout << "Input data for flight " << (size + 1) << ":\n";
    input[size].InputStruct();
    ++size;
    InputArrStruct_2(input, size);
}

void OutputStruct(const BusInfo& my_struct, size_t index) {
    std::cout << "Output data for bus ride " << index + 1 << ":\n";
    if (my_struct.is_type_) {
        std::cout << "Type of the bus: " << my_struct.add_info_.bus_type_ << '\n';
    } else {
        std::cout << "Bus number: " << my_struct.add_info_.bus_number_ << '\n';
    }
    std::cout << "Bus destination: " << my_struct.destination_ << '\n';
    std::cout << "Bus arrival time: " << my_struct.arrival_time_ << '\n';
    std::cout << "Bus department time: " << my_struct.departure_time_ << '\n';
}

bool CompareByDestinationIgnoreCase(const BusInfo& a, const BusInfo& b) {
    std::string destination_a = a.destination_;
    std::string destination_b = b.destination_;
    std::transform(destination_a.begin(), destination_a.end(), destination_a.begin(), ::tolower);
    std::transform(destination_b.begin(), destination_b.end(), destination_b.begin(), ::tolower);

    return destination_a < destination_b;
}

void OutputArrStruct_2(BusInfo*& my_struct, size_t size) {
    char choice;
    std::cout << "Would you like to get sorting bus scheldue? (1 - yes, 0 - no): ";
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
    if (choice == '1'){
        std::sort(my_struct, my_struct + size, CompareByDestinationIgnoreCase);
        std::cout << "Sorting by city names scheldue: \n";
        for (size_t i = 0; i < size; ++i) {
            OutputStruct(my_struct[i], i);
        }
    } else {
        std::cout << "Not sorting schelsue: \n";
        for (size_t i = 0; i < size; ++i) {
        OutputStruct(my_struct[i], i);
        }
    }
}

void OutputInterestingStruct_2(BusInfo* my_struct, size_t size) {
    std::string interest_city;
    std::cout << "Enter the destination point of interesting bus: ";
    std::cin >> interest_city;
    std::transform(interest_city.begin(), interest_city.end(), interest_city.begin(), ::tolower);
    std::string target_time;
    std::cout << "Enter the latest depatrment time: ";
            std::cin.ignore();
            InputTime(target_time);

    size_t count = 1;
    std::sort(my_struct, my_struct + size, CompareByDestinationIgnoreCase);

    for (size_t i = 0; i < size; ++i) {
        std::string destination_lower = my_struct[i].destination_;
        std::transform(destination_lower.begin(), destination_lower.end(), destination_lower.begin(), ::tolower);
        if (destination_lower == interest_city) {
            if (CheckArrivDepart(my_struct->departure_time_, target_time)) {
            OutputStruct(my_struct[i], count);
            ++count;
            }
        }
    }

    if (count == 1) { 
        std::cout << "No buses arriving at " << interest_city << " before " << target_time << ".\n"; 
    }
}

// work with text file
void CorrectStruct_2(FlightInfo* my_struct, size_t size){
    std::cout << "Enter the number of flight that you want to correct : ";
    int choice;
    while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice < 0 || choice > size) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0- " << size << "): ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-" << size << "):";
            } else {
                break;
            }
        }
    OutputStruct(my_struct[choice - 1], choice - 1);
    my_struct[choice - 1].EditStructPoles(&my_struct[choice - 1]);
}


// context menu
void DeleteBusData_2(BusInfo** my_struct, size_t& size) {
    std::cout << "Your sure that you want delete sheldue (1 - yes, 0 - no): ";
    char choice;
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
    if(choice == '1')  {
        delete[] *my_struct;
        size = 0;
        *my_struct = new BusInfo[5];
    } 
}

void ExplainTask2() {
    std::cout << "In the reference office of the bus station, there is a schedule of bus routes.\n"
              << "Each route includes its number, the type of bus, the destination point,\n"
              << "departure time, and arrival time. Display information about the routes that\n"
              << "can be used to arrive at the destination point before a given time.\n";
}

void DisplayMenuTask2() { 
    std::cout << "--- Context menu ---\n"
              << "1. Task description\n"
              << "2. Author information\n"
              << "3. Input info about bus\n"
              << "4. Find bus to town\n"
              << "5. Output all information\n"
              << "6. Correct bus data\n"
              << "7. Delete all information\n"
              << "8. Work with text file\n"
              << "0. Exit\n"
              << "Choose an option: ";
}