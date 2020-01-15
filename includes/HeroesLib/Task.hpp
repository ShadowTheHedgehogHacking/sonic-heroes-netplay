#pragma once



// Struct Forward Declarations //
struct TObject;
// ~Struct Forward Declarations~ //



// Struct Definitions //
struct THeapCtrl
{
	char data[0x70000];


	static int* Malloc(int size, THeapCtrl* a2);
	static TObject* Free(TObject* TObject, unsigned int** TaskHeap);
};
// ~Struct Definitions~ //



// Global Variables //
extern THeapCtrl*& TaskHeap;
extern void*& StageObjTop;
extern void*& TL_05;
// ~Global Variables~ //