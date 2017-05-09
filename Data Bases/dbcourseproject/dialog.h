#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"

class MainWindow;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog(QWidget *parent = 0);
	~Dialog();

private slots:
	void on_buttonLogin_clicked();

private:
	Ui::Dialog *ui;
	MainWindow *mainWindow;
};

#endif // DIALOG_H
