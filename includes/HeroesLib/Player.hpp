#pragma once
#include "Renderware.hpp"
#include "team.hpp"
#include "TObject.hpp"



enum PlayerMode
{
	PlayerMode_Standing = 0x0,
	PlayerMode_RocketAccelCharge = 0x1,
	PlayerMode_Jumping = 0x2,
	PlayerMode_Fall = 0x4,
	PlayerMode_Tripping = 0x5,
	PlayerMode_SpringLaunched = 0x6,
	PlayerMode_PoleLaunched = 0x7,
	PlayerMode_PushingSwitch = 0x9,
	PlayerMode_Hurt = 0xA,
	PlayerMode_Running = 0xE,
	PlayerMode_JumpDash = 0xF,
	PlayerMode_RidingPinballRail = 0x12,
	PlayerMode_MovingTowardsPowerCharacter = 0x13,
	PlayerMode_SpinningOnPowerCharacter = 0x14,
	PlayerMode_AI_TooFar = 0x1A,
	PlayerMode_AIMaybe_Returning = 0x1B,
	PlayerMode_CanonFired = 0x1C,
	PlayerMode_Grinding = 0x1D,
	PlayerMode_RainbowRingTrick = 0x1E,
	PlayerMode_Grabbing = 0x1F,
	PlayerMode_ObjectControl_Spinning = 0x21,
	PlayerMode_StandingWithSwitch = 0x22,
	PlayerMode_GrabbingOntoSwitch = 0x23,
	PlayerMode_SwitchRelease_Maybe = 0x24,
	PlayerMode_PullingSwitch = 0x25,
	PlayerMode_Captured = 0x26,
	PlayerMode_Vanished = 0x27,
	PlayerMode_PinballMode = 0x28,
	PlayerMode_SpeedFly_Gliding = 0x29,
	PlayerMode_Event = 0x2B,
	PlayerMode_Dead = 0x2C,
	PlayerMode_Fly = 0x34,
	PlayerMode_RocketAccelRelease = 0x36,
	PlayerMode_Power_Attack1 = 0x38,
	PlayerMode_Power_Attack2 = 0x39,
	PlayerMode_ThunderShootSpinning = 0x3B,
	PlayerMode_PinballRelated = 0x3D,
	PlayerMode_AirPowerAttackSpinMode = 0x3E,
	PlayerMode_AirPowerAttackInPosition = 0x3F,
	PlayerMode_PinballRelated_apparently = 0x3F,
	PlayerMode_AirPowerAttackShot = 0x40,
	PlayerMode_Tornado = 0x42,
	PlayerMode_Power_Gliding = 0x43,
	PlayerMode_WallStand = 0x44,
	PlayerMode_WallJump = 0x45,
	PlayerMode_Tails_RingThrow = 0x4B,
	PlayerMode_HammerSwing = 0x4C,
	PlayerMode_HammerFloat = 0x4D,
	PlayerMode_LightSpeedDash = 0x53,
	PlayerMode_Kick = 0x54,
	PlayerMode_SFA = 0x55
};


enum PlayerStatus
{
	PlayerStatus_isOnGround = 0x1,
	PlayerStatus_isOnObject = 0x2,
	PlayerStatus_isHurt = 0x4,
	PlayerStatus_0x8 = 0x8,
	PlayerStatus_0x10 = 0x10,
	PlayerStatus_0x20 = 0x20,
	PlayerStatus_0x40 = 0x40,
	PlayerStatus_0x80 = 0x80,
	PlayerStatus_isJumpBall = 0x100,
	PlayerStatus_isAttacking = 0x400,
	PlayerStatus_UsedDashPad = 0x1000,
	PlayerStatus_AutoPath = 0x2000,
	PlayerStatus_AutoMoveAtStart = 0x4000,
	PlayerStatus_CanUseSpecialAttacks = 0x100000,
	PlayerStatus_hasPressedJump = 0x200000,
	PlayerStatus_Konohagakure = 0x400000,
	PlayerStatus_0x800000 = 0x800000,
	PlayerStatus_isNotNPC = 0x1000000,
	PlayerStatus_AvailableForAirAttack = 0x2000000,
};


