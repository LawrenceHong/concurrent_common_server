// libevent_test.cpp : 定义控制台应用程序的入口点。
//

#include "HttpContainer.h"
#include "LibeventLog.h"
#include "Configure.h"
#include "TcpClientThread.h"
#include "TcpServer.h"
#include "HttpServer.h"
#include "TimeoutServer.h"
#include "InputHandler.h"

#include "TcpServerMsgHandler.h"
#include "ConnectionManager.h"

class MyTcpServer : public TcpServer {
public:
	MessageHandler *createMsgHandler() {
		return new TcpServerMsgHandler();
	}
};


int main(int argc, char *argv[]) {
	HttpContainer *container = new PersistHttpContainer();
	container->addServer(new MyTcpServer());
	container->addServer(new HttpServer());
	container->addServer(new TimeoutServer());

	TcpClientThread *td = new TcpClientThread(new InputHandler());
	td->start();

	container->loop();
	td->exitThread();
	td->milliSleep(1000);
	delete td;
	delete container;

	ConnectionManager *cfg = ConnectionManager::getInstance();
	delete cfg;
}

