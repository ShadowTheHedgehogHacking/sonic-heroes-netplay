#pragma once
#include "TObject.hpp"
#include "Player.hpp"
#include "Renderware.hpp"


enum ItemFlags
{
	Powerups_Barrier = 0x1,
	ItemFlags_Magnetic = 0x2,
	Powerups_SpeedShoes = 0x4,
	ItemFlags_ResetFlyTime = 0x8,
	Powerups1_10 = 0x10,
	Powerups1_20 = 0x20,
	Powerups1_40 = 0x40,
	Powerups1_80 = 0x80,
	ItemFlags_KnockbackLaunch = 0x400,
	ItemFlags_NotPosted = 0x800,
	ItemFlags_TeamBattleIsCPU = 0x1000,
	ItemFlags_2000 = 0x2000,
	ItemFlags_Dead = 0x4000,
	ItemFlags_Muteki = 0x8000,
};

enum ENUM_TEAM_KIND
{
	ENUM_TEAM_KIND_SONIC = 0x0,
	ENUM_TEAM_KIND_DARK = 0x1,
	ENUM_TEAM_KIND_ROSE = 0x2,
	ENUM_TEAM_KIND_CHAOTIX = 0x3,
};

enum ENUM_TEAMPLAY_MODE
{
};



// Struct Forward Declarations //
struct TObjPlayer;
// ~Struct Forward Declarations~ //



struct TObjTeam
{
	char GetLeaderPlayerNo();


	char gap0[4];
	char* objectName;
	char gap8[22];
	short objectSize;
	char gap20[12];
	TObject* pointer_0x2c;
	char gap30[4];
	ENUM_TEAM_KIND teamKind;
	char teamNo;
	char numOfTeamMembersActive;
	char leaderPlayerNo;
	char nowLeader;
	char cameraTarget;
	char gap3D;
	short cameraTargetPositionHistoryCount;
	RwV3d cameraTargetPosition;
	RwV3d cameraTargetPositionHistory[16];
	float flightVerticalCamSpeed;
	char playerNo[3];
	char gap113;
	TObjPlayer* playerPtr[3];
	char formationMemberNo;
	char postedMemberNumber;
	char speedMemberAvailableCopy;
	char flyMemberAvailableCopy;
	char powerMemberAvailableCopy;
	char speedMemberAvailable;
	char flyMemberAvailable;
	char powerMemberAvailable;
	TObjPlayer* pFormationMember[3];
	TObjPlayer* pPostedMember0;
	TObjPlayer* pPostedMember1;
	TObjPlayer* pPostedMember2;
	int formationNo;
	int lastFormationNo;
	int formationNoRelated;
	char controllerNo;
	char specialActionButtonStatus;
	short SFACount;
	ENUM_TEAMPLAY_MODE teamPlayModeReserve;
	ENUM_TEAMPLAY_MODE teamplayMode;
	int lastTeamPlayMode;
	char gap15C[89];
	char jumpButton;
	char actionButton;
	char teamBlastButton;
	char formChangeLButton;
	char gap1B9[67];
	__int16 autoMoveTime;
	short lightAttackTime;
	short speedShoesTimer;
	short MutekiTime;
	__int16 prohibitionOfFormationChange;
	ItemFlags ItemFlags;
	char speedLevel;
	char flyLevel;
	char powerLevel;
	char railRideFlag;
	char gap20C[1];
	char prohibitFormationChangeNo[3];
	char gap210[12];
	char SFADamageForEnemy;
	char neonScreen;
	char whiteScreen;
	char gap21F;
	RwV3d SFABasePos;
	char SFABaseAngleY;
	char gap22D[15];
	int chaotixClearItem;
	char gap240[12];
	char techniquePoint[8];
	char techniquePoint2[8];
	char techniquePoint3[8];
	char suitNo;
	char isCasinoBallLane;
	char char_0x266;
	char dontUsePinballMode;
	int* cameraMotionGoal;
	void* cameraMotionTB; //RPCLUMP FIX THIS
	void* cameraMotionTB2;
	char gap274[4];
	int field_278;
};



// Global Variables //
extern TObjTeam** teamTOp;
// ~Global Variables~ //