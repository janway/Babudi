#include "stdafx.h"
#include "Greeting.h"
CGreeting::CGreeting(void)
{
	//pMsg = NULL;
}



CGreeting::CGreeting(const CGreeting & obj)
{

}

void CGreeting::Call(int x)
{
	std::cout<<"inside the callback" << endl;
}

CGreeting::~CGreeting(void)
{
}

void CGreeting::operator()() const
{
	//TRACE(CString(message.c_str()));
	//TRACE(_T("%d"),*pMsg);
	//cout << message << endl;
}
