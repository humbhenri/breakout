#include "block.h"
#include <QPainter>

Block::Block()
    :width(50), height(20)
{
}

QRectF Block::boundingRect() const
{
    return QRectF(-width, -height, width, height);
}

QPainterPath Block::shape() const
{
    QPainterPath path;
    path.addRect(-width, -height, width, height);
    return path;
}

void Block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setBrush(Qt::red);
    painter->drawRect(-width, -height, width, height);
}

void Block::advance(int phase)
{
    if (!phase)
        return;
}
