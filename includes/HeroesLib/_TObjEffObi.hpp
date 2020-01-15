#pragma once
#include "TObject.hpp"
#include "Renderware.hpp"



// Struct Definitions //
struct TObjEffObi_Node
{
	RwV3d position;
	sRealAngle3 angle;
	RwRGBA color;
	int unknown;
};



struct TObjEffObi : TObject
{
	RwRGBA* GetEffObiMaterialColor();
	TObjEffObi_Node* GetPreviousNode();
	TObjEffObi_Node* GetCurrentNode();
	int GetPreviousNodeNum();
	int GetCurrentNodeNum();
	void RenderEffObi();
	void SetEffObiMaterialColor(RwRGBA const* color);
	void Joined();
	bool CanIJoinYou();

	TObjEffObi(int a1, int characterNo);
	~TObjEffObi();
	virtual void Exec();
	virtual void Disp();
	virtual void TDisp();
	virtual void PDisp();
	virtual void PCSpecific();
	virtual void ImmAftSetRaster();
	virtual void Debug();
	virtual void Error();
	virtual void Render();

	static RwMatrix* UpdateVertexes(TObjEffObi* a1);
	static void CalcAngleXYFrom2Points(RwV3d* a1, RwV3d* a2, sRealAngle3* a3);


	char characterNo;
	bool canJoin;
	signed short short_0x2A;
	signed short short_0x2C;
	RwRGBA materialColor;
	RwReal radius;
	TObjEffObi_Node nodes[0x20];
	char gap438[13820];
	int field_0;
};
// ~Struct Definitions~ //



// Function Prototypes //
void SetEffectObi(int characterNo);
// ~Function Prototypes~ //



// Global Variables //
extern const char* CL_TObjEffObi;
extern const RwRGBA default_color_0[12];
extern const float default_radius[12];

extern RwV3d*& pos_EffObi_Local;
extern TObjEffObi** pTO_obi;
// ~Global Variables~ //