#ifndef gui_H
#define gui_H

#include <QMainWindow>
#include "Minicut.h"
#include <qtreewidget.h>

#include <file/Libmanager.h>
#include "draw/drawingtools.h"
#include <QtGui>
enum move_way{mwHALT,mwH,mwB,mwG,mwD,mwHG,mwHD,mwBG,mwBD};
namespace Ui {
class gui;
}

class gui : public QMainWindow
{
    Q_OBJECT

public:
    explicit gui(QWidget *parent = 0);
    void load_svg_file(QString filepath);
    void load_mnc_file(QString filepath);
    void load_txt_file(QString filepath);
    //void load_file(QString filepath);
    void setlibrarypath(QString path);




    ~gui();

private:
    Ui::gui *ui;
int actual_dest_temp;
//void enregistrer();
QFile *devicefile;
minicut *machine;

//bool mncstate;

Libmanager *lib;

//outil de dessin
drawingTools *fileDraw,*previewDraw,*decoupeDraw;
//fichier actuellement chargé
QStringList *fileContent;
//dans l'onglet "dessin":
QGraphicsScene *filePreviewScene,*decoupePreviewScene;
QGraphicsView *filePreviewView,*decoupePreviewView;
move_way button_said;


signals:
    void filechanged(QStringList*);
    void item_ready(QGraphicsItem*);


//void item_ready(QGraphicsItem*);
//void preview_path_cliqued(QGraphicsItem*);
void moveway_changed(move_way);
//void sceneClicked(bool);
void temp_changed(int);
void realquit();

public slots:
void load_file(QTreeWidgetItem* itemClicked, int col);
void reload_filePreview(bool truc=0);
void togglelibrary(void);
void sendgcode(void);
void getcode(void);
void resizepreviewx(double);
void resizepreviewy(double);

void importtolibrary(void);

void  changelibrarypath(void);
void openmachinelist(void);


void chauffeplus();
void chauffemoins();
void setwhatrunbutton(move_way);
void mw_hdmove();
void mw_dmove();
void mw_bdmove();

void mw_hgmove();
void mw_bgmove();
void mw_gmove();

void mw_bmove();
void mw_hmove();
void mw_HALTmove();

void teststatut();
void init_machine(void);
void testmove();
void asktoquit();

/*void set_action(move_way);
void run();
void stop();
*/
};

#endif // gui_H
