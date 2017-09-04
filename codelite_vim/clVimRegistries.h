#ifndef _CL_VIM_REGISRIES_H__
#define _CL_VIM_REGISRIES_H__

#include <wx/string.h>
#include <array>
#include <list>

enum VIM_REGISTRY_TYPE {
    ALPHA, NUMERIC, READ_ONLY, NOT_VALID
};

namespace VIM_REGISTRIES {
    const std::size_t N_ALPHA_REGISTRIES = 26;
    const std::size_t N_NUM_REGISTRIES   = 10;
}

/**
 * Class that implements the registries of vim
 * 
 * There is one "instance" per workspace, a pointer will be given to the vimCommand
 * to be abe to use the proper buffer.
 * @ref http://www.brianstorti.com/vim-registers/
 */


class VimRegistries
{
    
public:
    
    VimRegistries();  /*!< ctr*/
    ~VimRegistries(); /*!< dstr*/

    wxString GetRegistry ( );                                         /*!< Get content of the registry 'anonimous'*/
    wxString GetRegistry ( const wxChar registry );                   /*!< Get content of the registry 'registry'*/

    /** @brief Set content of the registry 'registry'*/
    void     SetRegistry ( const wxChar registry, const wxString buffer, const bool append = false);
    /** @brief Set content of the registry 'registry'*/
    void     SetRegistry ( const wxChar registry, const wxChar ch, const bool append = false );
    /** @brief Set the value of the current registry to registry */
    void     SetRegistry ( const wxChar registry );

    std::list<std::pair<wxChar, wxString> > GetListAllRegistries( );      /*!< Get the list of all registries content*/
    std::list<std::pair<wxChar, wxString> > GetListRegistries( std::list<wxChar> list_regs );  /*!< Get the selected 
                                                                                                 registries content*/
    
private:
    
    template< std::size_t size>
    using Registries_list = std::array<wxString, size>;
    /** @brief list alpha registries
     *
     * to access the right position in the array 
     */

    enum VIM_READ_REGISTRIES {
        /*Read-only*/
        R_period = 0, R_perc, R_colomn, R_diesis,
        R_search, R_Black_Hole, R_small_del, R_expr,
        n_tot
    };

    wxString m_anonimous_registry;

    Registries_list< VIM_REGISTRIES::N_ALPHA_REGISTRIES> m_alpha_registries;
    Registries_list< VIM_READ_REGISTRIES::n_tot>         m_read_registries;
    Registries_list< VIM_REGISTRIES::N_NUM_REGISTRIES  > m_numeric_registries;

    std::size_t m_curr_numeric_registry;          /*position in m_numeric_registries of the most recent one*/
    bool        m_append_alpha;
    wxChar      m_curr_registry;

    void         InitRegistries();
    void        GetRegistryTypeIndex( const wxChar& ch, VIM_REGISTRY_TYPE& type, std::size_t& index );
    wxString DoGetRegistry( const VIM_REGISTRY_TYPE& type, const std::size_t& index );
    
};

#endif // _CL_VIM_REGISRIES_H__
