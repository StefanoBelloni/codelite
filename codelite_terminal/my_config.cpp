#include "my_config.h"

MyConfig::MyConfig()
    : wxFileConfig("codelite-terminal", "", "", "", wxCONFIG_USE_SUBDIR|wxCONFIG_USE_LOCAL_FILE)
{
}

MyConfig::~MyConfig()
{
    Save();
}

wxPoint MyConfig::GetTerminalPosition() const
{
    wxPoint pt(100, 100);
    Read("frame_position_x", &pt.x);
    Read("frame_position_y", &pt.y);
    return pt;
}

wxSize MyConfig::GetTerminalSize() const
{
    wxSize size(600,400);
    Read("frame_size_width",  &size.x);
    Read("frame_size_height", &size.y);
    return size;
}

void MyConfig::SetTerminalPosition(const wxPoint& pt)
{
    Write("frame_position_x", pt.x);
    Write("frame_position_y", pt.y);
}

void MyConfig::SetTerminalSize(const wxSize& size)
{
    Write("frame_size_width",  size.x);
    Write("frame_size_height", size.y);
}

void MyConfig::Save()
{
    Flush();
}

wxColour MyConfig::GetBgColour() const
{
    wxString col;
    if ( Read("bg_colour", &col) && !col.IsEmpty() ) {
        wxColour colour(col);
        return colour;
    }
    return *wxBLACK;
}

wxColour MyConfig::GetFgColour() const
{
    wxString col;
    if ( Read("fg_colour", &col) && !col.IsEmpty() ) {
        wxColour colour(col);
        return colour;
    }
    return *wxWHITE;
}

void MyConfig::SetBgColour(const wxColour& col)
{
    Write("bg_colour", col.GetAsString());
}

void MyConfig::SetFgColour(const wxColour& col)
{
    Write("fg_colour", col.GetAsString());
}