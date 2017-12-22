#pragma once

#include <string>
#include <utility>

using namespace std;

//!
/*!
	Superclasse regroupant tous les élements pouvant se trouver sur la carte.
	Tout ces objets ont :
	- un nom, 
	- des coordonnées (utilisées pour éviter de reparcourir toute la carte pour savoir où se trouvent ces objets),
	- un booléen indiquant si cet objet est ramassable par le joueur.
Les objets Trésor et Pelle seront des instances de cette classe.
*/

class objetCarte 
{
	protected:
		//! Nom de l'objet.
		string nom;
		//! Coordonnées de l'objet.
		pair<int, int> coordonnees;
		//! Booléen indiquant si l'objet est ramassable par le joueur ou pas.
		bool ramassable;

	public:
		//! Constructeur sans arguments.
		/*!
			Ce constructeur n'initialise rien.
		*/
		objetCarte();

		//! Constructeur permettant de créer un objet nommé et d'indiquer s'il est ramassable ou pas.
		/*!
			L'objet sera initialisé avec les valeurs suivantes:
			- nom = nom_n,
			- ramassable = ramassable_n,
			- coordonnées : (0,0).
		*/
		objetCarte(string nom_n, bool ramassable_n);
		
		//! Fonction retournant les coordonnées de l'objet.
		pair<int,int> getCoordonnees();

		//! Fonction permettant d'initialiser les coordonnées de l'objet.
		void setCoordonnees(pair<int,int>);
		void setCoordonnees(int,int);
		
		//! Fonction retournant le type de l'objet.
		string getType();
		
		//! Fonction retournant le nom de l'objet.
		/*!
			Utilisée pour obtenir le nom de l'objet, notamment lors du ramassage de l'un d'eux.
			\return Une string contenant le nom.
		*/
		string getNom();
		
		//! Fonction retournant si l'objet est ramassable ou pas.
		/*!
		Utilisée pour savoir si l'objet est ramassable ou non, notamment lors du ramassage de l'un d'eux.
		\return Un booléen. True si on peut le ramasser, false sinon.
		*/
		bool getRamassable();
		
		//! Fonction convertissant les données d'un objet en string.
		/*!
			Utilisée pour la sauvegarde dans un fichier texte. 
			A ce stade, celle-ci renvoie seulement le nom de l'objet. Elle sera ensuite overriden dans les classes filles.
			\return Une string sous ce format : nom.
		*/
		virtual string toString();
		
		//! Fonction retournant l'attaque de l'objet.
		/*!
		Utilisée pour obtenir l'attaque de l'objet, notamment pour mise à jour des statistiques du joueur (ramassage).
		\return Un int contenant l'attaque.
		*/
		virtual int getAttack();

		//! Fonction retournant la défense de l'objet.
		/*!
		Utilisée pour obtenir la défense de l'objet, notamment pour mise à jour des statistiques du joueur (ramassage).
		\return Un int contenant la défense.
		*/
		virtual int getDefense();

		//! Fonction retournant si l'objet est vivant ou non.
		/*!
		Utilisée pour savoir si l'objet est vivant ou non, notamment pour la fin de partie.
		\return Un* booléen. True si l'objet est vivant, false sinon.
		*/
		virtual bool getVivant();

		//! Destructeur d'objetCarte.
		~objetCarte();
};