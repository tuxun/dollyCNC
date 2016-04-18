#ifndef DRAW_VIEW_H
#define DRAW_VIEW_H

#include <QGraphicsView>
#include <iostream>



class draw_view : public QGraphicsView
{
    Q_OBJECT
public:
    explicit draw_view(QGraphicsScene *parent = 0);


      //  void mousePressEvent ( QMouseEvent * event );
     //   void mouseMoveEvent (QMouseEvent *event );

        void wheelEvent( QWheelEvent * event );
        QGraphicsScene *sceneConteneur;

QString name;
   //     void paintEvent(QPaintEvent *);
void autoscale(void);

    signals:
void sceneClicked(bool);
void preview_path_cliqued(QGraphicsItem*);

public slots:
//  void add_shape(QStringList*);
    //void draw_ziguigui(bool nada);
    //void drawPath(QGraphicsItem* itemtoadd);
    void zoomIn(void);
    void zoomOut(void);

    void rotateLeft(void);
    void rotateRight(void);




};

#endif // DRAW_VIEW_H
