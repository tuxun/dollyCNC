#include "file/Libmanager.h"
#include <iostream>
#include <QLineEdit>
/*void Libmanager::shit_Happen()
{//this->parent->set_logs
    // std::cout << thing_to_log.ascii()<<std::endl;
}
*/


void Libmanager::refresh(void)
{
    QStyle* style =  QApplication::style();
        QIcon warnIcon = style->standardIcon(QStyle::SP_MessageBoxWarning);
    QDir alphabetDir = QDir(this->path+"/bibliotheque/alphabets/");
    QDir elementDir = QDir(this->path+"/bibliotheque/elements/");
    QDir decoupeDir = QDir(this->path+"/bibliotheque/decoupes/");
   //liste les fichiers répondant aux filtres
    //QDir currentDir = QDir("/home/tuxun/txt/");
    QStringList alphabetFiles= alphabetDir.entryList(QStringList("*.txt")<<("*.mnc")<<("*.svg")<<("*.dxf"),
                                                     QDir::Files | QDir::NoSymLinks);
    QStringList elementFiles= elementDir.entryList(QStringList("*.txt")<<("*.mnc")<<("*.svg")<<("*.dxf"),
                                                   QDir::Files | QDir::NoSymLinks);
    QStringList decoupeFiles= decoupeDir.entryList(QStringList("*.txt")<<("*.mnc")<<("*.svg")<<("*.dxf"),
                                                   QDir::Files | QDir::NoSymLinks);

    //liste alphabets
    QList<QTreeWidgetItem *> alphabets;
    if(alphabetDir.exists())
    {
        alphabets.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList("alphabets")));

        for (int x=0;x<alphabetFiles.count();++x)
        {
            //std::cout<<files.at(x-1).ascii()<<std::endl;
            alphabets.first()->addChild(
                        new QTreeWidgetItem((QTreeWidget*)0,
                       QStringList(alphabetFiles.at(x))+QStringList(alphabets.first()->text(0))));

        }
    }   else
    {
        alphabets.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList("444:alphabets NOT FOUND")));
alphabets.first()->setIcon(1,warnIcon);
    }

    //liste elements
    QList<QTreeWidgetItem *> elements;
    if(elementDir.exists())
    {
        elements.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(trUtf8("élements"))));

        for (int x=0;x<elementFiles.count();++x)
        {
            //std::cout<<files.at(x-1).ascii()<<std::endl;
            elements.first()->addChild(new QTreeWidgetItem((QTreeWidget*)0, QStringList(elementFiles.at(x))));

        }

    }
    else
    {
        elements.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList("444:elements NOT FOUND")));
        elements.first()->setIcon(1,warnIcon);

    }

    //liste "mes decoupes"
    QList<QTreeWidgetItem *> decoupes;
    if(decoupeDir.exists())
    {
        decoupes.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(trUtf8("Mes découpes"))));

        for (int x = 0; x < decoupeFiles.count(); ++x)
        {        decoupes.first()->addChild(new QTreeWidgetItem((QTreeWidget*)0, QStringList(decoupeFiles.at(x))));

        }
    }   else
    {
        decoupes.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(decoupeDir.path()+"444")));
        decoupes.first()->setIcon(1,warnIcon);

    }
    //QTreeWidget *elementTree,*alphabetTree,*decoupeTree;
    this->libTreeWidget->insertTopLevelItems(1, elements);
    this->libTreeWidget->insertTopLevelItems(0, alphabets);

    this->libTreeWidget->insertTopLevelItems(2, decoupes);
}

