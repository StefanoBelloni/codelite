#include "clVimRegistries.h"

/* ===================================================================== 
 *                       PUBLIC METHODS
 * ===================================================================== */

/**
 * Default constructor
 */
VimRegistries::VimRegistries()
    : m_curr_numeric_registry(0),
      m_anonimous_registry(wxEmptyString),
      m_append_alpha( false )
      
{
    InitRegistries();
}

/* ===================================================================== */
/**
 * Get the content of the registry anonimous
 */
wxString VimRegistries::GetRegistry()
{
    return m_anonimous_registry;
}

/* ===================================================================== */
/**
 * 
 */
wxString VimRegistries::GetRegistry( const wxChar registry )
{
    std::size_t index;
    VIM_REGISTRY_TYPE reg_type;
    GetRegistryTypeIndex( registry, reg_type, index );
    return DoGetRegistry( reg_type, index );
}

/* ===================================================================== */
/**
 * 
 */
void SetRegistry( const wxChar registry ) { m_curr_registry = registry }
/* ===================================================================== */
/**
 * 
 */
void SetRegistry( const wxChar registry, const wxString buffer, const bool append )
{
    SetRegistry(registry);
    std::size_t index;
    VIM_REGISTRY_TYPE reg_type;
    GetRegistryTypeIndex( registry, reg_type, index );
    wxString registry_buf = DoGetRegistry( reg_type, index );
    
    if ( m_append_alpha || append )
        registry_buf.Append( buffer );
    else
        registry_buf = buffer;

}

/* ===================================================================== */
/**
 * 
 */
void SetRegistry( const wxChar registry, const wxChar ch, const bool append )
{
    SetRegistry(registry);
    std::size_t index;
    VIM_REGISTRY_TYPE reg_type;
    GetRegistryTypeIndex( registry, reg_type, index );
    wxString registry_buf = DoGetRegistry( reg_type, index );
    
    if ( m_append_alpha || append )
        registry_buf.Append( ch );
    else
        registry_buf = wxString( ch );  /*FIXME: registry_buf = ch works?*/

}




/* ===================================================================== 
 *                       PRIVATE METHODS
 * ===================================================================== */

/* ===================================================================== */
/**
 * This function initialize the registries:
 * This might be used in future to impl. the possibility to remember 
 * the buffers along different run of codelite.
 */
void VimRegistries::InitRegistries()
{
    
    m_alpha_registries.fill   ( wxEmptyString );
    m_read_registries.fill    ( wxEmptyString );
    m_numeric_registries.fill ( wxEmptyString );

}

/* ===================================================================== */

int GetRegistryTypeIndex( const wxChar& ch, VIM_REGISTRY_TYPE& type, std::size_t& index )
{

    index = 0;
    type = VIM_REGISTRY_TYPE::READ_ONLY;
    m_append_alpha = false;
    switch ( ch ) {
        
    case '.': index = VIM_READ_REGISTRIES::R_period;     return;  
    case '%': index = VIM_READ_REGISTRIES::R_perc;       return;
    case ':': index = VIM_READ_REGISTRIES::R_colomn;     return;
    case '#': index = VIM_READ_REGISTRIES::R_diesis;     return;
    case '/': index = VIM_READ_REGISTRIES::R_search;     return;
    case '_': index = VIM_READ_REGISTRIES::R_Black_Hole; return;
    case '-': index = VIM_READ_REGISTRIES::R_small_del;  return;
    case '=': index = VIM_READ_REGISTRIES::R_expr;       return;
    default:  type = VIM_REGISTRY_TYPE::NOT_VALID;       break;
        
    }

    if ( ch >= 'a' && ch <= 'z' ) {
        index = ch - 'a';
        type = VIM_REGISTRY_TYPE::ALPHA;
        return;
    }

    if ( ch >='A' && ch <= 'Z' ) {
        index = ch - 'A';
        type = VIM_REGISTRY_TYPE::ALPHA;
        m_append_alpha = true;
        return;
    }

    if ( ch >= '0' && ch <= '9' ) {
        index = ch - '0';
        type = VIM_REGISTRY_TYPE::NUMERIC;
        return;
    }
    
}

/* ===================================================================== */

wxString& DoGetRegistry( const VIM_REGISTRY_TYPE& type, const std::size_t& index )
{
    switch( type ) {
    case VIM_REGISTRY_TYPE::ALPHA:
        return m_alpha_registries[ index ];
    case VIM_REGISTRY_TYPE::NUMERIC:
        return m_numeric_registries[ index ];
    case return VIM_REGISTRY_TYPE::READ_ONLY:
        return m_read_registries[ index ];
    default:
        /*TODO THROW Exemption*/
        return wxEmptyString;
    }

}
