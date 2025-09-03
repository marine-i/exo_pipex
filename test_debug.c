#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd[2];
    int term = dup(STDOUT_FILENO);   // copie de la sortie terminal
    char buf[64];

    pipe(fd);
    dup2(fd[1], STDOUT_FILENO);      // 1 -> pipe

    write(STDOUT_FILENO, "dans le pipe\n", 13); // n’apparaît pas… encore
    write(term, "sur le terminal\n", 16);      // s’affiche tout de suite

    //close(fd[1]);                    // on ferme l'écriture -> prêt à lire
    read(fd[0], buf, 13);
    write(term, "lu: ", 4);
    write(term, buf, 13);            // on voit sortir ce qui était “piégé” dans le pipe
    write(term, "\n", 1);
    close(fd[0]);
    close(term);
}
