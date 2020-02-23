#pragma once
#include <iostream>
#include <vector>
#include <array>

class Neuron {
public:

	Neuron(double bias, std::vector<double> weights) : _bias(bias), _weights(weights) {}
	double Activate(std::vector<double> _inputs)
	{
		if (_inputs.size() != _weights.size()) {
			throw std::invalid_argument("Invalid input, sizes does not match");
		}

		//std::cout << "Activating " << *this << "\n  INPUT  = { ";
		//for (auto i : _inputs) {
		//	std::cout << i << " ";
		//}
		//std::cout << "}" << std::endl;
		double sum = 0;
		for (int i = 0; i < _inputs.size(); i++) {
			sum += _weights[i] * _inputs[i];
		}
		sum += _bias;
		return sigmoid(sum);
	}

	double _bias;
	std::vector<double> _weights;

	double sigmoid(double z)
	{
		return 1 / (1 + exp(-z));
	}
};

inline std::ostream& operator<<(std::ostream& os, Neuron const &n)
{
	os << "  Neuron<" << n._weights.size() << "> {\n    bias = " << n._bias << "\n    weights = { ";
	for (auto w : n._weights) {
		os << w << " ";
	}
	os << "}\n  }\n\n";
	return os;
}