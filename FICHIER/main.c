#include <stdio.h>
int main()
{
    FILE *e;
    char nom[50], prenom[50];
    float moyenne;
    int i, nb;
    printf("Donner le nombre d etudiants :");
    scanf("%d", &nb);
    e = fopen("etudiants.txt", "w");
    for (i = 1; i <= nb; i++)
    {
        printf("Donner le nom de l’etudiant :");
        scanf("%s", nom);
        printf("Donner le prénom de l’etudiant :");
        scanf("%s", prenom);
        printf("Donner la moyenne de l’etudiant :");
        scanf("%f", &moyenne);

        fprintf(e, "%s  \t  %s  \t   %f \n", nom, prenom, moyenne);
    }
    fclose(e);

    e = fopen("etudiants.txt", "r");
    while (!feof(e))
    {
        fscanf(e, "%s %s %f", nom, prenom, &moyenne);
        if (feof(e))
            break;
        printf("Etudiant : %s %s a pour moyenne : %f\n", nom, prenom, moyenne);
    }
    fclose(e);

    return 0;
}