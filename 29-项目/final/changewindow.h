#ifndef CHANGEWINDOW_H
#define CHANGEWINDOW_H
#include <QSoundEffect>
#include <QWidget>
#include <QButtonGroup>
#include <QLabel>

namespace Ui {
class changewindow;
}

class changewindow : public QWidget
{
    Q_OBJECT

public:
    explicit changewindow(QWidget *parent = nullptr);
    ~changewindow();
    QSoundEffect* music;
private slots:
    void on_yinxiaok_clicked(bool checked);
    void on_yinxiaog_clicked(bool checked);
    void on_back_clicked();
private:
    Ui::changewindow *ui;
    QButtonGroup *yinx=new QButtonGroup(this);
    QButtonGroup* skin = new QButtonGroup(this);
    QButtonGroup* difficulty = new QButtonGroup(this);
    QButtonGroup* type = new QButtonGroup(this);
    QLabel* skinLabel0 = new QLabel(this);
    QLabel* skinLabel1 = new QLabel(this);
    QPixmap* skinImage0 = new QPixmap(":/resource/images/456px-Pacman.svg.png");
    QPixmap* skinImage1 = new QPixmap(":/resource/images/a6p1t-5x2sy-007.png");
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // CHANGEWINDOW_H
