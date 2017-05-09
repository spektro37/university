#include <iostream>
#include <QtSql>
#include <fstream>

using namespace std;

int connectToDatabases()
{
	int liveDbOpened, archDbOpened, dbsOpened;

	QSqlDatabase dbLive = QSqlDatabase::addDatabase("QMYSQL", "live");
	dbLive.setHostName("localhost");
	dbLive.setDatabaseName("dbcourseproject");
	dbLive.setUserName("dbcourseproject");
	dbLive.setPassword("Kosinus)12");
	liveDbOpened = dbLive.open();
	if(!liveDbOpened)
	{
		qDebug() << dbLive.lastError();
	}

	QSqlDatabase dbArch = QSqlDatabase::addDatabase("QMYSQL","arch");
	dbArch.setHostName("localhost");
	dbArch.setDatabaseName("dbcourseprojarch");
	dbArch.setUserName("dbcourseprojarch");
	dbArch.setPassword("Kosinus)12");
	archDbOpened = dbArch.open() * 2;
	if(!archDbOpened)
	{
		qDebug() << dbArch.lastError();
	}
	dbsOpened = liveDbOpened + archDbOpened;
	return dbsOpened;
}

void disconnectFromDatabases()
{
	QSqlDatabase dbLive = QSqlDatabase::database("live");
	dbLive.close();
	QSqlDatabase::removeDatabase("live");

	QSqlDatabase dbArch = QSqlDatabase::database("arch");
	dbArch.close();
	QSqlDatabase::removeDatabase("arch");
}
