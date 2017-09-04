#ifndef __VIM_MANAGER_H__
#define __VIM_MANAGER_H__

#include <wx/stc/stc.h>
#include <wx/kbdstate.h>
#include <list>

#include "globals.h"
#include "ieditor.h"
#include "event_notifier.h"
#include "macros.h"
#include "imanager.h"

#include "codelite_events.h"
#include "VimSettings.h"
#include "clVimCommand.h"
#include "clVimEditorStatus.h"
#include "clVimRegistries.h"

/**
 * @brief This Class is used to intercet the key event end rederect them
 * to perform vi-key-bindings.
 */

class VimManager : public wxEvtHandler
{

public:
    /*ctr-distr ... */
    VimManager(IManager* manager, VimSettings& settings);
    virtual ~VimManager();
    void SettingsUpdated();

protected:
    void OnEditorChanged(wxCommandEvent& event);
    void OnEditorClosing(wxCommandEvent& event);
    void OnWorkspaceClosing(wxCommandEvent& event);
    void OnAllEditorsClosing(wxCommandEvent& event);

    void OnCharEvt(wxKeyEvent& event);
    void OnKeyDown(wxKeyEvent& event);

    void DoBindEditor(IEditor* editor);
    void DoCleanup(bool unbind = true);

    // Internals
    void CloseCurrentEditor();
    void SaveCurrentEditor();

    void UpdateOldEditorState();
    void SaveOldEditorState();
    void DeleteClosedEditorState();
    void DeleteAllEditorState();

private:

    IManager*    m_mgr;
    VimSettings& m_settings;

    VimRegistries m_registries;

    std::list<VimEditorStatus> m_editorStatesList;
    VimCommand m_currentCommand; /*!< command currenly */
    VimCommand m_lastCommand;    /*!< last command performed */

};

#endif // __VIM_MANAGER_H__

