#include "gui.h"
#include "ui_gui.h"
#include "Minicut.h"
#include  <QDir>
#include <QMessageBox>
#include <QFileDialog>
//#include <QTreeWidgetItem>
#include "file/Libmanager.h"
#include <QtSvg>
gui::gui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gui)
{
    actual_dest_temp=0;
    button_said=mwHALT;
    ui->setupUi(this);
    ui->tempbare->setValue(0);
    this->showMaximized();

    this->lib= new Libmanager(this);
    //...
    //lib(this);
    //=lib.libwidget;


    //ui->browserWidget=lib.libTreeWidget;
    //!\
    //!
    //!
    //!
    QHBoxLayout *dessinLayout=new QHBoxLayout();
    QWidget *dessinWidget=new QWidget(this);
    this->fileDraw=new drawingTools(this,"fichier");
    this->decoupeDraw=new drawingTools(this,"previsualition");
    QWidget *dessinTab=new QWidget();
    QVBoxLayout *dessinTabLayout=new QVBoxLayout(dessinTab);
    dessinTabLayout->addWidget(this->fileDraw->sceneVue->window());
    //drawingTools *test=new drawingTools();
    //test->show();
    dessinTabLayout->addWidget(this->decoupeDraw);
    dessinLayout->addWidget(dessinTab);
    dessinWidget->setLayout(dessinLayout);
    ui->browserWidget->setLayout(lib->libwidget->layout());
    //ui->widget->show();
    ui->tab_4->setLayout(dessinWidget->layout());
    ui->initButton->setText("open");

    connect(ui->browserWidget, SIGNAL(itemClicked(QTreeWidgetItem*  ,int )), this, SLOT(load_file(QTreeWidgetItem*,int)));

    connect(ui->moinschaudButton,SIGNAL(clicked()),this,SLOT(chauffemoins()));
    connect(ui->pluschaudButton,SIGNAL(clicked()),this,SLOT(chauffeplus()));

    connect(ui->hgButton,SIGNAL(clicked()),this,SLOT(mw_hgmove()));
    connect(ui->hdButton,SIGNAL(clicked()),this,SLOT(mw_hdmove()));
    connect(ui->hButton,SIGNAL(clicked()),this,SLOT(mw_hmove()));

    connect(ui->gButton,SIGNAL(clicked()),this,SLOT(mw_gmove()));
    connect(ui->dButton,SIGNAL(clicked()),this,SLOT(mw_dmove()));

    connect(ui->runstopbutton,SIGNAL(clicked()),this,SLOT(mw_HALTmove()));


    connect(ui->bgButton,SIGNAL(clicked()),this,SLOT(mw_bgmove()));
    connect(ui->bdButton,SIGNAL(clicked()),this,SLOT(mw_bdmove()));
    connect(ui->bButton,SIGNAL(clicked()),this,SLOT(mw_bmove()));


    connect (ui->getstatutButton,SIGNAL(clicked()),this,SLOT(teststatut()));

    connect (ui->testmoveButton,SIGNAL(clicked()),this,SLOT(testmove()));


    connect(ui->actionQuitter , SIGNAL(triggered()), this, SLOT(asktoquit()));

    connect(this , SIGNAL(realquit()), qApp, SLOT(quit()));


    connect(this,SIGNAL(temp_changed(int)),ui->tempbare,SLOT(setValue(int)));

    connect(this,SIGNAL(moveway_changed(move_way)),this,SLOT(setwhatrunbutton(move_way)));

    connect(ui->initButton,SIGNAL(clicked()),this,SLOT(init_machine()));

    connect(ui->actionConnecter , SIGNAL(triggered()), this, SLOT(openmachinelist()));

    connect(ui->actionImport , SIGNAL(triggered()), this, SLOT(importtolibrary()));

    connect(ui->actionLibrary_path , SIGNAL(triggered()), this, SLOT(changelibrarypath()));

    connect(ui->actionToggle_Library , SIGNAL(triggered()), this, SLOT(togglelibrary()));
    //!
    connect(this, SIGNAL(filechanged(QStringList*)), this->fileDraw, SLOT(add_shape(QStringList*)));

    statusBar()->showMessage("lancement de driver ready:");
    connect(ui->gcodesendButton,SIGNAL(clicked()),this,SLOT(sendgcode()));
    ui->gcodesendText->setText("G0 X1.\n");
    connect(ui->drawtocodeButton,SIGNAL(clicked()),this,SLOT(getcode()));
    this->centralWidget()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    connect(ui->doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(resizepreviewx(double)));
    connect(ui->doubleSpinBox_2,SIGNAL(valueChanged(double)),this,SLOT(resizepreviewy(double)));

    std::cout << "listing hid device:"<< std::endl;

    QStringList devicehid=this->machine->get_hid_device();
    for (int i = 0; i < devicehid.size(); ++i)
             std::cout << devicehid.at(i).toLocal8Bit().constData() << std::endl;

    std::cout << "listing serial device:"<< std::endl;

    QStringList deviceserial=this->machine->get_serial_device();
    for (int i = 0; i < deviceserial.size(); ++i)
             std::cout << deviceserial.at(i).toLocal8Bit().constData() << std::endl;
}
void gui::resizepreviewx(double nsize)
{
    //this->fileDraw->adjustSize();
this->fileDraw->sceneVue->scale(nsize,1);
    //this->fileDraw->sceneConteneur->setSceneRect();
   // this->fileDraw->autoscale();
}
void gui::resizepreviewy(double nsize)
{
   // this->fileDraw->adjustSize();
this->fileDraw->sceneVue->scale(1,nsize);
    //this->fileDraw->sceneVue->mapToParent()
}
void gui::getcode()
{
    //drawnpath=
    ui->gcodesendText->clear();
    int i;
    QStringList pathscoordstring=this->fileDraw->get_paths();
    for(i=0;i<pathscoordstring.size();i++){

        ui->gcodesendText->append(pathscoordstring.at(i)+'\n');
    }
    if(!i)
    {QMessageBox::information(this,"attention au bugs","gui::getcode() pas de  path chargé!",QMessageBox::YesToAll);
    }
}

