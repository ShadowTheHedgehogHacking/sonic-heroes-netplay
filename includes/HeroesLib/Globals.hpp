#pragma once

#include "Renderware.hpp"



// Incomplete Types //
struct sBitFlag
{
	unsigned int TstBit(const unsigned int a2);

	unsigned int data;
};
//



// Enums //
enum LevelID : char
{
	LevelID_SeasideHill = 0x2,
	LevelID_OceanPalace = 0x3,
	LevelID_GrandMetropolis = 0x4,
	LevelID_PowerPlant = 0x5,
	LevelID_CasinoPark = 0x6,
	LevelID_BINGOHighway = 0x7,
	LevelID_RailCanyon = 0x8,
	LevelID_BulletStation = 0x9,
	LevelID_FrogForest = 0xA,
	LevelID_LostJungle = 0xB,
	LevelID_HangCastle = 0xC,
	LevelID_MysticMansion = 0xD,
	LevelID_EggFleet = 0xE,
	LevelID_FinalFortress = 0xF,
	LevelID_TeamBattle1 = 0x11,
	LevelID_TeamBattle2 = 0x14,
	LevelID_MetalMadness = 0x17,
	LevelID_MetalOverlord = 0x18,
	LevelID_2P_SeasideCourse = 0x1A,
	LevelID_2P_CityCourse = 0x1B,
	LevelID_2P_CasinoCourse = 0x1C,
	LevelID_BonusStage1 = 0x1D,
	LevelID_BonusStage2 = 0x1E,
	LevelID_BonusStage3 = 0x1F,
	LevelID_BonusStage4 = 0x20,
	LevelID_BonusStage5 = 0x21,
	LevelID_BonusStage6 = 0x22,
	LevelID_BonusStage7 = 0x23,
	LevelID_RailCanyon_TeamChaotix = 0x24,
	LevelID_2P_SeasideHill = 0x25,
	LevelID_2P_GrandMetropolis = 0x26,
	LevelID_2P_BINGOHighway = 0x27,
	LevelID_2P_CityTop = 0x28,
	LevelID_2P_CasinoRing = 0x29,
	LevelID_2P_TurtleShell = 0x2A,
	LevelID_2P_EggTreat = 0x2B,
	LevelID_2P_PinballMatch = 0x2C,
	LevelID_2P_HotElevator = 0x2D,
	LevelID_2P_RockRoad = 0x2E,
	LevelID_2P_MadExpress = 0x2F,
	LevelID_2P_TerrorHall = 0x30,
	LevelID_2P_RailCanyon = 0x31,
	LevelID_2P_FrogForest = 0x32,
	LevelID_2P_EggFleet = 0x33,
	LevelID_SpecialStage1 = 0x34,
	LevelID_SpecialStage2 = 0x35,
	LevelID_SpecialStage3 = 0x36,
	LevelID_SpecialStage4 = 0x37,
	LevelID_SpecialStage5 = 0x38,
	LevelID_SpecialStage6 = 0x39,
	LevelID_SpecialStage7 = 0x3A,
	LevelID_2P_SpecialStage1 = 0x3B,
	LevelID_2P_SpecialStage2 = 0x3C,
	LevelID_2P_SpecialStage3 = 0x3D,
};
// ~Enums~ //



// Function Prototypes //
signed int LoadFile(char* fileName, int* a2);
signed int btpsGetLanguage();
// ~Function Prototypes~ //



// Global Variables //
extern RwV3d& AxisZ;
extern RwV3d& AxisX;
extern RwV3d& AxisY;
extern int& sync_const;
extern int& sync_count;
extern char& G_Language;
extern int& stageNo;
extern RwMatrix& MatrixStack;
extern RwReal* const& sine;
extern RwMatrix*& pCurrentMatrix;
extern int& dword_A77898;
// ~Global Variables~ //