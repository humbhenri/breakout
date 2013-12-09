#ifndef BLOCK_H
#define BLOCK_H
#include <QGraphicsItem>

class Block: public QGraphicsItem
{
public:
    Block();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void advance(int phase);
private:
    int width;
    int height;
};

#endif // BLOCK_H