void gui::sendgcode(void)
{
    //int  bytesend;//=this->devicefile->write(ui->gcodesendText->toPlainText().toUtf8());
    //qint64  bytesend=this->devicefile->write(ui->gcodesendText->toPlainText().toUtf8());
    int bytesend=this->devicefile->write(ui->gcodesendText->toPlainText().toUtf8()/*+'\n'*/,ui->gcodesendText->toPlainText().length()+1);
    this->devicefile->flush();
    if(bytesend<1)

    {
        statusBar()->showMessage(this->devicefile->errorString());
    }
    else
    {        statusBar()->showMessage("Octets bien send:"+bytesend+ui->gcodesendText->toPlainText().toUtf8());

    }
    //QMessageBox::warning(this, "Error", QString("Failed to open iPod device. Reason: ").append(this->devicefile->errorString()));

}

void gui::importtolibrary(void)
{
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg),CNC (*.rml *.ngc *.gcode),Images vectorielles(*.dxf *.eps *.svg *.txt)");
    QString fichier1 = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
}

void  gui::changelibrarypath(void)
{
    QString dossier=QFileDialog::getExistingDirectory(this);
    this->lib->set_path(dossier);
}

void gui::openmachinelist(void)
{

}

void gui::togglelibrary(void)
{

    this->lib->close();
}

void gui::reload_filePreview(bool truc)
{
    this->filePreviewScene->clear();
    this->fileDraw->sceneConteneur->clear();
    this->decoupeDraw->sceneConteneur->clear();

    //this->decoupeDraw->sceneVue->show();
}

void gui::load_txt_file(QString filepath)
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
                paths_name.append(QString(line.toUtf8()));
                path_count++;
            }
            else
            {
                paths.append(QString(line.toUtf8()));
            }


        }
        while (!in.atEnd());

        /* for (int i = 0; i < paths.size(); ++i)
                 {
            std::cout << paths.at(i).toStdString()<<std::endl;
        }*/


        this->fileContent= new QStringList (paths);
        emit filechanged(this->fileContent);


    }
    else
    {
        statusBar()->showMessage("failed to open "+filepath);
    }
}

