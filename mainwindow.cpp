#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QEvent>
#include <QMouseEvent>

#define SCENE_WIDTH 800
#define SCENE_HEIGHT 600

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);        
    ui->centralWidget->setCursor(Qt::BlankCursor);
    setWindowTitle("Breakout 1.0");
    scene = new QGraphicsScene(ui->graphicsView);
    scene->setSceneRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->installEventFilter(this);
    setFixedSize(SCENE_WIDTH+75, SCENE_HEIGHT+100);
    createPaddle();
}

void MainWindow::createPaddle()
{
    paddle = new Paddle;
    scene->addItem(paddle);
}

bool MainWindow::eventFilter(QObject *, QEvent *event){
    if (event->type() == QEvent::MouseMove) {
        scene->advance();
    }
    return false;
}


MainWindow::~MainWindow()
{
    delete ui;
}
