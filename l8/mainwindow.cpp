#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_Koniec, SIGNAL(triggered()), this, SLOT(koniec_programu()) );
//    aminationButton -> setIcon(QIcon())
    connect(ui->przycisk, SIGNAL(clicked()), ui->widget, SLOT(toggle_animation()));

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::koniec_programu()

{

    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "NOOOooo11!!!1", "Do you realy want to leave this programme?",
        QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        QApplication::quit();


}



void MainWindow::on_action_O_programie_triggered()
{
 QMessageBox::aboutQt(this,"O wspaniałym programie");
}
