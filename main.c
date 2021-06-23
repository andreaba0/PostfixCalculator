#include "header.h"

int main(int argc, char*argv[]) {
	if(argc!=2) {
		printf("Richiesta un'espressione\n");
		return 1;
	}

	/*if(strlen(argv[1])<3) {
		printf("Espressione non valida: %s\n", argv[1]);
		return 1;
	}*/
	
	DirtNode*head=NULL;
	Node*headOp=NULL;
	Node*headOpCode=NULL;
	int res = evaluate(&head, argv[1]);
	if(res!=0) {
		printf("Errore durante il calcolo (%d)\n", res);
		return 1;
	}
	res = controlUnit(&head, &headOp, &headOpCode);
	if(res!=1) {
		printf("Errore durante il calcolo (%d)\n", res);
		return 1;
	}
	printf("Risultato: %.2f\n", atof(headOp->data));
	return 0;
}
