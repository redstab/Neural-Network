#pragma once
#include <iostream>
#include <vector>
#include <array>

template<int N>
class Neuron {
public:
	Neuron(double bias, std::array<double, N> weights) : _bias(bias), _weights(weights) {}
	double Activate(std::array<double, N> _inputs)
	{
		std::cout << "Activating " << *this << "\n  INPUT  = { ";
		for (auto i : _inputs) {
			std::cout << i << " ";
		}
		std::cout << "}" << std::endl;
		double sum = 0;
		for (int i = 0; i < N; i++) {
			sum += _weights[i] * _inputs[i];
		}
		sum += _bias;
		return sigmoid(sum);
	}

	double _bias;
	std::array<double, N> _weights;

	double sigmoid(double z)
	{
		return 1 / (1 + exp(-z));
	}
};
template<int N>
std::ostream& operator<<(std::ostream& os, Neuron<N> n)
{
	os << "Neuron<" << N << "> {\n  bias = " << n._bias << "\n  weights = { ";
	for (auto w : n._weights) {
		os << w << " ";
	}
	os << "}";
	return os;
}
