#ifndef TEMPERATURA_H_
#define TEMPERATURA_H_

class Temperatura
{
    private: 
        int tmpKelvin;
    public:
        Temperatura();
        void setTempKelvin(int tmp);
        void setTempFahrenheit(int tmp);
        void setTempCelsius(int tmp);
        float getTempKelvin();
        float getTempFahrenheit();
        float getTempCelsius();
};
#endif