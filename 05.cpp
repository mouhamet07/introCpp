/*
1.creer une classe
2.afficher les classe
2.ajouter un etudiants
3.afficher un etudiant
4.afficher tous les etudiants d'une classe
5.quitter
*/

#include <iostream>
#include <string>
#include <limits>
#define maxNotes 3
#define maxEtu 30
#define maxEval 5
#define maxClasse 10
struct Module{
    std::string nom;
    int coeff;
};
struct Eval{
    Module mod;
    int nbrNote;
    float notes[maxNotes];
};
struct Etu{
    std::string nom;
    std::string prenom;
    std::string mat;
    int nbrEval;
    struct Eval tabEval[maxEval];
};
struct Classe{
    std::string niveau;
    std::string filiere;
    std::string code;
    int nbrEtu;
    Etu tabEtu[maxEtu];
};
Classe tabClasse[maxClasse];
int nbrClasse = 0;

void menu();
char demande(std::string msg);
std::string saisieString(std::string msg);
float saisieNote();
Module saisieModule();
Eval saisieEval();
Etu saisieEtu();
Classe saisieClasse();
bool ajouterClasse(Classe tab[], int &nbr, Classe c);
bool ajouterEtu(Etu tab[], int &nbr, Etu e);
void afficheModule(Module m);
float afficheNote(float tab[], int nbr);
float afficheEval(Eval e);
void afficheTabEval(Eval tab[], int nbr);
void afficheEtu(Etu e);
void afficheTabEtu(Etu tab[], int nbr);
void afficheClasse(Classe c);
void afficheTabClasse(Classe tab[], int nbr);
void gestionProgramme();


int main(){
    gestionProgramme();
    return 0;
}

void menu(){
    std::cout << "===============  Menu  ===============" << std::endl;
    std::cout << "1. Creer une classe" << std::endl;
    std::cout << "2. Afficher les classes" << std::endl;
    std::cout << "3. Ajouter un etudiant" << std::endl;
    std::cout << "4. Afficher tous les etudiants" << std::endl;
    std::cout << "5. Afficher les etudiants d'une classe" << std::endl;
    std::cout << "6. Afficher le bulletin d'un etudiant" << std::endl;
    std::cout << "7. Quitter" << std::endl;
    std::cout << "======================================" << std::endl;
};

char demande(std::string msg){
    char rep;
    do{
        std::cout << msg << std::endl;
        std::cin >> rep;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    } while (rep != 'o' && rep != 'n');
    return rep;
};

std::string saisieString(std::string msg){
    std::string str;
    std::cout << msg << std::endl;
    std::getline(std::cin, str);
    return str;
};
float saisieNote(){
    float note;
    do{
        std::cout << "Saisir une note: ";
        std::cin >> note;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    } while (note < 0 || note > 20);
    return note;
};
Module saisieModule(){
    Module m;
    m.nom = saisieString("Saisir le nom du module: ");;
    do{
        std::cout << "Saisir le coefficient du module: ";
        std::cin >> m.coeff;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    } while (m.coeff < 0);
    return m;
};
Eval saisieEval(){
    Eval e;
    char rep;
    e.mod = saisieModule();
    e.nbrNote = 0;
    do
    {
        e.notes[e.nbrNote] = saisieNote();
        e.nbrNote++;
        rep = demande("Voulez-vous saisir une autre note? (o/n)");
    } while (rep == 'o' && e.nbrNote < maxNotes);
    return e;
};
Etu saisieEtu(){
    Etu e;
    e.nom = saisieString("Saisir le nom de l'etudiant: ");
    e.prenom = saisieString("Saisir le prenom de l'etudiant: ");
    e.mat = saisieString("Saisir le matricule de l'etudiant: ");
    e.nbrEval = 0;
    char rep;
    do
    {
        e.tabEval[e.nbrEval] = saisieEval();
        e.nbrEval++;
        rep = demande("Voulez-vous saisir une autre evaluation? (o/n)");
    } while (rep == 'o' && e.nbrEval < maxEval);
    return e;
};
bool ajouterEtu(Etu tab[], int &nbr, Etu e){
    if(nbr < maxEtu){
        tab[nbr] = e;
        nbr++;
        return true;
    }
    return false;
};
Classe saisieClasse(){
    Classe c;
    c.niveau = saisieString("Saisir le niveau de la classe: ");
    c.filiere = saisieString("Saisir la filiere de la classe: ");
    c.code = saisieString("Saisir le code de la classe: ");
    c.nbrEtu = 0;
    char rep;
    do
    {
        c.tabEtu[c.nbrEtu] = saisieEtu();
        c.nbrEtu++;
        rep = demande("Voulez-vous saisir un autre etudiant? (o/n)");
    } while (rep == 'o' && c.nbrEtu < maxEtu);
    return c;
};
bool ajouterClasse(Classe tab[], int &nbr, Classe c){
    if(nbr < maxClasse){
        tab[nbr] = c;
        nbr++;
        return true;
    }
    return false;
};
void afficheModule(Module m){
    std::cout << "Nom: " << m.nom << std::endl;
    std::cout << "Coeff: " << m.coeff << std::endl;
};
float afficheNote(float tab[], int nbr){
    float somme = 0;
    if(nbr > 0){
        for (int i = 0; i < nbr; i++){
            int cpt = i + 1;
            std::cout << "Note " << cpt << ": " << tab[i] << std::endl;
            somme += tab[i];
        }
        return somme / nbr;
    }else{
        std::cout << "Aucune note disponible" << std::endl;
        return 0;
    }
};
float afficheEval(Eval e){
    afficheModule(e.mod);
    float somme = afficheNote(e.notes,e.nbrNote);
    return (somme * e.mod.coeff);
};
void afficheTabEval(Eval tab[], int nbr){
    float moy = 0;
    int sommeCoeff = 0;
    if(nbr > 0){
        for (int i = 0; i < nbr; i++){
            moy += afficheEval(tab[i]);
            sommeCoeff += tab[i].mod.coeff;
        }
        if (sommeCoeff > 0) {
            moy /= sommeCoeff;
        } else {
            moy = 0;
        }
        std::cout << "Moyenne: " << moy << std::endl;
    }else{
        std::cout << "Aucune evaluation disponible" << std::endl;
    }
};
void afficheEtu(Etu e){
    std::cout << "Nom: " << e.nom << std::endl;
    std::cout << "Prenom: " << e.prenom << std::endl;
    std::cout << "Mat: " << e.mat << std::endl;
    //afficheTabEval(e.tabEval, e.nbrEval);
};
void afficheTabEtu(Etu tab[], int nbr){
    if(nbr > 0){
        for (int i = 0; i < nbr; i++){
            afficheEtu(tab[i]);
        }
    }else{
        std::cout << "Aucun etudiant disponible" << std::endl;
    }
};
void afficheClasse(Classe c){
    std::cout << "Niveau: " << c.niveau << std::endl;
    std::cout << "Filiere: " << c.filiere << std::endl;
    std::cout << "Code : "<< c.code << std::endl;
    //afficheTabEtu(c.tabEtu, c.nbrEtu);
};
void afficheTabClasse(Classe tab[], int nbr){
    if(nbr > 0){
        for (int i = 0; i < nbr; i++){
            afficheClasse(tab[i]);
        }
    }else{
        std::cout << "Aucune classe disponible" << std::endl;
    }
}

