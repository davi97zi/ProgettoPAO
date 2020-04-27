#include "dpsInterface.h"

void DpsInterface::increaseProbCritico(){
    //Check (utile?)
    if(probCritico>2)
        probCritico--;
}

//***srand(time(NULL)) e rand() causavano warning per la conversione implicita***
/*ProbCritico diminuisce all'aumentare del livello del personaggio --> aumenta la probabilità di effettuare un colpo critico
se all'inizio è 5, la prob. di ottenere un critico è 1/5, diminuendolo aumenta la probabilità*/
unsigned int DpsInterface::critico() const{
    //la prossima riga serve per i numeri random
    srand(static_cast<unsigned int>(time(nullptr)));
    //rand()%ProbCritico genera un numero casuale [0,ProbCritico-1], se esce 0 (probabilità=1/ProbCritico) si ottiene un critico
    //esempio: se ProbCritico è 5, si genera un numero [0,4]
    if((static_cast<unsigned int>(rand())%probCritico)==0)
        return 3+getLevel(); //viene restituito un intero che sarà usato per moltiplicare il danno fatto
    else
        return 1; //se non esce 0, non si ottiene un critico; quindi il moltiplicatore restituito è 1
}
