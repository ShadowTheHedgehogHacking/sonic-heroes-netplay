#pragma once

#include "Renderware.hpp"



//
struct TObjSetObj;
struct SetObjParam;
struct SETOBJ_PARAM;
struct BINFile;
//



// Incomplete Types //
struct TObjSetObj
{
	static int CheckRangeOutWithoutIgnorRangeFlag(BINFile* a1, float);
	static int CheckRangeOut(BINFile* a1, float);

};
// //



struct SetObjParam
{
	char data[36];
};


struct SETOBJ_PARAM
{
	RwV3d position;
	sAngle rotation;
	char oddFlag_Usually0x09;
	char teamLayoutNo;
	__int16 ignored_Usually0x0002;
	int ignored_Usually0x00000000;
	char oddFlag_Usually0x09_Repeat;
	char teamLayoutNo_Repeat;
	__int16 ignored_Usually0x0002_Repeat;
	int ignored_Usually0x00000000_Repeat;
	char itemNo;
	char listNo;
	char communicateId;
	char renderDistance;
	SetObjParam* PARAM;
};


struct BINFile
{
	RwV3d position;
	sAngle rotation;
	char usually0x09Maybe0x0B;
	char objectTeamID;
	short usually0x0002;
	int usually0x0000;
	__int64 repeatLast8Bytes;
	char objectType;
	char objectList;
	char communicateId;
	char renderDistanceMultiplier;
	int* pMiscProperties;
};




namespace TObjSetGen
{
	static char* OneFileUsualName = (char*)0xA23D28;
	static SETOBJ_PARAM objTable = *(SETOBJ_PARAM*)0xA825D8;
};



// Function Prototypes //
void setobjCheckRangeOut2_hook(RwV3d* position, float a2);
int setobjCheckRangeOut2(RwV3d const* position, float range);
signed int ObjSwitchesAreAllOn(unsigned char a1);
// ~Function Prototypes~ //



// Global Variables //
extern int &SetGenTp;
