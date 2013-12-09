#include "ball.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>

Ball::Ball()
    :width(15), dx(3), dy(3)
{
}

QRectF Ball::boundingRect() const
{
    return QRectF(-width, -width, width, width);
}

QPainterPath Ball::shape() const
{
    QPainterPath path;
    path.addEllipse(-width, -width, width, width);
    return path;
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setBrush(Qt::blue);
    painter->drawEllipse(-width, -width, width, width);
}

void Ball::advance(int phase)
{
    if (!phase)
        return;

    if (collidingItems().size() > 0)
        dy = -dy;

    int adjust =20;
    QPointF pos = scenePos();
    if (pos.x() > scene()->sceneRect().right() + adjust)
        dx = -dx;
    if (pos.y() < scene()->sceneRect().top())
        dy = -dy;
    if (pos.x() < scene()->sceneRect().left())
        dx = -dx;

    setPos(x() + dx, y() + dy);
}

