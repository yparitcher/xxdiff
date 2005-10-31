/******************************************************************************\
 * $Id: util.h 234 2001-09-30 19:44:09Z blais $
 * $Date: 2001-09-30 15:44:09 -0400 (Sun, 30 Sep 2001) $
 *
 * Copyright (C) 1999-2001  Martin Blais <blais@iro.umontreal.ca>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
nn * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *****************************************************************************/

#ifndef INCL_XXDIFF_UTIL
#define INCL_XXDIFF_UTIL

/*==============================================================================
 * EXTERNAL DECLARATIONS
 *============================================================================*/

#ifndef INCL_XXDIFF_DEFS
#include <defs.h>
#endif

#ifndef INCL_QT_QSTRING
#include <qstring.h>
#define INCL_QT_QSTRING
#endif

#ifndef INCL_STD_STDIO
#include <stdio.h>
#define INCL_STD_STDIO
#endif

#ifndef INCL_STD_SIGNAL
#include <signal.h>
#define INCL_STD_SIGNAL
#endif

#ifndef INCL_STD_IOSTREAM
#include <iostream>
#define INCL_STD_IOSTREAM
#endif


XX_NAMESPACE_BEGIN

/*==============================================================================
 * CLASS XxUtil
 *============================================================================*/

// <summary> utilities </summary>

class XxUtil {

public:

   /*----- static member functions -----*/

   // Return true if the file is a directory.
   static bool isDirectory( const QString& filename );

   // Copy a stream to a file.
   static void copyToFile( FILE* fin, FILE* fout );

   // Copy a file.
   // Destination may be a directory name or a filename.
   // Returns 0 if no error (see pclose(3)).
   static int copyFile( const QString& src, const QString& dest );

   // Remove a file.
   // Returns 0 if no error.
   static int removeFile( const QString& src );

   // Conduct some tests to determine if the input file is suitable for
   // processing by our program.  Return true on success.
   static bool testFile(
      const QString& filename,
      const bool     testAscii,
      bool&          isDirectory
   );

   // Quick heuristic to test whether a file's contents are ascii text
   static bool isAsciiText( const QString& filename );

   // Run a program with command line arguments and two pathname arguments via
   // fork/exec and forget about it. Returns true on success.
   static bool spawnCommand( 
      const char** argv,
      void (*sigChldHandler)(int) = 0
   );

   // Run a program with command line arguments and two pathname arguments via
   // fork/exec and return a pipe file descriptor into which standard output and
   // standard error have been redirected.
   static FILE* spawnCommandWithOutput( 
      const char** argv,
      void (*sigChldHandler)(int) = 0
   );

   // This is code for an interruptible system() call as shown as suggested in
   // GNU libc/Linux system(3) man page.
   static int interruptibleSystem( const QString& command );

   // Time snapshot (extremely rudimentary, modulo 100 seconds)
   static long getCurrentTime();

   // Print time value to stream.
   static void printTime( std::ostream& os, long time );

   static QString baseName( const QString& str );

   // Note: you have to free() out_args when you're done.
   static int splitArgs( 
      const QString& command,
      const char**&  out_args
   );

   // Free args allocated with splitArgs.
   static void freeArgs( const char**& out_args );

};


XX_NAMESPACE_END

#endif