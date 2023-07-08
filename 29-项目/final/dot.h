#ifndef DOT_H
#define DOT_H
#include<QGraphicsPixmapItem>
#include<QTimer>
#include <QGraphicsColorizeEffect>
class dotClass:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    dotClass();
    void updatePosition();//更新dot位置
    void reset();//dot的刷新
    int isCapsule() const;//判断dot是否为capsule //capsule：进入超级模式的道具 // TODO：capsule的造型
    //capsule的类型
    void rush();
    void resetSpeed();
    ~dotClass();
private:
    QPixmap* dotImage;
    QTimer* rushTimer;
    QGraphicsColorizeEffect* color = nullptr;//颜色效果
    int speed = 4;//速度
    int capsule = 0;//是否为capsule
};

#endif // DOT_H
