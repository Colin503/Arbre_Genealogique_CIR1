int main() {
    Population pop;
    pop = read_csv("../10000.csv");
    linkPopulation(pop);
    char path[30];
    printf("%s %d\n",path,fichePath(path, pop.tab_personne[6666]));
    exportPersonHTML(pop,pop.tab_personne[6666],path);
    return 0;
}
