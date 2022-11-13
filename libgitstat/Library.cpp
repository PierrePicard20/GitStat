#include "Library.h"

namespace GitStat
{
    Library g_lib;

    Library::Library()
    {
        git_libgit2_init();
    }

    Library::~Library()
    {
        git_libgit2_shutdown();
    }
}