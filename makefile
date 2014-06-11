javaa: output.jasm
	./javaa output.jasm

output.jasm: parser
	./parser testfile < testfile

parser: lex.yy.c y.tab.c
	gcc -o parser y.tab.c symTable.c 

y.tab.c: y.y
	bison -dy y.y

lex.yy.c: lex.l
	flex lex.l

clean:
	rm -f *.o lex.yy.c y.tab.c y.tab.h y.output *.jasm
