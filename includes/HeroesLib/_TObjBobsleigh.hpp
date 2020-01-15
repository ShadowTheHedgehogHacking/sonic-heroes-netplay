#pragma once

#include "Renderware.hpp"
#include "TObject.hpp"



// Struct Forward Declarations //
// ~Struct Forward Declarations~ //



// Incomplete Types //
// ~Incomplete Types~ //



// Struct Definitions //
struct TObjBobsleigh
{
	TObject TObject;
	char EffShadowStuff[64];
	char CCL_INFO[124];
	char gapE4[24];
	DWORD state;
	RwV3d position;
	float jumpAngXLand;
	RwV3d rotation;
	char gap11C[48];
	float turnSpeed;
	float vSpeed;
	float hSpeed;
	char gap158[8];
	float acceleration;
	DWORD waypointIndex;
	float currentWaypointDistance;
	char widthRatio;
	char gap16D[43];
	DWORD playerIndex;
	char gap19C[36];
	float speedRatio;
	float speed0;
	char speedMax;
	float speedMin;
	float speedStart;
	float widthSpeedRatio;
	float startWidthRatio;
	int isInAir;
	int jumpAfterTime;
	char secondaryXTiltRotation;
	float jumpHeight;
	float boundY;
	RwV3d effPosition;
	int xTiltRotation;
	char gap204[28];
	int cameraStartAngY;
	char gap224[168];
	float powerH;
	float powerV;
	char gap2D4[8];
	int fallenPlayerNo;
	char gap2E0[8];
	DWORD currentLapNumber;
	DWORD currentLapGoal;
	char gap2F0[12];
	int turnDisableCount;
	char gap300[4];
	int teamPlayMode;
	RpClump* pClumpBob;
	char gap30C[56];
	void* pTObjBobsleighAttack;
	char gap348[16];
	int* pTObjBobsleighLight;
	int isMultiplayer;
	char gap360[4];
	int drawShadow;
	int isDelayedStart;
	int cantAccelOrFinish;
	int isDemoMaybe;
	char field_380;
	int leaderNo;
	char gap388[7];
	char field_0;

	
	static RwV3d* SetArrowPosition(TObjBobsleigh* a1);
};
// ~Struct Definitions~ //



// Function Prototypes //
int initObjS31Bob();
void SetArrowPosition_hook(TObjBobsleigh* a1);
void arrowdisptest();
void arrowdisptest_hook();
// ~Function Prototypes~ //



// Global Variables //
extern float sBobArrowOffsetY;;

extern RpClump** pClumpBobArrow;
// ~Global Variables~ //