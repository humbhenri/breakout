#include "ball.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>
#include "sound.h"

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
    painter->setPen(Qt::blue);
    painter->drawEllipse(-width, -width, width, width);
    painter->setBrush(Qt::red);
}

void Ball::advance(int phase)
{
    if (!phase)
        return;
    handleItemCollisions();
    handleBorderCollision();
    moveBy(dx, dy);
}

void Ball::handleItemCollisions()
{
    if (collidingItems().size() > 0) {
        QGraphicsItem *item = collidingItems().at(0);
        QRectF itemRect = item->sceneBoundingRect();
        if (itemRect.contains(mapToScene(QPointF(0, width)))) {
            // hit bottom
            dy = -dy;
        } else if (itemRect.contains(mapToScene(QPointF(0, -width)))) {
            // hit top
            dy = -dy;
        } else if (itemRect.contains(mapToScene(QPointF(-width, 0)))) {
            // hit left
            dx = -dx;
        } else if (itemRect.contains(mapToScene(QPointF(width, 0)))) {
            // hit right;
            dx = -dx;
        }
        playHitSound();
    }
}

void Ball::handleBorderCollision()
{
    int adjust = 20;
    QPointF pos = scenePos();

    if (pos.x() > scene()->sceneRect().right() + adjust) {
        dx = -dx;
        playHitSound();
    }
    if (pos.y() < scene()->sceneRect().top()) {
        dy = -dy;
        playHitSound();
    }
    if (pos.x() < scene()->sceneRect().left()) {
        dx = -dx;
        playHitSound();
    }
}

void Ball::playHitSound()
{
    Sound(QCoreApplication::applicationDirPath() + "/ballhit.wav").play();
}