//load mnc:         QStringList list1 = toadd->at(i).split(":", QString::SkipEmptyParts);
void gui::load_mnc_file(QString filepath)
{
    //   std::cout "loading mnc file: ". filepath.toUtf8();

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
                paths_name.append(QString(line.toUtf8()));
                path_count++;
            }
            else if (firstchar.isDigit())
            {
                QStringList list1 = line.split("=", QString::SkipEmptyParts);
                //std::cout list1.at(1).toUtf8()<<std::endl;

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
        statusBar()->showMessage("failed to open "+filepath);
    }
}
void gui::load_svg_file(QString filepath)
{
    //std::cout "loading svg!!! file: "<<filepath.toUtf8()<<std::endl;

    //

    QFile *file=new QFile(filepath);
    QSvgRenderer *renderer = new QSvgRenderer(filepath);
    //QSvgWidget *svg=new QSvgWidget("svg.svg");
if(renderer->isValid())
{

}
else
{        std::cout<<"norenderer"<<std::endl;
}


    //worked!    QFile *file=new QFile(QString("/home/tuxun/txt/noel.txt"));
    if(file->open(QIODevice::ReadOnly|QIODevice::Text))
    {

        QGraphicsSvgItem *svg=new QGraphicsSvgItem(filepath);
        std::cout<<"svgdump "<<filepath.toStdString()<<std::endl;
        //svg->paint(QPainter(),0);
        QList<QGraphicsItem*> itemlist=svg->childItems();
        //svg->dumpObjectTree();
        //svg->dumpObjectInfo();
        //this->fileContent= new QStringList (paths);
        //!/
        //
       emit item_ready(svg->parentItem())      ;
       /// emit item_ready(renderer->children());
        int i;
        for (i = 0; i < itemlist.size(); ++i) {
            emit item_ready(itemlist.at(i));
        }
        std::cout <<i<<"items"<<std::endl;

    }
    else
    {
        statusBar()->showMessage("failed to open "+filepath);
    }
}
/*
void gui::enregistrer()
{
    QString filtre;
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Fichier Texte(*.txt *.mnc *.dxf *.svg)", &filtre);

  }
*/
void gui::init_machine()
{

    this->devicefile=new QFile();


    FILE* fd = fopen(ui->deviceMenu->currentText().toUtf8(),"w+"); // get a file descriptor somehow
    //this->devicefile.open(fd, QIODevice::ReadWrite); // or use an INT file descriptor
    if (this->devicefile->open(fd,QIODevice::ReadWrite)) {

        statusBar()->showMessage("connected to "+ui->deviceMenu->currentText());
        ui->initButton->setText("close");
        ui->dri_statelabel->setText(QString("opened"));
        ui->dev_filelabel->setText(ui->deviceMenu->currentText());
    }
    else
    {
        ui->initButton->setText("open");
        QMessageBox::warning(this, "Error", QString("Failed to open iPod device. Reason: ").append(devicefile->errorString()));

        statusBar()->showMessage("failed to open "+ui->deviceMenu->currentText());
    }
    // this->machine=new minicut(ui->deviceMenu->currentText());
    /* if (machine)
    {
        ui->dri_statelabel->setText(QString(machine->driver_device_state()?"ok":"pb"));

        ui->dev_filelabel->setText(machine->get_path());

    }
else
    {   qDebug("no machine found! but parrot should be launched!");
        ui->dri_statelabel->setText("AArrr!");
    }
    */
}




//slot:   "load file"
void gui::load_file(QTreeWidgetItem* itemClicked, int col)
{
    //std::cout<<itemClicked->text(0).ascii()<<std::endl;
    //QApplication::applicationDirPath()

    QString filename=itemClicked->text(0).prepend(this->lib->get_path()+"bibliotheque/"+itemClicked->parent()->text(0)+'/');

    //  std::cout<<filename.toStdString()<<col<<std::endl;

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
    else         statusBar()->showMessage("filetype not supported (yet)" );


}

void gui::teststatut()
{
    //this->machine=new minicut(ui->deviceMenu->currentText());

    // this->mncstate=machine->driver_device_state();
    //QChar ch2(machine->read1s());
    QString str;

    ui->dev_filelabel->setText(machine->get_path());
    ui->dri_statelabel->setText(QString(machine->driver_device_state()?"ok":"pb"));
    str.append(ui->textBrowser->document()->toPlainText());
    str.append(machine->read1s());
    ui->textBrowser->setText(str);

}


