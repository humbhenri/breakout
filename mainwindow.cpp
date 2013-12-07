#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QEvent>
#include <QMouseEvent>
#include "graphicsscene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);        
    setWindowTitle("Breakout 1.0");
    ui->centralWidget->setCursor(Qt::BlankCursor);
    scene = new GraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setMouseTracking(true);
    setFixedSize(SCENE_WIDTH+75, SCENE_HEIGHT+100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
