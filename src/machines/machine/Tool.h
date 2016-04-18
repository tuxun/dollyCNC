#ifndef Tool_H
#define Tool_H
#include "machines/machine/Machine.h"
enum Machine_Tool_Type{PARROT_Tool,HOTWIRE,EXTRUDER,PLOTTER,LASER,MILL,SEW,STEPPER};

class Tool
{
public:
    Tool();
    Tool(Machine_Tool_Type machinetooltype);
   static Machine_Tool_Type tooltype_from_productid(wchar_t pid,wchar_t vid);

};

#endif // Tool_H
