#pragma once
#include "Topology.h"
#include "Layer.h"

class Network {
public:
	Network(Topology network_layout);

	std::vector<double> PropForward(std::vector<double> input);

private:
	Topology _layout;
	std::vector<Layer> _layers;
};