#ifndef _CL_VIM_COMMAND_H_
#define _CL_VIM_COMMAND_H_

#include <wx/chartype.h>
#include "clVimBaseCommand.h"
#include "clVimRegistries.h"

class VimCommand : public VimBaseCommand
{
public:
    
    VimCommand(const VimRegistries& registries);
    bool OnSpecialKey();
    bool OnNewChar();
    void SetEditor();
private:
    VimRegistries registries;
    
};
    
#endif // _CL_VIM_COMMAND_H_
