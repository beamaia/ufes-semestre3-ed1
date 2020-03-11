#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_esfera(float r, float* area, float* volume) {
	*area = 4 * M_PI * pow(r, 2);
	*volume = *area * r / 3;
}

void fatorial(int n, int* f) {
	if(n > 1) {
		*f *= n;
		fatorial(n - 1, f);
	}
}

int negativos(int n, float* vet) {
	int neg = 0;
	for(int i = 0; i < n; i++) {
		if(vet[i] < 0) {
			neg++;
		}
	}

	printf("De %d elementos, %d são negativos\n", n, neg);
} 

void inverte(int n, int* vet) {
	int temp;

	for(int i = 0; i < n/2; i++) {
		temp = vet[i];
		vet[i] = vet[n - i - 1];
		vet[n - i - 1] = temp; 
	}
}

//Apresenta o numero da main que inverte
void apresenta_num_inverte(int n, int* vet) {
	for(int i = 0; i < n; i++) {
		printf("%d ", vet[i]);
	}
	
}

/*

//Main 1: para calcular area de superficie e volume da esfera
int main() {
	float raio, area, volume;

	printf("Insira um valor para o raio:\n");
	scanf("%f", &raio);
	calc_esfera(raio, &area, &volume);
	printf("Área da superfície: %.2f\nVolume da esfera: %.2f\n", area, volume);
	return 0;
}

*/


/*

// Main 2: para fatorial	
int main(){
		
	int resultado = 1, num_fat;
	
	printf("Insira um número:\n");
	scanf("%d", &num_fat);

	fatorial(num_fat, &resultado); 
	printf("%d! = %d\n", num_fat, resultado);
	return 0;
}

*/


/*

//Main 3: para contar quantidade de numeros negativos
int main() {
	int tam;
	float *vet;

	printf("Quantos elementos tem no seu vetor?\n");
	scanf("%d", &tam);

	vet = (float *) malloc(sizeof(float) * tam);
	
	printf("Insira os valores do vetor. Lembre que são %d elementos\n", tam);

	for(int i = 0; i < tam; i++) {
		scanf("%f", &vet[i]);
	}

	negativos(tam, vet);
	free(vet);
	return 0;	
}

*/

//Main 4: para inverter o vetor
int main() {
	int tam;
	int *vet;

	printf("Quantos elementos tem no seu vetor?\n");
	scanf("%d", &tam);

	vet = (int *) malloc(sizeof(int) * tam);
	
	printf("Insira os valores do vetor. Lembre que são %d elementos\n", tam);

	for(int i = 0; i < tam; i++) {
		scanf("%d", &vet[i]);
	}	
	
	inverte(tam, vet);
	apresenta_num_inverte(tam, vet);
	free(vet);
	return 0;
}

