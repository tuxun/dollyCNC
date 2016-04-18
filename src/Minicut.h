#ifndef MINICUT_H
#define MINICUT_H
#include <qstring.h>
#include <iostream>
#include "hid/hidapi.h"
#include "machines/machine/Machine.h"

#define __MNC_MAX_STR 255

class minicut : public Machine //une mnc EST une machine
{
public:
    minicut();
    minicut(QString);
    minicut(wchar_t vid, wchar_t pid);
    char *read1s();

    bool init_device();
    bool close();

    bool driver_state;//false=none;
    bool driver_real;//false=real;
    QString driver_path;
    bool machinestate;
    unsigned char *buffer;
    /*true=ok*/

    bool driver_device_state();

    /*qt utilities*/
    QString get_pathqstring_from_device(hid_device*);
    QString get_path(void);


    /*fun tests*/
    void teststop();
    bool  try_device(void);
    int teststatus();
    int testmove();

private:
    /*HID device to open*/
    hid_device *minicut_device=NULL;
    hid_device *minicut_parrot_device=NULL;


    /*machine command code*/
    void softstop();
    void hardstop();
    void set_pwm();
    //send data
    //reset!



};

#endif // MINICUT_H
