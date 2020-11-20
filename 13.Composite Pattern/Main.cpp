#include <iostream>

#include "GraphRepresentation.h"

int main()
{
	Node* one = new Node(1);
	Node* two = new Node(2);
	Node* three = new Node(3);
	EndNode* four = new EndNode(4, Node::graphNodes);
	EndNode* five = new EndNode(5, Node::graphNodes);
	EndNode* six = new EndNode(6, Node::graphNodes);
	EndNode* seven = new EndNode(7, Node::graphNodes);

	one->addNode(two);
	one->addNode(three);

	two->addNode(four);
	two->addNode(five);

	three->addNode(six);
	three->addNode(seven);

	one->extractNodes();
	std::cout << Node::graphNodes.str();

	delete seven;
	delete six;
	delete five;
	delete four;
	delete three;
	delete two;
	delete one;

	return 0;
}
