#pragma once
#include <iostream>
#include <vector>
#include <array>

template<int N>
class Perceptron {
public:
	Perceptron(int threshold, std::array<int, N> weights) : _threshold(threshold), _weights(weights) {}
	int Calculate(std::array<int, N> _inputs)
	{
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += _weights[i] * _inputs[i];
		}
		std::cout << "\n\n  Weighted Sum: " << sum << std::endl;
		return sum > _threshold;
	}
private:
	int _threshold;
	std::array<int, N> _weights;
};
