#include "dot.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsColorizeEffect>
#include <QRandomGenerator>
#include <QTimer>
#include <QGraphicsColorizeEffect>
dotClass::dotClass(): dotImage(new QPixmap), rushTimer(new QTimer){
    int randomx = QRandomGenerator::global()->bounded(700) + 850;
    int randomy = QRandomGenerator::global()->bounded(400) + 150;
    int randnum = QRandomGenerator::global()->bounded(100);
    if(randnum <= 5){
        capsule = 1;
        setScale(0.03);
        dotImage->load(":/resource/images/027c491e1f13703f.png");
        setPixmap(*dotImage);
        if(color != nullptr) delete color;
        color = nullptr;
        setGraphicsEffect(color);
    }
    else if(randnum <= 5){
        capsule = 2;
        setScale(0.05);
        dotImage->load(":/resource/images/OIP.png");
        setPixmap(*dotImage);
        if(color == nullptr) color = new QGraphicsColorizeEffect;
        QColor temp = Qt::red;
        color->setColor(temp);
        setGraphicsEffect(color);
    }
    else{
        dotImage->load(":/resource/images/OIP.png");
        setPixmap(*dotImage);
        setScale(0.05);
        if(color != nullptr) delete color;
        color = nullptr;
        setGraphicsEffect(color);
    }
    setPos(randomx, randomy);
    connect(rushTimer, &QTimer::timeout, this, &dotClass::resetSpeed);
}

int dotClass::isCapsule() const{
    return capsule;
}

void dotClass::reset(){
    int randomx = QRandomGenerator::global()->bounded(700) + 850;
    int randomy = QRandomGenerator::global()->bounded(400) + 150;
    int randnum = QRandomGenerator::global()->bounded(100);
    if(randnum <= 5){
        dotImage->load(":/resource/images/027c491e1f13703f.png");
        setPixmap(*dotImage);
        capsule = 1;
        setScale(0.03);
        if(color != nullptr) delete color;
        color = nullptr;
        setGraphicsEffect(color);
    }
    else if(randnum <= 15){
        dotImage->load(":/resource/images/OIP.png");
        setPixmap(*dotImage);
        capsule = 2;
        setScale(0.05);
        if(color == nullptr) color = new QGraphicsColorizeEffect;
        QColor temp = Qt::red;
        color->setColor(temp);
        setGraphicsEffect(color);
    }
    else{
        dotImage->load(":/resource/images/OIP.png");
        setPixmap(*dotImage);
        capsule = 0;
        setScale(0.05);
        if(color != nullptr) delete color;
        color = nullptr;
        setGraphicsEffect(color);
    }
    setPos(randomx, randomy);
}

void dotClass::updatePosition(){
    setPos(x() - speed, y());
    if(x() < -50){
        int randomnum = QRandomGenerator::global()->bounded(400) + 150;
        setPos(1000, randomnum);
    }
}
void dotClass::rush(){
    speed = 50;
    rushTimer->start(200);
}
void dotClass::resetSpeed(){
    speed = 4;
    rushTimer->stop();
}

dotClass::~dotClass(){
    delete dotImage;
}
