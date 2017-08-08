/*Fichier Header de la librairie i2cRegister*/
#ifndef i2cRegister_h
#define i2cRegister_h
//Inclusion des objets
#include "Key.h"
//Inclusion des librairies
#include "EEPROM.h"
//#define byte unsigned char
#define REGISTER_SIZE 6
//Definition de la classe i2cRegister
class i2cRegister
{
  public :
    //Constructeur 
    i2cRegister(int RegisterSize);
    //Fonction qui enregistre une valeur dans un registre
    void setByte(byte registerAddr,byte MSB,byte LSB);
    //Fonction qui lit une valeur dans un registre
    void getByte(byte registerAddr,byte *val);
    //Fonction qui enregistre un float dans le registre
    void storeFloat(byte registerAddr, float val);
    //Fonction qui lit un float depuis le registre
    float readFloat(byte registerAddr);
    //Fonction qui reconstitue un float depuis deux octets
    float buildFloat(byte MSB, byte LSB);
    //Fonction qui code un float en deux octets
    void byteFloat(float val, byte *res);
    //Fonction qui enregistre un int dans le registre
    void storeInt(byte registerAddr, int val);
    //Fonction qui lit un int depuis le registre
    int readInt(byte registerAddr);
    //Fonction qui reconstitue un int depuis deux octets
    int buildInt(byte MSB, byte LSB);
    //Fonction qui code un int en deux octets
    void byteInt(int val, byte *res);
    //Fonction qui sauvegarde le registre sur l'EEPROM
    void saveEEPROM();
    //Fonction qui restaure le registre depuis l'EEPROM
    void readEEPROM();
    //Taille du registre
    int _RegisterSize;
  private : 
    //Declaration des variables private
    Key* Registre;
};
#endif

