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
// 4 -- вывод номер рейсов которыые выдетаю(куда пользователь скажет) quick sort to upper (для номеров рейсов)
// 5 -- менять что-то в структуре(может и удалять)
// 6 --  quick sort to upper(для номеров рейсов) из 4 задания 


/*functions
1 - inputStruct
2 - outputStruct
3 - outputFlightNumber
    3.1  quick sort to upper(для номеров рейсов)
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

void inputCheck (auto &number){
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

bool isHour(char c1, char c2, char c3, char c4) {// 0(1)
    if(c1 == '2' && c2 == '4') return (c3 == c4 == '0') ? 1 : 0;
    else {
    bool first = ('0' <= c1 && c1 < '2') && ('0' <= c2 && c2 <= '9');
    bool second = (c1 == '2' && ('0' <= c2 && c2 <= '4'));
    return first || second;
    }
}

bool isMinute(char c1, char c2) {// 0(1)
    return ('0' <= c1 && c1 < '6') && ('0' <= c2 && c2 <= '9');
}

void inputTime(std::string &time){
    while (true) {
            std::cin >> time;
            bool hour = isHour(time[0], time[1], time[3], time[4]);
            bool minute = isMinute(time[3], time[4]);
            if (!hour  ||  time[2] != ':'  ||  !minute) {
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

typedef struct flightInfo {
    union{
        double airplaneTypeCode;
        int  flightNumber;
    } addInfo;
    std::string classOfFlight;
    std::string destination; 
    std::string arrivalTime;
} flight; 

void inputStruct(flight &myStruct){
    char choice;
    std::cout << "Enter 1 or 2 to input (flight number) / (airplane code): ";
    while(true){
        std::cin >> choice;
        if (choice == '1'){
        std::cout << "Enter flight number: ";
        inputCheck(myStruct.addInfo.flightNumber);
        break;
    } else if (choice == '2'){
        std::cout << "Enter airplane code: ";
        inputCheck(myStruct.addInfo.airplaneTypeCode);
        break;
    }
    }
    std::cout << "Enter class of your flight(first, business etc.): ";
    std::cin >> myStruct.classOfFlight;
    std::cout << "Enter your plane destination: ";
    std::cin >> myStruct.destination;
    std::cout << "Enter arrival time(hh:mm): ";
    inputTime(myStruct.arrivalTime);
}


int main(){
    /*
    flight test;
    test.classOfFlight = "first";
    test.airplaneTypeCode = 111;
    test.destination = "New York";
    test.arraivalTime = "17:31";
    std::cout << test.flightNumber << " " << test.airplaneTypeCode << "  " << test.destination << " " << test.arraivalTime;
*/
    flight test;
    inputStruct(test);
    std::cout << test.addInfo.flightNumber << '\n' << test.classOfFlight << '\n' << test.destination << '\n' << test.arrivalTime;
    

    return 0;
}