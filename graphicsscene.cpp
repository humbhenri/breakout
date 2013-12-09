#include "graphicsscene.h"
#define ADJUST 18
#define BLOCK_ROWS 4
#define BLOCK_START 75
#define BLOCK_INC 100
#define BLOCK_Y_START 50

GraphicsScene::GraphicsScene(QGraphicsView *view)
    :QGraphicsScene(view)
{
    setSceneRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT);
    setItemIndexMethod(QGraphicsScene::NoIndex);
    addPaddle();
    addBall();
    addBlocks();
}

void GraphicsScene::addBlocks()
{
    for (int j=1; j<=BLOCK_ROWS; j++) {
        for (int i=BLOCK_START; i<SCENE_WIDTH; i+=BLOCK_INC) {
            Block *block = new Block;
            addItem(block);
            block->setPos(i, j * BLOCK_Y_START);
        }
    }
}

void GraphicsScene::addPaddle()
{
    paddle = new Paddle;
    addItem(paddle);
}

void GraphicsScene::addBall()
{
    ball = new Ball;
    addItem(ball);
    ball->setPos(sceneRect().center());
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    movePaddle(event);
}

void GraphicsScene::movePaddle(QGraphicsSceneMouseEvent *event)
{
    qreal paddleX = qMin(event->scenePos().x(), sceneRect().width() - paddle->boundingRect().width() + ADJUST);
    paddle->setPos(paddleX, paddle->y());
}

