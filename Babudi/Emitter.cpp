#include "stdafx.h"
#include "Emitter.h"


CEmitter::CEmitter(void)
{
}


CEmitter::~CEmitter(void)
{
}

void CEmitter::operator()() const
{
	TRACE(_T("hello this is emitter thread!\n"));
	concurrency::parallel_for(size_t(0), size_t(50), [&](size_t i)
	{
		//TRACE(_T("%d\n"),i);
		DoTask(i);
	});
}

void CEmitter::DoTask(size_t i)const
{
	//throw std::logic_error("The method or operation is not implemented.");
	for (size_t j=0;j<10000;j++)
	{
		TRACE(_T("i=%d,j=%d\n"),i,j);
	}
}
