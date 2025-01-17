/*
   jep - Java Embedded Python

   Copyright (c) 2015-2022 JEP AUTHORS.

   This file is licensed under the the zlib/libpng License.

   This software is provided 'as-is', without any express or implied
   warranty. In no event will the authors be held liable for any
   damages arising from the use of this software.

   Permission is granted to anyone to use this software for any
   purpose, including commercial applications, and to alter it and
   redistribute it freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you
   must not claim that you wrote the original software. If you use
   this software in a product, an acknowledgment in the product
   documentation would be appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and
   must not be misrepresented as being the original software.

   3. This notice may not be removed or altered from any source
   distribution.
*/

/*
 * Contains includes and macros to enable compilation across multiple
 * platforms with different compilers while supporting both Python 2 and 3.
 * This file aims to be for Jep what pyport.h is for CPython.
 */

// Python.h needs to be included first, see http://bugs.python.org/issue1045893
#include <Python.h>
#include <assert.h>

static_assert(PY_MAJOR_VERSION >= 3,"There is no Python 2 support!");
#ifdef WIN32
    #include "winconfig.h"
#endif

#if HAVE_CONFIG_H
    #include <config.h>
#endif

#if HAVE_UNISTD_H
    #include <sys/types.h>
    #include <unistd.h>
#endif


#include <jni.h>

#ifndef _Included_jep_platform
    #define _Included_jep_platform

    /* Windows compatibility */
    #ifdef WIN32
        #define FILE_SEP               '\\'
    #else
        #define FILE_SEP               '/'
    #endif // Windows compatibility

    /*
    * A default number of local references to reserve when using the
    * PushLocalFrame JNI method. Most native jep methods need a few local java
    * references that are deleted before the method returns. Rather than trying
    * to get an exact number of local references for every frame it is simpler
    * to overallocate. The JNI specification mandates that there are at least
    * 16 local references avaialble when enetering native code from java so
    * using the same value as a default for creating new local frames means
    * that native methods will have the same number of local references
    * available regardless of whether the frame was created by JNI or by a call
    * from PushLocalFrame.
    */
    #define JLOCAL_REFS 16

#endif // ifndef _Included_jep_platform