enum ENUM_CHAR_MODE : short
{
	CharMode_UnderControl = 0x0,
	CharMode_Normal = 0x1,
	CharMode_FlyFormation = 0x2,
	CharMode_PowerAirSpin = 0x4,
	CharMode_PowerAttackHold = 0x8,
	CharMode_PowerAttackGather = 0x9,
	CharMode_ThunderShoot = 0xE,
	CharMode_Return = 0xF,
	CharMode_Inactive = 0x11,
	CharMode_Disabled = 0x12,
};


enum PlayerAnimation
{
	PlayerAnimation_Stand = 0x0,
	PlayerAnimation_Idle = 0x2,
	PlayerAnimation_Idle2 = 0x3,
	PlayerAnimation_Walk = 0x4,
	PlayerAnimation_Run = 0x5,
	PlayerAnimation_Run2 = 0x6,
	PlayerAnimation_Run3 = 0x7,
	PlayerAnimation_Run3_ = 0x8,
	PlayerAnimation_Roll = 0x9,
	PlayerAnimation_RollStill_ = 0xA,
	PlayerAnimation_Launched = 0xB,
	PlayerAnimation_Falling = 0xC,
	PlayerAnimation_Falling_MaybeFast = 0xD,
	PlayerAnimation_StandingLand = 0xE,
	PlayerAnimation_StandingLand2 = 0xF,
	PlayerAnimation_LandWalking = 0x10,
	PlayerAnimation_SkidStart = 0x11,
	PlayerAnimation_Skid = 0x12,
	PlayerAnimation_SkidStop = 0x13,
	PlayerAnimation_SkidTurnLeftStart = 0x14,
	PlayerAnimation_SkidTurnLeftStop = 0x15,
	PlayerAnimation_HurtStart = 0x16,
	PlayerAnimation_HurtAir = 0x17,
	PlayerAnimation_HurtGround = 0x18,
	PlayerAnimation_FanFloat = 0x19,
	PlayerAnimation_Land_ = 0x1A,
	PlayerAnimation_TurnAroundLeft = 0x1B,
	PlayerAnimation_TurnAroundRight = 0x1C,
	PlayerAnimation_StopNoTurnAround_ = 0x1D,
	PlayerAnimation_TeamBlast = 0x1F,
	PlayerAnimation_TeamBlastEnd = 0x20,
	PlayerAnimation_Push = 0x21,
	PlayerAnimation_Pull = 0x22,
	PlayerAnimation_Grab = 0x23,
	PlayerAnimation_Holding = 0x24,
	PlayerAnimation_LetGo = 0x25,
	PlayerAnimation_PushLarge = 0x26,
	PlayerAnimation_Pull_MaybeLarge = 0x27,
	PlayerAnimation_Grab_MaybeLarge = 0x28,
	PlayerAnimation_Holding_MaybeLarge = 0x29,
	PlayerAnimation_LetGo_MaybeLarge = 0x2A,
	PlayerAnimation_2PIntro = 0x2B,
	PlayerAnimation_2PIntroEnd = 0x2C,
	PlayerAnimation_2PIntroInactive_ = 0x2D,
	PlayerAnimation_VictoryPose = 0x2E,
	PlayerAnimation_VictoryPoseEnd = 0x2F,
	PlayerAnimation_Captured_ = 0x30,
	PlayerAnimation_Dead = 0x31,
	PlayerAnimation_StunnedOrDead2 = 0x32,
	PlayerAnimation_TripStart = 0x33,
	PlayerAnimation_Trip = 0x34,
	PlayerAnimation_TripEnd = 0x35,
	PlayerAnimation_JumpCurl = 0x36,
	PlayerAnimation_JumpRoll = 0x37,
	PlayerAnimation_JumpUncurl = 0x38,
	PlayerAnimation_JumpFall = 0x39,
	PlayerAnimation_JumpPad = 0x3B,
	PlayerAnimation_FlightFormationRelated_ = 0x3C,
	PlayerAnimation_Hang = 0x3D,
	PlayerAnimation_Trick = 0x3E,
	PlayerAnimation_Glide = 0x3F,
	PlayerAnimation_FlightFormationStill = 0x40,
	PlayerAnimation_FlightFormationMove = 0x41,
	PlayerAnimation_FlightFormationRelated = 0x42,
	PlayerAnimation_FlightFormationRelated2 = 0x43,
	PlayerAnimation_RollRelated = 0x44,
	PlayerAnimation_JumpDash = 0x45,
	PlayerAnimation_OnRail = 0x46,
	PlayerAnimation_GrindHold = 0x49,
	PlayerAnimation_GrindStart = 0x4C,
	PlayerAnimation_GrindEnd = 0x4D,
	PlayerAnimation_BottomFlyFormationRail = 0x4E,
	PlayerAnimation_SuperTeamBlastIntro = 0x52,
	PlayerAnimation_SuperTeamBlast = 0x53,
	PlayerAnimation_SuperVictoryPose = 0x54,
	PlayerAnimation_SuperVictoryPoseEnd = 0x55,
	PlayerAnimation_RingThrow = 0x5A,
	PlayerAnimation_RingDash = 0x5A,
	PlayerAnimation_PowerAirAttack = 0x5A,
	PlayerAnimation_WallStand = 0x5B,
	PlayerAnimation_PowerAttack = 0x5B,
	PlayerAnimation_FlyBobsled = 0x5C,
	PlayerAnimation_WallJump = 0x5C,
	PlayerAnimation_PowerAttack2 = 0x5C,
	PlayerAnimation_BackFlip = 0x5D,
	PlayerAnimation_PowerAttack3Start = 0x5D,
	PlayerAnimation_SideFlip = 0x5E,
	PlayerAnimation_PowerAttack3 = 0x5E,
	PlayerAnimation_BackFlip2 = 0x5F,
	PlayerAnimation_PowerAttack3End = 0x5F,
	PlayerAnimation_LeafTornado = 0x60,
	PlayerAnimation_PowerPunch2 = 0x60,
	PlayerAnimation_HammerSwingStart = 0x61,
	PlayerAnimation_PowerPunch3 = 0x61,
	PlayerAnimation_HammerSwing = 0x62,
	PlayerAnimation_PowerExtraAttack = 0x62,
	PlayerAnimation_HammerSwingEnd = 0x63,
	PlayerAnimation_HammerTornado = 0x64,
	PlayerAnimation_HammerTornadoEnd = 0x65,
	PlayerAnimation_HammerFloat = 0x66,
	PlayerAnimation_PowerBobsled = 0x66,
	PlayerAnimation_ThrowStar = 0x67,
	PlayerAnimation_SlideKick = 0x68,
};


