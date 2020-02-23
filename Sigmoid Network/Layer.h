#pragma once
#include <random>
#include "Neuron.h"

enum class NodeType {
	Input,
	Hidden,
	Output
};

struct Layer {
	Layer(NodeType type, int N, int P) : _type(type), _size(N), _prev_size(P) { setup_neurons(N, P); }

	Neuron& operator[](int n)
	{
		if (n < 0) {
			throw std::invalid_argument("Out of bounds");
		}
		return _neurons[n];
	}

	std::vector<double> ActivateLayer(std::vector<double> _inputs)
	{
		std::cout << "Activating ";
		if (_type == NodeType::Input) {
			std::cout << "Input Layer" << std::endl;
			return _inputs;
		}
		std::cout << "Hidden/Output Layer" << std::endl;
		std::vector<double> _results;
		for (int i = 0; i < _size; i++) {
			std::cout << "  Activating Neuron\n    Inputs = { ";
			for (auto d : _inputs) {
				std::cout << d << " ";
			}
			std::cout << "}\n";
			double result = this->operator[](i).Activate(_inputs);
			std::cout << "    Output = " << result << std::endl << "  }\n";
			_results.push_back(result);
		}
		return _results;
	}

	int _size;
	int _prev_size;
	NodeType _type;
	std::vector<Neuron> _neurons;

	void setup_neurons(int n, int p)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::normal_distribution<double> dis(0, 1);

		for (int i = 0; i < n; i++) {
			std::vector<double> weights;
			for (int i = 0; i < p; i++) {
				weights.push_back(dis(gen));
			}
			_neurons.push_back(Neuron(dis(gen), weights));
		}
	}
};