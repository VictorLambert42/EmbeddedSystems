#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char *tab;


int creerTab(int n)
{
    tab=(unsigned char *)malloc(n*sizeof(unsigned char));
    if (!tab)
    {
    	printf("Erreur memoire.\n");
    	return 0;
    }
    memset(tab,1,n);
    return 1;
}

void libererTab()
{
	free(tab);
}

void elimine(int i,int N)
{
	int j;
	for (j=i+1;j<N;j+=i)
	{
		//on elimine ses multiples
			tab[j]=0;
	}
}

void afficher(int N)
{
	int i;
    printf("Terminé !\nPremiers : ");
    for (i=2;i<N;i++)
    	if (tab[i])
    		printf("%d ",i);
    printf("\n");
}

int main(int argc, char *argv[])
{
    int N;
    int i;
    
    if (argc < 2)
    {
    	printf("Utilisation : %s N\n",argv[0]);
    	return 1;
    }
    N=atoi(argv[1]);
    
    printf("Premiers de 2 a %d.\n",N);
	if (!creerTab(N))
		return 1;		
    
    for (i=2;i<N;i++)
    {
    	if (tab[i])
    	{
    		//si pas elimine, il est premier
    		elimine(i,N);
    	}
    }
    
	afficher(N);
    libererTab();
    return 0;
}