void gui::asktoquit(){
    machine->close();
    emit realquit();
}
void gui::mw_hmove()
{
    emit(moveway_changed(mwH));

}

void gui::testmove()
{

    std::cout<<"main->testmoveslot()!"<<std::endl;
    //eg: usb data to move the first motor on 10 stepwhile 1 second
    //1 . send reset from pc: 0x42+0x00
    //1a. IPL5X answer is 0x42+0xFF
    //2 .source=USB (from PC): 0x42+0x01
    //2a. IPL5X answer is 0x42+0xFF
    //3 .Fill buffer
    unsigned char data=0x42; //Return the size of written data



    //return
    machine->testmove();

}



void gui::mw_hgmove()
{
    emit(moveway_changed(mwHG));

}

void gui::mw_hdmove()
{
    emit(moveway_changed(mwHD));

}


void gui::mw_gmove()
{
    emit(moveway_changed(mwG));

}

void gui::mw_dmove()
{
    emit(moveway_changed(mwD));

}

void gui::mw_bgmove()
{
    emit(moveway_changed(mwBG));

}

void gui::mw_bdmove()
{
    emit(moveway_changed(mwBD));

}

void gui::mw_bmove()
{
    emit(moveway_changed(mwB));

}

void gui::mw_HALTmove()
{
    emit(moveway_changed(mwHALT));

}

void gui::setwhatrunbutton(move_way wayin)
{
    switch (wayin)
    {
    case mwHALT:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:green");

        ui->movewaylabel->setText("Stop");
        break;
    case mwH:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");

        ui->movewaylabel->setText("haut");
        break;
    case mwHG:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");

        ui->movewaylabel->setText("Haut/gauche");
        break;
    case mwHD:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");

        ui->movewaylabel->setText("Haut/droite");
        break;
    case mwG:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");

        ui->movewaylabel->setText("Gauche");
        break;
    case mwD:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");

        ui->movewaylabel->setText("Droite");
        break;
    case mwBG:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");

        ui->movewaylabel->setText("Bas/gauche");
        break;
    case mwBD:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");

        ui->movewaylabel->setText("Bas/droite");
        break;
    case mwB:
        button_said=wayin;
        ui->runstopbutton->setStyleSheet("background:red");
        ui->movewaylabel->setText("Bas");
        break;
    }
}

void gui::chauffeplus()
{
    actual_dest_temp=actual_dest_temp+1;
    if (actual_dest_temp>100)
    {
        actual_dest_temp=100;
    }
    emit (temp_changed(actual_dest_temp));
}
void gui::chauffemoins()
{
    actual_dest_temp=actual_dest_temp-1;

    if (actual_dest_temp<0)
    {
        actual_dest_temp=0;
    }

    emit (temp_changed(actual_dest_temp));
}
gui::~gui()
{
    delete ui;
}
//  dessinTabLayout->addWidget(this->filePreviewView);
//dessinTabLayout->addWidget(this->decoupePreviewView);
//QWidget *dec=new QWidget(this->decoupeDraw->sceneVue->viewport());

//  this->decoupeDraw->sceneVue->update();
//this->librairy->setSizePolicy(QSizePolicy,QSizePolicy::);
//dessinTabLayout->addWidget(this->decoupeDraw->sceneVue->window());

//dessinLayout->addWidget(this->librairy->libwidget);
//
//mainLayout->addWidget(preView->viewport());



// mainLayout->addWidget(menuButtonGroup);
//mainLayout->addWidget(onglets);

//mainLayout->addWidget (dessinWidget);


/*

ui->widget=lib.libwidget;
ui->widget->show();
*/

//  ui->widget=lib.libwidget;

//ui->tab_3=lib.libwidget;

//this->setLayout(lib.libwidget->layout());
//ui->dessin->show();        //ui->widget->layout()->addWidget(lib.libwidget);

//ui->tab_4=lib.libwidget;
// ui->tab_4->show();
//ui->widget=this->fileDraw;// lib.libwidget;
//ui->widget->layout()->addWidget(lib.libwidget);
//ui->widget->layout()->addWidget(dessinWidget);

//ui->widget->layout()->addWidget(dessinWidget);
