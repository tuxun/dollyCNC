#include "tools/gui/mainwindow.h"
#include "tools/gui/ui_mainwindow.h"
#include <QSlider>
//#include "qt_libusb.h"
//#include "nutrace/include/qxpotrace_global.h"
//#include "nutrace/include/qxpotrace.h"
#include <QtSvg/QSvgRenderer>
#include <QGraphicsSvgItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QMdiArea *zoneCentrale = new QMdiArea;
      //  setCentralWidget(zoneCentrale);
        //zoneCentrale->setBackgroundColor(Qt::blue);
 /*   QMenu *menuFichier = menuBar()->addMenu("&Fichier");
        QMenu *menuEdition = menuBar()->addMenu("&Edition");
        QMenu *menuAffichage = menuBar()->addMenu("&Affichage");
 */
 QWidget * mainWidget = new QWidget(this);

    QScrollArea * scrollArea = new QScrollArea(this->centralWidget());

       scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
       scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
       scrollArea->setWidgetResizable(false);

        this->litleSizePolicy=QSizePolicy() ;
          this->litleSizePolicy.setHorizontalStretch(-2);


        this->librairy=new Libmanager(this);
        //une fois qu'on a init la libmanager on peut la mettre dans le dock
       this->setupDock(this);



    //fin menu!

    //layout principale vertical: contient le menu, les onglets et la barre d'info.
    QVBoxLayout *mainLayout=new QVBoxLayout(mainWidget);
    //les onglets: dessin/decoupe/info


    //onglet dessins doit etre ajoute a onglet, et contenir un hlayout:lib,preview
    QHBoxLayout *dessinLayout=new QHBoxLayout();
    QWidget *dessinWidget=new QWidget(this);


    QVBoxLayout *liblayout=new QVBoxLayout();



    //conteneur pour les éléments 2D dans les fichiers chargé
    this->filePreviewScene=new QGraphicsScene();
    //this->filePreviewScene->setSceneRect(-100, -100, 200,200);


   this->filePreviewScene->addText(".");

     this->filePreviewView=new QGraphicsView(this->filePreviewScene);
 //  preView->setFixedSize(100,100);
   this->filePreviewView->scale(1,-1);

    //
//preView->setFrameRect(QRect(-10,-10,10,10));
  this->filePreviewView->setStyleSheet("background-color:#0099CC;border:solid 3px red;");



  this->fileDraw=new drawingTools(this,"fichier");
this->decoupeDraw=new drawingTools(this,"previsualition");



   QWidget *dessinTab=new QWidget();

    QVBoxLayout *dessinTabLayout=new QVBoxLayout(dessinTab);

  //  dessinTabLayout->addWidget(this->filePreviewView);
    //dessinTabLayout->addWidget(this->decoupePreviewView);
//QWidget *dec=new QWidget(this->decoupeDraw->sceneVue->viewport());

  //  this->decoupeDraw->sceneVue->update();
//this->librairy->setSizePolicy(QSizePolicy,QSizePolicy::);
    dessinTabLayout->addWidget(this->fileDraw->sceneVue->window());
   //dessinTabLayout->addWidget(this->decoupeDraw->sceneVue->window());

//drawingTools *test=new drawingTools();
    //test->show();
    dessinTabLayout->addWidget(this->decoupeDraw);

    //dessinLayout->addWidget(this->librairy->libwidget);
    dessinLayout->addWidget(dessinTab);


    dessinWidget->setLayout(dessinLayout);

    //
   //mainLayout->addWidget(preView->viewport());



   // mainLayout->addWidget(menuButtonGroup);
    //mainLayout->addWidget(onglets);
mainLayout->addWidget (dessinWidget);
//setCentralWidget(onglets);

//mainWidget->setLayout(mainLayout);

    this->setCentralWidget(dessinWidget);

    // this->show();
 /*   QxPotrace traceur= QxPotrace();
 traceur.trace( QImage("Button_save-qt.png"));
 */
 //QGraphicsPolygonItem it= traceur.polygons();
//traceur.

    //QObject::connect(this->librairy->vectorizeButton, SIGNAL(clicked(bool)), this->fileDraw, SLOT(draw_ziguigui(bool)));

    QObject::connect(this, SIGNAL(filechanged(QStringList*)), this->fileDraw, SLOT(add_shape(QStringList*)));
    //QObject::connect(this, SIGNAL(filechanged(QStringList*)), this->decoupeDraw, SLOT(add_shape(QStringList*)));
    QObject::connect(this->fileDraw->sceneVue, SIGNAL(preview_path_cliqued(QGraphicsItem*)) , this->decoupeDraw, SLOT(add_shape(QGraphicsItem*)));
    QObject::connect(this, SIGNAL(item_ready(QGraphicsItem*)) , this->fileDraw, SLOT(add_shape(QGraphicsItem*)));


    QObject::connect(this->decoupeDraw->sceneVue, SIGNAL(preview_path_cliqued(QGraphicsItem*)) , this->decoupeDraw, SLOT(action_on(QGraphicsItem*)));

 // connect(this->fileDraw, SIGNAL(preview_path_cliqued(QGraphicsItem*)), this->decoupeDraw, SLOT(drawPath(QGraphicsItem*)));
  //connect(this->fileDraw, SIGNAL(item_ready(QGraphicsItem*)), this->fileDraw, SLOT(drawPath(QGraphicsItem*)));

    //this->centralWidget()->showMaximized();
    //this->statusBar()->setBackgroundColor(Qt::red);

