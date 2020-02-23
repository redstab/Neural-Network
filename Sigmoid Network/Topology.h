#pragma once
#include <vector>

struct Topology {
	int input_nodes;
	int output_nodes;
	std::vector<int> nodes_per_layer;
};