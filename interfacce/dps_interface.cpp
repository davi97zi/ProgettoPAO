#include "dps_interface.h"

void DpsInterface::increaseProbCritico(){
    //Check (utile?)
    if(probCritico>2)
        probCritico--;
}


//***srand(time(NULL)) VA MESSO UNA SOLA VOLTA NEL MAIN
/*ProbCritico diminuisce all'aumentare del livello del personaggio --> aumenta la probabilità di effettuare un colpo critico
se all'inizio è 5, la prob. di ottenere un critico è 1/5, diminuendolo aumenta la probabilità*/
unsigned int DpsInterface::critico() const{
    //PER FARLO FUNZIONARE VA MESSO srand(time(NULL)) NEL MAIN (O IN PARTITA) UNA VOLTA

    if((static_cast<unsigned int>(rand())%probCritico)==0){
        return 3+getLevel(); //viene restituito un intero che sarà usato per moltiplicare il danno fatto
    }
    else{
        return 1; //se non esce 0, non si ottiene un critico; quindi il moltiplicatore restituito è 1
    }
}
