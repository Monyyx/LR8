#include <iostream>
typedef struct inner {
    bool x;
    char z;
    int y;
} inner;

#pragma pack(2)
struct T {
    int i;
    short j;
    double k;
    inner in;
} first;

int main(){
    std::cout << sizeof(first);
}