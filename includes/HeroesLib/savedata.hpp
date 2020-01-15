#pragma once


struct SAVEDATA
{
	char gap0[24];
	int field_18;
	char gap1C[32];
	int savedNumberOfLivesCopy;
	char gap40[1377];
	char storyStuff[128];
	char gap621[215];
	char HARD_DATA;
	char gap6F9[19];
	int field_0;

	
	static signed int Init(SAVEDATA* a1);
};


// Global Variables //
extern char* byte_7BAC78;
extern SAVEDATA& savedata;
// ~Global Variables~ //