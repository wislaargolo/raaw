all: compilador

compilador: lex.yy.c y.tab.c ./lib
	gcc lex.yy.c y.tab.c ./lib/record.c ./lib/stack.c ./lib/hash_table.c ./lib/types.c ./lib/variables.c ./lib/functions.c ./lib/aux_functions.c -o compiler

lex.yy.c: lex.l
	flex lex.l

y.tab.c: parser.y
	bison parser.y -d -v -o y.tab.c

clean:
	rm -rf lex.yy.c y.tab.* compiler output.txt y.output
