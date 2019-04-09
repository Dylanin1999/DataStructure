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
	void CreateBinTree(istream& in, BinTreeNode<T>* &subTree);
	bool Insert(BinTreeNode<T>* &subTree, const T& x);
	void destroy(BinTreeNode<T>* &subTree);
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


//先序遍历
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


//中序遍历
template <typename T>
void BinaryTree<T>::inOrder(void(*visit)(BinTreeNode<T> *p))
{
	inOrder(root, visit);
}


template <typename T>
void BinaryTree<T>::inOrder(BinTreeNode<T> &subTree, void(*visit)(BinTreeNode<T> *p))
{
	if (subTree != nullptr)
	{
		inOrder(subTree->leftChild, visit);
		visit(subTree);
		inOrder(subTree->rightChild, visit);
	}
}


//后序遍历
template <typename T>
void BinaryTree<T>::postOrder(void(*visit)(BinTreeNode<T> *p))
{
	postOrder(root, visit);
}


template <typename T>
void BinaryTree<T>::postOrder(BinTreeNode<T> &subTree, void(*visit)(BinTreeNode<T> *p))
{
	if (subTree != nullptr)
	{
		postOrder(subTree->leftChild, visit);
		postOrder(subTree->rightChild, visit);
		visit(subTree);
	}
}

template <typename T>
void BinaryTree<T>::destroy(BinTreeNode<T>* &subTree)
{
	while (subTree!=nullptr)
	{
		destroy(subTree->leftChild);
		destroy(subTree->rightChild);
		destroy(subTree);
	}
}

template <typename T>
void BinaryTree<T>::CreateBinTree(istream& in, BinTreeNode<T>* &subTree)
{

}


template <typename T>
BinTreeNode<T> *BinaryTree<T>::Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current)
{
	if (subTree == nullptr)
	{
		return nullptr;
	}
	if (subTree->leftChild == current || subTree->rightChild == current)
	{
		return subTree;
	}
	BinTreeNode<T> *p;
	if ((p = Parent(subTree->leftChild,current)) != nullptr)
	{
		return p;
	}
	else
	{
		return Parent(subTree->rightChild, current);
	}
}


template <typename T>
void BinaryTree<T>::Traverse(BinTreeNode<T> *subTree, ostream& out)
{
	if (subTree != nullptr)
	{
		out << subTree->data << " ";
		Traverse(subTree->leftChild, out);
		Traverse(subTree->rightChild, out);
	}
}

template <typename T>
istream& operator >> (istream& in, BinaryTree<T>& Tree)
{
	BinaryTree<T>::CreateBinTree(in, Tree.root);
	return in;
}


template <typename T>
ostream& operator<<(ostream& out, BinaryTree<T>& Tree)
{
	out << "二叉树的前序遍历" << endl;
	Tree.Traverse(Tree.root, out);
	out << endl;
	return out;
}


#endif
