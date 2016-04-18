#ifndef DRAW_SCENE_H
#define DRAW_SCENE_H

#include <QGraphicsScene>
#include <QGraphicsLineItem>

struct pathStruct{
public: int x_orig;
    int y_orig;
    int x_dest;
    int y_dest;
    QGraphicsLineItem line;
    };


    struct shapesStruct{

     QList<pathStruct> paths;
    };

class draw_scene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit draw_scene();
        shapesStruct *shape;

QGraphicsView *sceneVue;
//void paintEvent(QPaintEvent *);

    signals:
void preview_path_cliqued(QGraphicsItem*);
void item_ready(QGraphicsItem*);
void item_ready(QGraphicsPathItem*);

public slots:
    //void add_shape(QStringList*);
    void draw_ziguigui(bool nada);
    //void autoscale();
    void drawPath(QGraphicsItem* itemtoadd);
    void drawPath(QGraphicsPathItem* itemtoadd);


};

#endif // DRAW_SCENE_H
