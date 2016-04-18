#ifndef DRAWINGTOOLS_H
#define DRAWINGTOOLS_H
#include <qgraphicsitem.h>
#include <QWidget>
#include <QtGui>
#include <iostream>
#include <QLocale>
#include <QHBoxLayout>
#include <QMessageBox>
#include "draw/draw_scene.h"
#include "draw/draw_view.h"
    class drawingTools : public QWidget

{
    Q_OBJECT
public:
    explicit drawingTools(QWidget *parent = 0);
        explicit drawingTools(QWidget *parent = 0,QString name="defaultitre");
        QStringList get_paths(void);

     //   void show(void);

        QString x_fromTxtCoordString(QString TxtCoordsSring);
        QString y_fromTxtCoordString(QString TxtCoordsSring);
         draw_scene *sceneConteneur;
draw_view *sceneVue;
//void paintEvent(QPaintEvent *);
void autoscale(void);

    signals:
void item_ready(QGraphicsItem*);
void preview_path_cliqued(QGraphicsItem*);

void sceneClicked(bool);

public slots:
void add_shape(QStringList*);
void add_shape(QGraphicsItem*);

void action_on(QGraphicsItem*);

  //  void draw_ziguigui(bool nada);
   // void autoscale();
   // void drawPath(QGraphicsItem* itemtoadd);



};







    ;

#endif // DRAWINGTOOLS_H
