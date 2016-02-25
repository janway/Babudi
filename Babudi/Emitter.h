#pragma once
#include <ppl.h>

class CEmitter
{
public:
	CEmitter(void);
	~CEmitter(void);

//
	void operator()()const;
	void DoTask(size_t i)const;
};