enum ENUM_PLAYER_VOICE
{
	VOICE_FlyStart = 0x9,
};



// Struct Forward Declarations //
struct TObject;
struct EffShadow;
struct EffWink;
struct CCL_INFO;
struct C_COLLI;
struct PLAYERWK;
struct TObjSonic;
struct TObjPlayer__vtable;
struct TObjPlayer;
struct TObject;
struct TObjTeam;
// ~Struct Forward Declarations~ //


// Typedefs //
// ~Typedefs~ //


// Incomplete Types //

/*namespace TObjMiles
{

}*/
// ~Incomplete Types~ //



struct EffShadow
{
	char gap0[4];
	float field_4;
	char gap8[52];
	int field_0;
};


struct EffWink
{
	RwReal blinkIndex;
	char gap4[4];
	RwReal blinkSpeed;
	char gapC[12];
	int blinkCount;
	int field_1C;
	int field_0;
};


struct CCL_INFO
{
	int statusBitsMaybe;
	int statusBitsMaybe2;
	RwV3d collisionPosition;
	RwReal objectCollisionRadius;
	RwReal objectCollisionRadiusRelatedMaybe;
	RwReal horizontalObjectCollisionRadiusMaybe;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	RwV3d field_38;
	RwReal field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
};


struct C_COLLI
{
	C_COLLI** field_0;
	__int16 strength;
	__int16 vitality;
	__int16 field_8;
	__int16 field_A;
	float range;
	CCL_INFO* CCL_INFO;
	char gap14[76];
	RwV3d position;
	sAngle angle;
	int characterId;
	char gap7C[8];
	int field_84;
};


