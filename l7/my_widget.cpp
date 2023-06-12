
#include "my_widget.h"

#include <QPainter>

#include <QMouseEvent>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent) {

}

void MyWidget::paintEvent(QPaintEvent *event) {

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(QBrush(QColor(Qt::GlobalColor::darkMagenta)));

    auto r = this->rect();

    painter.drawRect(r);

    for (const auto &circ : circles) {

        painter.setBrush(QBrush(circ.color)); // Ustawienie koloru koła

        QPointF point(circ.center.x() * r.width(), circ.center.y() * r.height());

        painter.drawEllipse(point, circ.radius, circ.radius);

    }

    QWidget::paintEvent(event);

}

void MyWidget::mousePressEvent(QMouseEvent *event) {

    auto pos = event->localPos();

    auto rec = rect();

    Circle c;

    c.radius = DEFAULT_RADIUS;

    c.center.setX(pos.x() / rec.width());

    c.center.setY(pos.y() / rec.height());

    c.color = QColor(Qt::GlobalColor::darkYellow); // Ustawienie domyślnego koloru koła

    circles.push_back(c);

    update();

}

void MyWidget::KeyPressed() {

    if (!circles.empty()) {

        circles.pop_back();

    }

}

void MyWidget::wheelEvent(QWheelEvent *event) {

    for (auto &circ : circles) {

        circ.color = QColor(rand()%256, rand()%256, rand()%256); // Ustawienie losowego koloru koła

    }

    update();

    event->accept();

}

