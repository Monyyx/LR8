#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

typedef struct FlightInfo{

} flightInfo;

void DisplayMenuTask();

void AuthorInfo();

void ExplainTask1();

void InputArrStruct(FlightInfo*& input, size_t& size);

void OutputInterestingStruct(FlightInfo* my_struct, size_t size);

void OutputArrStruct(FlightInfo* my_struct, size_t size);
