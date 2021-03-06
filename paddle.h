#ifndef PADDLE_H
#define PADDLE_H
#include <QGraphicsItem>

class Paddle: public QGraphicsItem
{
public:
    Paddle();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

protected:

private:
    int width;
};

#endif // PADDLE_H
