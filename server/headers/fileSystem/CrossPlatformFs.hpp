#ifndef    __CROSSPLATFORMFS__HPP__
#define    __CROSSPLATFORMFS__HPP__

#ifdef __GNUC__

# include "UnixFs.hpp"

typedef UnixFs fs;

#elif defined _WIN32


#endif
#endif      /* __CROSSPLATFORMSOCKETS__HPP__ */