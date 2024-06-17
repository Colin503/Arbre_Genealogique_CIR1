int main() {
    Population pop;
    pop = read_csv("../resources/40.csv");
    linkPopulation(pop);
    Person** tab = ancetre(pop, pop.tab_personne[22]);
    for(int i=0;i<5;i++)
        printf("%d\n",tab[i]->id);
    return 0;
}
