#
# $Id$
#****h* main_module/module [1.0] *
# NAME
#       tool -- explanation
# COPYRIGHT
#   Copyright (c) 2000-2002 by Francis Micheli.
#   Gnu Public Licence
#   See the file "license.terms" for information on usage and
#   distribution of this file, and for a DISCLAIMER OF ALL WARRANTIES.
# FUNCTION
#
# AUTHOR
#   Francis Micheli
# CREATION DATE
#   200
# MODIFICATION HISTORY
#
# NOTES
#
#******
# source("")

#****f* module/procname [1.0] *
# NAME
#
# FUNCTION
#
# INPUTS
#
# RESULT
#
# SOURCE
#
#toto <- function ( ) {
#}
#********

#****f* module/procname [1.0] *
# NAME
#
# FUNCTION
#
# INPUTS
#
# RESULT
#
# SOURCE
#
# MAIN ============================
# dd <- read.table("Data/martinique.asc", skip=6)
# mm <- t(as.matrix(dd))[,336:1]
# # idx <- which(mm < 0 )
# # mm[idx] <- NA
# image(mm, col=terrain.colors(24), asp=1)


dd <- read.table( "roi.xyz", col.names=c("x", "y", "z") )
plot(dd$x, dd$y, asp=1, col="goldenrod4", cex=0.1)
print("And now zoom full screen !")

# /MAIN ===========================
#********
