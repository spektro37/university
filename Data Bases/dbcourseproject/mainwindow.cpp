#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workingwithdb.h"
#include <QMessageBox>
#include <QtSql>
#include <QColor>

MainWindow::MainWindow(QWidget *parent, QSqlDatabase db, QString accessLevel) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QPalette pal(palette());
	if(db.connectionName() == "arch")
	{
		pal.setColor(QPalette::Background, QColor(165,180,255));
		this->setAutoFillBackground(true);
	}
	this->setPalette(pal);

	ui->semesters->setCurrentIndex(5);
	ui->semesters->setEnabled(0);
	qDebug() << accessLevel << endl;
	qDebug() << db.connectionName() << endl;
	if(accessLevel == "Curator" && db.connectionName() == "arch")
	{
		ui->currentControlDate->setEnabled(0);
		ui->currentControlTime->setEnabled(0);
		ui->studentAddButton->setEnabled(0);
		ui->studentDeleteButton->setEnabled(0);
		ui->groupAddButton->setEnabled(0);
		ui->groupDeleteButton->setEnabled(0);
		ui->controlAddButton->setEnabled(0);
		ui->controlDeleteButton->setEnabled(0);
		ui->controlAddDate->setEnabled(0);
		ui->controlAddTime->setEnabled(0);
		ui->subjectAddButton->setEnabled(0);
		ui->subjectDeleteButton->setEnabled(0);
		ui->subjectAddName->setEnabled(0);
		ui->controlAddTeacher->setEnabled(0);
		ui->controlAddType->setEnabled(0);
		ui->currentResultDelete->setEnabled(0);
		ui->currentResultSave->setEnabled(0);
		ui->currentControlResult->setEnabled(0);
	}
	else if(accessLevel == "Teacher")
	{
		ui->currentControlDate->setEnabled(0);
		ui->currentControlTime->setEnabled(0);
		ui->studentAddButton->setEnabled(0);
		ui->studentDeleteButton->setEnabled(0);
		ui->groupAddButton->setEnabled(0);
		ui->groupDeleteButton->setEnabled(0);
		ui->controlAddButton->setEnabled(0);
		ui->controlDeleteButton->setEnabled(0);
		ui->controlAddDate->setEnabled(0);
		ui->controlAddTime->setEnabled(0);
		ui->subjectAddButton->setEnabled(0);
		ui->subjectDeleteButton->setEnabled(0);
		ui->subjectAddName->setEnabled(0);
		ui->controlAddTeacher->setEnabled(0);
		ui->controlAddType->setEnabled(0);
		if(db.connectionName() == "arch")
		{
			ui->currentResultDelete->setEnabled(0);
			ui->currentResultSave->setEnabled(0);
			ui->currentControlResult->setEnabled(0);
		}
		else
		{
			ui->currentResultDelete->setStyleSheet("background-color: red");
			ui->currentResultSave->setStyleSheet("background-color: #49FF38");
		}
	}
	else
	{
		ui->groupDeleteButton->setStyleSheet("background-color: red");
		ui->groupAddButton->setStyleSheet("background-color: #49FF38");
		ui->subjectDeleteButton->setStyleSheet("background-color: red");
		ui->subjectAddButton->setStyleSheet("background-color: #49FF38");
		ui->controlDeleteButton->setStyleSheet("background-color: red");
		ui->controlAddButton->setStyleSheet("background-color: #49FF38");
		ui->studentDeleteButton->setStyleSheet("background-color: red");
		ui->studentAddButton->setStyleSheet("background-color: #49FF38");
		ui->currentResultDelete->setStyleSheet("background-color: red");
		ui->currentResultSave->setStyleSheet("background-color: #49FF38");
	}

	ui->databaseSelected->setText(db.connectionName());
	QSqlTableModel *groupTableModel = new QSqlTableModel(this, db);
	groupTableModel->setTable("groups");
	groupTableModel->select();
	ui->groups->setModel(groupTableModel);
}

MainWindow::~MainWindow()
{
	delete ui;
}
