#ifndef GRAPH_REPRESENTATION_H
#define GRAPH_REPRESENTATION_H

#include <string>
#include <vector>
#include <sstream>

struct IGraph
{
	virtual void extractNodes() = 0;
	virtual ~IGraph() = default;
};

class Node : public IGraph
{
	int id;
	std::vector<IGraph*> neighbors;
public:
	static std::ostringstream graphNodes;
public:
	Node(int id) :
		id(id), neighbors(0) {}
public:
	void addNode(IGraph* node)
	{
		this->neighbors.push_back(node);
	}
	void extractNodes() override
	{
		Node::graphNodes << this->id;

		Node::graphNodes << std::endl;
		Node::graphNodes << " ";

		for (size_t i = 0; i < this->neighbors.size(); i++)
		{			
			this->neighbors[i]->extractNodes();

			Node::graphNodes << std::endl;
			Node::graphNodes << " ";
		}
	}
};
std::ostringstream Node::graphNodes;

class EndNode : public IGraph
{
	int id;
	std::ostringstream& graphNodes;
public:
	EndNode(int id, std::ostringstream& graphNodes) :
		id(id), graphNodes(graphNodes) {}
public:
	void extractNodes() override
	{
		Node::graphNodes << " ";
		graphNodes << this->id;
	}
};

#endif // !GRAPH_REPRESENTATION_H
