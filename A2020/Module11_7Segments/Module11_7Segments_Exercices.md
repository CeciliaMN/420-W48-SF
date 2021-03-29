# Module 11 - Afficheur 7-segments

## Exercice 1 - Programme de test

### Matériel

- TinkerCad avec le programme
https://www.tinkercad.com/things/7PynAsakWfQ 

### Étape 1 - Analyser le code

- Ajoutez des commentaires au programme qui servira de test pour les montages de l'afficheur 7-segments.

- Ajoutez la fonction reset() à votre copie du programme. La fonction sera utile pour éteindre les segments de l'afficheur.

<details>
<summary>Solution</summary>

```cpp
/* PROGRAMME DE TEST
  afficheur 1 X 7 segments
  modele 5611as Cathode commune
*/

int segmentCourant = 0;
int activation = 2;
int debut = 6;
int fin = 13;

void reset();

void setup() {

  pinMode(activation, OUTPUT);

  for (size_t pin = debut; pin <= fin; ++pin) {

    pinMode(pin, OUTPUT);
  }

  digitalWrite(activation, HIGH);
  reset();
}

void loop() {
  digitalWrite(segmentCourant + 6, HIGH);
  digitalWrite(activation, LOW);

  delay(500);

  digitalWrite(segmentCourant + 6, LOW);
  digitalWrite(activation, HIGH);
  
  segmentCourant = (segmentCourant + 1) % 8;
}

void reset() {
  for (size_t pin = debut; pin <= fin; ++pin) {
    digitalWrite(pin, LOW);
  }
}
```

</details>

### Questions de réflexion

1. Quelle différence y a-t-il entre les deux déclarations suivantes ?
   - ```for (size_t pin = 6; pin <= 13; ++pin)```
   - ```for (int pin = 6; pin <= 13; ++pin)```

2. Quelle est la dimension de la variable size_t?

## Exercice 2 - Affichage des nombres hexadécimaux

### Matériel

- TinkerCad ave le programme
https://www.tinkercad.com/things/1tZqUFVHNU9 

### Étape 1 - Affichage des nombres 0x0 à 0xF

- Complétez le code pour représenter les 16 nombres hexadécimaux dans l'afficheur.
- Ajoutez la fonction "AfficherNombre()" à votre copie du programme. Cette fonction rend le code modulaire.
- Modifiez le code pour afficher les 16 nombres, en ordre croissant, puis en ordre décroissant.

### Étape 2 - Allumer la marque decimale

- Allumez la marque décimale seulement durant la période décroissante des nombres.

## Exercice 3 - Classe 7-segments

### Matériel

- Votre version du programme basé sur
https://www.tinkercad.com/things/1tZqUFVHNU9 

- Convertir votre programme pour un usage avec une classe nommée 7Segments

## Exercice 4 - Usage du registre à décalage (optionnel)

### Matériel

- Registre à décalage et la classe 7Segments

### Étape 1 - Montage du registre à décalage

- Utilisez le registre à décalage pour alimenter l'afficheur 7segments

### Étape 2 - Codage

- Codez une nouvelle classe qui permet d'utiliser le registre à décalage afin de controler les segments.