struct PLAYERWK
{
	short hangTime;
	short WORD_0x02;
	char array_0x04[12];
	float float_0x10;
	float float_0x14;
	float jumpPower;
	float float_0x1c;
	float decelerationRelated;
	float walk2AnimationSpeed;
	float run1AnimationSpeed;
	float run2AnimationSpeed;
	float float_0x30;
	float run3AnimationSpeed;
	float float_0x38;
	float aiSpeedRelatedMaybe;
	float float_0x40;
	float groundDeceleration;
	float skidDeceleration1;
	float jumpBallTurnAroundDeceleration;
	float airDeceleration;
	float run3Or2AccelerationMaybe;
	float upAndDownForceMaybe;
	float sidewaysDecelerationMaybe;
	float skidDeceleration2;
	float sidewaysSpeedRelated;
	float affectsRun1StartSpeedMaybe;
	float float_0x6c;
	float amountBumpedFromTeamMemberMaybe;
	float collisionSizeRelatedMaybeGeo;
	float weight;
	float float_0x7c;
	float objectCollisionAndMaybeDrawingYOffsetAffected;
};


struct TObjPlayer__vtable
{
	int(__thiscall* vtable__sub_5CC170)(int, char);
	int(__thiscall* Exec)(TObjPlayer*);
	char(__thiscall* vtable__sub_5D1A20)(TObjPlayer*);
	void(__thiscall* vtable__sub_5D1F90)(TObjPlayer*);
	void(__thiscall* vtable__nullsub_1)(void*);
	void(__thiscall* vtable__nullsub_1_2)(void*);
	void(__thiscall* vtable__nullsub_1_3)(void*);
	void(__thiscall* vtable__nullsub_1_4)(void*);
	void(__stdcall* vtable__nullsub_4)(int);
	void(__thiscall* vtable__nullsub_1_5)(void*);
	int(__thiscall* TObjOldPlayer__ResetWorks)(void*);
	int(__thiscall* TObjOldPlayer__AddClump)(int);
	int(__thiscall* vtable__sub_581CF0)(int);
	int(__thiscall* TObjSonic__DeleteParticleTask)(void*);
	int(__thiscall* vtable__sub_5CCBC0)(TObjPlayer*);
	int(__thiscall* vtable__sub_5CCC80)(TObjPlayer*);
	void(__thiscall* vtable__nullsub_1_6)(void*);
	void(__thiscall* vtable__nullsub_1_7)(void*);
	void(__thiscall* vtable__nullsub_1_8)(void*);
	int(__thiscall* vtable__sub_5D1830)(TObjPlayer*);
	int(__thiscall* vtable__sub_5D1E90)(TObjPlayer*);
	char(__thiscall* vtable__sub_5D2C50)(int);
	char(__thiscall* vtable__sub_5CB160)(TObjPlayer*);
	int(__thiscall* TObjOldPlayer__ResetSpecialWorks)(TObjPlayer*);
	void(__thiscall* vtable__nullsub_1_9)(void*);
	void(__thiscall* vtable__nullsub_1_10)(void*);
	void(__thiscall* vtable__nullsub_1_11)(void*);
	void(__thiscall* vtable__nullsub_1_12)(void*);
};


