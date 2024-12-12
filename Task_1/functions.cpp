//#include "func_1.h"
#include <iostream>
#include <limits>
#include <string>

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


typedef struct flightInform {
    std::string classOfFlight;
    union{
        double airplaneTypeCode;
        int  flightNumber;
    };
    std::string destination; //пункт назначения
    std::string arraivalTime;
} flight; 

int main(){
    flight test;
    test.classOfFlight = "first";
    test.airplaneTypeCode = 111;
    test.destination = "New York";
    test.arraivalTime = "17:31";
    std::cout << test.flightNumber << " " << test.airplaneTypeCode << "  " << test.destination << " " << test.arraivalTime;

    return 0;
}