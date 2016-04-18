#include "draw_scene.h"

draw_scene::draw_scene() :
    QGraphicsScene()
{

   //QPen pen(Qt::red, 10, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
//this->p();
    // a grid foreground
   // this->setForegroundBrush(QBrush(Qt::lightGray, Qt::CrossPattern));
}
void draw_scene::drawPath(QGraphicsPathItem* itemtoadd)
{
    QPen pen(Qt::blue, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

//qreal offset=itemtoadd->boundingRect().size().width();
this->addItem(itemtoadd);

}
void draw_scene::drawPath(QGraphicsItem* itemtoadd)
{

//qreal offset=itemtoadd->boundingRect().size().width();
this->addItem(itemtoadd);

}

void draw_scene::draw_ziguigui(bool nada)
{
    QGraphicsPathItem *Qpath=new QGraphicsPathItem();
QPen pen(Qt::blue, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QPainterPath pth(QPointF(1.1,1.1));

    //pth.setElementPositionAt(0,5,-4);
    //pth.setElementPositionAt(1,2,5);
    pth.lineTo(2,5);
    pth.lineTo(2,6);
    pth.lineTo(5,1);
    pth.lineTo(-3,-2);
    pth.lineTo(2,5);
    pth.lineTo(5,2);
    pth.lineTo(-9,7);
    pth.lineTo(-3,4);
    Qpath->setPath(pth);
   // this->sceneConteneur->addItem(Qpath);
    emit item_ready(Qpath);
   // this->autoscale();
}

//offset.width()
//itemtoadd->setPos(itemtoadd->pos().x(),itemtoadd->pos().y());
        //this->filePreviewScene->addItem(itemtoadd);



    //check la superposition!
/*if(itemtoadd->boundingRect().contains(this->scene->itemsBoundingRect()))
{
    std::cout<<"superposition"<<std::endl;
}*/

//std::cout<<"bump"<<std::endl;
//this->update();

//this->filePreviewScene->update();

 //this->sceneVue->setSceneRect(itemtoadd->boundingRect());// itemsBoundingRect());

   // this->scene->setFocusItem(scene);
//this->sceneConteneur->setFocusItem(itemtoadd);




//this->autoscale();
//emit scenechanged!!!
