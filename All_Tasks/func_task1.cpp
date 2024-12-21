#include "functions_1.h"

//functions "helpers" to main functions )
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

bool CompareByDestinationIgnoreCase(const FlightInfo& a, const FlightInfo& b) {
    std::string destination_a = a.destination_;
    std::string destination_b = b.destination_;
    std::transform(destination_a.begin(), destination_a.end(), destination_a.begin(), ::tolower);
    std::transform(destination_b.begin(), destination_b.end(), destination_b.begin(), ::tolower);

    return destination_a < destination_b;
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

//main functions :)
void InputArrStruct(FlightInfo*& input, size_t& size, size_t& capacity) {
    char choice;
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
    InputArrStruct(input, size, capacity);
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
/*
void CorrectStruct(FlightInfo* my_struct, size_t size, const std::string &OutFile) {
    std::cout << "Enter the number of flight that you want to correct: ";
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

    std::ofstream outFile(OutFile, std::ios::binary | std::ios::in | std::ios::out);
    if (!outFile) {
        std::cerr << "Error opening file!" << '\n';
        return;
    }

    // Correct the structure
    my_struct[choice - 1].EditStructPoles(outFile, my_struct[choice - 1], my_struct, choice - 1);

    outFile.close();
}

/*void CorrectStruct(FlightInfo* my_struct, size_t size, const std::string &OutFile){
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
    my_struct[choice - 1].EditStructPoles(&my_struct, choice - 1, OutFile);
}*/

void WriteStringToFileAtPosition(std::fstream &outFile, const std::string &str, std::streampos position) {
    size_t length = str.size();
    outFile.seekp(position);
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(str.c_str(), length);
}

void EditStructInBinaryFile(FlightInfo* flightList, size_t size, const std::string &filename) {
    std::cout << "Enter the number of flight that you want to correct: ";
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > size) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid option (1- " << size << "): ";
        } else if (std::cin.peek() != '\n') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid option (1-" << size << "):";
        } else {
            break;
        }
    }

    // Открываем бинарный файл для чтения и записи
    std::fstream file(filename, std::ios::binary | std::ios::in | std::ios::out);
    if (!file) {
        std::cerr << "Error opening file!" << '\n';
        return;
    }

    FlightInfo &flight = flightList[choice - 1];

    char editChoice;
    std::cout << "Would you like to edit this flight data? (1 - yes, 0 - no): ";
    while (true) {
        std::cin >> editChoice;
        if (std::cin.fail() || (editChoice != '1' && editChoice != '0')) {
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
    if (editChoice == '0') {
        file.close();
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
                InputCheck(flight.add_info_.airplane_type_code_);
                flight.is_code_ = true;
            } else {
                std::cout << "Enter airplane type: ";
                InputCheck(flight.add_info_.airplane_type_);
                flight.is_code_ = false;
            }
            break;
        case 2:
            std::cout << "Enter flight number: ";
            InputCheck(flight.flight_number_);
            break;
        case 3:
            std::cout << "Enter class of flight: ";
            std::cin.ignore();
            std::getline(std::cin, flight.class_of_flight_);
            break;
        case 4:
            std::cout << "Enter destination: ";
            std::cin.ignore();
            std::getline(std::cin, flight.destination_);
            break;
        case 5:
            std::cout << "Enter arrival time (hh:mm): ";
            InputTime(flight.arrival_time_);
            break;
        default:
            std::cout << "Invalid choice.\n";
            file.close();
            return;
    }

    // Вычисление позиции структуры в файле
    std::streampos pos = sizeof(size_t) + (choice - 1) * (sizeof(flight.add_info_) + sizeof(flight.is_code_) + sizeof(flight.flight_number_)
                                                          + flight.class_of_flight_.size() + sizeof(size_t) + flight.destination_.size() + sizeof(size_t)
                                                          + flight.arrival_time_.size() + sizeof(size_t));

    file.seekp(pos);
    file.write(reinterpret_cast<const char*>(&flight.add_info_), sizeof(flight.add_info_));
    file.write(reinterpret_cast<const char*>(&flight.is_code_), sizeof(flight.is_code_));
    file.write(reinterpret_cast<const char*>(&flight.flight_number_), sizeof(flight.flight_number_));
    WriteStringToFileAtPosition(file, flight.class_of_flight_, file.tellp());
    WriteStringToFileAtPosition(file, flight.destination_, file.tellp());
    WriteStringToFileAtPosition(file, flight.arrival_time_, file.tellp());

    file.close();
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

// work with binary files :/
void WriteStringToFile(std::ofstream &outFile, const std::string &str) {
    size_t length = str.size();
    outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outFile.write(str.c_str(), length);
}

void ReadStringFromFile(std::ifstream &inFile, std::string &str) {
    size_t length;
    inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
    str.resize(length);
    inFile.read(&str[0], length);
}

void SaveStructArrayToFile(const std::string &filename, FlightInfo *my_struct, size_t size) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Error!\n";
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (size_t i = 0; i < size; ++i) {
        outFile.write(reinterpret_cast<const char*>(&my_struct[i].add_info_), sizeof(my_struct[i].add_info_));
        outFile.write(reinterpret_cast<const char*>(&my_struct[i].is_code_), sizeof(my_struct[i].is_code_));
        outFile.write(reinterpret_cast<const char*>(&my_struct[i].flight_number_), sizeof(my_struct[i].flight_number_));

        WriteStringToFile(outFile, my_struct[i].class_of_flight_);
        WriteStringToFile(outFile, my_struct[i].destination_);
        WriteStringToFile(outFile, my_struct[i].arrival_time_);
    }

    outFile.close();
    if (!outFile.good()) {
        std::cerr << "Error!\n";
    }
}

