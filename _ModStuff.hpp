#pragma once
#include "includes/SFML/Network.hpp"


class Connection
{
public:
	Connection(bool isTCP = true, bool isBlocking = false);
	~Connection();


	sf::TcpSocket* socket;
};


class Listener
{
public:
	sf::TcpListener* socket;
};


class ConnectionManager
{
public:
	bool listen(unsigned short port, const char* const & ip = "", bool isBlocking = false);
	bool accept();
	bool connect(const char* const& remoteAddress, unsigned short remotePort);

	~ConnectionManager();

	Connection* connection;

private:
	Listener* listener;
};