void gestionProgramme() {
    int choix;
    do {
        menu();
        std::cout << "Saisir votre choix: ";
        std::cin >> choix;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::string code;
        Classe c;
        bool statut;
        switch (choix) {
        case 1:
            c = saisieClasse();
            statut = ajouterClasse(tabClasse, nbrClasse, c);
            if (statut) {
                std::cout << "Classe ajoutee avec succes" << std::endl;
            } else {
                std::cout << "Impossible d'ajouter la classe" << std::endl;
            }
            break;
        case 2:
            afficheTabClasse(tabClasse, nbrClasse);
            break;
        case 3:
            afficheTabClasse(tabClasse, nbrClasse);
            std::cout << "Saisir le code de la classe: " << std::endl;
            std::cin >> code;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for (int i = 0; i < nbrClasse; i++) {
                if (tabClasse[i].code == code) {
                    Etu e = saisieEtu();
                    statut = ajouterEtu(tabClasse[i].tabEtu, tabClasse[i].nbrEtu, e);
                    if (statut) {
                        std::cout << "Etudiant ajoutee avec succes" << std::endl;
                    } else {
                        std::cout << "Impossible d'ajouter l'etudiant" << std::endl;
                    }
                    break;
                }
            }
            break;
        case 4:
            for (int i = 0; i < nbrClasse; i++) {
                afficheTabEtu(tabClasse[i].tabEtu, tabClasse[i].nbrEtu);
            }
            break;
        case 5:
            afficheTabClasse(tabClasse, nbrClasse);
            std::cout << "Saisir le code de la classe: " << std::endl;
            std::cin >> code;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            for (int i = 0; i < nbrClasse; i++) {
                if (tabClasse[i].code == code) {
                    afficheTabEtu(tabClasse[i].tabEtu, tabClasse[i].nbrEtu);
                    break;
                }
            }
            break;
        case 6:
            afficheTabClasse(tabClasse, nbrClasse);
            std::cout << "Saisir le code de la classe: " << std::endl;
            std::cin >> code;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            for (int i = 0; i < nbrClasse; i++) {
                if (tabClasse[i].code == code) {
                    afficheTabEtu(tabClasse[i].tabEtu, tabClasse[i].nbrEtu);
                    std::cout << "Saisir le matricule de l'etudiant: " << std::endl;
                    std::string mat;
                    std::cin >> mat;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    for (int j = 0; j < tabClasse[i].nbrEtu; j++) {
                        if (tabClasse[i].tabEtu[j].mat == mat) {
                            afficheTabEval(tabClasse[i].tabEtu[j].tabEval, tabClasse[i].tabEtu[j].nbrEval);
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        case 7:
            std::cout << "Au revoir" << std::endl;
            break;
        default:
            std::cout << "Choix invalide" << std::endl;
            break;
        }
    } while (choix != 7);
}