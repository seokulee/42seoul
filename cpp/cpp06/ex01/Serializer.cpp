#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Serializer::Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Serializer::Data*>(raw);
}
