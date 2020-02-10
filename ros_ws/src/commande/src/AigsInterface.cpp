#include "AigsInterface.h"

#include <ros/ros.h>
#include <iostream>
//Messages
#include <std_msgs/Int32.h>

using namespace std;

//Couleur des messages des aiguillages
#define RESET   "\033[0m"
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */

AigsInterface::AigsInterface(ros::NodeHandle noeud)
{
	msg.data=1;
	pub_aig_Droite=noeud.advertise<aiguillages::Msg_Aiguillage>("/commande/Simulation/AiguillageDroite",100);
	pub_aig_Gauche=noeud.advertise<aiguillages::Msg_Aiguillage>("/commande/Simulation/AiguillageGauche",100);
}

AigsInterface::~AigsInterface()
{
}

void AigsInterface::Droite(int num_Aig)
{
	msg_aigs.Aiguillage=num_Aig;
	pub_aig_Droite.publish(msg_aigs);
}

void AigsInterface::Gauche(int num_Aig)
{
	msg_aigs.Aiguillage=num_Aig;
	pub_aig_Gauche.publish(msg_aigs);
}
