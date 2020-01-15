#include "pch.h"
#include "_Hook.hpp"


const char asm_jmpRel8 = (char)0xEB;
const char asm_jmp = (char)0xE9;


void __declspec(naked) Hook::StdcallHook(void* function)
{
	__asm
	{
		push edi;
		push esi;
		call function;
		pop esi;
		pop edi;
	}
}

void Hook::Replace(int targetAddress, void* pFunction, ConventionType callingConvention)
{
	switch (callingConvention)
	{
		case Cdecl:
		{
			break;
		}

		case Custom:
		{
			// Invalid call
			break;
		}
	}
	entryPoint = (int*)targetAddress;
	functionAddress = pFunction;
	WriteJMP(entryPoint, functionAddress);
}

void Hook::Replace(int targetAddress, void* pFunction, ConventionType callingConvention, void* (hookASMFunction)())
{
	switch (callingConvention)
	{
	case Cdecl:
	{
		break;
	}

	case Custom:
	{
		(void (*)())hookASMFunction();
		break;
	}
	}
	entryPoint = (int*)targetAddress;
	functionAddress = pFunction;
	WriteJMP(entryPoint, functionAddress);
}


bool Hook::WritePatch(void* address, char* data, int size)
{
	return WriteProcessMemory(GetCurrentProcess(), address, data, size, NULL);
}


bool Hook::WriteJMP(void* writeAddress, void* toAddress)
{
	int offset = (int)toAddress - ((int)writeAddress + 2);
	int size;
	char data[5];
	if (offset < -127 || offset > 127)
	{
		size = 5;
		offset = (int)toAddress - ((int)writeAddress + size);
		data[0] = asm_jmp;
		*(int*)(data + 1) = offset;
	}
	else
	{
		size = 2;
		offset = (int)toAddress - ((int)writeAddress + size);
		data[0] = asm_jmpRel8;
		data[1] = offset;
	}
	return WritePatch(writeAddress, data, size);
}


bool Hook::WriteCall(void* writeAddress, void* toAddress)
{
	int offset = (int)toAddress - ((int)writeAddress + 2);
	int size;
	char data[5];
	size = 2;
	offset = (int)toAddress - ((int)writeAddress + size);
	data[0] = 0xE8;
	data[1] = offset;
	return WritePatch(writeAddress, data, size);
}