# Copyright (C) 2016 Francis Micheli <fmicheli@teaser.fr>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#
#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([MartiniqueHM], [0.0.1], [heightmap@teaser.fr])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_SRCDIR([src/lib_hmap/hmap_io.cpp])
AC_CONFIG_MACRO_DIR([m4])
# information on the package
AM_INIT_AUTOMAKE
AM_CONFIG_HEADER([config.h])

# Library versioning (current:revision:age)
# See the libtool manual for an explanation of the numbers
MARTINIQUEHM_VERSION="1:0:0"
#
# LIBRARY_VERSION =	 12:0:0
#					   | | |
#				+------+ | +---+
#				|		|	 |
#			 current:revision:age
#				|		|	 |
#				|		|	 +- increment if interfaces have been added
#				|		|		set to zero if interfaces have been removed
#				|		|		or changed
#				|		+- increment if source code has changed
#				|		   set to zero if current is incremented
#               +- increment if interfaces have been added, removed or changed
#
AC_SUBST(MARTINIQUEHM_VERSION)
AC_SUBST(CONFIGDATE, `date +%Y-%m-%d`)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL

# Checks for libraries.
AC_CHECK_LIB([m], [sin])
AC_CHECK_LIB([gslcblas],[cblas_dgemm])
AC_CHECK_LIB([gsl],[gsl_blas_dgemm])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h string.h unistd.h values.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Flags : CPPFLAGS denotes pre-processor flags, such as -I options.
# CFLAGS denotes flags for the C compiler.
# CXXFLAGS denotes flags for the C++ compiler.
CFLAGS+=" -g -Wall"
CXXFLAGS+=" -std=c++11 -g -Wall -Wold-style-cast"

# Checks for library functions.

AC_CONFIG_FILES([config/makefile
                 data/makefile
                 doc/makefile
                 lib/makefile
                 m4/makefile
                 makefile
                 src/makefile
				 src/version.h
				 src/martiniquehm/makefile
				 src/lib_geom/makefile
				 src/lib_geom/Test/makefile
				 src/lib_stl/makefile
				 src/lib_stl/Test/makefile
				 src/lib_srtmfiles/makefile
				 src/lib_srtmfiles/Test/makefile
#				 src/lib_hmap/makefile
#				 src/lib_hmap/Test/makefile
				 src/SRTMasc2bin/makefile
				 ])
AC_OUTPUT

#                  src/hm2stl/makefile