this->load_txt_file( QString("alphabet/carre.txt"));
  //  this->show();

   this->showMaximized();





}


void MainWindow::setupDock(QWidget *target)
    {
    QWidget *menuButtonGroup=get_menuWidget ();

        menuButtonGroup->setSizePolicy (this->litleSizePolicy);
    QDockWidget *dock = new QDockWidget(tr("Fichiers"), this);
        dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    QWidget *DockWidget=new QWidget(target);


    QWidget *decoupeWidget=new QWidget();
    QVBoxLayout *decoupeLayout=new QVBoxLayout();

    QHBoxLayout *setchauffeLayout=new QHBoxLayout();
    QString thispath=QApplication::applicationDirPath();

    QImage bloc(thispath+"/ressources/icons/decoupewidget/ChauffeOn.ico");
    QLabel *imgDisplayLabel = new QLabel("");
      imgDisplayLabel->setPixmap(QPixmap::fromImage(bloc));

     imgDisplayLabel->setFixedSize(50,38);

    imgDisplayLabel->adjustSize();
QComboBox *choixmatiere=new QComboBox();

QDir matieresDir = QDir(thispath+"/settings/matieres/");
QStringList alphabetFiles= matieresDir.entryList(QStringList("*.xml")<<("*.qsetting")<<("*.set")<<("*.m2c"),
                                                 QDir::Files | QDir::NoSymLinks);

QList<QTreeWidgetItem *> alphabets;
if(matieresDir.exists())
{
  //  alphabets.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList("alphabets")));

    for (int x=0;x<alphabetFiles.count();++x)
    {
        choixmatiere->insertItem(x,alphabetFiles.at(x));
        //std::cout<<files.at(x-1).ascii()<<std::endl;
       // alphabets.first()->addChild(new QTreeWidgetItem((QTreeWidget*)0, QStringList(alphabetFiles.at(x))));

    }
}






    QSlider *chauffevaleur=new QSlider(Qt::Horizontal);
    setchauffeLayout->addWidget (imgDisplayLabel);

    setchauffeLayout->addWidget (chauffevaleur);

    decoupeLayout->addLayout(setchauffeLayout);

    decoupeLayout->addWidget (choixmatiere);








    decoupeWidget->setLayout(decoupeLayout);

    QVBoxLayout *DockLayout=new QVBoxLayout();

    DockLayout->addWidget(menuButtonGroup);
    QTabWidget *onglets= new QTabWidget();
    onglets->addTab(  this->librairy->libwidget,this->gearIcon,trUtf8 ("Création"));
    onglets->addTab(  decoupeWidget,this->gearIcon,trUtf8 ("Création"));


    DockLayout->addWidget(onglets);
    DockWidget->setLayout (DockLayout);
    dock->setWidget(DockWidget);

    addDockWidget(Qt::LeftDockWidgetArea, dock);


}

QWidget* MainWindow::get_menuWidget(void)
{
    QString thispath=QApplication::applicationDirPath();
    QStyle* style =  QApplication::style();

    this->openIcon =QIcon(thispath+"/ressources/menuProjetsActions/OuvrirSequence.ico");
    this->newIcon = QIcon(thispath+"/ressources/icons/menuProjetsActions/NouveauProjet.ico");
    this->gearIcon =style->standardIcon(QStyle::SP_FileDialogInfoView);
    this->saveAsIcon =QIcon(thispath+"/ressources/icons/menuProjetsActions/SauverSous.ico");
    this->saveIcon =style->standardIcon(QStyle::SP_FileDialogEnd);
    this->aproposIcon =QIcon(thispath+"/ressources/icons/menuProjetsActions/ProjetMiniCut.ico");
    //fin icones

    //menu

    QToolButton *newProjectButton=new QToolButton();
    QToolButton *openProjectButton=new QToolButton();
    QToolButton *saveAsButton=new QToolButton();
    QToolButton *saveButton=new QToolButton();
    QToolButton *aProposButton=new QToolButton();

    newProjectButton->setIcon(newIcon);
    newProjectButton->setToolTip(tr("Nouveau Projet"));
    openProjectButton->setIcon(openIcon);
    openProjectButton->setToolTip(tr("Ouvrir Projet"));
    saveAsButton->setIcon(saveAsIcon);
    saveAsButton->setToolTip(tr("enregistrer Sous"));
    saveButton->setIcon(saveIcon);
    saveButton->setToolTip(tr("Enregistrer"));
    aProposButton->setIcon(aproposIcon);
    aProposButton->setToolTip(tr("A Propos"));

    QHBoxLayout *menuLayout=new QHBoxLayout();

    menuLayout->addWidget(openProjectButton);
    menuLayout->addWidget(newProjectButton);
    menuLayout->addWidget(saveAsButton);
    menuLayout->addWidget(saveButton);
    menuLayout->addWidget(aProposButton);
    //menuButtonGroup->setLayout(menuLayout);
    QWidget *ret=new QWidget(this);


      // scrollArea->setWidgetResizable(false);
       ret->setLayout(menuLayout);

    connect(saveAsButton, SIGNAL(clicked(bool)), this, SLOT(enregistrer()));

    return ret;
}

