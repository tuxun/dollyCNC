#include "Tool.h"

Tool::Tool()
{
}

Tool::Tool(Machine_Tool_Type machinetooltype)
{
}

Machine_Tool_Type tooltype_from_machinetype(Machine_Type type)
{switch (type)
    {
    case MINICUT    :
            return HOTWIRE;
        case REPRAP:
            //marlin 2.0
            //ulltimaker tuxunuesque
            return EXTRUDER;

        default: return PARROT_Tool;
}}
