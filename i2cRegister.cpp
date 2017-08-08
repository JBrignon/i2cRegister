//Inclusion du header
#include "i2cRegister.h"
//Inclusion des objets
#include "Key.h"
//Inclusion des librairies
#include "EEPROM.h"
#define byte unsigned char
#define REGISTER_SIZE 6
//Declaration du constructeur
i2cRegister::i2cRegister()
{
  for(int i=0; i<REGISTER_SIZE; i++)
  {
    Registre[i] = new Key(i);
  }
}
//Fonction qui enregistre une valeur dans un registre
void i2cRegister::setOctet(byte registerAddr,byte MSB,byte LSB)
{
  Registre[registerAddr]._MSB = MSB;
  Registre[registerAddr]._LSB = LSB;
}
//Fonction qui lit une valeur dans un registre
void i2cRegister::getOctet(byte registerAddr,byte *val)
{
  val[0] = Registre[registerAddr]._MSB;
  val[1] = Registre[registerAddr]._LSB;
}
//Fonction qui enregistre un float dans le registre
void i2cRegister::storeFloat(byte registerAddr, float val)
{
  int tmp = val*100.0;
  storeInt(registerAddr, tmp);
}
//Fonction qui lit un float depuis le registre
float i2cRegister::readFloat(byte registerAddr)
{
  return buildFloat(Registre[registerAddr]._MSB,Registre[registerAddr]._LSB);
}
//Fonction qui reconstitue un float depuis deux octets
float i2cRegister::buildFloat(byte MSB, byte LSB)
{
  return buildInt(MSB,LSB)/100.0;
}
//Fonction qui code un float en deux octets
void i2cRegister::byteFloat(float val, byte *res)
{
  int tmp = val*100.0;
  byteInt(tmp, res);
}
//Fonction qui enregistre un int dans le registre
void i2cRegister::storeInt(byte registerAddr, int val)
{
  Registre[registerAddr]._LSB = val & 0x00FF;
  Registre[registerAddr]._MSB = (val >> 8) & 0x00FF;
}
//Fonction qui lit un int depuis le registre
int i2cRegister::readInt(byte registerAddr)
{
  return buildInt(Registre[registerAddr]._MSB,Registre[registerAddr]._LSB);
}
//Fonction qui reconstitue un int depuis deux octets
int i2cRegister::buildInt(byte MSB, byte LSB)
{
  int tmp = MSB;
  tmp = tmp << 8;
  return tmp | LSB;
}
//Fonction qui code un int en deux octets
void i2cRegister::byteInt(int val, byte *res)
{
  //LSB
  res[1] = val & 0x00FF;
  //MSB
  res[0] = (val >> 8) & 0x00FF;
}
//Fonction qui sauvegarde le registre sur l'EEPROM
void i2cRegister::saveEEPROM()
{
  for(int i=0; i<2*REGISTER_SIZE; i++)
  {
    EEPROM.write(i,Registre[i/2]._MSB);
    i++;
    EEPROM.write(i,Registre[i/2]._LSB);
  }
}
//Fonction qui restaure le registre depuis l'EEPROM
void i2cRegister::readEEPROM()
{
  for(int i=0; i<2*REGISTER_SIZE; i++)
  {
    Registre[i/2]._MSB = EEPROM.read(i);
    i++;
    Registre[i/2]._LSB = EEPROM.read(i);
  }
}

