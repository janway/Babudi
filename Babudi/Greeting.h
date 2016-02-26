#pragma once
#include <string>
#include <iostream>
using namespace std;
class CGreeting
{
	int *pMsg;
public:
	CGreeting(void);
	CGreeting(const CGreeting & obj);

	//explicit CGreeting(std::string const& msg):message(msg){};
	//explicit CGreeting(int const& msg):message(msg){};
	//CGreeting(int a);

	void Call(int x);

	virtual ~CGreeting(void);
	void operator()()const;



};

