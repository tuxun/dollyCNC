#include "draw_view.h"
#include "QMouseEvent"
#include "QGraphicsItem"
/* public SLOTS */
void draw_view::zoomIn() { scale(1.2, 1.2); }
void draw_view::zoomOut() { scale(1 / 1.2, 1 / 1.2); }
void draw_view::rotateLeft() { rotate(-10); }
void draw_view::rotateRight() { rotate(10); }


/* public EVENTS (les slots ne sont pas des events! */
/*
void draw_view::mousePressEvent ( QMouseEvent * event )
{
    //QMessageBox::information (this,"itemunder","got item under!!!");
    qDebug(this->name.toAscii ()+"view cliqued");
    // QApplication::setOverrideCursor(QCursor(Qt::PointingHandCursor));


    QGraphicsItem *itemunder=this->itemAt (QPoint(event->x (),event->y ()));
    if(itemunder)
    {

        qDebug("got path cliqued");

        //QApplication::setOverrideCursor(QCursor(Qt::ClosedHandCursor));


        emit (preview_path_cliqued(itemunder));



        //bug            this->autoscale();

    }
    else {
        //QApplication::setOverrideCursor(QCursor(Qt::arrowCursor));

    }


}
*/
//see http://qt-project.org/doc/qt-4.8/qcursor.html#details
void draw_view::wheelEvent(QWheelEvent* event)
{
    if (this->rect().contains(event->pos()))
    {
        std::cout << "zoom fileView! (" << event->x() << " , " << event->y() << " ) " << std::endl;
        // std::cout << "coords fileView! (" << this->sceneRect().x() << " , "  << this->sceneRect().y() << " ) " << std::endl;
        //std::cout << "zomm" << std::endl;


        //QApplication::setOverrideCursor(QCursor(Qt::PointingHandCursor));
    }
    else {
        //QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
    }

}



/*
void draw_view::mouseMoveEvent (QMouseEvent *event)
{
    QGraphicsItem *itemunder=this->itemAt (QPoint(event->pos ().x (),event->pos().y ()));
    if(itemunder)
    {
        //QApplication::setOverrideCursor(QCursor(Qt::pointingHandCursor));
        qDebug ("got item under!!!");

        setCursor (QCursor(Qt::PointingHandCursor));


        itemunder->setPos (event->pos ().x (),event->pos().y ());


    }
    else {
        setCursor (QCursor(Qt::ArrowCursor));

    }
}

*/
void draw_view::autoscale(void)
{
    //       this->sceneVue->fitInView( this->sceneConteneur->sceneRect(), Qt::KeepAspectRatio );

    QRectF rect = this->sceneConteneur->itemsBoundingRect();

        if (rect.isNull())
        {
        this->sceneConteneur->setSceneRect(QRectF(0, 0, 1, 1));
            //QDebug<<"scene rect is null";
        }
        else
        {
        this->sceneConteneur->setSceneRect(rect);
        }

        QRect rec = this->contentsRect ();
        if (rec.isNull())
        {
        this->scroll(0, 1);
        }
        else
        {
        this->scroll (rec.x (),rec.y ());
        }


   this->fitInView( this->sceneRect(), Qt::KeepAspectRatioByExpanding );
    this->update ();
    //!!this->setWindowSurface (this->sceneVue->window ()->windowSurface ());
   // this->update ();
}

draw_view::draw_view(QGraphicsScene *parent) :
    QGraphicsView(parent)
{
}
