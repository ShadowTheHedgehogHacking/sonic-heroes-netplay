#pragma once
#include "TObject.hpp"


struct TObjCamera;
struct TObjCamera__cameraParam;



//(Temp) CLASS STATIC VARIABLES//
//extern TObjCamera::cameraParam** const TObjCamera::CameraParameterP;
//extern TObjCamera::cameraParam** const TObjCamera::CurrentCameraParameterP;
//extern int const& TObjCamera__maxCamera;
//extern int& TObjCamera::currentCamera;
extern TObjCamera* const& cameraTp;
//~(Temp) CLASS STATIC VARIABLES//



struct TObjCamera__cameraParam
{
	float xPosition;
	float yPosition;
	float zPosition;
	int zAngle;
	int xAngle;
	int yAngle;
	char gap18[6];
	short objectSize;
	char gap20[4];
	float aimXPosition;
	float aimZPosition;
	float aimYPosition;
	float xSpeed;
	float zSpeed;
	float ySpeed;
	int stateOrPresetAngle_;
	char gap40[12];
	int cameraLevel;
	int cameraMode;
	char gap54[8908];
	int field_58;
};

struct TObjCamera
{
	TObject TObject;
	int* RwCamera;
	RwRaster* frameBuffer;
	RwRaster* frameBufferSubRaster[4];
	RwRaster* zBuffer;
	RwRaster* zBufferSubRaster[4];
	char gap54[4];
	int field_0;


	struct cameraParam
	{
		float xPosition;
		float yPosition;
		float zPosition;
		int zAngle;
		int xAngle;
		int yAngle;
		char gap18[6];
		short objectSize;
		char gap20[4];
		float aimXPosition;
		float aimZPosition;
		float aimYPosition;
		float xSpeed;
		float zSpeed;
		float ySpeed;
		int stateOrPresetAngle_;
		char gap40[12];
		int cameraLevel;
		int cameraMode;
		char gap54[8908];
		int field_58;
	};

	static cameraParam** const CameraParameterP;
	static cameraParam** const CurrentCameraParameterP;
	static int const& maxCamera;
	static int &currentCamera;
};



