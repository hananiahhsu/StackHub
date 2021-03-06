// ListQueueStack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "CList.h"
#include "CQueue.h"
#include "CStack.h"

using namespace std;



class CStudent
{
public:
	CStudent();
	CStudent(DWORD stu_id) : m_stu_id(stu_id)
	{

	}
	~CStudent();

	static DWORD GetStuId(CStudent *student)
	{
		DWORD dwValue = student->GetID();
		return dwValue;
	}

	DWORD GetID() const
	{
		return m_stu_id;
	}
private:
	DWORD m_stu_id;
};

CStudent::CStudent()
{
}

CStudent::~CStudent()
{
}






int main()
{
    std::cout << "Hello World!\n"; 

	CQueue<int>* m_queue = new CQueue<int>();
	CStack<double>* m_stack = new CStack<double>();

	for (int i = 0;i < 10;i++)
	{
		m_queue->Enqueue(new int(i));
		m_stack->Push(new double(i/10.0));
	}


	for (int i = 0;i < 10;i++)
	{
		m_queue->Dequeue();
		m_stack->Pop();
	}


	CList<CStudent> *list = new CList<CStudent>();
	list->Insert(new CStudent(1));
	list->Insert(new CStudent(2));
	list->Insert(new CStudent(3));

	CStudent *tmp_stu = list->Find(&CStudent::GetStuId,2);
	if (tmp_stu != NULL)
	{
		printf("You get your id");
	}

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
