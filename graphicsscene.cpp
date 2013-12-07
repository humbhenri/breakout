#include "graphicsscene.h"
#define ADJUST 18

GraphicsScene::GraphicsScene(QGraphicsView *view)
    :QGraphicsScene(view)
{
    setSceneRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT);
    setItemIndexMethod(QGraphicsScene::NoIndex);
    paddle = new Paddle;
    addItem(paddle);
}

void GraphicsScene::movePaddle(QGraphicsSceneMouseEvent *event)
{
    qreal paddleX = qMin(event->scenePos().x(), sceneRect().width() - paddle->width() + ADJUST);
    paddle->setPos(paddleX, paddle->y());
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    movePaddle(event);
}
