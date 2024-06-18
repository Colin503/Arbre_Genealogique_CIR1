int main() {
    Population pop;
    pop = read_csv("../10000.csv");
    linkPopulation(pop);
    char path[30];
    printf("%s %d\n",path,fichePath(path, pop.tab_personne[6666]));
    exportPersonHTML(pop,pop.tab_personne[6666],path);
    return 0;
}


void affichage_tableau(Person** tab) {
    int taille=0;
    while (tab[taille]!=NULL) {
        taille++;
    }
    for (int i=0;i<taille;i++) {
        printf("id : %d\nnom : %s\nprenom : %s\n",tab[i]->id,tab[i]->firstname,tab[i]->lastname);
    }
}
