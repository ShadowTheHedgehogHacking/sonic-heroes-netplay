#pragma once
#include "Task.hpp"



// Enums //
enum TObjectStatus
{
	TObjectStatus_Killed = 0x1,
	TObjectStatus_Disabled = 0x4,
	TObjectStatus_Hidden = 0x10,
	TObjectStatus_Deleted = 0x20,
};
// ~Enums~ //



// Struct Definitions //
struct TObject
{
	void Kill();
	bool is(const char* a2);

	TObject(int a2);
	virtual ~TObject();
	virtual void Exec();
	virtual void Disp();
	virtual void TDisp();
	virtual void PDisp();
	virtual void PCSpecific();
	virtual void ImmAftSetRaster();
	virtual void Debug();
	virtual void Error();
	virtual void Render();

	void* operator new(size_t size)
	{
		return THeapCtrl::Malloc(size, TaskHeap);
	}

	void operator delete(void* p)
	{
		THeapCtrl::Free((TObject*)p, (unsigned int**)TaskHeap);
	}


	const char* CL_Name;
	char status;
	char field_9;
	char field_A;
	char field_B;
	void* pSelf;
	char field_10;
	char field_11;
	char field_12;
	char field_13;
	char pTObject;
	char pTObject_2;
	char gap16[8];
	short objectSize;
	char gap20[4];
	short field_24;
	short field_26;
};
// ~Struct Definitions~ //



// //
static const char* CL_TObject = "TObject";
static int& ObjectCount = *(int*)0xA778C8;
// //