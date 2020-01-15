#pragma once
#include "TObject.hpp"
#include "setGen.hpp"



struct TObjSpring : TObject
{
	RwFrame* SetPosition();

	void Exec(double result, unsigned char a3);;


	TObject TObject;
	char gap28[4];
	BINFile* pBINFileData;
	char gap30[136];
	int bounceState;
	char relatedToAbilityToBounce;
	char alsoRelatedToAbilityToBounce;
	char byte0xBF;
	char byte0xC0;
	char byte0xC1;
	char byte0xC2;
	char byte0xC3;
	short disableControlTime;
	char gapC6[2];
	RwV3d position;
	sAngle rotation;
	int bounceAnimationIndex;
	RwV3d scaleMaybe;
	float power;
	char gapF4[346];
	int field_0;
};