struct TObjPlayer
{
	TObjPlayer__vtable* vtbl;
	char objectName;
	char gap5[25];
	char objectSize;
	char gap1F[13];
	C_COLLI C_COLLI;
	char gapB4[6];
	char characterNo;
	char characterKind;
	char suitNo;
	char gapBD[1];
	char teamNo;
	char teamMemberID;
	char controllerNo;
	char role;
	char formationLeaderNo;
	char gapC3[1];
	__int16 ItemFlags;
	char gapC6[2];
	int superFlag;
	TObjTeam* pTObjTeam;
	char gapD0[4];
	short jumpBallTime;
	short delayMovementTime;
	short idleTime;
	char gapDA[2];
	short nextAnimationMaybe;
	char gapDE[2];
	float slopeAngle;
	char gapE4[16];
	short mode;
	short stateCopy;
	short modeChange;
	short flashTimer;
	RwV3d flt_0xfc;
	float hSpeed;
	float VSpeed;
	float sidewaysSpeedMaybe;
	RwV3d position;
	sAngle rotation;
	RwV3d scale;
	RwV3d speedCopy;
	RwV3d acceleration;
	sAngle rotationCopy;
	RwV3d pushedSpeed;
	char gap168[24];
	sAngle accelerationDirection;
	RwV3d slopeCollisionAngleMaybe;
	int int0x198_wallJumpRotationMaybe;
	int int0x19C_wallJumpRotationMaybe;
	int int0x1A0_wallJumpRotationMaybe;
	int statusRelated0x1A4;
	int statusRelated0x1A8;
	int playerStatus_0x1AC_PhysicsMaybe;
	char gap1B0[4];
	int field_1B4;
	int statusRelated0x1B8;
	int statusBits;
	char playerStatus_0x1C0;
	char gap1C1[3];
	PLAYERWK playerpwp;
	char waterEffectIs2;
	char gap249[7];
	int int_0x250;
	int int_0x254;
	float groundBelowFallMaybe;
	float groundHeight;
	char gap260[12];
	RwV3d flyFormationPosition;
	int npcTargetRelatedMaybe0x278;
	float field_27C;
	float notStartMovingRad;
	float distanceXZToTargetPosCopy;
	float distanceXZToTargetPos;
	char gap28C[60];
	ENUM_CHAR_MODE charMode;
	ENUM_CHAR_MODE lastAIState;
	ENUM_CHAR_MODE charModeReserve;
	short relatedToSwitchingRails;
	float pathPointDistance;
	void* PATHTAG;
	char gap2D8[5];
	char finaleFlipType;
	short airAttackTimer;
	short airAttackTimer2;
	char gap2E2[6];
	int flyFormationYTilt;
	char gap2EC[4];
	int flyFormationZTilt;
	int flyFormationBoostYTilt;
	char gap2F8[20];
	short grindTimer;
	char gap30E[6];
	short powerAirSpinTimer;
	char gap316[2];
	float powerAirSpinPositionRelated;
	short tornadoTimer;
	char gap31E[6];
	RwV3d tornadoOrigin;
	char gap330[16];
	int someTimerMaybeFlashRelated;
	char gap344[84];
	short animationIndex;
	short animation;
	short animationCopy;
	char gap39E[46];
	void* clump_3CC;
	char gap3D0[332];
	RwV3d spinballPointyEffectPosition;
	char gap528[1012];
	void* pTexture;
	void* textureRelated;
	int muteCount;
	EffShadow EffShadow;
	char gap968[44];
	float flightGuageAmount;
	char gap998[24];
	EffWink pEffWink;
	char gap9D4[28];
	int* pSuperSonicAura;
	char gap9F4[12];
	void* pSuperSonicSparkles;
	char gapA04[56];
	char field_0;
};


struct TObjMiles
{
	static TObjMiles* ChangeModeFormationFly(TObjMiles* result);


