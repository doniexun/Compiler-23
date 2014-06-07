scanner: lex.yy.c y.tab.c
    gcc y.tab.c symTable.c 

y.tab.c: y.y
    bison -dy y.y
    gcc y.tab.c

lex.yy.c: lex.l
    flex lex.l
    gcc -c lex.yy.c
clean:
    rm -f *.o lex.yy.c
