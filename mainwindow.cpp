#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsView>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QImage>
#include <QObject>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_ig = new ImageGenerator(400, 400);
    //connect(m_ig, &ImageGenerator::sigTest, this, &MainWindow::slotTest);
    connect(m_ig, &ImageGenerator::sigImageReady, this, &MainWindow::slotImage);
    m_ig ->start();
}

MainWindow::~MainWindow()
{
    m_ig->stop();
    if(m_ig)
    {
        delete m_ig;
        m_ig = nullptr;
    }
    delete ui;
}

//void MainWindow::slotTest()
//{
//    qInfo() << "a";
//}
void MainWindow::slotImage(QImage img)
{
    ui->label->setPixmap(QPixmap::fromImage(img));
}

//void MainWindow::on_pushButton_clicked()
//{
//    m_ig->start();
//}

//void MainWindow::on_pushButton_2_clicked()
//{
//    m_ig->stop();
//}

