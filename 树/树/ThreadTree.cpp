template <T>
struct ThreadNode
{
	int ltag, rtag;
	ThreadNode<T> *leftChild, *rightChild; //线索的标志；==0为指针，==1为线索
	T data;
	ThreadNode(const T item):data(item),leftChild(nullptr),rightChild(nullptr),ltag(0),rtag(0){}
};



template <class T>
class ThreadTree
{
	ThreadNode<T> *root;
	void createInThread(ThreadNode<T> *current, ThreadNode<T> *&pre);
	ThreadNode<T> *parent(ThreadNode<T> *t);

public:
	ThreadTree() :root(nullptr);
	void creatInThread();
	ThreadNode<T> *First(ThreadNode<T> *current);
	ThreadNode<T> *Last(ThreadNode<T> *current);
	ThreadNode<T> *Next(ThreadNode<T> *current);
	ThreadNode<T> *Prior(ThreadNode<T> *current);


	void InOrder(void(*vist)(ThreadNode<T> *p));
	void PreOrder(void(*vist)(ThreadNode<T> *p));
	void PostOrder(void(*vist)(ThreadNode<T> *p));

};


template <typename T>
ThreadNode<T> *ThreadTree<T>::First(ThreadNode<T> *current)
{
	ThreadNode<T> *p = current;
	while (p->ltag == 0)
	{
		p = p->leftChild;
	}
	return p;
}


template <typename T>
ThreadNode<T> *ThreadTree<T>::Last(ThreadNode<T> *current)
{
	ThreadNode<T> *p = current;
	while (p->ltag == 0)
	{
		p = p->rightChild;
	}
	return p;
}


template <typename T>
ThreadNode<T> *ThreadTree<T>::Next(ThreadNode<T> *current)
{
	ThreadNode *p = current->rightChild;
	if (p->rtag == 0)
	{
		return First(p);
	}
	else
	{
		return p;
	}
}

template <typename T>
ThreadNode<T> *ThreadTree<T>::Prior(ThreadNode<T> *current)
{
	ThreadNode<T> *p = current->leftChild;
	if (current->ltag == 0)
	{
		return Last(p);
	}
}


template <typename T>
void ThreadTree<T>::InOrder(void(*visit)(ThreadNode<T> *p))
{
	ThreadNode<T> *p;
	for (p = First(root);p!=nullptr;p = Next(p))
	{
		visit(p);
	}
}

template <class T>
void ThreadTree<T>::createInThread()
{
	ThreadNode *pre = nullptr;
	if (root != nullptr)
	{
		createInThread(root, pre);
		pre->rightChild = nullptr;
		pre->rtag = 1;
	}
}



template <typename T>
void ThreadTree<T>::createInThread(ThreadNode<T> *current, ThreadNode<T> *&pre)
{
	if (current == nullptr)
	{
		return;
	}
	createInThread(current->leftChild, pre);
	if (current->leftChild == nullptr)
	{
		current->leftChild = pre;
		current->ltag = 1;
	}
	if (pre != nullptr&&pre->rightChild == nullptr)
	{
		pre->rightChild = current;
		pre->rtag = 1;
	}
	pre = current;
	createInThread(current->rightChild, pre);
}


template <typename T>
void ThreadTree<T>::PreOrder(void(*visit)(ThreadNode<T> *p))
{
	ThreadNode<T> *p = root;
	while (p!=nullptr)
	{
		visit(p);
		if (p->ltag == 0)
		{
			p = p->leftChild;
		}
		else if (p->rtag == 0)
		{
			p = p->rightChild;
		}
		else
		{
			while (p!= nullptr&&p->rtag ==1)
			{
				p = p->rightChild;
			}
			if (p!=nullptr)
			{
				p = p->rightChild;
			}
		}
	}
}


template <typename T>
void ThreadTree<T>::PostOrder(void(*void)(ThreadNode<T> *p))
{
	ThreadNode<T> *t = root;
	while (t->ltag == 0 || t->rtag == 0)
	{
		if (t->ltag == 0)
		{
			t = t->leftChild;
		}
		else if (t->rtag == 0)
		{
			t = t->rightChild;
		}
	}
	visit(t);
	ThreadNode<T> *p;
	while ((p = parent(t)) != nullptr)
	{
		if (p->rightChild == t || p->rtag == 1)
		{
			t = p;
		}
		else
		{
			t = p->rightChild;
			while (t->ltag == 0 || t->rtag == 0)
			{
				if (t->ltag == 0)
				{
					t = t->leftChild;
				}
				else if (t->rtag == 0)
				{
					t = t->rightChild;
				}
			}
		}
		visit(t);
	}
}


