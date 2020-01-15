#pragma once




struct MODESWITCH
{
	char gap0[4];
	char commonTextureDataMaybe;
	char hideGUI;
	char hideGUI2;
	char hideGUI3;
	char hideGUIAndGeometryMaybe;
	char hideGUI4;
	char hideGUI5;
	char gapB[4];
	char somethingPALWhen2Maybe;
	char gap10[1];
	char PALMode;
	char soundModeMaybe;
	char textLang;
	char localSpeechMaybe;
	char gap15[1];
	char isPlayBGM;
	char isPlaySFX;
	char demoMode;
	char gap19[1];
	char showGDisp;
	char showGDispRing;
	char gap1C[2];
	char is2PMode;
	char TimeStop;
	char SFAScreen;
	char SETObjInteraction;
	char hideTextAndNumbers;
	char dontDieFromFalling;
	char rule;
	char missionType;
	char dontMovegdisp_stack;
	char isStoryMode;
	char levelType;
	char splitscreenOrientationMaybe;
	char returnToMenuID;
	char gap2B[1];
	int gamePlayTime;
	int frame;
	int timeStopframe;
	int systemMode;
	char gap3C[4];
	int eventNo;

	MODESWITCH(MODESWITCH* a2);
};


extern int defaultflags[11];
extern int defaultlws[6];
extern MODESWITCH*& pModeSwitch;