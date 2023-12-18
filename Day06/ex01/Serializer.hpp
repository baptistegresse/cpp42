#pragma once
#include <iostream>
#include <string>
#include <stdint.h>

struct Data {
    int a;
    char b;
    float c;
};

class Serializer {
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        Serializer();
};