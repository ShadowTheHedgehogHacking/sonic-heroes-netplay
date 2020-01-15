#pragma once

#include "Renderware.hpp"



// Struct Definitions //
struct LandManagerStruct
{
	char gap0[780];
	int cam1BlockVisibility;
	char gap310[60];
	int cam2BlockVisibility;
	char gap350[60];
	char field_38C;
	char gap38D[63];
	char field_3CC;
	char gap3CD[28295];
	int* field_7254;
	char gap7258[156];
	char field_72F4;
	char gap72F5[6439];
	RwTexDictionary* texDictionary;
	char gap8C20[8];
	char field_8C28;
	int field_0;
};



// Global Variables //
extern LandManagerStruct* LandManager;