

#include "serialization.hpp"
#include "data.hpp"
#include <iostream>

int main(void)
{
	Data data;

	data.i = 42;
	data.d = 3.14;
	data.str = "Hello, World!";

	std::cout << "Original Data:" << std::endl;
	std::cout << "i: " << data.i << std::endl;
	std::cout << "d: " << data.d << std::endl;
	std::cout << "str: " << data.str << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "\nSerialized Data (raw): " << raw << std::endl;
	
	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "\nDeserialized Data:" << std::endl;
	std::cout << "i: " << deserializedData->i << std::endl;
	std::cout << "d: " << deserializedData->d << std::endl;
	std::cout << "str: " << deserializedData->str << std::endl;

    std::cout << "\nPointer comparison: " << (deserializedData == &data ? "OK" : "FAIL") << "\n";
	return 0;
}
