#include "functions_1.h"
// 1 -- ввод значений в структру
    /* основная функция - принять структура и сделать проверку на ввод там где int, double
    -- если не знает сколько стурктур то принимать по 1 и спрашивать "хотит 
// 2 -- вывод всех структур *пусть будет переменная которая зранит количество введенных
// 3 -- дополнить (в 1 уже есть такой функционал)
// 4 -- вывод номер рейсов которыые выдетаю(куда пользователь скажет) quick sort to upper (для 1 буквы города куда летит)
// 5 -- менять что-то в структуре(может и удалять)
// 6 --  quick sort to upper(для номеров рейсов) из 4 задания 

/*functions
1 + inputSuct
2 + outputStruct
3 + outputFlightNumber
    + 3.1  quick sort to upper(для 1 буквы города куда летит)
4 - correctingStruct
    4.1 deletetruct
*/
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

void InputArrStruct(FlightInfo*& input, size_t& size) {
    char choice;
    size_t capacity;
    std::cout << "Would you like to input data about a flight? (1 - yes, 0 - no): ";
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
        FlightInfo* new_input = new FlightInfo[capacity];
        std::copy(input, input + size, new_input);
        delete[] input;
        input = new_input;
    }
    std::cout << "Input data for flight " << (size + 1) << ":\n";
    input[size].InputStruct();
    ++size;
    InputArrStruct(input, size);
}

void OutputStruct(const FlightInfo& my_struct, size_t index) {
    std::cout << "Output data for flight " << index + 1 << ":\n";
    if (my_struct.is_code_) {
        std::cout << "Code of the airplane: " << my_struct.add_info_.airplane_type_code_ << '\n';
    } else {
        std::cout << "Airplane: " << my_struct.add_info_.airplane_type_ << '\n';
    }
    std::cout << "Number of the flight: " << my_struct.flight_number_ << '\n';
    std::cout << "Class of the flight: " << my_struct.class_of_flight_ << '\n';
    std::cout << "Your destination: " << my_struct.destination_ << '\n';
    std::cout << "Flight arrival time: " << my_struct.arrival_time_ << '\n' << '\n';
}

bool CompareByDestinationIgnoreCase(const FlightInfo& a, const FlightInfo& b) {
    std::string destination_a = a.destination_;
    std::string destination_b = b.destination_;
    std::transform(destination_a.begin(), destination_a.end(), destination_a.begin(), ::tolower);
    std::transform(destination_b.begin(), destination_b.end(), destination_b.begin(), ::tolower);

    return destination_a < destination_b;
}

void OutputArrStruct(FlightInfo* my_struct, size_t size) {
    char choice;
    std::cout << "Would you like to get sorting data about a flights? (1 - yes, 0 - no): ";
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
        std::cout << "Sorting by city names data about flights: \n";
        for (size_t i = 0; i < size; ++i) {
            OutputStruct(my_struct[i], i);
        }
    } else {
        std::cout << "Not sorting data about flights :/n";
        for (size_t i = 0; i < size; ++i) {
        OutputStruct(my_struct[i], i);
        }
    }
}

void OutputInterestingStruct(FlightInfo* my_struct, size_t size) {
    std::string interest_city;
    std::cout << "Enter the destination point of interesting flight: ";
    std::cin >> interest_city;
    std::transform(interest_city.begin(), interest_city.end(), interest_city.begin(), ::tolower);
    size_t count = 1;
    std::sort(my_struct, my_struct + size, CompareByDestinationIgnoreCase);

    for (size_t i = 0; i < size; ++i) {
        std::string destination_lower = my_struct[i].destination_;
        std::transform(destination_lower.begin(), destination_lower.end(), destination_lower.begin(), ::tolower);
        if (destination_lower == interest_city) {
            OutputStruct(my_struct[i], count);
            ++count;
        }
    }
    if (count == 1) { 
        std::cout << "No airplanes arriving at " << interest_city << ".\n";
    }
}

void DeleteFlightData(FlightInfo** my_struct, size_t& size) {
    std::cout << "Your sure that you want delete all data about flights& (1 - yes, 0 - no): ";
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
        *my_struct = new flightInfo[5];
    } 
}

// сделать корректировку структуры в бинарном 
// в бинарном фацйле хранить все стркутуры  
// делать созраненя в бинарный файл

void AuthorInfo() {
    std::cout << "Completed by: Matvei Khadorik\n";
}

void ExplainTask2() {
    std::cout << "You are given a schedule of flight departures for an airport.\n"
              << "For each flight, the schedule includes its number, the type of airplane, the destination point,\n"
              << "and the departure time. Your task is to display all flight numbers departing to a specified\n"
              << "destination point. The results should be sorted in ascending order using the quicksort algorithm.\n";
}

void DisplayMenuTask() { 
    std::cout << "--- Context menu ---\n"
              << "1. Task description\n"
              << "2. Author information\n"
              << "3. Input info about flight\n"
              << "4. Find flights to town\n"
              << "5. Output all information\n"
              << "6. Delete all information\n"
              << "0. Exit\n"
              << "Choose an option: ";
}