#pragma once
#ifndef _LIST_
#define _LIST_

#include <windows.h>
template<class T>
class CNode
{
public:
	CNode() :tElement(tElement), next(0)
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








#endif