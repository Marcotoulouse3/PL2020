/**** Projet long N7 2017 ****/

#include "tache3.h"


//Constructeur
Tache3::Tache3()
{}



//Destructeur
Tache3::~Tache3()
{}

/** Initialisation **/
//Initialisation des différents services, publishers et subscribers
void Tache3::init(ros::NodeHandle noeud, std::string executionPath)
{

	FINI=0;

	FINI_msg.data=FINI;

	//Déclaration service simRosSetIntegerSignal
	client_simRosColor = noeud.serviceClient<vrep_common::simRosSetIntegerSignal>("/vrep/simRosSetIntegerSignal");

	//Déclaration service simRosGetInfo
	client_simGetVrepTime = noeud.serviceClient<vrep_common::simRosGetInfo>("/vrep/simRosGetInfo");


	//Subscribers
	dureeTache =noeud.subscribe("/Cmde_tache3/lancementTache3", 10, &Tache3::get_dureeTacheCallback, this);

	robotPosition = noeud.subscribe("/robot/PositionRobot2", 10, &Tache3::PositionRobotCallback, this);
	
	robotBras = noeud.subscribe("/robot/BrasRobot2",10,&Tache3::BrasRobotCallback,this);

	robotPince = noeud.subscribe("/robot/PinceRobot2",10,&Tache3::PinceRobotCallback,this);

	posteProduit = noeud.subscribe("/P3_Tache/ProduitATraiter",10,&Tache3::TraitementProduitCallback,this);

	posteDeposee = noeud.subscribe("/Cmde_P3/ProduitPose",10,&Tache3::PieceDeposeeCallback,this); ///****** <---- MODIFICATION

	postePris = noeud.subscribe("/Cmde_P3/ProduitPrise",10,&Tache3::PiecePriseCallback,this); ///****** <---- MODIFICATION

	pubFINI= noeud.advertise<std_msgs::Int32>("/commande/Simulation/ProduitTraitement3fini",10);


	//Publishers	
	pub_traitementProduitTache = noeud.advertise<std_msgs::Int32>("/Tache_P3/Tache3Finie",10);

	pub_retourTraitement = noeud.advertise<std_msgs::Int32>("/commande/Simulation/ProduitTraitement3",10);


	//Définition des noms des signaux
	table = "Table#3_color";


	//Initialisation des variables de retour du robot
	position = -1;
	bras = -1;
	pince = -1;
	oldproduit = -1;
	duree=-1;


	// Récupération du chemin vers le Working_Folder
	int count = 0 ;
	int pos = 0 ;
	while (count < 4)
		{
		if(executionPath[pos] == '/') count++;
		pos++;
		}
	std::string Working_Folder = executionPath.substr(0,pos);

	
	//Initialisation des produits à l'aide du fichier de configuration

		//Définition du chemin du fichier de config
	std::string configFile = Working_Folder + "/ProductConfiguration.config";

	std::ifstream streamConfigFile(configFile.c_str(), std::ios::in);
	
	if (streamConfigFile)
	{
		std::string pNameFF,destinationPart,jobTimePart,contents;

		//saut des lignes d'entêtes, repèrage du start.
		while(1)
		{
			std::getline(streamConfigFile,contents);
			std::size_t found = contents.find("Start");
		  	if (found!=std::string::npos)
			{
				break;
			}
		}
		//Configuration nombre max de shuttle
		std::getline(streamConfigFile,contents);

		//Configuration temps entre lancement
		std::getline(streamConfigFile,contents);
	
		//GAMME/TEMPS
		while (std::getline(streamConfigFile, contents))
		{
			if (contents.find(':') != std::string::npos )
			{

				//ROS_INFO("%s",contents.c_str())	;
				std::size_t pos2 = contents.find(":");
				std::size_t pos3 = contents.find_last_of(":");
		
				pNameFF = contents.substr(0,pos2);
				ROS_INFO("Product %s",pNameFF.c_str());
				destinationPart = contents.substr(pos2+1,pos3-pos2-1);
				ROS_INFO("destination part =%s",destinationPart.c_str());
				jobTimePart = contents.substr(pos3+1);
				ROS_INFO("jobTimePart =%s",jobTimePart.c_str());
				int destination[10];
				int jobTime[10];
				int manRSize = 0; //manufacturing range size of the produit = number of operation

				char * cstr2 = new char [destinationPart.length()+1]; 
		  		std::strcpy (cstr2, destinationPart.c_str());	// création objet cstring
				char * cstr3 = new char [jobTimePart.length()+1]; 
		  		std::strcpy (cstr3, jobTimePart.c_str());

		  		// cstr now contains a c-string copy of str
				int n2 = 0; //compteur sur les destinations
				int n3 = 0; //compteur sur les temps de fabrications
		 	 	

				char * p2 = std::strtok (cstr2," ");
		  		while (p2!=NULL)
		  		{
					destination[n2++] = atoi(p2);
					manRSize++ ;
		  			p2 = std::strtok(NULL," ");
		  		}

				char * p3 = std::strtok (cstr3," ");
				while (p3!=NULL)
		  		{
					jobTime[n3++] = atoi(p3);
		  			p3 = std::strtok(NULL," ");
		  		}

		  		delete[] cstr2;
				delete[] cstr3; 


				char charName;
				charName = char(pNameFF.c_str()[0]-16);
				int pNumberBase = atoi(&charName) * 10 ; 
				int pNumber;
				int JobTimeProduct;


				//  Pour gérer le n° de la prochaine destination d'un produit
				for (int i = 0; i < manRSize; i++)	
				{

					if(destination[i] == 3)		
					{
						pNumber = pNumberBase + i; 		
						JobTimeProduct = jobTime[i];
						initProduct(JobTimeProduct,pNumber);
					}
	
				}
		
			}
		}

		streamConfigFile.close(); //fermeture du fichier ProductConfiguration.txt ouvert en lecture//

	}
	else ROS_ERROR("Impossible d'ouvrir le fichier ProductConfiguration.config !");

}


