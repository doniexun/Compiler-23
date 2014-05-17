#include "operator.h"

static char *OPERATOR[] = {
	"+", "-", "*", "/",
	"=",
	".NOT.", ".AND.", ".OR.", "GT", "GE", "LT", "LE", ".EQV.", ".NEQV."
};

char *operatorStr(enum operator op) { return OPERATOR[op]; }
