#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    ui->centralWidget->setMouseTracking(true);
    ui->centralWidget->installEventFilter(this);
    setCursor(Qt::BlankCursor);
    setWindowTitle("Breakout 1.0");
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);

    // paddle
    painter.setBrush(Qt::black);
    int paddleHeight = 0.04 * height();
    int paddleWidth = 0.15 * width();
    int y = height() - paddleHeight;
    QPoint mouse = mapFromGlobal(QCursor::pos());
    int x = mouse.x();
    painter.drawRect(x, y, paddleWidth, paddleHeight);

}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    Q_UNUSED(obj)
    if (event->type() == QEvent::MouseMove) {
        update();
    }
    return false;
}

MainWindow::~MainWindow()
{
    delete ui;
}
