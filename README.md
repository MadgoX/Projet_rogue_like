# Projet_rogue_like

Programmeurs :
  BOUYEURE Lucien,
  BUON Romane,
  PAULMERY Yann
 
Ce jeu a été programmé dans le cadre d'un projet étudiant en L2 Informatique.
L'objectif est de programmer un jeu Roguelike.

Pour compiler le jeu :
Ouvrir un terminal dans le répertoire du jeu et compiler à l'aide de la commande make

Pour lancer le jeu :
Dans le terminal, après avoir compilé, lancer le jeu à l'aide de la commande ./rogue_like

typedef struct piece_s{
	int x_haut;
	int y_gauche;
	int x_porte1;
	int y_porte1;
	char position_p1;			//vaut h (si la porte est sur le coté haut ou bas de la piece) ou v (si la porte est sur le coté droit ou gauche de la piece)
	int x_porte2;
	int y_porte2;
	char position_p2;			//vaut h (si la porte est sur le coté haut ou bas de la piece) ou v (si la porte est sur le coté droit ou gauche de la piece)
} piece_t;
