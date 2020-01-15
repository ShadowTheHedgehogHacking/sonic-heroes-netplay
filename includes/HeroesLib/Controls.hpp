#pragma once
#include "Player.hpp"
 


// Typedefs //

// ~Typedefs~ //



// Enums //
enum Buttons
{
	Buttons_A_Jump = 1,
	Buttons_B_FormationChangeR = 2,
	Buttons_X_Action = 4,
	Buttons_Y_FormationChangeL = 8,
	Buttons_Up = 0x10,
	Buttons_Down = 0x20,
	Buttons_Left = 0x40,
	Buttons_Right = 0x80,
	Buttons_CameraRotateL = 0x100,
	Buttons_CameraRotateR = 0x200,
	Buttons_Pause = 0x4000,
	Buttons_Z_TeamBlast = 0x30000,
	Buttons_Unknown_MaybeC = 0x40000
};
// ~Enums~ //



// Struct Forward Declarations //
struct gPADStruct;
struct sGameStatus;
struct PeriCtrlStruct;
struct SKYPAD;
struct sGamePeri;
struct PL_BUTTON_STATUS;
struct PL_BUTTON;
// ~Struct Forward Declarations~ //



// Struct Definitions //
struct gPADStruct
{
	int buttonFlags[1];
	int minusOneMinusButtonFlags;
	int oneFramePressButtonFlags;
	int oneFrameReleaseButtonFlags;
	float leftStickX;
	float leftStickY;
	float rightStickX;
	float rightStickY;
	int isEnabled;
};


struct sGameStatus
{
	gPADStruct gPAD[4];
};


struct sGamePeri
{
	unsigned int ConvertBit_A(unsigned int a1);
	unsigned int edgeCheck_A(unsigned int a2);

	static SKYPAD* makeAnalogDir(SKYPAD* result, short a2, short a3);
	static sGamePeri* makeRepeatCount(sGamePeri* result);


	int buttonsHeld;
	int buttonsNotHeld;
	int buttonsPressed;
	int buttonsReleased;
	short triggerPressureL;
	short triggerPressureR;
	short analogXAxis;
	short analogYAxis;
	float turnDirectionRelatedMaybe;
	int leftStickVector;
	float leftStickForce;
	int rightStickVector;
	int rightStickForce;
	short upRepeatCount;
	short downRepeatCount;
	short leftRepeatCount;
	short rightRepeatCount;
	short upRepeatCountAnalog;
	short downRepeatCountAnalog;
	short leftRepeatCountAnalog;
	short rightRepeatCountAnalog;
	short lsClickRepeatCount;
	short rsClickRepeatCount;
	int noButtonsPressed;
	int buttonsAndAnalogHeld;
	int movePressed;
};


struct PeriCtrlStruct
{
	int map[6];
	int controlsEnabled[6];
	int controlsDisabled[6];
	sGamePeri menu[6];
	sGamePeri game[6];
};


struct SKYPAD
{
	int buttonsHeld;
	int buttonsNotHeld;
	int buttonsPressed;
	int buttonsReleased;
	short triggerPressureL;
	short triggerPressureR;
	short analogXAxis;
	short analogYAxis;
	short rightStickRelated[2];
	int leftStickVector;
	float leftStickForce;
	int rightStickVector;
	int rightStickForce;
	short upRepeatCount;
	short downRepeatCount;
	short leftRepeatCount;
	short rightRepeatCount;
	short upRepeatCountAnalog;
	short downRepeatCountAnalog;
	short leftRepeatCountAnalog;
	short rightRepeatCountAnalog;
	short lsClickRepeatCount;
	short rsClickRepeatCount;
	int noButtonsPressed;
	int buttonsAndAnalogHeld;
	int movePressed;
};


struct PL_BUTTON_STATUS
{
	char isOn(char* a1);
	void setRelease(char* a1);
	void setOff(char* a1);
	void setPress(char* a1);
	void setOn(char* a1);
	void clearAll(char* a1);

	char jump;
	char action;
	char sfa;
	char formChangeL;
	char formChangeR;
	char BYTE_0X5;
	char BYTE_0X6;
};


struct PL_BUTTON
{
	float analogAmount;
	int cameraRelativeAnalogDirection;
	char moveEdgePressed;
	PL_BUTTON_STATUS PL_BUTTON_STATUS;
};
// ~Struct Definitions~ //


// Function Prototypes //
sGamePeri* GetGamePeriPtr(int a1);
sGamePeri* periConvertPadData(gPADStruct* sGamePeri, SKYPAD* SKYPAD);
int InitPeripheral();
sGameStatus* ChkController();
short* MakeGameKeyData();
int ClearSoftReset();
short ClampAnalogPad(short* a1, short* a2);
double CalcAnalogStroke(float a1, float a2);
int CalcAnalogAngle(float a1, float a2);
void MakePlayersKeyData();
// ~Function Prototypes~ //


// Global Variables //
extern int action_button;
extern int jump_button;
extern int leader_button;
extern int leaderR_button;
extern int sfa_button;
extern float IGNORE_STROKE_THRESHOLD;
extern sGamePeri peri_dummy;
extern BOOL noMemory;

extern float const& clampAnalogPadAngle;
extern int* const& PeriCtrlMap;
extern int* const& TBL_Port;
extern sGamePeri** periPeri;
extern sGameStatus& gStatus;
extern sGamePeri& gameperi_dummy;
extern PeriCtrlStruct& PeriCtrl;
extern int* PeriCtrl_someArray;
extern PL_BUTTON* const player_input;
extern char& softreset;
extern short& softreset_count;
extern char& hardreset;
extern short& hardreset_count;
extern char& reset_callback;
extern RwBool& RwInitialized;
// ~Global Variables~ //