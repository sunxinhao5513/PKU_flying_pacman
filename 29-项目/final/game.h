#ifndef GAME_H
#define GAME_H
#include <QSoundEffect>
#include <QWidget>
#include <QLayout>
#include "mainwindow.h"
#include "helpwindow.h"
#include "changewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class game; }
QT_END_NAMESPACE

class game : public QWidget
{
    Q_OBJECT

public:
    game(QWidget *parent = nullptr);
    ~game();
    QSoundEffect* music = new QSoundEffect();

private:
    Ui::game *ui;
    int skin = 0;
    int diff = 0;
    int type = 0;

    // QWidget interface
protected:
    MainWindow* window;
    helpwindow* helpwind = new helpwindow(this);
    QVBoxLayout* gameLayout = new QVBoxLayout(this);
    changewindow* changewind=new changewindow(this);

public slots:
    void changeToSkin0(bool checked);
    void changeToSkin1(bool checked);
    void changeToDiff0(bool checked);
    void changeToDiff1(bool checked);
    void changeToType0(bool checked);
    void changeToType1(bool checked);

private slots:
    void on_helpbutton_clicked();
    void on_quitbutton_clicked();
    void on_startbutton_clicked();
    void on_pushButton_clicked();
    void handleReturnTo();

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // GAME_H
