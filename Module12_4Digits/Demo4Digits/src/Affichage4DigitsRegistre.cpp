#include "Affichage4DigitsRegistre.h"

#include "OptimiserEntreesSorties.h"

Affichage4DigitsRegistre::Affichage4DigitsRegistre(const int& p_pinDS, const int& p_pinSH, const int& p_pinST, const int& p_pinD1, const int& p_pinD2, const int& p_pinD3, const int& p_pinD4, const bool& p_cathodeCommune)
    : Affichage4DigitsBase(p_pinD1, p_pinD2, p_pinD3, p_pinD4, p_cathodeCommune), m_pinDS(p_pinDS), m_pinSH(p_pinSH), m_pinST(p_pinST)
{
    pinMode(this->m_pinDS, OUTPUT);
    pinMode(this->m_pinSH, OUTPUT);
    pinMode(this->m_pinST, OUTPUT);
}

void Affichage4DigitsRegistre::EnvoyerValeur(const byte p_valeur) const
{
    //Serial.println(String("Affichage4DigitsRegistre::EnvoyerValeur(") + p_valeur);
    monDigitalWrite(this->m_pinST, LOW);

#if !OPTIMISE_BOUCLE_ENVOYERVALEUR
    for (int i = 0; i < 8; ++i)
    {
        monDigitalWrite(this->m_pinSH, LOW);
        monDigitalWrite(this->m_pinDS, ((p_valeur >> i) & 1) ? this->m_segmentOn : this->m_segmentOff);
        monDigitalWrite(this->m_pinSH, HIGH);
    }
#else
        monDigitalWrite(this->m_pinSH, LOW);
        monDigitalWrite(this->m_pinDS, (p_valeur & 0x1) ? this->m_segmentOn : this->m_segmentOff);
        monDigitalWrite(this->m_pinSH, HIGH);

        monDigitalWrite(this->m_pinSH, LOW);
        monDigitalWrite(this->m_pinDS, (p_valeur & 0x2) ? this->m_segmentOn : this->m_segmentOff);
        monDigitalWrite(this->m_pinSH, HIGH);

        monDigitalWrite(this->m_pinSH, LOW);
        monDigitalWrite(this->m_pinDS, (p_valeur & 0x4) ? this->m_segmentOn : this->m_segmentOff);
        monDigitalWrite(this->m_pinSH, HIGH);

        monDigitalWrite(this->m_pinSH, LOW);
        monDigitalWrite(this->m_pinDS, (p_valeur & 0x8) ? this->m_segmentOn : this->m_segmentOff);
        monDigitalWrite(this->m_pinSH, HIGH);

        monDigitalWrite(this->m_pinSH, LOW);
        monDigitalWrite(this->m_pinDS, (p_valeur & 0x10) ? this->m_segmentOn : this->m_segmentOff);
        monDigitalWrite(this->m_pinSH, HIGH);

        monDigitalWrite(this->m_pinSH, LOW);
        monDigitalWrite(this->m_pinDS, (p_valeur & 0x20) ? this->m_segmentOn : this->m_segmentOff);
        monDigitalWrite(this->m_pinSH, HIGH);

        monDigitalWrite(this->m_pinSH, LOW);
        monDigitalWrite(this->m_pinDS, (p_valeur & 0x40) ? this->m_segmentOn : this->m_segmentOff);
        monDigitalWrite(this->m_pinSH, HIGH);

        monDigitalWrite(this->m_pinSH, LOW);
        monDigitalWrite(this->m_pinDS, (p_valeur  & 0x80) ? this->m_segmentOn : this->m_segmentOff);
        monDigitalWrite(this->m_pinSH, HIGH);
#endif

    monDigitalWrite(this->m_pinST, HIGH);
    monDigitalWrite(this->m_pinST, LOW);
}
