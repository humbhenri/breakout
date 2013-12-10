#ifndef BLOCK_H
#define BLOCK_H
#include <QGraphicsItem>
#include <QObject>

class Block: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Block(QObject *parent = 0);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void advance(int phase);
private:
    int width;
    int height;
private slots:
    void destroyMe();
};

#endif // BLOCK_H
