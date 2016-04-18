#include <qstringlist.h>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "machines/machine/Machine.h"

Machine::Machine()
{
    Tool defaut_tool(PARROT_Tool);

}
Machine::Machine(wchar_t pid, wchar_t vid)
{
    this->machine_type=this->from_productid(pid,vid);
   Tool defaut_tool=Tool(PARROT_Tool);

}





QStringList Machine::get_hid_device(void)
{
    // Enumerate and print the HID devices on the system
     struct hid_device_info *devs, *cur_dev;
QStringList ret;
        devs = hid_enumerate(0x0, 0x0);
        cur_dev = devs;
        while (cur_dev) {
            ret<< cur_dev->path;
//doit tester si cest une minicut!*
            //std::cout<<cur_dev->path;
           //set_connection_path(cur_dev->path);

            cur_dev = cur_dev->next;

        }
        hid_free_enumeration(devs);
return ret;
    //P:  Vendor=04d8 ProdID=00aa Rev=00.34
    //souris[57837.076239] usb 2-2: New USB device found, idVendor=046d, idProduct=c050

    //        realmnc = hid_open(0x4d8, 0x00aa, NULL);//real mnc ID


}

  QStringList Machine::get_serial_device(void)
  {QStringList ret;

      QList<QSerialPortInfo> retl =QSerialPortInfo::availablePorts();
      for (int i=0;i<retl.size();i++)
      {
          ret.append(retl.at(i).portName()+retl.at(i).productIdentifier());
      }


  return  ret;}




//Machine::Machine(QString)
//{
//}
Machine_Type Machine::from_productid(wchar_t pid, wchar_t vid)
{
 switch(pid)
    {
    case 0x4d8:
    {
            return MINICUT;
    break;
    }
        case 0x6029:
            //marlin 2.0
            //ulltimaker tuxunuesque
            {return REPRAP;
}
        default: return PARROT_MACHINE;

 }}
        //v0x1d50 	p0x6029 	Marlin 2.0 (USB Serial)
//        2341  Arduino SA
//            0001  Uno (CDC ACM)
//            0010  Mega 2560 (CDC ACM)
//            003b  Serial Adapter (CDC ACM)
//            003f  Mega ADK (CDC ACM)
//            0042  Mega 2560 R3 (CDC ACM)
//            0043  Uno R3 (CDC ACM)
//            0044  Mega ADK R3 (CDC ACM)
//            0045  Serial R3 (CDC ACM)
//            8036  Leonardo (CDC ACM, HID)


Machine::Machine(Machine_Type machineTooltype)
{
    Tool defaut_Tool(Machine_Tool_Type machineTooltype);

}
