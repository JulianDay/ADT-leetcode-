#pragma once
template<typename T>
class BinaryNode
{
public:
	BinaryNode(const T &e):element(e), left(nullptr),right(nullptr){}
	BinaryNode(const T& e, BinaryNode* l, BinaryNode* r) :element(e), left(l), right(r) {}
	T element;			// data
	BinaryNode<T>* left;		// left child
	BinaryNode<T>* right;		// right child
};