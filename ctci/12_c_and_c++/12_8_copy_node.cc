// 12.8 Write a method that takes a pointer to a Node structure as a
// parameter and returns a complete copy of the passed in data structure.
// The Node data structure contains two pointers to other Nodes.
//
// The algorithm will maintain a mapping from a node address in the
// original structure to the corresponding node in the new structure.
// This mapping will allow us to discover previously copied nodes
// during a traditional depth-first traversal of the structure.
// Traversals often mark visited nodes - the mark can take many forms
// and does not necessarily need to be stored in the node.
//
// Thus we have a simple recursive algorithm:

#include <iostream>

typedef map<Node* , Node*> NodeMap;

Node *copy_recursive(Node *curr, NodeMap &nodeMap)
{
	if (curr == nullptr) {
		return nullptr;
	}

	NodeMap::iterator i = nodeMap.find(curr);

	if (i != nodeMap.end()) {
		// we've been here before, return the copy
		return i->second;
	}

	Node *node = new Node;
	nodeMap[curr] = node;	// map current before traversing links
	node->ptr1 = copy_recursive(curr->ptr1, nodeMap);
	node->ptr2 = copy_recursive(curr->ptr2, nodeMap);

	return node;
}

Node *copy_structure(Node *root)
{
	NodeMap nodeMap;	// we will need an empty map

	return copy_recursive(root, nodeMap);
}

int main()
{
	return 0;
}
