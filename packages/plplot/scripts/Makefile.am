# scripts/Makefile.am for PLplot
###
### Process this file with automake to produce Makefile.in
###
# Copyright (C) 2002  Alan W. Irwin
# Copyright (C) 2004  Rafael Laboissiere
#
# This file is part of PLplot.
#
# PLplot is free software; you can redistribute it and/or modify
# it under the terms of the GNU Library General Public License as published
# by the Free Software Foundation; version 2 of the License.
#
# PLplot is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Library General Public License for more details.
#
# You should have received a copy of the GNU Library General Public License
# along with the file PLplot; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA

examplesdir = $(DATA_DIR)/examples

dist_bin_SCRIPTS = \
	plm2gif \
	plpr \
	pstex2eps
nodist_bin_SCRIPTS = plplot-config

MAINTAINERCLEANFILES = Makefile.in

### FIXME: Brute force inclusion in dist tarball.  The files below may
### be treated in a different way for installation [RL, 2003-03-06]
EXTRA_DIST = \
	check-tarball-cvs.sh \
	check-year-author.pl \
	fixfort \
	get-dependency-libs.sh \
	htdocs-gen_plot-examples.sh \
	htdocs-replace.sh \
	make-cvs-tarball.sh \
	make_tarball.sh \
	mktclIndex \
	upload-cvs-tarball.sh
