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

    if (resultado >= 6) {
        printf("Parabens!, voce tirou %d e foi aprovado! \n", resultado);
    } else {
        printf("Infelizmente voce tirou %d e nao passou dessa vez! \n", resultado);
    }

    return 0;

}
