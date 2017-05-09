#include <iostream>
#include <QtSql>
#include <QApplication>
#include "workingwithdb.h"
#include "mainwindow.h"
#include "dialog.h"

using namespace std;

bool querySuccessful;
int newGroup;

int main(int argc, char *argv[])
{
	//Test Table Model
	connectToDatabases();
	/*QString database = "live";
	QObject *parent = NULL;
	QSqlDatabase db = QSqlDatabase::database(database);*/

	/*QSqlTableModel model;
	qDebug() << model.database();
	model.setTable("groups");
	model.select();
	for(int i = 0; i < model.rowCount(); ++i)
	{
		int groupNumber = model.record(i).value("number").toInt();
		cout << groupNumber << endl;
	}*/

	/*
	QSqlTableModel *model = new QSqlTableModel(parent, db);
	qDebug() << model->database();
	model->setTable("groups");
	model->select();
	for(int i = 0; i < model->rowCount(); ++i)
	{
		int groupNumber = model->record(i).value("number").toInt();
		cout << groupNumber << endl;
	}*/


	QApplication app(argc, argv);
	Dialog loginDialog;
	loginDialog.show();

	//Test selection
	/*QSqlDatabase db = QSqlDatabase::database();
	QSqlQuery query(db);
	querySuccessful = query.exec("SELECT * FROM groups");
	if(!querySuccessful)
	{
		qDebug() << query.QSqlQuery::lastError();
	}
	else
	{
		while(query.next())
		{
			int group = query.value(0).toInt();
			cout << group << endl;
		}
		cout << query.size() << endl;
	}*/
	//Test insertion
	/*query.prepare("INSERT INTO groups (number) VALUES (:number)");
	query.bindValue(":number", newGroup);
	query.exec();*/

	//Test selection
	/*querySuccessful = query.exec("SELECT * FROM groups");
	if(!querySuccessful)
	{
		qDebug() << query.QSqlQuery::lastError();
	}
	else
	{
		while(query.next())
		{
			int group = query.value(0).toInt();
			cout << group << endl;
		}
		cout << query.size() << endl;
	}*/
	return app.exec();
}
