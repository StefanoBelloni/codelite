#ifndef _CL_VIM_COMMAND_BASE_H_
#define _CL_VIM_COMMAND_BASE_H_

#include <utility>
#include <wx/chartype.h>
#include "clVimEnums.h"

class VimCommand;

class VimBaseCommand
{
public:
    VimBaseCommand();
    explicit VimBaseCommand(const VimBaseCommand& cmd);
    explicit VimBaseCommand(const VimCommand& cmd);
    
protected:
    std::pair<VimModi,int> m_modus;   /*modus and flag*/

    int      m_repeat;           /*!< number of repetition for the command */
    wxChar   m_baseCommand;      /*!< base command (first char of the cmd)*/
    int      m_n_actions;        /*!< repetition of the modifier.In 'c3x', "3" */
    wxChar   m_actionCommand;    /*!< eventual command modifier.In 'c3w', "w" */

};


#endif // _CL_VIM_COMMAND_H_
