#include "header.h"

int main(int argc, char*argv[]) {
	if(argc!=2) {
		printf("Richiesta un'espressione\n");
		return 1;
	}

	if(strlen(argv[1])<3) {
		printf("Espressione non valida: %s\n", argv[1]);
		return 1;
	}
	
	dirtData*head=NULL;
	evalRes*res = evaluateAndExecute(&head, argv[1]);
	return 0;
}
