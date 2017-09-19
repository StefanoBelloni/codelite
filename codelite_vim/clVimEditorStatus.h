#ifndef _VIM_EDITOR_STATUS
#define _VIM_EDITOR_STATUS

#include "clVimBaseCommand.h"

class VimEditorStatus
{
    
public:

    VimEditorStatus(){};
    explicit VimEditorStatus( const VimCommand& vimCommand);
    explicit VimEditorStatus( const VimBaseCommand& vimBaseCommand);
    ~VimEditorStatus();

    
private:
    VimBaseCommand baseCommand;
    
};

#endif   // _VIM_EDITOR_STATUS
