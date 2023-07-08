#include "bird.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsColorizeEffect>
#include <QPixmap>
#include <QTimer>
#include <QKeyEvent>
#include <iostream>

PacbirdClass::PacbirdClass(int idx):
    birdImage(new QPixmap), superTimer(new QTimer)
{
    if(idx == 0){
        birdImage->load(":/resource/images/456px-Pacman.svg.png");
        setScale(0.08);
    }
    else{
        birdImage->load(":/resource/images/a6p1t-5x2sy-007.png");
        setScale(0.2);
    }
    setPixmap(*birdImage);
    setPos(375, 275);
    connect(superTimer, &QTimer::timeout, this, &PacbirdClass::offSuper);
    index = idx;
    setGraphicsEffect(color);
}

bool PacbirdClass::isSuper() const{
    return super;
}

bool PacbirdClass::Sprint() const{
    return sprint;
}

void PacbirdClass::onSuper(){
    super = 1;
    superTimer->start(4000);
    if(index == 1)setScale(0.4);
    else setScale(0.16);
}

void PacbirdClass::offSuper(){
    super = 0;
    superTimer->stop();
    if(index == 1) setScale(0.2);
    else setScale(0.08);
}

void PacbirdClass::updatePosition(){
    speed += 2;
    setPos(x(), y() + speed * 2 / 3);
}

void PacbirdClass::flap(){
    speed -= 40;
}
void PacbirdClass::getSprint(){
    sprint = 1;
    if(color == nullptr) color = new QGraphicsColorizeEffect;
    QColor temp = Qt::red;
    color->setColor(temp);
    setGraphicsEffect(color);
}
void PacbirdClass::rush(){
    speed = 0;
}
void PacbirdClass::resetSprint(){
    sprint = 0;
    if(color != nullptr) delete color;
    color = nullptr;
    setGraphicsEffect(color);
}

PacbirdClass::~PacbirdClass(){
    delete birdImage;
    delete superTimer;
}
