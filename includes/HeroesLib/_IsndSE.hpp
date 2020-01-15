#pragma once
#include "_MODESWITCH.hpp"


// Incomplete Types //
namespace IsndADX
{
	signed int Serif_GetPlayer(int a1);
	MODESWITCH* BGM_Play2(const char* a1);

	static int* &SerifTask = *(int**)0xA7786C;
	static int* &SerifWork = *(int**)0xA77874;
}

namespace TObjSERIF
{
	signed int Stop(char a1, char si, int a2, int a3);
}

namespace IsndCallSE
{
	static void SetParameterForNew(int a1, char* a2, short a3, char a4);
}

namespace sVOICE
{
	static signed int Init(int a1);
	static int Stop(int a1, int a2);
}
// Incomplete Types //


struct IsndSE
{
	IsndSE(IsndSE* a1);
	static char GetTblNumFromID(unsigned short a1);
	static signed int isPauseTone(unsigned int a1);
	static char GetNewHandleNum(short* a1, char* a2, unsigned short a3);
	static signed int isGoalTone(unsigned int a1);
	static int CreateNewCall(short a1, float a2, unsigned char a3, int a4);
	static int CreateNewCall(int a1, int a2, unsigned char a3, float a4, int a5);
	static double GetRange(int a1);
	static signed int Play(short soundID, int esi0, char a1, int a2);
	static int StopByPtr(int a1, int a2);
	static double GetDistanceFromOffsetVolume(float* a1);

	char unknownData[0xA54];
};


IsndSE* InitSESystem();


// Global Variables //
extern short* SEID_ON_PAUSE;
extern short* SEID_ON_GOAL;
extern IsndSE*& SndSE;
extern int* g_VOICE;

extern int VoiceId_SeTable[120];
// ~Global Variables~ //