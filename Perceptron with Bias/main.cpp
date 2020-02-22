#include "Perceptron.h"

int main()
{
	Perceptron<2> NAND(3, { -2, -2 });

	Perceptron<2> NOR(2, { -2, -2 });

	Perceptron<2> AND(-1, { 1, 1 });

	std::cout << "NAND Tests" << std::endl << std::endl;
	std::cout << "  0 NAND 0 = " << NAND.Calculate({ 0,0 }) << std::endl;
	std::cout << "  0 NAND 1 = " << NAND.Calculate({ 0,1 }) << std::endl;
	std::cout << "  1 NAND 0 = " << NAND.Calculate({ 1,0 }) << std::endl;
	std::cout << "  1 NAND 1 = " << NAND.Calculate({ 1,1 }) << std::endl << std::endl;

	std::cout << "NOR Tests" << std::endl << std::endl;
	std::cout << "  0 NOR 0 = " << NOR.Calculate({ 0,0 }) << std::endl;
	std::cout << "  0 NOR 1 = " << NOR.Calculate({ 0,1 }) << std::endl;
	std::cout << "  1 NOR 0 = " << NOR.Calculate({ 1,0 }) << std::endl;
	std::cout << "  1 NOR 1 = " << NOR.Calculate({ 1,1 }) << std::endl << std::endl;

	std::cout << "AND Tests" << std::endl << std::endl;
	std::cout << "  0 AND 0 = " << AND.Calculate({ 0,0 }) << std::endl;
	std::cout << "  0 AND 1 = " << AND.Calculate({ 0,1 }) << std::endl;
	std::cout << "  1 AND 0 = " << AND.Calculate({ 1,0 }) << std::endl;
	std::cout << "  1 AND 1 = " << AND.Calculate({ 1,1 }) << std::endl;
}