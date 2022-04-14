#ifndef IMAGEGENERATOR_H
#define IMAGEGENERATOR_H

#include <QObject>
#include <QImage>
class ImageGenerator : public QObject
{
    Q_OBJECT
public:
    explicit ImageGenerator(int width, int height, QObject *parent = 0);
    ~ImageGenerator();

    void start();
    void stop();

private:
    void process();
    QImage m_img;
    int m_index;
    int m_width, m_height;
signals:
    void sigImageReady(QImage img);
    void sigThreadFinished();
    void sigTest();

public slots:
    void threadFunc();
};

#endif // IMAGEGENERATOR_H
