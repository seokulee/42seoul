#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data *ds = new Data;
    ds->n = 42;
    ds->s1 = "Hello, World!";
    ds->s2 = "Goodbye, World!";

    std::cout << "---------------------------" << std::endl;
    std::cout << "ds = " << ds << std::endl;
    std::cout << "ds->n = " << ds->n << std::endl;
    std::cout << "ds->s1 = " << ds->s1 << std::endl;
    std::cout << "ds->s2 = " << ds->s2 << std::endl;
    std::cout << "---------------------------" << std::endl;

    std::cout << "Serializer::serialize(ds)" << std::endl;
    uintptr_t raw = Serializer::serialize(ds);
    std::cout << "raw = " << raw << std::endl;

    std::cout << "Serializer::deserialize(raw)" << std::endl;
    Data *ds2 = Serializer::deserialize(raw);
    std::cout << "ds2 = " << ds2 << std::endl;

    std::cout << "---------------------------" << std::endl;
    std::cout << "ds2->n = " << ds2->n << std::endl;
    std::cout << "ds2->s1 = " << ds2->s1 << std::endl;
    std::cout << "ds2->s2 = " << ds2->s2 << std::endl;
    std::cout << "---------------------------" << std::endl;

    delete ds;
    return 0;
}
