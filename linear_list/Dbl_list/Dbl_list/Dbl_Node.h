#pragma once

template <typename T>
class DblNode
{
public:
	DblNode();
	~DblNode();

private:
	DblNode *rLink, *lLink;
	T data;
};
template <typename T>
DblNode::DblNode()
{
}
template <typename T>
DblNode::DblNode(DblNode<T> *left = nullptr, DblNode<T> *right = nullptr):lLink(left),rLink(right)
{
}

template <typename T>
DblNode::DblNode(T value,DblNode<T> *left = nullptr, DblNode<T> *right = nullptr) :data(value), lLink(left), rLink(right)
{
}

template <typename T>
DblNode::~DblNode()
{
}