void MainWindow::reload_filePreview(bool truc=0)
{
    this->filePreviewScene->clear();
    this->fileDraw->sceneConteneur->clear();
    this->decoupeDraw->sceneConteneur->clear();

//this->decoupeDraw->sceneVue->show();
}

void MainWindow::enregistrer()
{
    QString filtre;
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Fichier Texte(*.txt *.mnc *.dxf *.svg)", &filtre);

  }



//publicslot:




//slot:   "load txt file"
void MainWindow::load_file(QTreeWidgetItem* itemClicked, int col)
{
    //std::cout<<itemClicked->text(0).ascii()<<std::endl;

    //QApplication::applicationDirPath()
    QString filename=itemClicked->text(0).prepend(
                QApplication::applicationDirPath()+"/bibliotheque/alphabets/");


    if(filename.endsWith("txt",Qt::CaseInsensitive))
{load_txt_file(filename);

    }

    else if(filename.endsWith("mnc",Qt::CaseInsensitive))

    {
load_mnc_file(filename);
}

else if(filename.endsWith("svg",Qt::CaseInsensitive))

{
load_svg_file(filename);
}

}

void MainWindow::load_txt_file(QString filepath)
{
  //  std::cout <<"loading txt file: " << filepath;

    //

    QFile *file=new QFile(filepath);

//worked!    QFile *file=new QFile(QString("/home/tuxun/txt/noel.txt"));
    if(file->open(QIODevice::ReadOnly|QIODevice::Text))
    {

        QStringList paths,paths_name;
        QTextStream in(file);
        QString line,lineBis;
        int path_count=0;
        do{

            line = in.readLine();
            QChar firstchar=line.at(0);
            if (firstchar.isLetter())
            {
                paths_name.append(QString(line.toAscii()));
                path_count++;
            }
            else
            {
                paths.append(QString(line.toAscii()));
             }


        }
        while (!in.atEnd());
/*
        for (int i = 0; i < paths.size(); ++i)
                 {
            std::cout << paths.at(i).ascii()<<std::endl;
        }
*/

        this->fileContent= new QStringList (paths);
emit filechanged(this->fileContent);


    }
    else
    {
        std::cout<<"errorloadfileslot (error opening clicked txt file)"<<std::endl;
    }
}

//load mnc:         QStringList list1 = toadd->at(i).split(":", QString::SkipEmptyParts);
void MainWindow::load_mnc_file(QString filepath)
{
 //   std::cout "loading mnc file: ". filepath.toAscii();

    //

    QFile *file=new QFile(filepath);

//worked!    QFile *file=new QFile(QString("/home/tuxun/txt/noel.txt"));
    if(file->open(QIODevice::ReadOnly|QIODevice::Text))
    {

        QStringList paths,paths_name;
        QTextStream in(file);
        QString line,lineBis;
        int path_count=0;
        do{

            line = in.readLine();
            QChar firstchar=line.at(0);
            if (firstchar.isLetter())
            {
                paths_name.append(QString(line.toAscii()));
                path_count++;
            }
            else if (firstchar.isDigit())
            {
                QStringList list1 = line.split("=", QString::SkipEmptyParts);
                //std::cout list1.at(1).toAscii()<<std::endl;

                paths.append(QString(list1.at(1)));
             }


        }
        while (!in.atEnd());
/*
        for (int i = 0; i < paths.size(); ++i)
                 {
            std::cout << paths.at(i).ascii()<<std::endl;
        }
*/

        this->fileContent= new QStringList (paths);
emit filechanged(this->fileContent);


    }
    else
    {
        //std::cout "errorloadfileslot (error opening clicked mnc file)"<<std::endl;
    }
}
void MainWindow::load_svg_file(QString filepath)
{
    //std::cout "loading svg!!! file: "<<filepath.toAscii()<<std::endl;

    //

    QFile *file=new QFile(filepath);
    //QSvgRenderer *renderer = new QSvgRenderer(QLatin1String("SvgCardDeck.svg"));
//QSvgWidget *svg=new QSvgWidget("svg.svg");

        //worked!    QFile *file=new QFile(QString("/home/tuxun/txt/noel.txt"));
    if(file->open(QIODevice::ReadOnly|QIODevice::Text))
    {

  QGraphicsSvgItem *svg=new QGraphicsSvgItem(filepath);

  QList<QGraphicsItem*> itemlist=svg->childItems();        //this->fileContent= new QStringList (paths);
//emit item_ready(svg->parentItem())      ;
int i;
  for (i = 0; i < itemlist.size(); ++i) {
     emit item_ready(itemlist.at(i));
  }
  std::cout <<i<<"items"<<std::endl;



    }
    else
    {
        //std::cout "errorloadfileslot (error opening clicked svg file)"<<std::endl;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
