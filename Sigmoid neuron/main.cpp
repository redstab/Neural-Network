#include "Neuron.h"
#include <iostream>
#include <Windows.h>

int main()
{
	Neuron<5> SampleSigmoid(3, { -2,-3, 3, 2, 1});
	std::cout << "  OUTPUT = " << SampleSigmoid.Activate({ 0.4,0.23, 0.5, 1, 0.12 }) << "\n}\n\n";
}