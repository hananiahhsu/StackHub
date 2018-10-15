#pragma once
#include "CList.h"

template<class T>
class CQueue : CList<T>
{
public:
	CQueue():CList<T>() {}
	CQueue(T* tElement):CList<T>(tElement) {}
	virtual ~CQueue() {}
	//Add element to the tail of queue
	virtual void Enqueue(T* tElement)
	{
		CList<T>::Append(CList<T>::Head(),tElement);
	}

	//Remove member from
	virtual T* Dequeue()
	{
		T* tElement = CList<T>::GetFirst();
		CList<T>::Remove(tElement);
		return tElement;
	}

	virtual T* Peek()
	{
		return CList<T>::GetFirst();
	}

	CList<T>::Count;
protected:
	CQueue(const CQueue<T>& queue);
	CQueue<T>& operator=(const CQueue<T>& queue);
};