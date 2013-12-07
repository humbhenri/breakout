#include "paddle.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QCursor>

Paddle::Paddle()
    :width(100)
{
}

QRectF Paddle::boundingRect() const
{

    return QRectF(0, this->scene()->sceneRect().height(), width, 20);
}

void Paddle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}

void Paddle::advance(int step)
{
    if (!step)
        return;

    setPos(QCursor::pos().x(), y());
}
