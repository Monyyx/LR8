#include "functions_2.h"

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

void InputArrStruct(BusInfo*& input, size_t& size) {
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
    InputArrStruct(input, size);
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

void OutputArrStruct(BusInfo* my_struct, size_t size) {
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

//добавить поиск по двум параметрам 1 - у город, 2 - время прибытия (сначала отсортить по городу а потом проветь время)

void DeleteFlightData(BusInfo** my_struct, size_t& size) {
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