#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <vector>

class MyWidget : public QWidget
{
    Q_OBJECT
  public:
    constexpr static double DEFAULT_RADIUS = 100;

    explicit MyWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event)override;


    void KeyPressed();


    struct Circle
    {
        QPointF center;
        double radius;
        QColor color; // dodanie tej opcji poniewaz inaczej nie mozna zmienic koloru
    };

  signals:

  private:
    std::vector<Circle> circles;
};

#endif  // MYWIDGET_H
