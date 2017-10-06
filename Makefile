OPTIONS=-D_DEBUG=1 -DRE_USE_MALLOC=1 -I../octothorpe
OBJECTS=x86_register.o x86_disas.o

all: x86_disasm.a

x86_disasm.a: $(OBJECTS)
	ar r x86_disasm.a x86_register.o x86_disas.o

x86_register.o: x86_register.c x86_register.h
	gcc $(OPTIONS) -c x86_register.c

x86_disas.o: x86_disas.c x86_disas.h x86_disas_internals.h x86_ins_codes.h x86_tbl_entries.h
	gcc $(OPTIONS) -c x86_disas.c

x86_disasm_tests: x86_disasm_tests.c x86_disasm_tests.h
	gcc $(OPTIONS) x86_disasm_tests.c -o x86_disasm_tests x86_disasm.a ../octothorpe/octothorpe.a

tests: x86_disasm_tests

clean:
	rm -f *.o
	rm -f x86_disasm.a
	rm -f tests

