#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// fork sert a dupliquer le processus actuel parent/enfant s'execute en parallele
// pid_t pid = fork()
// pid > 0 : parent, il contien tle pid de l'enfant
// pid == 0 : enfant
// pid == -1 : erreur, le fork a échoué

/*
Avant fork :
+------------------------+
|  Processus Parent      |
|  PID = 1234            |
+------------------------+

Après fork :
+------------------------+        +------------------------+
|  Processus Parent      |        |  Processus Fils        |
|  PID = 1234            |        |  PID = 1235            |
|  fork() retourne 1235  |        |  fork() retourne 0     |
+------------------------+        +------------------------+

+----------+           +-----------+
| Parent   |           | Enfant    |
| FD 3     | --------> | FD 3      |
+----------+           +-----------+
    	\____________________/ = ouvert
(pareil ^ici))				X = fermé (ici si l'enfant ferme son acces a fd, le parent lui a tjr acces
           même fichier ouvert


*/

int	main(void)
{
	getpid();
	printf("Coucou je suis le parents courant ! Mon pid est : %d\n", getpid());
	pid_t pid;
	pid = fork();
	if (pid > 0)
	{
		sleep(1);
		printf("Coucou je suis le parents ! Mon pid est : %d\n", getpid());
		return (0);
	}
	else if (pid == 0)
	{
		printf("Coucou je suis son enfant ! Mon pid est : %d, et le pid de mon parent est : %d\n", getpid(), getppid());
		return (0);
	}
}
