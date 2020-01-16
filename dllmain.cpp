// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "_Hook.hpp"
#include "includes/HeroesLib/Controls.hpp"
#include "includes/HeroesLib/action.hpp"
#include "includes/HeroesLib/advertise.hpp"
#include "includes/SFML/Network.hpp"
#include <thread>
#include <future>
#include "_ModStuff.hpp"



extern "C" __declspec(dllexport) void Init();
void DoIt();



BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		Init();
		break;
	}
	case DLL_THREAD_ATTACH:
	{
		break;
	}
	case DLL_THREAD_DETACH:
	{
		break;
	}
	case DLL_PROCESS_DETACH:
	{
		break;
	}
	}
	return TRUE;
}


extern "C" __declspec(dllexport) void Init()
{
	Hook Hooker;

	//Hooker.Replace(0x5865E0, MakePlayersKeyData);
	std::thread t1(DoIt);
	t1.detach();
	//MakePlayersKeyData();
	//DoIt();
}


void DoIt()
{
	bool running = true;
	bool error = false;
	bool isHost = false;
	char lastError = 0;
	short timeOutCount = 0;

	ConnectionManager* manager = new ConnectionManager;

	while (running)
	{
		if (Action.mode == 1) // If Game Mode is "in a menu"
		{
			if (Advertise.subMode == 11) // if Current Menu is 2P Menu
			{
				if (isHost)
				{
					if (!manager->listen(53000))
					{
						//error
					}

					if (!manager->accept())
					{
						//no new client, or an error accepting
					}
				}
				else
				{
					if (!manager->connection)
					{
						if (!manager->connect("localhost", 53000))
						{
							// error
						}
					}
				}
			}
		}
		Sleep(20);
	}

	delete manager;
}