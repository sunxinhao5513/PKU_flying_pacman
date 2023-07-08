#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsPixmapItem>
#include <QGraphicsColorizeEffect>
#include <QPixmap>
#include <QTimer>

class GhostClass:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    GhostClass(int num, bool _flag, int _diff = 0, int _type = 0);
    void updatePosition();//更新ghost位置
    ~GhostClass();
    bool checkpos();
    void rush();
    void resetSpeed();

public slots:
    void onSuper();//开启超级模式
    void offSuper();//关闭超级模式

private:
    QPixmap* ghostImage;//TODO：ghost的造型
    QGraphicsColorizeEffect* color;//颜色效果
    void init(int num = 0);//初始化ghost
    void initColor();//初始化ghost的颜色
    int speed = 4;//速度
    int flag = 0;//鬼在上方还是下方
    bool left = false; //判断鬼在鸟的左边还是右边 用于加分
    bool super = 0;//超级模式
    QTimer* superTimer = new QTimer;//计时器
    QTimer* rushTimer = new QTimer;
    int diff = 0;//难度
    int type = 0;//类别
};

#endif // GHOST_H
