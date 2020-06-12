#ifndef PERSONAGGIO_H
#define PERSONAGGIO_H
#include <QApplication>



class Personaggio{
private:
    unsigned int maxHealth;
    int health;
    unsigned int baseAttack;
    unsigned int level;
    unsigned int expPoint;
    unsigned int armor;
    //proposta da healInterf-> aggiungere un campo bool alive x controllare stato, true= is alive, false= is alive
    bool dead;
    const QString tipoPersonaggio;// dovrebbe essere static? idk
    const QString nome;
    unsigned int prezzo; //dovrebbe essere const

protected:
    void increaseMaxHealth(unsigned int addVal);
    void increaseArmor(unsigned int addVal);
    void increaseAttack(unsigned int addVal);
    void setLevel(unsigned int newLevel); //usato da increaselevel (serve ad accedere al campo privato)

    void setHealth(int damage);

    //NB aggiunta per effettivamente andare a toccare exp
    void setExp(unsigned int ex);

    virtual int reducedDamageWithArmor(int damage) const;

    //proposta da healIntef
    //per riportare in vita un personaggio, va chiamato DURANTE UNA BATTAGLIA
    void resurrect();
    //per uccidere un personaggio dopo setHealth
    void kill();

public:
    Personaggio(){}
  //Personaggio(QString t= "tipo", QString n="nome", unsigned int p=1): tipoPersonaggio(t), nome(n), prezzo(p) {}
  Personaggio(unsigned int mh,
              unsigned int ba,
              unsigned int exp, // NB sostituito a lv xke quello è calcolato via increaseLevel
              unsigned int a,
              QString t,
              QString n,
              unsigned int p):
                 maxHealth(mh),
                 health(static_cast<int>(mh)),
                 baseAttack(ba),
                 level(1),
                 expPoint(exp),
                 armor(a),
                 dead(false),
                 tipoPersonaggio(t),
                 nome(n),
                 prezzo(p){}

  virtual ~Personaggio() = default;


  QString getTipoPersonaggio()const;
  QString getNome()const;
  unsigned int getPrezzo() const;

  int getHealth() const;
  unsigned int getMaxHealth() const;
  unsigned int getBaseAttack() const;
  unsigned int getLevel() const;
  unsigned int getExpPoint() const;
  unsigned int getArmor() const;

  //proposta da healInterf->per modificare i campi specifici delle interfaccie deve essere virtuale! && potrebbe ritornare se è avvenuto o no un cambio lvl wt a BOOL
  virtual bool increaseLevel(unsigned int newExpPoint);

  void receiveDamage(int damage);

  //proposte da healInterf
  bool getDeathState()const;

  //gain=hp guarita, divineIntervention=is a REZ or NOT
  void receiveHealing(unsigned int gain, bool divineIntervention=false);

  virtual int abilita1();
  virtual int abilita2();
  virtual int abilita3();

};
#endif // PERSONAGGIO_H
