TESTS = run-x86_disasm_tests.sh

check_PROGRAMS = x86_disasm_tests

x86_disasm_tests_SOURCE = x86_disasm_tests
x86_disasm_tests_LDADD = $(top_builddir)/lib/libx86_disasm.la

AM_CPPFLAGS = -I$(top_srcdir)/include

EXTRA_DIST = run-x86_disasm_tests.sh test32_1.h test32_2.h x86_disasm_tests.h XOR_tests.h
