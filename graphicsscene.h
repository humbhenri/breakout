#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include "paddle.h"
#include "ball.h"

#define SCENE_WIDTH 800
#define SCENE_HEIGHT 600

class GraphicsScene: public QGraphicsScene
{
public:
    GraphicsScene(QGraphicsView *view);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
private:
    Paddle *paddle;
    Ball *ball;
    void movePaddle(QGraphicsSceneMouseEvent *event);

};

#endif // GRAPHICSSCENE_H
