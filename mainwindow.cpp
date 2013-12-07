#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphicsscene.h"
#include <QDebug>

void MainWindow::debug()
{
    qDebug() << "blah";
}

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
    ui->graphicsView->setRenderHints(QPainter::Antialiasing);
    setFixedSize(SCENE_WIDTH+75, SCENE_HEIGHT+100);
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(1000/33);
}

MainWindow::~MainWindow()
{
    delete ui;
}
