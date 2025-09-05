/*
execve : int execve(const char *pathname, char *const argv[], char *const envp[])
fonction qui remplace le programme actuel par celui demander
si reussi , le programme est ecrase, sinon il retourne -1 et le code continue
pathname : chemin d un binaire executable ou script qui commence par #!interpréteur [argument-optionnel],
chemin complet vers la commande exemple : /bin/ls
argv: les commandes qu on veut executer : exemple char **av = {"ls", "-l", NULL}
! av[0] toujours le nom du prog (ls, echo, cat ..), av[1] les arg (-l -la ...), et toujours finir par NULL
envp : les variables d environnement/environnement pointeur / tableau de chaine de caractere que le programme recoit au demerage, 
toutes les chaines sont : "VARIABLE=valeur", et doit terminer par NULL
exemple : "PATH=chemin vers les commandes"




*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	int	i;

	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], "PATH", 4) == 0)
			printf("%s\n", envp[i]);
		i++;
	}
	//printf("%s\n", envp[1]);
}*/

int	main(int ac, char **av, char **envp)
{
	char *avs[] = {};
}