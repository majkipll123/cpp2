#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "my_widget.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QMessageBox::information(this, "Informacja",
                             "Ten program reaguje na <br/>"
                             "<b><span style=\"color:red\">kliknięcia myszą</span></b> <br/>"
                             "w obszarze roboczym <i>okna programu</i>");
    this->installEventFilter(this);
}
MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_action_Zakoncz_triggered() {
    qApp->quit();
}
void MainWindow::on_action_O_programie_triggered() {
    QMessageBox::information(this, "O programie", "W tym prostym programie można klikać, a może i coś więcej");
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->modifiers() == Qt::ControlModifier && keyEvent->key() == Qt::Key_Z)
        {
            MyWidget *myWidget = findChild<MyWidget *>();

            if (myWidget)
            {
                myWidget->KeyPressed();
                myWidget->update();
            }

            return true;
        }
    }
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->modifiers() == Qt::ControlModifier && keyEvent->key() == Qt::RightButton)
        {
            MyWidget *myWidget = findChild<MyWidget *>();

            if (myWidget)
            {
                myWidget->KeyPressed();
                myWidget->update();
            }

            return true;
        }
    }

    return QObject::eventFilter(obj, event);
}


