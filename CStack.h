#pragma once
#include "CList.h"

template<class T>
class CStack:CList<T>
{
public:
	CStack() : CList<T>() 
	{
	
	}
    virtual ~CStack()
	{
	
	}
	CStack(T *tElement):CList<T>(tElement) 
	{
	
	}
	virtual void Push(T* tElement)
	{
		CList<T>::Insert(tElement);
	}

	virtual T* Pop()
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
private:
	CStack(const CStack<T>& cStack);
	CStack<T>& operator=(const CStack<T>& cStack);
};

