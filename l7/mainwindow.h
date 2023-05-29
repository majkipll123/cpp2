#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:
    void on_action_Zakoncz_triggered();

    void on_action_O_programie_triggered();

  protected:
    bool eventFilter(QObject *obj , QEvent *event);

  private:
    Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
