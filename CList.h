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

#endif