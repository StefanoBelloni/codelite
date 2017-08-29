#ifndef _CL_VIM_ENUMS_
#define _CL_VIM_ENUMS_


enum VimModi {
    kNormalModus,
    kInsertModus,
};


namespace VimFlags {
    const int no_flag        = 1 << 0;
    const int replacing_mode = 1 << 1;
    const int command_mode   = 1 << 2;
    const int visual_mode    = 1 << 3;
}

#endif // _CL_VIM_ENUMS_
e
