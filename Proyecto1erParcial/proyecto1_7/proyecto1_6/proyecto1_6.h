#ifndef PROYECTO1_6_H_
#define PROYECTO1_6_H_
class candidato
{
    public:
        int number;
        bool primo = true;
        candidato(int number, bool primo){
            this->number = number;
            this->primo = primo;    
        }
};
void Criba(int);
#endif
