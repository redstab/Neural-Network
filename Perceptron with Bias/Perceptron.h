#pragma once
#include <iostream>
#include <vector>
#include <array>

template<int N>
class Perceptron {
public:
	Perceptron(int bias, std::array<int, N> weights) : _bias(bias), _weights(weights) {}
	int Calculate(std::array<int, N> _inputs)
	{
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += _weights[i] * _inputs[i];
		}
		sum += _bias;
		return sum > 0;
	}
private:
	int _bias;
	std::array<int, N> _weights;
};
