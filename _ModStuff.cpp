#include "pch.h"
#include "_ModStuff.hpp"



bool ConnectionManager::listen(unsigned short port, const char* const & ip, bool isBlocking)
{
	if (!listener)
	{
		listener = new Listener;
		listener->socket->setBlocking(isBlocking); // non-blocking by default to keep thread from freezing
	}

	bool status;
	if (ip != "") //just in caese address_any is useful??
	{
		if (listener->socket->listen(port, ip) == sf::Socket::Done)
		{
			status = true;
		}
		else
		{
			status = false;
		}
	}
	else
	{
		if (listener->socket->listen(port) == sf::Socket::Done)
		{
			status = true;
		}
		else
		{
			status = false;
		}
	}
	return status;
}


bool ConnectionManager::accept()
{
	connection = new Connection;

	if (connection)
	{
		if (listener->socket->accept(*connection->socket) == sf::Socket::Done)
		{
			return true;
		}
		delete connection;
		connection = NULL;
		return false;
	}
}


bool ConnectionManager::connect(const char* const& remoteAddress, unsigned short remotePort)
{
	if (connection->socket->connect(remoteAddress, remotePort) == sf::Socket::Done)
	{
		return true;
	}
	return false;
}


ConnectionManager::~ConnectionManager()
{
	if (listener)
	{
		delete listener;
		listener = NULL;
	}
}


Connection::Connection(bool isTCP, bool isBlocking)
{
	socket = new sf::TcpSocket;
	socket->setBlocking(isBlocking); // non-blocking by default to keep thread from freezing
}

Connection::~Connection()
{
	delete socket;
}