#include "paddle.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QCursor>

Paddle::Paddle()
    :_width(100)
{
}

QRectF Paddle::boundingRect() const
{

    return QRectF(0, this->scene()->sceneRect().height(), width(), 20);
}

QPainterPath Paddle::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}
void Paddle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}

int Paddle::width() const
{
    return _width;
}

