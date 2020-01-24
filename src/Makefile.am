SUBDIRS = ../lib/tr_util_suppress_echo_back

AM_CPPFLAGS = -I$(srcdir)/../lib/tr_util_suppress_echo_back/src

bin_PROGRAMS = sample

sample_SOURCES = sample.cc
sample_LDFLAGS = -L../lib/tr_util_suppress_echo_back/src
sample_LDADD = -ltr_util_suppress_echo_back
