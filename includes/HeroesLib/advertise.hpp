#pragma once
#include "TObject.hpp"
#include "Renderware.hpp"



//
struct MAESTRO_DATA_ADV
{
	int field_0;
	int field_4;
	const char** stringLabel;
	Rt2dMaestro* maestro;
	char gap10[4];
	int field_14;
	char gap18[4];
	RwV2d pos;
	int field_24;
	RwMatrix MTM;
};


struct TAdvBg
{
	TObject TObject;
	MAESTRO_DATA_ADV* maestroData;
	void* formSpinnerMaestroData;
	const char** maestroStringMaybe;
	float animCount;
	float formSpinnerAnimCount;
	float bottomRightCircleAnimCount;
	float bgAnimSpeed;
	float float_44;
	float float_48;
	int modeChange;
	int mode;
	int changeBgMaybe;
	float minAnimCount;
	float maxAnimCount;
	float bottomRightCircleMaxAnimCount;
	int field_64;
	int field_68;
	float formSpinnerMaxAnimCountMaybe;
};



struct ADVERTISE_CONTROL
{
	TObject TObject;
	DWORD dispStateNo;
	DWORD selectionIndex;
	char gap30[4];
	float animCount;
	MAESTRO_DATA_ADV* maestroData;
	int maestroNoMaybe;
	int nextSubMode;
	int lastSubMode;
	int gotoSubMode;
	char gap4C[8];
	int chaoLastSelectionIndex;
	int chaoMessageNo;
	int modeChange;
	int animDelayRelated;
	char gap6C[16];
	int field_7C;
};



struct ADV_2P
{
	signed int Initialize();


	ADVERTISE_CONTROL ADVERTISE_CONTROL;
	char gap80[424];
	DWORD mode;
	char gap22C[4];
	DWORD selectedLevelIndex;
	DWORD p1Team;
	DWORD p2Team;
	DWORD p1FirstAvailableChoice;
	DWORD p1SecondAvailableChoice;
	DWORD p1ThirdAvailableChoice;
	DWORD p1FourthAvailableChoice;
	char gap24C[112];
	DWORD p1NumberOfChoicesAvailable;
	DWORD p1ChoiceID;
	DWORD p1ChoicesCanLoopMaybe;
	DWORD p2FirstAvailableChoice;
	char gap2CC[144];
	int teamReadyCount;
	char gap360[48];
	int readyTimeCount;
	int readyTimeMaxNo;
	int playerIsReady[2];
	char gap3A0[3];
	char field_0;
};


struct ADVERTISE
{
	int fsone1;
	int fsfour1;
	int field_8;
	int subMode;
	int lastSubMode;
	int field_14;
	int field_18;
	int ework_fzero1;
	int ework_fzero2;
	int ework_fzero3;
	int fzero1;
	int obj2;
	int fzero2;
	int RpWorld;
	int TAdvCamera;
	int fzero3;
	int field_40;
	int field_44;
	int field_48;
	RwV3d cam;
	int statusThing;
	int textLang;
	int localSpeechMaybe;
	int field_64;
	TAdvBg* TAdvBg;
};
//



extern ADVERTISE& Advertise;
extern TAdvBg*& gBG_PTR;



