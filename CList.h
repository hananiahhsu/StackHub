#pragma once
#ifndef _LIST_
#define _LIST_

#include <windows.h>
template<class T>
class CNode
{
public:
	CNode(T* tElement) :tElement(tElement), next(0)
	{

	}

	T* Element()
	{
		return tElement;
	}

	CNode*& Next()
	{
		return next;
	}
private:
	T* tElement;
	CNode* next;
};



template<class T>
class CList
{
public:
	CList() :dwCount(0),head(0)
	{

	}
	CList(T* tElement):dwCount(1),head(new CNode<T>(tElement))
	{

	}
	virtual~CList() {}
public:
	void Append(CNode<T>*& node, T* tElement);
	void Insert(T* tElement);
	bool Remove(T* tElement);
	DWORD Count()const { return dwCount; }
	CNode<T>*& Head() { return head; }
	T* GetFirst() { return head != NULL ? head->Element() : NULL; }
	T* GetLast();
	T* GetNext(T* tElement);
	T* Find(DWORD(*Function)(T* tParameter),DWORD dwValue);
protected:
	CList(const CList& list);
	CList& operator=(const CList& list);
private:
	CNode<T>* head;
	DWORD dwCount;
};



template <class T>
void CList<T>::Append(CNode<T>*& node, T* tElement)
{
	if (node == NULL)
	{
		dwCount++;
		node = new CNode<T>(tElement);
		return;
	}
	Append(node->Next(), tElement);
}

//Ç°²å
template<class T>
void CList<T>::Insert(T* tElement)
{
	dwCount++;
	if (head == NULL)
	{
		head = new CNode<T>(tElement);
		return;
	}
	else
	{
		CNode<T> * tmp = head;
		head = new CNode<T>(tElement);
		head->Next() = tmp;
		return;
	}
}

template<class T>
bool CList<T>::Remove(T* tElement)
{
	if (head == NULL)
	{
		return false;
	}
	if (head->Element() == tElement)
	{
		CNode<T> *tmp_head = head;
		head = tmp_head->Next();
		this->dwCount--;
		delete tmp_head;
		return true;
	}
	//For the last node's next == NULL
	CNode<T> *pre_node = head;
	CNode<T> *lst_node = head->Next();
	while (lst_node != NULL)
	{
		if (lst_node->Element() == tElement)
		{
			dwCount--;
			pre_node->Next() = lst_node->Next();
			delete lst_node;
			return true;
		}
		//previous node
		pre_node = pre_node->Next();
		lst_node = lst_node->Next();
	}
}

template<class T>
T* CList<T>::GetLast()
{
	if (head)
	{
		CNode<T>* tmp = head;
		while (tmp->Next())
		{
			tmp = tmp->Next();
		}
		return tmp->Element();
	}
	return NULL;
}

template<class T>
T* CList<T>::GetNext(T* tElement)
{
	if (NULL == head)
	{
		return NULL;
	}
	if (NULL == tElement)
	{
		return GetFirst();//important for the undefined function
	}

	if (head->Element() == tElement)
	{
		return head->Next() != NULL ? head->Next()->Element() : NULL;
	}
	CNode<T> *tmp = head->Next();
	while (tmp)
	{
		if (tmp->Element() == tElement)
		{
			return tmp->Next() != NULL ? tmp->Next()->Element() : NULL;
		}
		tmp = tmp->Next();
	}
	return NULL;
}

//The Function is not defined here(the param of Function could not be used for Find() )
template<class T>
T* CList<T>::Find(DWORD(*Function)(T* tParameter), DWORD dwValue)
{
	try
	{
		T* tElement = NULL;
		while (tElement = GetNext(tElement))
		{
			if (Function(tElement) == dwValue)
			{
				return tElement;
			}
		}
	}
	catch (...)
	{

	}
	return NULL;
}










































































































































#endif