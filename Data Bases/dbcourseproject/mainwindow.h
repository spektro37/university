#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include "dialog.h"

class Dialog;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0, QSqlDatabase db = QSqlDatabase(), QString accessLevel = 0);
	~MainWindow();

private:
	Ui::MainWindow *ui;
	Dialog *dialog;
};

#endif // MAINWINDOW_H
