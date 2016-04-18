#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <QMainWindow>
#include <QtGui>
#include <tools/file/Libmanager.h>
#include "tools/draw/drawingtools.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QWidget *get_menuWidget(void);
    QIcon openIcon,newIcon ,gearIcon,saveAsIcon ,saveIcon,aproposIcon;
    void load_txt_file(QString filepath);
    void load_mnc_file(QString filepath);
    void load_svg_file(QString filepath);
    void load_dxf_file(QString filepath);
    QSizePolicy litleSizePolicy;
    void setupDock(QWidget *target);
    //    void mousePressEvent ( QMouseEvent * event );
//    void wheelEvent( QWheelEvent * event );


public slots:
    void load_file(QTreeWidgetItem*,int);
    //void  drawPreviewPath(QGraphicsItem*);
    void reload_filePreview(bool truc);
private slots:
    void enregistrer();
    
private:
    Ui::MainWindow *ui;

Libmanager *librairy;

//outil de dessin
drawingTools *fileDraw,*previewDraw,*decoupeDraw;
//fichier actuellement chargé
QStringList *fileContent;
//dans l'onglet "dessin":
QGraphicsScene *filePreviewScene,*decoupePreviewScene;
QGraphicsView *filePreviewView,*decoupePreviewView;
signals:
    void filechanged(QStringList*);
    void item_ready(QGraphicsItem*);


};

#endif // MAINWINDOW_H
