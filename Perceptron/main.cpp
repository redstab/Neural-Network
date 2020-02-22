#include "Perceptron.h"
#include <iostream>
#include <string>

int Input(std::string question)
{
	int result = 0;
	std::cout << question;
	std::cin >> result;
	return result;
}

int InputYN(std::string question)
{
	std::string result;
	std::cout << question;
	std::cin >> result;
	return result == "yes";
}

int main()
{
	/*

		Example of how perceptrons kinda work. From [Neural Networks and Deep Learning] by Michael Nielsen

		Question
			Attend cheese festival ?

		Factors
			1. Is the weather good?
			2. Does your boyfriend or girlfriend want to accompany you?
			3. Is the festival near public transit? (You don’t own a car).

	*/
	std::cout << "Deside wether to attend cheese festival?" << std::endl << std::endl;

	std::cout << "  On a scale from 1 to 10:" << std::endl << std::endl;

	std::array<int, 3> weights = {
		Input("    How much do you value good weather? "),
		Input("    How much do you value boy/girlfriend accompany? "),
		Input("    How much do you value near festival transit? ")
	};

	int threshold = Input("\n    How much does these factors matter to you ? ");

	std::cout << "\n  Answer these question with 'yes' / 'no'" << std::endl << std::endl;

	std::array<int, 3> input = {
		InputYN("    Is the weather good on the festival? "),
		InputYN("    Is your boy/girlfriend accompaning you on the festival? "),
		InputYN("    Does there any public transit near the festival? ")
	};

	Perceptron<3> GotoFestival(threshold, weights);

	int decision = GotoFestival.Calculate(input);

	if (decision) {
		std::cout << "\n\nIt is suggested that you attend the cheese festival" << std::endl;
	}
	else {
		std::cout << "\n\nIt is suggested that you do not attend the cheese festival" << std::endl;
	}

}