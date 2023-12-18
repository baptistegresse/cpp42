#include "Serializer.hpp"

int	main(void)
{
	Data data;

	data.a = 23;
	data.b = 'c';
	data.c = 23.23;

	uintptr_t dataserialize = Serializer::serialize(&data);

	std::cout << dataserialize << std::endl;

	Data *newData = Serializer::deserialize(dataserialize);

	std::cout << newData->a << " " << newData->b << " " << newData->c << std::endl;

	return (0);
}