/** Fonction interne permettant d'évacuer le produit de la table lorsque le robot l'a récupéré **/
//Fonction permettant de changer la couleur de la table lorsque le traitement est terminé
void Tache3::FinTraitementProduit(int numTable)
{
	if((numTable == 3)&&(Prise==1)&&(position==1)/*&&(bras == 1)&&(pince == 1)*/) ///****** <---- MODIFICATION
	{
		srv_simRosColor.request.signalName = table;
		srv_simRosColor.request.signalValue = 0; //couleur de base
		client_simRosColor.call(srv_simRosColor);
		Prise=0;
		Deposee=0;
		finTraitement = -1;
		oldproduit = -1;
		duree=-1;
		
		FINI=0;
		FINI_msg.data=FINI;
		pubFINI.publish(FINI_msg);
	}
}




/** Fonctions permettant de connaître la position du robot ainsi que l'état de la pince et du bras **/
//Fonction Callback permettant de récupérer la position du robot 1
void Tache3::PositionRobotCallback(const std_msgs::Int32::ConstPtr& msg)
{
	position = msg->data;
}



//Fonction Callback permettant de récupérer l'état du bras du robot 1
void Tache3::BrasRobotCallback(const std_msgs::Int32::ConstPtr& msg)
{
	bras = msg->data;
}



//Fonction Callback permettant de récupérer l'état de la pince du robot 1
void Tache3::PinceRobotCallback(const std_msgs::Int32::ConstPtr& msg)
{
	pince = msg->data;
}

void Tache3::PiecePriseCallback(const std_msgs::Int32::ConstPtr& msg) ///****** <---- MODIFICATION
{
	Prise=1;
}

void Tache3::PieceDeposeeCallback(const std_msgs::Int32::ConstPtr& msg) ///****** <---- MODIFICATION
{
	Deposee=1;
}

/** Fonction permettant le traitement d'un produit à la réception du message venant du noeud Poste associé **/
//Fonction Callback permettant de traiter le produit s'il est en position
void Tache3::TraitementProduitCallback(const std_msgs::Int32::ConstPtr& msg)
{


	produit=msg->data;	

	finTraitement = 0;
	retourTraitement.data=0;
		
	while(finTraitement != -1)
	{
		ros::spinOnce();
		if(produit != oldproduit)
		{
			if((position==1)&&(Deposee==1)/*&&(bras==0)&&(pince==0)*/)
			{
				//Coloration de la table associée à la tâche lors de la réception du produit
				srv_simRosColor.request.signalName = table;
				srv_simRosColor.request.signalValue = produit;
				client_simRosColor.call(srv_simRosColor);
				
				//Traitement du produit
				//Temps de Traitement du produit

				iteratorPMap = ProductsMap.find(produit);
				ProductTache* productPointer;

				if (iteratorPMap != ProductsMap.end() && (duree>=0)) // Vrai si l'itérateur n'est pas hors de la liste
				{
					productPointer = iteratorPMap->second;

					client_simGetVrepTime.call(srv_simGetVrepTime);
					t0 = srv_simGetVrepTime.response.simulationTime;
					time = t0;
					while(time - t0 <duree)
					{
						client_simGetVrepTime.call(srv_simGetVrepTime);
						time = srv_simGetVrepTime.response.simulationTime;
					}
					//Fin de traitement
					produit++;
					oldproduit = produit;		
	
					srv_simRosColor.request.signalValue = produit;
					client_simRosColor.call(srv_simRosColor);
		
					//Retour du traitement vers le node poste associé
					traitementProduit.data = produit;
					pub_traitementProduitTache.publish(traitementProduit);
	
					//Retour du traitement vers le node commmande		
					retourTraitement.data=1;
	
					finTraitement = 3;
				}		
			}
		
			pub_retourTraitement.publish(retourTraitement);
		}

		FinTraitementProduit(finTraitement);
	}
}







// Fonction Init du fichier configuration pour créer un produit
void Tache3::initProduct(int nJobtime, int pNumber)
{

	ROS_INFO("Creation Produit, temps de traitement = %d, numero produit = %d ", nJobtime,pNumber);

		// Création dynamique de l'object product
	ProductTache* newProductTache = new ProductTache(nJobtime,pNumber);

		// Insertion dans le map de la classe de la paire <key=pNumber,T=Product*>

	std::pair<std::map<int,ProductTache*>::iterator,bool> ret;			// ret permet d'avoir un retour de la fonction insert, il est faux si la key existe dèjà dans la map
	ret = ProductsMap.insert(std::pair<int,ProductTache*>(newProductTache->productNumber,newProductTache));

	if (ret.second==false)	// Si un produit avec le même nom existe déjà, celui-ci n'est pas ajouté à la collection
	{
    		ROS_WARN("Ordonnanceur : Un Produit de ce nom existe deja !"); 
  	} 

}

void Tache3::get_dureeTacheCallback(const std_msgs::Int32::ConstPtr& msg)
{
	duree=msg->data;
}
