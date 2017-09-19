#include "clVimManager.h"

// MACROS ---------------------------------------

#define BIND_VIMANAGER_EVT(evt, func) \
    EventNotifier::Get()->Bind(wxEVT_##evt,    \
                               &VimManager::func, this)

#define UNBIND_VIMANAGER_EVT(evt, func) \
    EventNotifier::Get()->Unbind(wxEVT_##evt,    \
                               &VimManager::func, this)
// ---------------------------------------------------------------------- #


VimManager::VimManager(IManager* manager, VimSettings& settings)
    : m_settings(settings)
    , m_registries()
    , m_editorStatesList()
    , m_currentCommand(m_registries)
    , m_lastCommand(m_registries)
{

    InitVimManager(manager);

}

VimManager::~VimManager()
{
    DoUnbindEvts();
}

void VimManager::InitVimManager(IManager* manager)
{
    this->m_mgr = manager;
    DoBindEvts();
}    

void VimManager::DoBindEvts()
{
    BIND_VIMANAGER_EVT(ACTIVE_EDITOR_CHANGED, OnEditorChanged);
    BIND_VIMANAGER_EVT(EDITOR_CLOSING, OnEditorClosing);
    BIND_VIMANAGER_EVT(WORKSPACE_CLOSING, OnWorkspaceClosing);
    BIND_VIMANAGER_EVT(ALL_EDITORS_CLOSING, OnAllEditorsClosing);

}

void VimManager::DoUnbindEvts()
{
    UNBIND_VIMANAGER_EVT(ACTIVE_EDITOR_CHANGED, OnEditorChanged);
    UNBIND_VIMANAGER_EVT(EDITOR_CLOSING, OnEditorClosing);
    UNBIND_VIMANAGER_EVT(WORKSPACE_CLOSING, OnWorkspaceClosing);
    UNBIND_VIMANAGER_EVT(ALL_EDITORS_CLOSING, OnAllEditorsClosing);
}
   

void VimManager::SettingsUpdated()
{}

void VimManager::OnEditorChanged(wxCommandEvent& event)
{
    event.Skip();
    IEditor* curr_editor = reinterpret_cast<IEditor*>(event.GetClientData());
    m_currentCommand.SetCurrentEditor( curr_editor );
    if(!m_settings.IsEnabled()) return;

    SaveOldEditorState();
    DoBindEditor(curr_editor);
}

void VimManager::OnEditorClosing(wxCommandEvent& event)
{}

void VimManager::OnWorkspaceClosing(wxCommandEvent& event)
{}

void VimManager::OnAllEditorsClosing(wxCommandEvent& event)
{}

void VimManager::OnCharEvt(wxKeyEvent& event)
{}

void VimManager::OnKeyDown(wxKeyEvent& event)
{}

void VimManager::DoBindEditor(IEditor* editor)
{
    DoCleanup();
    
}

void VimManager::DoCleanup(bool unbind)
{}

void VimManager::CloseCurrentEditor()
{}

void VimManager::SaveCurrentEditor()
{}

void VimManager::UpdateOldEditorState()
{}

void VimManager::SaveOldEditorState()
{}

void VimManager::DeleteClosedEditorState(
){}

void VimManager::DeleteAllEditorState()
{}

