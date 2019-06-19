#include "stdio.h"
#include "stdlib.h"
#include "random.h"
#include "genlib.h"
#include "time.h"

int RandomInteger(int low, int high)
{
    int k;
    double d;

    d = (double) rand() / ((double) RAND_MAX + 1);
    k = (int) (d * (high - low + 1));
    return (low + k);
}

int main()
{   
	//FAZER UM VETOR QUE ARMAZENE: VEZ JOGADA; PORTA ESCOLHIDA; PORTA GANHADORA; TROCA OU NÃO TROCA
	//
	// 
	//
	long long int n=100000, ESCOLHAS[n][3];
	long double TROCA=0,NAO_TROCA=0;

	for (int vezjogada= 0; vezjogada < n; ++vezjogada)
	{
	//ESCOLHAS SIMPLES 
		
		ESCOLHAS[vezjogada][0]=RandomInteger(1,3);//PORTA ESCOLHIDA
		ESCOLHAS[vezjogada][1]=RandomInteger(1,3);//PORTA GANHADORA
		ESCOLHAS[vezjogada][2]=RandomInteger(1,2);//TROCA(1) OU NÃO TROCA(2)

		if(ESCOLHAS[vezjogada][0]==ESCOLHAS[vezjogada][1] && ESCOLHAS[vezjogada][2]==2)
			{
			NAO_TROCA++; //o unico caso que ganha quando nao troca é quando a porta escolhida e a ganhadora sao iguais
		//	printf("+");
			}


		//é indiferente qual sera aberta, sendo que ela é sempre uma sem o prêmio
		//portanto, basta eu estar em uma porta diferente da vencedora
		//e com intenção de trocar que eu ganho

		if (ESCOLHAS[vezjogada][0]!=ESCOLHAS[vezjogada][1] && ESCOLHAS[vezjogada][2]==1)
			{
				TROCA++;
			}

		//printf("PORTA ESCOLHIDA: %lld \tPORTA GANHADORA: %lld\tT ou NT: %lld\n",ESCOLHAS[vezjogada][0],ESCOLHAS[vezjogada][1],ESCOLHAS[vezjogada][2]);

	}

	printf("\n");
	printf("Numero de vezes ganhado quando TROCA de porta: %Lf \n", TROCA);
	printf("Numero de vezes ganhado quando NAO TROCA de porta: %Lf \n",NAO_TROCA);
	printf("\n");

	double fracao= 0;

	fracao= (double)TROCA/(double)NAO_TROCA;

	printf("\t\tfração entre eles: %lf\n", fracao);
	printf("fração de TROCA/n= %Lf \t NAO_TROCA/n= %Lf \n", TROCA/(double)n, NAO_TROCA/(double)n);
    
	//podemos observar que a fração tende a 2. indicando que o tu tem o dobro de chance se trocar de porta
    return 0;
}