Libmanager::Libmanager(QWidget *parent) :
    QWidget(parent)
{
    //this->model=new QFileSystemModel();
    this->model=new QDir("/home/tuxun");

//this->setSizePolicy(QSizePolicy::Minimum);
//this->setSizePolicy(policyb);


     this->libTreeWidget=new QTreeWidget();



    /*  QTreeView *elementsTreeView=new QTreeView();
  QTreeView *decoupesTreeView=new QTreeView();

               model.setRootPath(QDir::currentPath());
    decoupesTreeView->setModel(&model);

    model.setRootPath(QDir::currentPath());
elementsTreeView->setModel(&model);
*/
    //this->model->setPath(QDir::currentPath());

   // this->libTreeWidget->setColumnCount(2);
    // this->model->setFilter(QDir::Filters(QDir::All));

//icons et bouttons:
QString thispath=QApplication::applicationDirPath();

//qDebug(QApplication::applicationDirPath().toAscii ());
QStyle* style =  QApplication::style();
    QIcon warnIcon = style->standardIcon(QStyle::SP_MessageBoxWarning);
    QIcon newIcon = style->standardIcon(QStyle::SP_FileIcon);
    QIcon closeIcon=  QIcon(thispath+"/ressources/icons/libmanager/close.png");
    //std::cout<<thispath.ascii();
    QIcon importIcon=  QIcon(thispath+"/ressources/icons/libmanager/import.png");
    QIcon vectorizeIcon= QIcon(thispath+"/ressources/icons/libmanager/convert.png");
    QIcon reloadIcon=  QIcon(thispath+"/ressources/icons/libmanager/reload.png");
std::cout <<thispath.toStdString ();
    QToolButton* closeButton=new QToolButton();
    //QToolButton *closeButton=new QToolButton(QIcon(thispath+"/libmanager/import.png"),QString("fermer"), QString("fermer"), this,0,this);
    QToolButton* importButton=new QToolButton();
   this->vectorizeButton=new QToolButton();
    QToolButton* reloadButton=new QToolButton();
    importButton->setIcon(importIcon);
    closeButton->setIcon(closeIcon);
    this->vectorizeButton->setIcon(vectorizeIcon);
    this->vectorizeButton->setToolTip("draw ziguigui...");
    reloadButton->setIcon(reloadIcon);
importButton->setFixedSize(44,28);
this->vectorizeButton->setFixedSize(44,28);
reloadButton->setFixedSize(44,28);
closeButton->setFixedSize(28,28);
importButton->setIconSize(closeButton->size());
this->vectorizeButton->setIconSize(closeButton->size());
reloadButton->setIconSize(closeButton->size());

closeButton->setIconSize(closeButton->size());

        //newProjectButton->setIcon(newIcon);
    //newProjectButton->setToolTip(tr("Nouveau Projet"));
    //TODO placer les quatres boutons de la LIB manager.



    //3 vue pour chaque "libs"
    //elements: filtre *.txt|*.dxf|*.mnc
    //decoupe: filtre *.mnc
    //alphabets filtre  *.dxf


    //libTreeWidget->insertChild(elements);
    //  alphabets.insert(2,elements);

    QSizePolicy policy = this->sizePolicy();
        policy.setVerticalStretch (.2);
        policy.setHorizontalStretch (.2);

    QWidget *fileActionsButtonGroup=new QWidget();
    QWidget *toolsWidget=new QWidget();

    QHBoxLayout *fileActionsHLayout=new QHBoxLayout(fileActionsButtonGroup);
    QVBoxLayout *toolsLayout=new QVBoxLayout();
    QHBoxLayout *toolsLayout1=new QHBoxLayout();


    //boite a outils
      QPushButton *mesurerButton= new QPushButton();//,"mesurer"
      QPushButton *couperButton= new QPushButton();
      QPushButton *selectButton= new QPushButton();
      QPushButton *etirerButton= new QPushButton();
      QPushButton *rotateButton= new QPushButton();
      QPushButton *moveButton= new QPushButton();
      mesurerButton->setIcon(QIcon(thispath+"/ressources/icons/outilschemins/OutilMesurer.ico"));
      couperButton->setIcon(QIcon(thispath+"/ressources/icons/outilschemins/OutilCouperProfil.ico"));
     // originButton->setIcon(QIcon(thispath+"/ressources/icons/outilschemins/OutilPointNumero1.ico"));
      etirerButton->setIcon(QIcon(thispath+"/ressources/icons/outilschemins/OutilEtirer.ico"));
      rotateButton->setIcon(QIcon(thispath+"/ressources/icons/outilschemins/OutilTourner.ico"));
      moveButton->setIcon(QIcon(thispath+"/ressources/icons/outilschemins/OutilDéplacer2.ico"));
      selectButton->setIcon(QIcon(thispath+"/ressources/icons/outilschemins/Selectionner.ico"));

      mesurerButton->setToolTip (tr("Mesurer"));
      couperButton->setToolTip (tr("couper")) ;
      selectButton->setToolTip (trUtf8 ("Définir l'origine"));
      etirerButton->setToolTip (trUtf8 ("Étirer"));
      rotateButton->setToolTip (tr("Tourner"));
      moveButton->setToolTip (trUtf8 ("Mettre à l'échelle"));

      mesurerButton->setFixedSize(44,30);
      couperButton->setFixedSize(44,30);
      selectButton->setFixedSize(44,30);
      etirerButton->setFixedSize(44,30);
      rotateButton->setFixedSize(44,30);
      moveButton->setFixedSize(44,30);

      mesurerButton->setIconSize(mesurerButton->size());
      couperButton->setIconSize(couperButton->size());
      selectButton->setIconSize(selectButton->size());
      etirerButton->setIconSize(etirerButton->size());
      rotateButton->setIconSize(rotateButton->size());
      moveButton->setIconSize(moveButton->size());


      toolsLayout1->addWidget(mesurerButton);
      toolsLayout1->addWidget(couperButton);
      toolsLayout1->addWidget(etirerButton);
      toolsLayout1->addWidget(rotateButton);
      toolsLayout1->addWidget(moveButton);
      toolsLayout1->addWidget(selectButton);

      /////   QPushButton *mesurerButton= new QPushButton();//,"mesurer"
      /// 7buttons...
      /// ces deux là en VLayout
      QVBoxLayout *undoredoLayout=new QVBoxLayout();

      QPushButton *undoButton= new QPushButton();
      QPushButton *redoButton= new QPushButton();

      QHBoxLayout *toolboxbisLayout=new QHBoxLayout();

      QPushButton *deleteButton= new QPushButton();
      QPushButton *cutpathButton= new QPushButton();
      QPushButton *symmetryButton= new QPushButton();
      QPushButton *startendpathButton= new QPushButton();
      QPushButton *copyButton= new QPushButton();


      undoButton->setIcon(QIcon(thispath+"/ressources/icons/outilschemins/Undo4.ico"));
      redoButton->setIcon(QIcon(thispath+"/ressources/icons/outilschemins/redo4.ico"));

      deleteButton->setIcon(QIcon(thispath+"/ressources/icons/outilschemins/poubelle.ico"));
      cutpathButton->setIcon(QIcon(thispath+"/ressources/icons/outilschemins/OutilCouperProfil.ico"));
      symmetryButton->setIcon(QIcon(thispath+"/ressources/icons/outilschemins/SymétrieHorizontale.ico"));
      startendpathButton->setIcon(QIcon(thispath+"/ressources/icons/outilschemins/Inverser.ico"));
      copyButton->setIcon(QIcon(thispath+"/ressources/icons/outilschemins/Dupliquer2.ico"));

      undoButton->setFixedSize(44,15);
      redoButton->setFixedSize(44,15);

      //

      deleteButton->setFixedSize(44,30);
      cutpathButton->setFixedSize(44,30);
      symmetryButton->setFixedSize(44,30);
      startendpathButton->setFixedSize(44,30);
      copyButton->setFixedSize(44,30);


      undoButton->setIconSize(mesurerButton->size());
      redoButton->setIconSize(mesurerButton->size());


      deleteButton->setIconSize(mesurerButton->size());
      cutpathButton->setIconSize(couperButton->size());
      symmetryButton->setIconSize(selectButton->size());
      startendpathButton->setIconSize(etirerButton->size());
      copyButton->setIconSize(rotateButton->size());
      //moveButton->setIconSize(moveButton->size());

//



      undoButton->setToolTip (tr("Mesurer"));
      redoButton->setToolTip (tr("couper")) ;

      undoredoLayout->addWidget(undoButton);
      undoredoLayout->addWidget(redoButton);

      deleteButton->setToolTip (trUtf8 ("Définir l'origine"));
      cutpathButton->setToolTip (trUtf8 ("Étirer"));
      symmetryButton->setToolTip (tr("Tourner"));
      startendpathButton->setToolTip (trUtf8 ("Mettre à l'échelle"));
      copyButton->setToolTip (trUtf8 ("Mettre à l'échelle"));

      toolboxbisLayout->addLayout(undoredoLayout->layout());






      toolboxbisLayout->addWidget(deleteButton);
      toolboxbisLayout->addWidget(cutpathButton);
      toolboxbisLayout->addWidget(copyButton);////

      toolboxbisLayout->addWidget(symmetryButton);
      toolboxbisLayout->addWidget(startendpathButton);


      QVBoxLayout *drawtoolLayout= new QVBoxLayout();
      drawtoolLayout->addLayout(toolsLayout1->layout());
      drawtoolLayout->addLayout(toolboxbisLayout->layout());



//groupbox? aligner et ajuster
//atention: un layout horiz contient deux verti dont l'un
//contient deux hori...
QVBoxLayout *hauteurfilLayout=new QVBoxLayout();

QPushButton *filhautButton= new QPushButton();
QPushButton *filmoyenButton= new QPushButton();
QPushButton *filbasaButton= new QPushButton();
filbasaButton->setIcon(QIcon(thispath+"/ressources/icons/alignbox/AlignerBas.ico"));
filmoyenButton->setIcon(QIcon(thispath+"/ressources/icons/alignbox/AlignerMilieu.ico"));
filhautButton->setIcon(QIcon(thispath+"/ressources/icons/alignbox/AlignerHaut.ico"));


filbasaButton->setFixedSize(44,20);
filmoyenButton->setFixedSize(44,20);
filhautButton->setFixedSize(44,20);


filbasaButton->setIconSize(filbasaButton->size());
filmoyenButton->setIconSize(filmoyenButton->size());
filhautButton->setIconSize(filhautButton->size());



hauteurfilLayout->addWidget(filhautButton);
hauteurfilLayout->addWidget(filmoyenButton);
hauteurfilLayout->addWidget(filbasaButton);




QHBoxLayout *alignLayout=new QHBoxLayout();
QPushButton *aligncenterButton= new QPushButton();
QPushButton *alignvertiButton= new QPushButton();
QPushButton *alignhoriButton= new QPushButton();
aligncenterButton->setIcon(QIcon(thispath+"/ressources/icons/alignbox/AjusterBloc3.ico"));
alignvertiButton->setIcon(QIcon(thispath+"/ressources/icons/alignbox/CentrerSuivantY.ico"));
alignhoriButton->setIcon(QIcon(thispath+"/ressources/icons/alignbox/CentrerSuivantX.ico"));


aligncenterButton->setFixedSize(44,30);
alignvertiButton->setFixedSize(44,30);
alignhoriButton->setFixedSize(44,30);


aligncenterButton->setIconSize(filbasaButton->size());
alignvertiButton->setIconSize(filbasaButton->size());
alignhoriButton->setIconSize(filbasaButton->size());

alignLayout->addWidget(aligncenterButton);
alignLayout->addWidget(alignhoriButton);
alignLayout->addWidget(alignvertiButton);



QHBoxLayout *alignbisLayout=new QHBoxLayout();
QPushButton *alignbiscentreButton= new QPushButton();
QPushButton *alignbisgaucheButton= new QPushButton();
QPushButton *alignbisdroiteButton= new QPushButton();
alignbisdroiteButton->setIcon(QIcon(thispath+"/ressources/icons/alignbox/AlignerDroite.ico"));
alignbisgaucheButton->setIcon(QIcon(thispath+"/ressources/icons/alignbox/AlignerGauche.ico"));
alignbiscentreButton->setIcon(QIcon(thispath+"/ressources/icons/alignbox/AlignerCentre.ico"));

alignbisdroiteButton->setFixedSize(44,30);
alignbisgaucheButton->setFixedSize(44,30);
alignbiscentreButton->setFixedSize(44,30);

alignbisdroiteButton->setIconSize(filbasaButton->size());
alignbisgaucheButton->setIconSize(filbasaButton->size());
alignbiscentreButton->setIconSize(filbasaButton->size());

alignLayout->addWidget(aligncenterButton);

alignbisLayout->addWidget(alignbisgaucheButton);
alignbisLayout->addWidget(alignbiscentreButton);
alignbisLayout->addWidget(alignbisdroiteButton);



QVBoxLayout *aligntoolLayout= new QVBoxLayout();
QHBoxLayout *aligntoolsLayout= new QHBoxLayout();

aligntoolLayout->addLayout(alignLayout->layout());
aligntoolLayout->addLayout(alignbisLayout->layout());

aligntoolsLayout->addLayout(hauteurfilLayout->layout());

aligntoolsLayout->addLayout(aligntoolLayout->layout());




QGridLayout *bloctailleLayout=new QGridLayout();
QLineEdit *hauteur=new QLineEdit("301mm");
QLineEdit *largeur=new QLineEdit("263mm");



QImage bloc(thispath+"/ressources/icons/outilschemins/taillebloc.ico");
QLabel *imgDisplayLabel = new QLabel("");
  imgDisplayLabel->setPixmap(QPixmap::fromImage(bloc));


 imgDisplayLabel->setFixedSize(100,38);

imgDisplayLabel->adjustSize();


hauteur->setFixedSize(100,26);
largeur->setFixedSize(70,38);
//hauteur->adjustSize();
//largeur->adjustSize();





bloctailleLayout->addWidget(hauteur, 0, 1);
bloctailleLayout->addWidget(largeur, 1,0);
bloctailleLayout->addWidget(imgDisplayLabel, 1,1);


QVBoxLayout *boxtoolLayout= new QVBoxLayout();
boxtoolLayout->addLayout(drawtoolLayout->layout());
boxtoolLayout->addLayout(aligntoolsLayout->layout());
boxtoolLayout->addLayout(bloctailleLayout->layout());

toolsWidget->setLayout(boxtoolLayout);



    fileActionsHLayout->addWidget(closeButton);
    fileActionsHLayout->addWidget(importButton);
    fileActionsHLayout->addWidget(reloadButton);
    fileActionsHLayout->addWidget(this->vectorizeButton);
    //!\this->libTreeWidget->layout()->addWidget(fileActionsButtonGroup);
   //libTreeWidget->show();
    //libTreeWidget->setWindowTitle("libmanager class");

    this->libwidget=new QWidget();
    QVBoxLayout *liblayout;
liblayout=new QVBoxLayout();



libTreeWidget->setSizePolicy(policy);
//fileActionsButtonGroup->setSizePolicy (policy);
//!!!!!!!!!!!workled

//liblayout->addWidget(fileActionsButtonGroup);
//this->libTreeWidget->layout ()->addWidget (fileActionsButtonGroup);
liblayout->addWidget(this->libTreeWidget);
//liblayout->addWidget(toolsWidget);






//!!!!!!!
fileActionsButtonGroup->setSizePolicy (policy);

   // policy.setVerticalPolicy(QSizePolicy::Minimum);
   // policy.setHorizontalPolicy(QSizePolicy::Minimum);

    libwidget->setSizePolicy(policy);
this->setSizePolicy(policy);
liblayout->setContentsMargins (0,0,0,0);
this->libwidget->setLayout(liblayout->layout());



   QObject::connect(this->libTreeWidget, SIGNAL(itemClicked(QTreeWidgetItem*  ,int )), this->parent(), SLOT(load_file(QTreeWidgetItem*,int)));

   QObject::connect(closeButton, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
   QObject::connect(reloadButton, SIGNAL(clicked(bool)), parent, SLOT(reload_filePreview(bool)));


   //defaut path for defaut constructor...
   this->set_path(thispath+"/../");
   //slot::
}
void Libmanager::set_path(QString path)
{
    //warn:nocheck!!!
    this->path=path;
   // QString test=QString ("test") ;
    this->refresh();

    //this->model->setPath(path);
}
QString Libmanager::get_path(void)
{
    //warn:nocheck!!!
return this->path;
}
/* shouldbe an signal
void Window::slotButtonClicked(bool checked)
{
    if (checked) {
        m_button->setText("Checked");
    } else {
        m_button->setText("Hello World");
    }
}
*/
void Libmanager::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this, tr("QMessageBox::critical()"),
                                  tr("<p>Message boxes have a caption, a text, " \
                                             "and any number of buttons, each with standard or custom texts." \
                                             "<p>Click a button to close the message box. Pressing the Esc button " \
                                             "will activate the detected escape button (if any)."),
                                  QMessageBox::Cancel | QMessageBox::Close | QMessageBox::Abort);
    if (reply == QMessageBox::Abort)
        event->ignore();
       else if (reply == QMessageBox::Close)
           {this->parentWidget()->close();
    event->accept();}
       else
           {
this->hide();
        event->ignore();}


}

void Libmanager::close(void)
{
std::cout<<"closeevent"<<std::endl;
    if(this->isHidden())
     {

        this->show();
        ///this->ignore();

    }
    else
     { this->hide();

               // this->ignore();
        //event.accept();
    }
}
