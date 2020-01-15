#pragma once
//#pragma comment (lib, "lib\\d3d8.lib")
//#pragma comment (lib, "lib\\d3dx8.lib")
#pragma comment (lib, "lib\\dinput8.lib")
//#pragma comment (lib, "dinput.lib")
//#pragma comment (lib, "dxguid.lib")

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include "Controls.hpp"


// Incomplete Types //
typedef void* PVOID;
typedef PVOID HANDLE;
typedef HANDLE _HWND;
#define LOBYTE(x)   (*((char*)&(x)))   // low byte
#define LOWORD(x)   (*((short*)&(x)))   // low word
#define LODWORD(x)  (*((int*)&(x)))
#define HIBYTE(x)   (*((char*)&(x)+1))
#define HIWORD(x)   (*((short*)&(x)+1))
#define HIDWORD(x)  (*((int*)&(x)+1))
#define BYTEn(x, n)   (*((char*)&(x)+n))
#define WORDn(x, n)   (*((short*)&(x)+n))
#define BYTE1(x)   BYTEn(x,  1)         // byte 1 (counting from 0)
#define BYTE2(x)   BYTEn(x,  2)
/*#define BYTE3(x)   BYTEn(x,  3)
#define BYTE4(x)   BYTEn(x,  4)
#define BYTE5(x)   BYTEn(x,  5)
#define BYTE6(x)   BYTEn(x,  6)
#define BYTE7(x)   BYTEn(x,  7)
#define BYTE8(x)   BYTEn(x,  8)
#define BYTE9(x)   BYTEn(x,  9)
#define BYTE10(x)  BYTEn(x, 10)
#define BYTE11(x)  BYTEn(x, 11)
#define BYTE12(x)  BYTEn(x, 12)
#define BYTE13(x)  BYTEn(x, 13)
#define BYTE14(x)  BYTEn(x, 14)
#define BYTE15(x)  BYTEn(x, 15)
#define WORD1(x)   WORDn(x,  1)
#define WORD2(x)   WORDn(x,  2)         // third word of the object, unsigned
#define WORD3(x)   WORDn(x,  3)
#define WORD4(x)   WORDn(x,  4)
#define WORD5(x)   WORDn(x,  5)
#define WORD6(x)   WORDn(x,  6)
#define WORD7(x)   WORDn(x,  7)*/
#define SLOBYTE(x)   (*((char*)&(x)))
// ~Incomplete Types~ //


// Function Prototypes //
BOOL EnumJoysticksCallback(LPCDIDEVICEINSTANCE a1, LPVOID pvRef);
BOOL DIEnumDeviceObjectsCallback(LPCDIDEVICEOBJECTINSTANCE a1, LPVOID pvRef);
int DIEnumEffectsCallback(LPCDIEFFECTINFOA pdei, LPVOID pvRef);
int sub_445B80(int result);
//int __stdcall WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
//int registerWindowClass(HINSTANCE a1);
//int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

namespace PCSpecific
{
	char InitControllers();
	HRESULT SetupDInput();
}
namespace PC
{
	signed int locateDVDRoot();
	void findGameDiskDrive();
	signed int isValidGameRoot(const char* a1);
}

// ~Function Prototypes~ //


// Global Variables //
static char* unk_723010 = (char*)0x723010;
static char* unk_722FD0 = (char*)0x722FD0;
static char* unk_722FE0 = (char*)0x722FE0;
static LPCSTR& lpClassName = *(LPCSTR*)0x7C9288;
static int &G_CharmyShutup = *(int*)0x8CAEF8;
static int* dword_A2F968 = (int*)0xA2F968;
static gPADStruct** gPAD = (gPADStruct**)0xA2F948;
static float &mouseIntensityXCopy = *(float*)0xA2FD28;
static float &mouseIntensityYCopy = *(float*)0xA2FD2C;
static int* gDUMMY = (int*)0xA2FD30;
static int &dword_A2FD50 = *(int*)0xA2FD50;
static float &mouseIntensityX = *(float*)0xA2FD54;
static float &mouseIntensityY = *(float*)0xA2FD58;
static HWND &hwnd = *(HWND*)0xA2FD5C;
static int &PauseBGMOnFocusLoss = *(int*)0xA2FD64;
static int &appValue12 = *(int*)0xA2FD68;
static int &appValue11 = *(int*)0xA2FD6C;
static IDirectInput8* &g_pDI = *(IDirectInput8**)0xA77978;
static LPDIRECTINPUTDEVICE8 &g_pKeyboard = *(LPDIRECTINPUTDEVICE8*)0xA7797C;
static LPDIRECTINPUTDEVICE8* g_pJoystick = (LPDIRECTINPUTDEVICE8*)0xA77980;
static LPDIRECTINPUTDEVICE8 &g_pMouse = *(LPDIRECTINPUTDEVICE8 *)0xA77988;
static int &dword_A77994 = *(int*)0xA77994;
static int &controllersInitialized = *(int*)0xA77998;
static LPDIRECTINPUTEFFECT* ppdeff = (LPDIRECTINPUTEFFECT*)0xA7798C;

static DIDEVCAPS lpDIDevCaps;
static HANDLE hMutex;
static int Perf;
static int dword_A8214C;

namespace PC
{
	static char &discDrive = *(char*)0xA78D28;
	static char* discDVDRoot = (char*)0xA78F38;
}
// ~Global Variables~ //