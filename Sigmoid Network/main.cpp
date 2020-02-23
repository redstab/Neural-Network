#include "Network.h"

int main()
{
	Topology layout;
	layout.input_nodes = 3;
	layout.nodes_per_layer = { 4 };
	layout.output_nodes = 1;
	Network nn(layout);

	std::vector<double> result = nn.PropForward({ 1, 0, 1 });

	std::cout << "\nNeural network result = { ";

	for (auto r : result) {
		std::cout << r << " ";
	}

	std::cout << "}" << std::endl;

	//Layer lay(NodeType::Hidden, 3, 5);
	//std::cout << lay;
	//for (auto i : lay.ActivateLayer({ 1,1,1,1,1 })) {
	//	std::cout << i << " ";
	//}
}