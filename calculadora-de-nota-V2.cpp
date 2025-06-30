#include <stdio.h>

int main(){

int A1,A2,A3,resultado;
char resposta;

do { printf("Digite o valor da primera nota: \n");
scanf("%d", &A1);
}	while (A1 >= 6);

do { printf("Digite o valor da segunda nota: \n");
scanf("%d", &A2);
}	while (A2 >= 6);

resultado = A1+A2;

if(resultado <6){
	printf("Voce fez atividade extra? digite s ou n \n");
	scanf(" %c", &resposta);
	
	switch (resposta) {
		case 's':
			printf("Digite o valor da nota extra: \n");
			scanf("%d", &A3);
			
	if (A1 < A2 && A3 > A1) {
    A1 = A3;
    } else if (A2 <= A1 && A3 > A2) {
    A2 = A3;
    }
                
    resultado = A1+A2;
    		printf("resultado: %d \n", resultado);
    		break;
            
    	case 'n':
    		printf("resultado: %d \n", resultado);
    		break;
        	
        default:
        printf("invalido.");
        return 1;
        }
    } else {
        printf("resultado: %d \n", resultado);
    }

    if (resultado >= 6) {
        printf("Parabens!, voce foi aprovado! \n");
    } else {
        printf("Infelizmente voce nao passou dessa vez! \n");
    }

    return 0;

}
