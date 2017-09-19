#ifndef _CL_VIM_ENUMS_
#define _CL_VIM_ENUMS_


enum class VimModi {
    kNormalModus,
    kInsertModus,
};


namespace VimFlags {
    const int no_flag        = 1 << 0;
    const int replacing_mode = 1 << 1;
    const int command_mode   = 1 << 2;
    const int visual_mode    = 1 << 3;
};

enum class VimManagerAction {
    kNone        = -1,
    kClose,
    kSave,
    kSaveAndClose,
    kForceAction
};

enum class VimManagerError {
    kNone    = 0,
    
};


    
#endif // _CL_VIM_EN
