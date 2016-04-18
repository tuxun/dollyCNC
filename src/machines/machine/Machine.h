#ifndef MACHINE_H
#define MACHINE_H
#include <QString>
#include "hid/hidapi.h"
#include "machines/machine/Tool.h"

enum Machine_Type{PARROT_MACHINE,MINICUT,REPRAP,SEWER,LASERCUT,CNCMILL,ROBOT};
enum Axis_orientation{WORKING_VERTICALY,WORKING_HORIZONTALY};



/*classe abstraite pour gerer les machines*/
class Machine
{
public:
    //as default settings as pid/vid to initialize itself  alone*/
    Machine();

    Machine(Machine_Type);
    Machine(wchar_t,wchar_t);


    //a init device fonction
    bool init_device();
    QStringList get_hid_device(void);
    QStringList get_serial_device(void);
    //machine has:

   //a device path
    QString device_driver_path;
bool set_path(QString path);
bool change_path(QString path);
static Machine_Type from_productid(wchar_t,wchar_t);

//Tool defaut_tool;
Machine_Type machine_type;
int axis_number;
Axis_orientation axis_orientation;







    //a product id
    wchar_t productId;
    //a vendor id
    wchar_t vendorId;
    //a state: false=not present

    bool driver_device_state;
    bool machine_device_state;
    //des logs!!!
    QString driver_logs[];
    QString machine_logs[];

    QString get_pathqstring_from_device(hid_device*);

    //un poitn d'origine

    //un nombre d'axes
    /*
    un nombre d'outils
    un nombre de param d'outils...(sic)
    EDIT:OU:
    un outil = un  param
    exemples:

    buse=temp
    extrudeur=vecteur

    fil_chaud=puissance (char 255 en %)

    plotter=enfoncement (type inconnu!) 100%

    laser=puissance
    mouvement=vecteur(vitesse incluse)
    rythme=HZ

    brodeuse=

*/


};

#endif // MACHINE_H
