/*Fichier Header de l'objet Key*/
#ifndef Key_h
#define Key_h
#define byte unsigned char
//Definition de la classe Key
class Key
{
  public :
    //Constructeur 
    Key();
    Key(byte Addr);
    //Declaration des variables public
    byte _Addr;
    byte _MSB;
    byte _LSB;
};
#endif
