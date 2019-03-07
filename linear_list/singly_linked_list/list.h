#ifndef LIST_H
#define LIST_H

template<typename T>
class LinkNode
{
public:
    T data;
    LinkNode* link;
    LinkNode(LinkNode<T> *ptr = nullptr)
    {
        link = ptr;
    }
    LinkNode(const T& item,LinkNode<T>* ptr = NULL)
    {
        data = item;
        link = ptr;
    }
};


template <typename T>
class List
{
public:
    List();
    List(const T& x);
    List(List<T>& L);
    ~List();
    void makeEmpty();
    int Length() const;
    LinkNode<T> *getHead()const;
    LinkNode<T> *Seacher()const;
    LinkNode<T> *Local() const;
    bool getData(int i,T& x)const;
    void setData(int i,T& x);
    bool Insert(int i,T& x);
    bool Remove(int i,T& x);
    bool IsEmpty() const;
    bool IsFull()const;
    void Sort();
    void Input();
    void Output();
    List<T>& operator=(List<T>& L);
 protected:
    LinkNode<T> *first;

};

#endif // LIST_H
