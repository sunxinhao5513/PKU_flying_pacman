#include "ghost.h"
#include <QPixmap>
#include <QRandomGenerator>
#include <QGraphicsColorizeEffect>
#include <QTimer>
#include <QGraphicsPixmapItem>

GhostClass::GhostClass(int num, bool _flag, int _diff, int _type):ghostImage(new QPixmap),
    color(new QGraphicsColorizeEffect), flag(_flag), diff(_diff), type(_type){
    if(flag == 0){
        if(type == 0) ghostImage->load(":/resource/images/Studio_Project_(1).png");
        else ghostImage->load(":/resource/images/pacman-145860_1281.png");
    }
    else{
        if(type == 0) ghostImage->load(":/resource/images/Studio_Project_(1) (1).png");
        else ghostImage->load(":/resource/images/pacman-145860_1280.png");
    }
    if(type == 1){
        delete color;
        color = nullptr;
    }
    else setGraphicsEffect(color);
    setPixmap(*ghostImage);
    setScale(0.3);
    connect(superTimer, &QTimer::timeout, this, &GhostClass::offSuper);
    init(num);
    connect(rushTimer, &QTimer::timeout, this, &GhostClass::resetSpeed);
}

void GhostClass::initColor(){
    int randnum = QRandomGenerator::global()->bounded(3);
    if(randnum == 0){
        if(color != nullptr) delete color;
        color = nullptr;
        setGraphicsEffect(color);
    }
    if(randnum == 1){
        if(color == nullptr) color = new QGraphicsColorizeEffect;
        QColor temp = Qt::yellow;
        temp = temp.darker(125);
        color->setColor(temp);
        setGraphicsEffect(color);
    }
    else if(randnum == 2){
        if(color == nullptr) color = new QGraphicsColorizeEffect;
        QColor temp = Qt::green;
        temp = temp.darker(125);
        color->setColor(temp);
        setGraphicsEffect(color);
    }
}

void GhostClass::init(int num){
    if(type == 0) initColor();
    if(flag == 0){
        int randomnum = QRandomGenerator::global()->bounded(100 + 75 * diff);
        setPos(1000 + 300 * num, -200 + randomnum); left = false;
    }
    else{
        int randomnum = QRandomGenerator::global()->bounded(100 + 75 * diff);
        setPos(1000 + 300 * num, 550 - randomnum); left = false;
    }
    //qDebug() << diff;
}

void GhostClass::onSuper(){
    super = 1;
    superTimer->start(4000);
    /*if(color == nullptr) color = new QGraphicsColorizeEffect;
    color->setColor(Qt::white);
    setGraphicsEffect(color);*/
}

void GhostClass::offSuper(){
    super = 0;
    superTimer->stop();
}

void GhostClass::updatePosition(){
    setPos(x() - speed, y());
    if(x() < -200) init();
}

bool GhostClass::checkpos(){
    if(left == false && x() < 375){
        left = true; return true;
    }
    else return false;
}
void GhostClass::rush(){
    speed = 50;
    rushTimer->start(100);
}
void GhostClass::resetSpeed(){
    speed = 4;
    rushTimer->stop();
}
GhostClass::~GhostClass(){
    delete ghostImage;
    delete color;
}
