#ifndef BINARY_TREE
#define BINARY_TREE
#include <iostream>

using namespace std;
template <typename T>
struct BinTreeNode
{
	T data;
	BinTreeNode<T> *leftChild, *rightChild;
	BinTreeNode() :leftChild(nullptr), rightChild(nullptr) {}
	BinTreeNode(T x, BinTreeNode<T> *l = nullptr, BinTreeNode<T> *r = nullptr) :data(x), leftChild(l), rightChild(r) {}
};

template <typename T>
class BinaryTree
{
public:
	BinaryTree() :root(nullptr) {}
	BinaryTree(T value) :RefValue(value), root(nullptr) {}
	BinaryTree(BinaryTree<T>& s);
	~BinaryTree();
	bool IsEmpty();
	BinTreeNode<T> *Parent(BinTreeNode<T> *current);
	BinTreeNode<T> *LeftChild(BinTreeNode<T> *current);
	BinTreeNode<T> *RightChild(BinTreeNode<T> *current);
	int Height();
	int Size();
	BinTreeNode<T> *getRoot() const;
	void preOrder(void(*visit)(BinTreeNode<T> *p));
	void inOrder(void(*visit)(BinTreeNode<T> *p));
	void postOrder(void(*visit)(BinTreeNode<T> *p));
	void levelOrder(void(*visit)(BinTreeNode<T> *p));
	int Insert(const T& item);
	BinTreeNode<T> *Find(T& item) const;

protected:
	BinTreeNode<T> *root;
	T RefValue;
	void CreateBinTree(istream& in, BinTreeNode<T>*&subTree);
	bool Insert(BinTreeNode<T>* &subTree, const T& x);
	void destroy(BinTreeNode<T> *subTree);
	bool Find(BinTreeNode<T> *subTree, const T& x) const;
	BinTreeNode<T> *Copy(BinTreeNode<T> *orignode);
	int Height(BinTreeNode<T> *subTree);
	int Size(BinTreeNode<T> *subTree);
	BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current);
	BinTreeNode<T> *Find(BinTreeNode<T> *subTree, const T& x) const;
	void Traverse(BinTreeNode<T> *subTree, ostream& out);
	void preOrder(BinTreeNode<T> &subTree, void(*visit)(BinTreeNode<T> *p));
	void inOrder(BinTreeNode<T> &subTree, void(*visit)(BinTreeNode<T> *p));
	void postOrder(BinTreeNode<T> &subTree, void(*visit)(BinTreeNode<T> *p));
	friend istream& operator >> (istream& in, BinaryTree<T>& Tree);
	friend ostream& operator << (ostream& out, BinaryTree<T>& Tree);



private:

};

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	destroy(root);
}

template <typename T>
bool BinaryTree<T>::IsEmpty()
{
	return (root == nullptr) ? true : false;
}


template <typename T>
BinTreeNode<T>* BinaryTree<T>::Parent(BinTreeNode<T> *current)
{
	return (current == nullptr || root == current) ? nullptr : Parent(root, current);
}


template <typename T>
BinTreeNode<T>* BinaryTree<T>::LeftChild(BinTreeNode<T> *current)
{
	return (current == nullptr) ? nullptr : current->leftChild;
}

template <typename T>
BinTreeNode<T>* BinaryTree<T>::RightChild(BinTreeNode<T> *current)
{
	return (current == nullptr) ? nullptr : current->rightChild;
}

template <typename T>
int BinaryTree<T>::Height()
{
	return Height(root);
}


template <typename T>
int BinaryTree<T>::Size()
{
	return Size(root);
}


template <typename T>
BinTreeNode<T>* BinaryTree<T>::getRoot() const
{
	return root;
}


//œ»–Ú±È¿˙
template <typename T>
void BinaryTree<T>::preOrder(void(*visit)(BinTreeNode<T> *p))
{
	preOrder(root, visit);
}


template <typename T>
void BinaryTree<T>::preOrder(BinTreeNode<T> &subTree, void(*visit)(BinTreeNode<T> *p))
{
	if (subTree != nullptr)
	{
		visit(subTree);
		preOrder(subTree->leftChild, visit);
		preOrder(subTree->rightChild, visit);
	}
}

#endif
