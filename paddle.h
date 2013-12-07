#ifndef PADDLE_H
#define PADDLE_H
#include <QGraphicsItem>

class Paddle: public QGraphicsItem
{
public:
    Paddle();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
protected:
    void advance(int step);
private:
    int width;
};

#endif // PADDLE_H
