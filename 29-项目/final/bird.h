#ifndef BIRD_H
#define BIRD_H
#include <QGraphicsColorizeEffect>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QObject>
class PacbirdClass:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    PacbirdClass(int idx = 0);//TODO:bird的造型
    void updatePosition();//更新bird位置
    void flap();//向上跳
    void rush();//冲刺
    void getSprint();
    void resetSprint();
    bool isSuper() const;//判断当前是否处于超级状态 //超级状态：bird变大，并且可以穿过ghost //TODO:ghost的状态变化
    bool Sprint() const;
    ~PacbirdClass();

public slots:
    void onSuper();//开启超级模式
    void offSuper();//关闭超级模式

private:
    QPixmap* birdImage;//TODO:动图
    QGraphicsColorizeEffect* color = nullptr;//颜色效果
    int speed = 0;//速度
    bool super = 0;//超级模式
    bool sprint = 0;//是否可以冲刺
    QTimer* superTimer;//计时器
    int index = 0;//皮肤
};

#endif // BIRD_H
