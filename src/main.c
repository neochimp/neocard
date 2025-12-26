#include <easyc.h>
#include "neocard.h"

int main() {
	size_t mem = EZ_ALLOCATED();
	Neocard();
	EZ_ASSERT(mem == EZ_ALLOCATED(), "Memory cleanup revealed a leak of %d bytes", (int)(EZ_ALLOCATED() - mem));
	EZ_INFO("See ya, space cowboy!");
	return 0;
}
