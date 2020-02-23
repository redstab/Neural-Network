#include "Network.h"

Network::Network(Topology network_layout) : _layout(network_layout)
{
	_layers.push_back(Layer(NodeType::Input, network_layout.input_nodes, network_layout.input_nodes));
	for (int i = 0; i < network_layout.nodes_per_layer.size(); i++) {
		_layers.push_back(Layer(NodeType::Hidden, network_layout.nodes_per_layer[i], _layers[i]._size));
	}
	_layers.push_back(Layer(NodeType::Output, network_layout.output_nodes, _layers.back()._size));
}

std::vector<double> Network::PropForward(std::vector<double> input)
{
	std::vector<double> result = input;
	for (auto layer : _layers) {
		result = layer.ActivateLayer(result);
	}
	return result;
}
