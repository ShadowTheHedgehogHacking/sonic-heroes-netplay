#pragma once



enum ActionMode
{
	ActionMode_Normal = 0x5,
	ActionMode_Pause = 0x6,
	GameStatus_PauseSettings = 0x7,
	GameStatus_PauseCameraSettings = 0x8,
	GameStatus_PauseGamePadConfig = 0x9,
};


struct STAGE_INFO
{
};


struct ACTION
{
	void* vftable;
	void* field_4;
	int mode;
	int int_0x0C;
	int levelEndType;
	int pauseSelectionType;
	int pauseGame;
	int pauseEnable;
	int pauseMenuOwner;
	int int_0x24;
	int stageNo;
	STAGE_INFO** StageTable;
	const char** StageInfo;
	int objList;
	int stageConnect[64];
	char stageConnect2PRubber[64];
	char gap178[176];
	int int_228;
	char gap22C[4];
	int int_230;
	char gap234[4];
	int teamKind[4];
	int pauseMainMenuSelection;
	int pauseSettingsSelection;
	int pauseGamePadSettingsIndex;
	int pauseCameraSettingsIndex;
	char mappedButtons[8];
	int pauseSettingsMenuSetsTo0;
	char gap264[8];
	char field_26C;
	char gap26D[11];
	int sync_count;
	signed int framesToSkip;
	int palCountMaybe;
	//int timeoverFunction;
	void (*timeoverFunction)(void (*)(void));
	char gap288[12];
	int lastLeader;
	char* stageNumberString;
	char gap29C[8];
	int addCountDisabled;
	char gap2A8[8];

	static int stageProgramInfo[122];
	//static void (*timeoverFunction)(void (*)(void));


	static void InitStage(ACTION* Action);
	static signed int InitStageAndTeamInfo(int a1, ACTION* a2);
	static void addFrame(int a1, ACTION* a2);
};
	void addFrame_Hook(int a1, ACTION* a2);


signed int InitStageAndTeamInfo(int a1, ACTION* a2);
//



//
extern ACTION& Action;
//