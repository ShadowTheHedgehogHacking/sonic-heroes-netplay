// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "_Hook.hpp"
#include "includes/HeroesLib/Controls.hpp"
#include "includes/HeroesLib/action.hpp"
#include "includes/HeroesLib/advertise.hpp"
#include "includes/SFML/Network.hpp"
#include <thread>
#include <future>



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

	sf::TcpSocket* socket = NULL;
	sf::TcpListener* listener = NULL;
	sf::TcpSocket* client = NULL;

	while (running)
	{
		// TODO: put client listening and server reading here


		if (Action.mode == 1) // If Game Mode is "in a menu"
		{
			if (Advertise.subMode == 11) // if Current Menu is 2P Menu
			{
				if (isHost)
				{
					if (!listener)
					{
						listener = new sf::TcpListener;
						listener = NULL;
					}
					listener->setBlocking(false); // Thread doesn't freeze while waiting for client
					
					if (listener->listen(53000) != sf::Socket::Done) // bind the listener to a port
					{
						// error...
					}

					// accept a new connection
					if (client)
					{
						delete client;
						client = NULL;
					}
					client = new sf::TcpSocket;
					client->setBlocking(false); // Thread doesn't freeze while waiting for packet
					if (listener->accept(*client) != sf::Socket::Done)
					{
						// no new client or error
					}
				}
				else
				{
					if (socket)
					{
						delete socket;
						socket = NULL;
					}
					socket = new sf::TcpSocket;
					socket->setBlocking(false); // Thread doesn't freeze while waiting for packet
					sf::Socket::Status status = socket->connect("localhost", 53000);
					if (status != sf::Socket::Done)
					{
						// error...
					}
				}
			}
		}
		Sleep(20);
	}
}