#pragma once

class Hook
{
	int* entryPoint;
	void* functionAddress;

public:
	enum ConventionType
	{
		Cdecl,
		Stdcall,
		Fastcall,
		Userpurge,
		Custom
	};

	//void operator()();
	void Replace(int targetAddress, void* pFunction, ConventionType callingConvention = Cdecl);
	void Replace(int targetAddress, void* pFunction, ConventionType callingConvention, void* (*hookASMFunction)());
	bool WritePatch(void* address, char* data, int size);
	bool WriteJMP(void* writeAddress, void* toAddress);
	bool WriteCall(void* writeAddress, void* toAddress);

	void StdcallHook(void* function);
};