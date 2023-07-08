#include "changewindow.h"
#include "ui_changewindow.h"
#include "qradiobutton.h"
#include <QButtonGroup>
#include "game.h"
#include <QPainter>
#include <QPaintEvent>

changewindow::changewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changewindow)
{
    ui->setupUi(this);
    yinx->addButton(ui->yinxiaok);
    yinx->addButton(ui->yinxiaog);
    skin->addButton(ui->skin0);
    skin->addButton(ui->skin1);
    difficulty->addButton(ui->easy);
    difficulty->addButton(ui->hard);
    type->addButton(ui->type0);
    type->addButton(ui->type1);
    *skinImage0 = skinImage0->scaled(75, 75);
    *skinImage1 = skinImage1->scaled(75, 75);
    skinLabel0->setPixmap(*skinImage0);
    skinLabel1->setPixmap(*skinImage1);
    skinLabel0->setGeometry(250, 225, 75, 75);
    skinLabel0->setStyleSheet("border-image: url(:/resource/images/kpath.png);background-image: url(:/resource/images/kpath.png);");
    skinLabel1->setGeometry(425, 225, 75, 75);
    skinLabel1->setStyleSheet("border-image: url(:/resource/images/kpath.png);background-image: url(:/resource/images/kpath.png);");
    ui->yinxiaok->setChecked(true);
    ui->skin0->setChecked(true);
    ui->easy->setChecked(true);
    ui->type0->setChecked(true);
    connect(ui->skin0, &QRadioButton::clicked, static_cast<game*>(parent), &game::changeToSkin0);
    connect(ui->skin1, &QRadioButton::clicked, static_cast<game*>(parent), &game::changeToSkin1);
    connect(ui->easy, &QRadioButton::clicked, static_cast<game*>(parent), &game::changeToDiff0);
    connect(ui->hard, &QRadioButton::clicked, static_cast<game*>(parent), &game::changeToDiff1);
    connect(ui->type0, &QRadioButton::clicked, static_cast<game*>(parent), &game::changeToType0);
    connect(ui->type1, &QRadioButton::clicked, static_cast<game*>(parent), &game::changeToType1);
}

void changewindow::paintEvent(QPaintEvent *event){
    QPainter p(this);
    p.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/resource/images/Set.png"));
}
changewindow::~changewindow()
{
    delete ui;
    delete skinLabel0;
    delete skinLabel1;
}
void changewindow::on_back_clicked()
{
    this->close();
}
void changewindow::on_yinxiaok_clicked(bool checked)
{
    if(checked == true)
    {
        music->play();
        music->setLoopCount(music->Infinite);
    }
    else music->stop();
}
void changewindow::on_yinxiaog_clicked(bool checked)
{
    if(checked == true) music->stop();
    else
    {
        music->play();
        music->setLoopCount(music->Infinite);
    }
}

