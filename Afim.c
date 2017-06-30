#include <stdio.h>
#include <string.h>
#include <locale.h>

void cod (char pPalavra[30], int pChaveA, int pChaveB);
void decod (char pPalavra[30], int pChaveA, int pChaveB);

int main (){
	setlocale(LC_ALL,"portuguese");
	char palavra[30], carac;
	int chaveA, chaveB;
	printf("Digite \"C\" para codificar e \"D\" para decodificar: ");
	scanf("%c", &carac);
	while(carac == 'C' || carac =='c' || carac == 'D' || carac =='d'){
		if (carac == 'C' || carac == 'c'){
			printf("Digite a palavra a ser codificada: ");
			fflush(stdin);
			gets(palavra);
			printf("Digite a chave A: ");
			fflush(stdin);
			scanf("%d", &chaveA);
			printf("Digite a chave B: ");
			fflush(stdin);
			scanf("%d", &chaveB);
			cod (palavra, chaveA, chaveB);	
			printf("\n\n");	
			printf("Digite \"C\" para codificar e \"D\" para decodificar: ");
			fflush(stdin);
			scanf("%c", &carac);
		}
		else{
			if (carac == 'D' || carac == 'd'){
			printf("Digite a palavra a ser decodificada: ");
			fflush(stdin);
			gets(palavra);
			printf("Digite a chave A: ");
			fflush(stdin);
			scanf("%d", &chaveA);
			printf("Digite a chave B: ");
			fflush(stdin);
			scanf("%d", &chaveB);
			decod (palavra, chaveA, chaveB);
			printf("\n\n");		
			printf("Digite \"C\" para codificar e \"D\" para decodificar: ");
			fflush(stdin);
			scanf("%c", &carac);	
			}
		}
	}
	return 0;
}

void cod (char pPalavra[30], int pChaveA, int pChaveB){
	int j, i, cont = 0;
	char alfa[27];
	int c[30];
	
	if (cont == 0){
	printf("A palavra codificada é: ");
	}
	for (i = 0; i < 26; i++){		// Laço para o alfabeto
		alfa[i] = i + 97;
	}
	for (i = 0; i < 30; i++){
		c[i] = ' ';
	}
	for (j = 0; j < 30; j++){				// Laço para a codificação
		for (i = 0; i < 26; i++){
			if (pPalavra[j] == alfa[i]){
				c[j] = (pChaveA*i+pChaveB) % 26;
				cont = 1;
			}
		}
	}	
	for (j = 0; j < 30; j++){		// Laço para printar na tela o resultado
		for (i = 0; i < 26; i++){
			if (c[j] == i){
				printf("%c", alfa[i]);
			}	
		}
	}
}

void decod (char pPalavra[30], int pChaveA, int pChaveB){
	int j, i, cont = 0, cont2 = 0, k;
	char alfa[27];
	int c[30];
	float inv;
	
	if (cont == 0){
	printf("A palavra decodificada é: ");
	}
	for (i = 0; i < 26; i++){		// Laço para o alfabeto
		alfa[i] = i + 97;
	}
	for (i = 0; i < 30; i++){
		c[i] = ' ';
	}
	for (j = 0; j < 30; j++){		// Laço para a codificação
		for (i = 0; i < 26; i++){
			if (pPalavra[j] == alfa[i]){
				for (k = 0; k < 30; k++){
					if (cont2 == 0){
						inv = (float)((k*26) + 1) / pChaveA;		// Cálculo do inverso
					}
					if (inv == (int)inv){		// Condição para para pegar o primeiro número inteiro
						c[j] = (int)inv*(i - pChaveB) % 26;
						cont = 1;
						cont2 = 1;
						if (c[j] < 0){
							c[j] = c[j] + 26;
						}					
					}
				}
			}
		}
	}	
	for (j = 0; j < 30; j++){		// Laço para printar na tela o resultado
		for (i = 0; i < 26; i++){
			if (c[j] == i){
				printf("%c", alfa[i]);
			}	
		}
	}

}

