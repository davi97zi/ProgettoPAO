#ifndef PERSONAGGIO_H
#define PERSONAGGIO_H

#include <string>
using std::string;//va bene o va tolto?

class Personaggio{
private:
    unsigned int maxHealth;
    int health;
    unsigned int baseAttack;
    unsigned int level;
    unsigned int expPoint;
    unsigned int armor;
    bool dead;
    const string tipoPersonaggio;
    const string nome;
    unsigned int prezzo;
    int turniAbilita3;

protected:
    void increaseMaxHealth(unsigned int addVal);
    void increaseArmor(unsigned int addVal);
    void increaseAttack(unsigned int addVal);
    void setLevel(unsigned int newLevel); //usato da increaselevel (serve ad accedere al campo privato)
    void setHealth(int damage);
    void setExp(unsigned int ex);
    virtual void setArmor(int arm);

    virtual int reducedDamageWithArmor(int damage) const;
    //per riportare in vita un personaggio, va chiamato DURANTE UNA BATTAGLIA
    void resurrect();
    //per uccidere un personaggio dopo setHealth
    void kill();

public:
    Personaggio(){}
    Personaggio(unsigned int mh,
              unsigned int ba,
              unsigned int exp,
              unsigned int a,
              string t,
              string n,
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
                 prezzo(p),
                 turniAbilita3(0) {}

    virtual ~Personaggio() = default;

    string getTipoPersonaggio()const;
    string getNome()const;
    unsigned int getPrezzo() const;
    int getHealth() const;
    unsigned int getMaxHealth() const;
    unsigned int getBaseAttack() const;
    unsigned int getLevel() const;
    unsigned int getExpPoint() const;
    unsigned int getArmor() const;
    int getTurniAbilita3() const;
    void setTurniAbilita3(int);

    virtual bool increaseLevel(unsigned int newExpPoint);

    void receiveDamage(int damage);
    bool getDeathState()const;
    //gain=hp guarigione, divineIntervention=true se riporta in vita
    void receiveHealing(unsigned int gain, bool divineIntervention=false);

    virtual int abilita1();
    virtual int abilita2();
    virtual int abilita3();

};
#endif // PERSONAGGIO_H
