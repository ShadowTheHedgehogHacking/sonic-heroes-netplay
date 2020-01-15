#pragma once



struct G_PARAM
{
	static char InitSavePosition();
	//static void InitRing();
	//static void InitSFA();
};


struct PARAM_CHALLENGE
{
	static int* num;
};


struct PARAM_VICTORY
{
	static int &num;
};


struct PARAM_TIME
{
	static bool addSec(int count);
	static signed int addMin(int count);
	static signed int addFrm(int count);


	static signed char& Frm;
	static signed char& Sec;
	static signed char& Min;
};


struct PARAM_SCORE
{
	static int* score;
};


struct PARAM_SAVEPOSITION
{
	static void setSaveTime();
	static void setSaveTime(signed char, signed char, signed char);


	static signed char &Frm;
	static signed char &Sec;
	static signed char &Min;
	static int &id;
};


struct PARAM_RING
{
	static int* num;
};


struct PARAM_SFA
{
	static float* tb;
	static int* sfa;
	static int* sfa_trigger;
};



//
signed int InitStageTime(signed char*, signed char*, signed char*);
signed int __cdecl getGameTime(signed char* Min, signed char* Sec, signed char* Frm);
//



//
extern char* stageTimerInfomation;
extern char*& lastBossTime;
extern int &dword_9DD744;
extern int &dword_9DD748;
extern int &dword_9DD734;
extern int &dword_9DD724;
extern int &dword_9DD738;
extern int &dword_9DD728;
//