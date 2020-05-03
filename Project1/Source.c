#include "character.h"
#include "class.h"

int main() {

	Charachter* karcsi = Create();
	PrintStats(karcsi);
	ClassStructure* class = CreatePlayer();
	PrintStat(class);

	return 0;
}