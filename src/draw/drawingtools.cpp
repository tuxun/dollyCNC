#include "draw/drawingtools.h"


//classe pour helper le dessin de different truc sur chaque zone
drawingTools::drawingTools(QWidget *parent, QString name) :
    QWidget(parent)

{
    this->setParent(parent);
    this->sceneConteneur=new draw_scene();
    //!! this->sceneConteneur->setSceneRect(-100, -100, 100, 100);
    this->sceneVue=new draw_view(this->sceneConteneur);

    //this->setScene (this->sceneConteneur);


    // this->sceneVue=new QGraphicsView(this->sceneConteneur);
    this->setStyleSheet("background-color:#FFFFFF;");
    // this->sceneVue->setStyleSheet("background-color:#9900CC;border:solid 3px red;");
    /*
 */
    //!! this->sceneVue->setSceneRect(-100, -100, 100, 100);
    this->sceneVue->scale(1,-1);




    /*

this->setParent(parent);
this->setWindowTitle("fgsdg");

//oups!!!
    QHBoxLayout *lay=new QHBoxLayout();
    lay->addWidget(this->sceneVue->viewport());
    this->setLayout(lay);
    //this->show();
//this=this->sceneVue->window();
      //this->sceneVue->show();
//this->show();


*/
    // this->setBackgroundColor(QColor(20,200,120,210));

    this->setToolTip(name);

    //  this->setWindowSurface(this->sceneVue->viewport()->windowSurface());
    //this->layout()->addWidget(sceneVue->viewport());
    //  this->setVisible(true);
    //!!this->setFixedSize(200,200);
    QHBoxLayout *la=new QHBoxLayout(this);

    //ah...ah!
    la->addWidget (sceneVue);
    setLayout (la);
    // this->layout ()->addWidget (sceneVue->viewport ());
    this->setAutoFillBackground(true);
    //  this->setStyleSheet("background-color:#678302;");
    // this->setWindowSurface(
    //QObject::connect(this, SIGNAL(sceneClicked()), this, SLOT(autoscale()));
    QObject::connect(this,SIGNAL(item_ready(QGraphicsItem*)),this->sceneConteneur,SLOT(drawPath(QGraphicsItem*)));

    //QObject::connect(this,SIGNAL(sceneClicked(bool)),this,SLOT(draw_ziguigui(bool)));
    setWindowFlags (Qt::Window);
  //  this->setMouseTracking (true);
this->sceneVue->setInteractive(true);
}


void drawingTools::autoscale(void)
{
          this->sceneVue->autoscale();
}

//constrcuter with name
//classe pour helper le dessin de different truc sur chaque zone
drawingTools::drawingTools(QWidget *parent) :
    QWidget(parent)
{
    this->setParent(parent);
    this->sceneConteneur=new draw_scene();
    //!! this->sceneConteneur->setSceneRect(-100, -100, 100, 100);
    this->sceneVue=new draw_view(this->sceneConteneur);

    //this->setScene (this->sceneConteneur);


    // this->sceneVue=new QGraphicsView(this->sceneConteneur);
    this->setStyleSheet("background-color:#FFFFFF;");
    // this->sceneVue->setStyleSheet("background-color:#9900CC;border:solid 3px red;");
    /*
 */
    //!! this->sceneVue->setSceneRect(-100, -100, 100, 100);
    this->sceneVue->scale(1,-1);




    /*

this->setParent(parent);
this->setWindowTitle("fgsdg");

//oups!!!
    QHBoxLayout *lay=new QHBoxLayout();
    lay->addWidget(this->sceneVue->viewport());
    this->setLayout(lay);
    //this->show();
//this=this->sceneVue->window();
      //this->sceneVue->show();
//this->show();


*/
    // this->setBackgroundColor(QColor(20,200,120,210));

    this->setToolTip("decoupewidget");

    //  this->setWindowSurface(this->sceneVue->viewport()->windowSurface());
    //this->layout()->addWidget(sceneVue->viewport());
    //  this->setVisible(true);
    //!!this->setFixedSize(200,200);
    QHBoxLayout *la=new QHBoxLayout(this);

    //ah...ah!
    la->addWidget (sceneVue);
    setLayout (la);
    // this->layout ()->addWidget (sceneVue->viewport ());
    this->setAutoFillBackground(true);
    //  this->setStyleSheet("background-color:#678302;");
    // this->setWindowSurface(
    //QObject::connect(this, SIGNAL(sceneClicked()), this, SLOT(autoscale()));
    QObject::connect(this,SIGNAL(item_ready(QGraphicsPathItem*)),this->sceneConteneur,SLOT(drawPath(QGraphicsPathItem*)));

    //QObject::connect(this,SIGNAL(sceneClicked(bool)),this,SLOT(draw_ziguigui(bool)));
    setWindowFlags (Qt::Window);
    this->setMouseTracking (true);
}

