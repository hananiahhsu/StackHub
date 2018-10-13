#include "pch.h"
#include "CList.h"

template <class T>
void CList<T>::Append(CNode<T>*& node, T* tElement)
{
	if (node == NULL)
	{
		dwCount++;
		node = new CNode<T>(tElement);
		return;
	}
	Append(node->Next(),tElement);
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
		head->next = tmp;
		return;
	}
}

template<class T>
bool CList<T>::Remove(T* tElement)
{

}

template<class T>
T* CList<T>::GetLast()
{

}

template<class T>
T* CList<T>::GetNext(T* tElement)
{

}

template<class T>
T* CList<T>::Find(DWORD(*Function)(T* tParameter), DWORD dwValue)
{

}