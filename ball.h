#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>

class Ball: public QGraphicsItem
{
public:
    Ball();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void advance(int phase);

private:
    int width;
    int dx;
    int dy;
};

#endif // BALL_H
