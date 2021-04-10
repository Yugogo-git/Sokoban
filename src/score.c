#include "main.h"

// Lecture du meilleur score depuis le fichier score_n 
// Où n est le numéro d'un niveau
int lecture_du_score (int quel_niveau){
	FILE* fichier;
	char chemin_du_niveau[100];

 	sprintf(chemin_du_niveau,"./niveau/leaderboard_%d", quel_niveau);
	
	if ((fichier = fopen(chemin_du_niveau, "r"))) {
		// Le fichier a bien été ouvert
		int score;

        fscanf(fichier, "%d", &score);

		fclose(fichier);

		return score;
	} else {
		// Erreur de lecture (le fichier n'existe pas ?)
        
		return -1; // Retour d'une valeur d'erreur
	}
}

// Insertion du meilleur score dans le fichier score_nb où nb est le numéro du niveau. 
// (si le score obtenu en fin de partie est supérieur au meilleur score)
void ecriture_du_score (int quel_niveau, int score){
	FILE* fichier;
	char* player_name = nom_du_joueur();
	char* leaderboard;
	
	sprintf(leaderboard, "./leaderboards/leaderboard_%d", quel_niveau);

	fichier = fopen(leaderboard, "r+");
	if (fichier == NULL) {
		char* leaderb;
		sprintf(leaderb, "touch ./leaderboards/leaderboard_%d", quel_niveau);
		system(leaderb);
		fichier = fopen(leaderboard, "r+");
	}
	fprintf(fichier, "%s %d","hugo" , score);
	
	fclose(fichier);
}

// Demander le nom du joueur puis l'enregistre dans le tabeau des highscores
char* nom_du_joueur (void) {
    return menu_saisie_texte("Entrez votre nom", 8);
}
