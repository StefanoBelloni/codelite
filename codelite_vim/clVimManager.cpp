#include "clVimManager.h"

VimManager::VimManager(IManager* manager, VimSettings& settings)
    : m_settings(settings)
{
    this->m_mgr = manager;
}

VimManager::~VimManager()
{}

void VimManager::SettingsUpdated()
{}

void VimManager::OnEditorChanged(wxCommandEvent& event)
{}

void VimManager::OnEditorClosing(wxCommandEvent& event)
{}

void VimManager::OnWorkspaceClosing(wxCommandEvent& event){}

void VimManager::OnAllEditorsClosing(wxCommandEvent& event){}

void VimManager::OnCharEvt(wxKeyEvent& event){}

void VimManager::OnKeyDown(wxKeyEvent& event){}

void VimManager::DoBindEditor(IEditor* editor){}

void VimManager::DoCleanup(bool unbind){}

void VimManager::CloseCurrentEditor(){}

void VimManager::SaveCurrentEditor(){}

void VimManager::UpdateOldEditorState(){}

void VimManager::SaveOldEditorState(){}

void VimManager::DeleteClosedEditorState(){}

void VimManager::DeleteAllEditorState(){}