/*

void drawingTools::show(void)
    {
    this->sceneVue->show();


}*/





QStringList drawingTools::get_paths(){
    QList<QGraphicsItem*> paths= this->sceneConteneur->items();
    QStringList pathscoords;
    int i, ibis,iter=0;
    QVariant vx,vy;
    for(i=0;i<paths.size();i++)
    {
        for (ibis=0;ibis<paths.at(i)->shape().elementCount();ibis++)
        {
            vx=QVariant::fromValue(paths.at(i)->shape().elementAt(ibis).x);
            vy=QVariant::fromValue(paths.at(i)->shape().elementAt(ibis).y);
            iter++;
            pathscoords.append("G0 X"+vx.toString()+" Y"+vy.toString());
            //pathscoords.append(vy.toString());
        }
    }
    if(!i)
    {QMessageBox::information(this,"attention au bugs","pas de  path chargé!",QMessageBox::YesToAll);
    }
    std::cout<<i<<"paths decoded"<<iter/3<<"nodes /"<<std::endl;
    return pathscoords;

}

void drawingTools::add_shape(QGraphicsItem *toadd)
{


    QGraphicsPathItem *Qpath=new QGraphicsPathItem();
    QPen pen(Qt::blue, 100, Qt::SolidLine, Qt::FlatCap, Qt::BevelJoin);
Qpath->setPen(pen);
QPainterPath *pth=new QPainterPath();//(toadd->shape ());
pth->addPath(toadd->shape().simplified());
    //Qpath->setPath(pth);
    emit item_ready(Qpath);
}


void drawingTools::action_on(QGraphicsItem *toadd)
{

    QPainterPath pth(toadd->shape());
    pth.moveTo (0,0);

    QGraphicsPathItem *Qpath=new QGraphicsPathItem();
    QPen pen(Qt::red, 10, Qt::SolidLine, Qt::FlatCap, Qt::BevelJoin);
Qpath->setPen(pen);
    Qpath->setPath(pth);
    emit item_ready(Qpath);
}


void drawingTools::add_shape(QStringList *toadd)
{


    int i=1,point_count=toadd->size();
    QGraphicsPathItem *Qpath=new QGraphicsPathItem();
    QLocale cl(QLocale::C);
    QStringList list1 = toadd->at(0).split(":", QString::SkipEmptyParts);
    QPainterPath pth(QPointF(cl.toDouble( list1.at(0).toUtf8()),cl.toDouble( list1.at(1).toUtf8())));

    QStringList list2 = toadd->at(i+1).split(":", QString::SkipEmptyParts);
    for (i;i < point_count; ++i)
    {

        list1 = toadd->at(i).split(":", QString::SkipEmptyParts);

        //!\//pseudo worked: added multiple ligne with a very rounded value :p
       // pth.lineTo(cl.toDouble( list1.at(0)),cl.toDouble( list1.at(1)));
        pth.lineTo(list1.at(0).toFloat(),list1.at(1).toFloat());

    }
    //this one!!!
    QPen pen(Qt::blue, 1, Qt::SolidLine, Qt::FlatCap, Qt::BevelJoin);
Qpath->setPen(pen);
    Qpath->setPath(pth);
    emit item_ready(Qpath);
}
