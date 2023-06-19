#include "my_widget.h"

#include <QPainter>

MyWidget::MyWidget(QWidget* parent)  //
    : QWidget(parent), timer(this)
{
    timer.start(timer_interval);
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}

void MyWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    painter.setBrush(QBrush(QColor(Qt::GlobalColor::lightGray)));
    auto r = this ->rect();
    painter.drawRect(r);
    painter.translate(rect().width() / 2.0, rect().height() / 2.0);
    auto side = std::min(rect().width(), rect().height());
    painter.scale(side / 400.0, side / 400.0);
    painter.setPen(Qt::NoPen);


    QRadialGradient gradient(50,50,50);
    gradient.setColorAt(0, QColor::fromRgbF(1,0,1,0.2));

    QRadialGradient gradient2(50,50,50);
    gradient2.setColorAt(0, QColor::fromRgbF(1,0,1,0.5));

   // gradient.setColorAt(0, QColor::fromRgbF(1,0,1,0));
    for (int i = 0; i < num_disks; i++)
    {
        if (i==3 || i== 6 || i== 9 || i== 0) //rysowanie krzyża
        {
            painter.setBrush(QBrush(QColor(Qt::GlobalColor::black)));
            painter.drawRoundRect(-1,-1,10,2);
        }

        if (i != hidden)
        {


            painter.setBrush(QBrush(QColor(Qt::GlobalColor::magenta)));
            painter.drawEllipse(-30, 130, 20, 20);

            painter.setBrush(QBrush(gradient2));
            painter.drawEllipse(-35, 125, 30, 30);

            painter.setBrush(QBrush(gradient));

            painter.drawEllipse(-40, 120, 40, 40);
        }
        painter.rotate(360.0 / num_disks);


    }
}


void MyWidget::on_timer()
{
    hidden = (hidden + 1) % num_disks;
    update();
}

void MyWidget::toggle_animation()
{
    if (timer.isActive())
        timer.stop();
    else
        timer.start(timer_interval);
}