void LoadStructArrayFromFile(const std::string &filename, FlightInfo *&my_struct, size_t &size) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error!.\n";
        return;
    }

    inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
    delete[] my_struct;
    my_struct = new FlightInfo[size];

    for (size_t i = 0; i < size; ++i) {
        inFile.read(reinterpret_cast<char*>(&my_struct[i].add_info_), sizeof(my_struct[i].add_info_));
        inFile.read(reinterpret_cast<char*>(&my_struct[i].is_code_), sizeof(my_struct[i].is_code_));
        inFile.read(reinterpret_cast<char*>(&my_struct[i].flight_number_), sizeof(my_struct[i].flight_number_));

        ReadStringFromFile(inFile, my_struct[i].class_of_flight_);
        ReadStringFromFile(inFile, my_struct[i].destination_);
        ReadStringFromFile(inFile, my_struct[i].arrival_time_);
    }

    inFile.close();
    if (!inFile.good()) {
        std::cerr << "Error!\n";
    }
}

void ClearFile(const std::string &filename) {
    std::ofstream outFile(filename, std::ios::binary | std::ios::trunc);
    if (!outFile) {
        std::cerr << "Failed to open file!\n";
        return;
    }
    outFile.close();
}

void BinaryFile(const std::string &filename, FlightInfo *&my_struct, size_t &size) {
    int choice;
    do {
        std::cout << "--- Context menu ---\n"
              << "1. Safe in binary\n"
              << "2. Load from binary\n"
              << "3. Clear binary\n"
              << "0. Exit\n"
              << "Choose an option: ";
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
                system("clear");
                SaveStructArrayToFile(filename, my_struct, size);
                break;
            case 2:
                system("clear");
                LoadStructArrayFromFile(filename, my_struct, size);
                break;
            case 3:
                system("clear");
                ClearFile(filename);
            case 0:
                std::cout << "Exit.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << '\n';
    } while (choice != 0);
}

//context menu
void AuthorInfo() {
    std::cout << "Completed by: Matvei Khadorik\n";
}

void ExplainTask1() {
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
              << "6. Correct flights data\n"
              << "7. Delete all information\n"
              << "8. Work with binary file\n"
              << "0. Exit\n"
              << "Choose an option: ";
}