ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}
lib_LTLIBRARIES = libx86_disasm.la

libx86_disasm_la_SOURCES = x86_disas.c X86_register.c

libx86_disasm_la_LDFLAGS = -version-info $(LIBX86_DISASM_CURRENT):$(LIBX86_DISASM_REVISION):$(LIBX86_DISASM_AGE)

AM_CPPFLAGS = -I$(top_srcdir)/include

EXTRA_DIST = x86_tbl_entries.h
