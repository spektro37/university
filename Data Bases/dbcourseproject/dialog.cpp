#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QtSql>

Dialog::Dialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);
}

Dialog::~Dialog()
{
	delete ui;
}

void Dialog::on_buttonLogin_clicked()
{
	//ui->inputUsername->setText("TestAdmin");
	//ui->inputPassword->setText("AdminPassword");
	//ui->inputPassword->setText("AdminArch");
	//ui->inputUsername->setText("TestCurator");
	//ui->inputPassword->setText("CuratorPassword");
	//ui->inputPassword->setText("CuratorArch");
	ui->inputUsername->setText("TestTeacher");
	ui->inputPassword->setText("TeacherPassword");
	//ui->inputPassword->setText("TeacherArch");
	QString username = ui->inputUsername->text();
	QString password = ui->inputPassword->text();
	QString database = ui->databases->currentText();
	QSqlDatabase db = QSqlDatabase::database(database);
	QSqlTableModel *tableModel = new QSqlTableModel(this, db);
	//qDebug() << tableModel->database();
	//qDebug() << username;
	//qDebug() << password;
	tableModel->setTable("users");
	tableModel->select();
	for(int i = 0; i < tableModel->rowCount(); ++i)
	{
		QString dbUser = tableModel->record(i).value("username").toString();
		QString dbPassword = tableModel->record(i).value("password").toString();
		//qDebug() << dbUser << endl;
		//qDebug() << dbPassword << endl;
		if(username == dbUser && password == dbPassword)
		{
			hide();
			mainWindow = new MainWindow(this, db, tableModel->record(i).value("access_level").toString());
			mainWindow->show();
		}
	}
}