	TObjPlayer__vtable* vtable;
	char objectName;
	char gap5[25];
	char objectSize;
	char gap1F[13];
	int collisionNumberMaybe;
	short currentDamage;
	char gap32[10];
	CCL_INFO* collisionStuff;
	char gap40[100];
	int CCLCharacterId;
	char gapA8[18];
	char formationTypeID;
	char characterID;
	char suitNo;
	char field_BD;
	char teamNo;
	char teamMemberID;
	char controllerNo;
	char role;
	char formationLeaderNo;
	char gapC3;
	__int16 ItemFlags;
	char gapC6[2];
	int superFlag;
	TObjTeam* pTObjTeam;
	char gapD0[4];
	short jumpBallTime;
	short delayMovementTime;
	short idleTime;
	char gapDA[2];
	short nextAnimationMaybe;
	char gapDE[2];
	float slopeAngle;
	char gapE4[16];
	short mode;
	short stateCopy;
	short modeChange;
	short flashTimer;
	float flt_0xfc;
	float flt_0x100;
	float flt_0x104;
	float hSpeed;
	float VSpeed;
	float sidewaysSpeedMaybe;
	RwV3d position;
	sAngle rotation;
	RwV3d scale;
	RwV3d speedCopy;
	RwV3d acceleration;
	sAngle rotationCopy;
	RwV3d pushedSpeed;
	char gap168[24];
	sAngle accelerationDirection;
	RwV3d slopeCollisionAngleMaybe;
	int int0x198_wallJumpRotationMaybe;
	int int0x19C_wallJumpRotationMaybe;
	int int0x1A0_wallJumpRotationMaybe;
	int statusRelated0x1A4;
	int statusRelated0x1A8;
	int playerStatus_0x1AC_PhysicsMaybe;
	char gap1B0[4];
	int field_1B4;
	int statusRelated0x1B8;
	int statusBits;
	char playerStatus_0x1C0;
	char gap1C1[3];
	PLAYERWK playerpwp;
	char waterEffectIs2;
	char gap249[7];
	int int_0x250;
	int int_0x254;
	float groundBelowFallMaybe;
	float groundHeight;
	char gap260[12];
	RwV3d flyFormationPosition;
	int npcTargetRelatedMaybe0x278;
	char gap27C[4];
	float notStartMovingRad;
	float distanceXZToTargetPosCopy;
	float distanceXZToTargetPos;
	char gap28C[60];
	ENUM_CHAR_MODE charMode;
	ENUM_CHAR_MODE lastAIState;
	ENUM_CHAR_MODE charModeReserve;
	__int16 relatedToSwitchingRails;
	float pathPointDistance;
	void* PATHTAG;
	char gap2D8[5];
	char finaleFlipType;
	short airAttackTimer;
	short airAttackTimer2;
	char gap2E2[6];
	int flyFormationYTilt;
	char gap2EC[4];
	int flyFormationZTilt;
	int flyFormationBoostYTilt;
	char gap2F8[20];
	short grindTimer;
	char gap30E[6];
	short powerAirSpinTimer;
	char gap316[2];
	float powerAirSpinPositionRelated;
	char gap31C[36];
	int someTimerMaybeFlashRelated;
	char gap344[84];
	short animationIndex;
	short animation;
	short animationCopy;
	char gap39E[46];
	void* clump_3CC;
	char gap3D0[332];
	RwV3d spinballPointyEffectPosition;
	char gap528[1012];
	void* pTexture;
	void* textureRelated;
	int field_924;
	char gap928[94];
	__int16 ringBombCounterMaybe;
	RwV3d flyStartPosition;
	float flyGuageAmount;
	char gap998[24];
	EffWink pEffWink;
	char gap9D4[40];
	float tailSpinSpeedMaybe;
	char gapA00[2];
	__int16 tailActionSpeed;
	__int16 tailActionDirection;
	__int16 tailActionRelated;
	char gapA08[2];
	__int16 tailMotionRelatedMaybe;
	char gapA0C[100];
	int field_0;
};


struct PlayerMaster
{
	struct pos_history_struct
	{
		RwV3d entry[1536];
	};

	struct ang_history_struct
	{
		sAngle entry[1536];
	};
	

	static int InitPlayersWork();
	static RwV3d* GetPlayerPositionHistory(int a1, unsigned char a2);


	static pos_history_struct*& pos_history;
	static ang_history_struct*& ang_history;
	static char& n_history;
};
//


// Function Prototypes //
signed int GetPlayerPosition(int a1, char a2, sAngle* angle, RwV3d* position);
signed int CallPlayerVoice(int characterID, ENUM_PLAYER_VOICE voiceID, int formationID);
void ChangeModeFormationFly_Hook();
float Distance2P2P(RwV3d const* a1, RwV3d const* a2);
// ~Function Prototypes~ //


// Global Variables //
extern TObjPlayer** const playerTOp;
extern int*& VoiceId_AdxTable;
// ~Global Variables~ //