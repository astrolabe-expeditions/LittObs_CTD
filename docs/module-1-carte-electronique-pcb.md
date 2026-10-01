# Module 1 : Carte électronique PCB

## Compétences requises

* Soudure
* Électronique

> **Étapes de construction :**
>
> 1. Souder tous les pins de la face avant
> 2. Souder les composants de la face arrière
> 3. Souder ﻿ l'horloge, le booster, la carte SD, l'ESP32 et l'opto isolateur sur leurs pins

**Datalog :**

* ESP32 Firebeetle - Fournisseur
* Micro SD reader (compatible avec générique (Amazon, 3.3V), adafruit micro SD de chez gotronic) - Fournisseur
* Carte micro SD (8Go) - [Fournisseur](https://www.conrad.fr/fr/p/carte-microsdhc-transcend-ultimate-600x-8-gb-class-10-uhs-i-avec-adaptateur-sd-1396522.html)﻿
* RTC : Compatible avec DS3231 générique Amazon et DS3231M DF Robot chez gotronic - [Fournisseur](https://www.gotronic.fr/art-module-rtc-i2c-dfr0641-32243.htm)﻿
* Batterie 18650 - 3600mAh x2 - [Fournisseur](https://letmeknow.fr/fr/batteries/2120-batterie-lg-3600ma-18650-8438493108507.html)﻿
* Led + R 47Ohm
* condensateurs ( 47pF, 1nF, 100nF)
* 2 Résistances 4700 Ohm de pullup pour I2C
* 1 résistance de 47 Ohm de pulldown pour l’isolateur
* 1 résistance 1000 Ohm
* 1 résistance 10 000 Ohm
* interrupteur à lames souples Reed Switch NO pour mode configuration - [Fournisseur](https://www.gotronic.fr/art-interrupteur-ils-1-rt-4082.htm)﻿
* interrupteur à lames souples Reed Switch NF 1A pour interrupteur alimentation - [Fournisseur](https://www.gotronic.fr/art-interrupteur-ils-1-t-4080.htm)﻿
* Connecteur NSK254-2 PCB Male x2
* Transistor 2N3904
* Pololu Step-up 5v U1V11F5 - [Fournisseur](https://www.gotronic.fr/art-booster-5-v-u1v11f5-21751.htm)﻿
* Interrupteur on/off - [Fournisseur﻿](https://fr.rs-online.com/web/p/interrupteurs-a-glissiere/7347296)﻿

﻿\
**Sonde :**

* Sonde conductivité Atlas Scientific EZO EC - [Fournisseur](https://www.robesol.nl/en/mini-conductivity-probe-k-10-87672470.html)﻿
* Opto Isolateur Atlas (Isolated Carrier Board) -[ Fournisseur](https://www.robesol.nl/en/electrically-isolated-ezo-carrier-board-102660261.html)﻿
* Circuit de conductivité - [Fournisseur](https://www.robesol.nl/en/ezo-conductivity-circuit-87672188.html)﻿
* Sonde pression Blue Robotic BAR 30 - [Fournisseur](http://syera.fr/boutique/fr/pression-temperature/72-capteur-de-pression-haute-resolution-300m.html)﻿
* Sonde température Blue Robotic Fast Temp - [Fournisseur](http://syera.fr/boutique/fr/pression-temperature/278-capteur-de-temperature.html)

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**Matériel face avant : (version sans le module UV)**

* ESP32 Firebeetle - Fournisseur
* Micro SD reader (compatible avec générique (amazon), adafruit micro SD de chez gotronic) -[ Fournisseur](https://www.amazon.fr/gp/product/B08YXSP666/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8\&psc=1)﻿
* Carte micro SD (8Go) - [Fournisseur](https://www.conrad.fr/fr/p/carte-microsdhc-transcend-ultimate-600x-8-gb-class-10-uhs-i-avec-adaptateur-sd-1396522.html)﻿
* RTC : Compatible avec DS3231 générique Amazon et DS3231M DF Robot chez gotronic - [Fournisseur](https://www.gotronic.fr/art-module-rtc-i2c-dfr0641-32243.htm)﻿
* Opto Isolateur Atlas (Isolated Carrier Board) -[ Fournisseur](https://www.robesol.nl/en/electrically-isolated-ezo-carrier-board-102660261.html)
* Circuit de conductivité EZO - [Fournisseur](https://www.robesol.nl/en/ezo-conductivity-circuit-87672188.html)﻿
* Led + R 47 Ohm
* condensateurs ( 47pF, 1nF, 100nF)
* 2 Résistances 4,7kOhm de pullup pour I2C
* 1 résistance de 4.7KOhm de pulldown pour l’isolateur
* interrupteur à lames souples Reed Switch NF 1A pour interrupteur alimentation - [Fournisseur](https://www.gotronic.fr/art-interrupteur-ils-1-t-4080.htm)﻿
* Embase pour CI, JST x2
* Transistor 2N3904
* Pololu Step-up 5v U1V11F5 - [Fournisseur](https://www.gotronic.fr/art-booster-5-v-u1v11f5-21751.htm)﻿
* Interrupteur on/off - [Fournisseur﻿](https://fr.rs-online.com/web/p/interrupteurs-a-glissiere/7347296)﻿

﻿\
![](https://wikifactory.com/files/RmlsZTo5MDMwNzU=)﻿\
![](https://wikifactory.com/files/RmlsZTo5MDMwOTE=)

﻿\
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

#### Description des principaux composants de la PCB

<figure><img src=".gitbook/assets/pcb-comments.png" alt=""><figcaption></figcaption></figure>

**1) ESP32 → Microcontrôleur et module de communication**

L’ESP32 est un microcontrôleur intégrant un processeur ainsi que des fonctionnalités de communication Wi-Fi et Bluetooth. C’est l’unité de contrôle principale de la carte électronique : il reçoit les informations provenant des capteurs, les traite et commande les différents composants de la PCB.

Il exécute le programme codé sur Arduino, afin de réaliser automatiquement les mesures, de gérer leur enregistrement et de communiquer avec les différents capteurs.

**2) Carte micro-SD → Stockage des données**

La carte micro-SD permet de stocker les données récoltées par les différents capteurs. L’ESP32 peut écrire les mesures sur la carte afin de conserver un historique des données, même lorsque la carte n’est plus connectée à un ordinateur ou à un réseau.

/!\ La carte micro-SD n'est pas visible sur cette photo. Elle est située sous le module ESP32.

**3) LED → Indicateur visuel de l’état de fonctionnement de la carte**

La led peut signaler que la carte est alimentée ou qu’une fonction particulière est active. Elle est associée à des résistances en série permettant de limiter le courant qui la traverse, afin d’éviter de l’endommager.

**4) Résistances → Limitation et adaptation du courant et des signaux**

Elles s’opposent au passage du courant électrique. Elles peuvent avoir plusieurs fonctions sur cette PCB : limiter le courant, notamment dans le circuit de la LED, mais aussi adapter les niveaux électriques ou assurer des fonctions de pull-up/pull-down pour les signaux numériques.

À tension constante, une augmentation de la résistance (mesurée en ohms ( Ω) entraîne une diminution du courant (en Ampères (A)).

**5) Horloge temps réel (HTR ou RTC en anglais) → Mesure et conservation du temps**

Permet de conserver une référence temporelle précise et de connaître la date et l’heure auxquelles les mesures sont effectuées. Elle permet également de programmer les acquisitions de données : dans notre cas on effectue une mesure toutes les 15 minutes.

La RTC possède sa propre source d’alimentation, ici une pile au lithium, ce qui lui permet de continuer à conserver l’heure lorsque l’alimentation principale de la carte est coupée.

**6) Connecteurs mâles → Connexion des capteurs**

Les connecteurs mâles permettent de relier les différents capteurs et périphériques à la carte électronique. Ils assurent la connexion électrique entre les capteurs et les circuits de la PCB.

Un connecteur mâle possède des broches ou « pins » qui s’insèrent dans les contacts correspondants d’un connecteur femelle, qui possède des logements ou contacts réceptacles.

**7) Condensateurs → Stockage temporaire et stabilisation de l’alimentation**

Les condensateurs stockent temporairement de l’énergie électrique. Sur une PCB, ils sont notamment utilisés pour filtrer et stabiliser les tensions d’alimentation.

**8) Circuit EZO de conductivité → Interface de mesure de la conductivité**

Le circuit EZO Conductivity d’Atlas Scientific est une interface électronique dédiée à l'exploitation d'une sonde de conductivité. Il permet de transformer le signal provenant de la sonde en une information exploitable par le microcontrôleur.

**9) Isolateur Atlas Scientific → Interface et isolation électrique du circuit de conductivité**

La carte Atlas Scientific (en violet) sert d’interface entre le circuit EZO et le reste du système. La sonde de conductivité est connectée à cette partie du système par l'intermédiaire d’un connecteur.

**10) Transistor → Commutation et commande électrique**

Le transistor est un composant électronique permettant notamment de commuter (c'est-à-dire transférer un courant électrique d'un circuit à un autre) ou contrôler le passage du courant dans une partie du circuit.

**11) Régulateur de tension → Stabilisation de la tension d’alimentation**

Le régulateur de tension permet de fournir une tension électrique stable et adaptée aux composants électroniques, même lorsque la tension d’alimentation disponible varie. Il évite ainsi que les variations de la tension d'entrée ne se transmettent directement aux circuits sensibles comme l’ESP32 ou les capteurs.

**12) Interrupteur → Mise sous/hors tension**

L’interrupteur permet de contrôler le passage du courant électrique dans le circuit.

* Interrupteur fermé → le circuit est conducteur et le courant peut circuler ;
* Interrupteur ouvert → le circuit est interrompu et le courant ne circule plus dans la partie concernée.<br>

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

#### Soudure étape par étape

**1. Souder les composants de la face avant (sauf pour l'horloge, le booster, la carte SD, l'ESP32 et l'opto isolateur où vous ne souderez que les pins à la face dans un premier temps).**![](https://wikifactory.com/files/RmlsZTo5MDMwNzg=)﻿<br>

> NB : - Pour le booster, souder les grandes pins vers le haut
>
> * le coté plat de la LED doit être orienté vers le haut du PCB
> * il n'y a pas d'ordre précis pour les condensateurs

L'AtlasScientific (composant pour le capteur de salinité, couleur violet) doit d'abord se voir retirer les pins horizontaux avant d'en mettre de nouveaux verticaux.

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**Matériel face arrière :**

* Batterie 18650 - 3600mAh x2 - [Fournisseur](https://letmeknow.fr/fr/batteries/2120-batterie-lg-3600ma-18650-8438493108507.html)﻿
* Support batterie 18650 x2 - [Fournisseur](https://letmeknow.fr/fr/coupleurs/1561-support-pour-batterie-18650-0616639922912.html)﻿
* Interrupteur à lames souples Reed Switch NO pour mode configuration - [Fournisseur](https://www.gotronic.fr/art-interrupteur-ils-1-rt-4082.htm)﻿

![](https://wikifactory.com/files/RmlsZTo5MDMwOTA=)﻿\
﻿<br>

> **2.﻿ Souder les composants de la face arrière**﻿<br>
>
> <img src="https://wikifactory.com/files/RmlsZTo5MDMwNzc=" alt="" data-size="original">

> Attention : à souder les supports batteries dans le bon sens (se référer au + et - dessinés sur les cartes PCB) et bien enlever les batteries lors de la soudure.

**3. Souder ﻿ l'horloge, le booster, la carte SD, l'ESP32 et l'opto isolateur sur leurs pins**![](https://wikifactory.com/files/RmlsZTo5MDMwNzY=)![](https://wikifactory.com/files/RmlsZTo5NTMwNjQ=)﻿<br>

* Lors de la soudure de ﻿l'interrupteur à lames souples Reed Switch, bien vérifier qu'il soit en position Fermé à l'aide d'un multimètre (le courant doit passer) et couper l'autre pin.
* Dessouder les pins déjà présents sur l'optoisolateur Atlas.
* une fois le tout souder, ajouter le circuit de conductivité (carte verte, somme sur image ci-dessus)

> NB : mettre un point de colle sous l'opto-isolateur pour l'isoler de la soudure de la pile. Attention les interrupteurs à lame souple sont très fragiles

**Fichiers pour imprimer la carte :**

![](https://wikifactory.com/files/RmlsZTo5MDMwODg=)![](https://wikifactory.com/files/RmlsZTo5MDMwODk=)﻿<br>

Vous trouverez les fichiers Gerber en suivant : hardware/pcbs/GERBER\_PCB\_CTD\_v2.3

{% file src=".gitbook/assets/PCB_CTD_v2.3 (1).zip" %}

#### 1. Hardware

**Vérifier les soudures**

Vérifier à l'aide d'un multimètre que les soudures ne se touchent pas (notamment les transistors qui ont des pattes très rapprochées

**Vérifier le bon fonctionnement du module EZO (petit module vert sur lequel on vient connecter la sonde de conductimétrie)**

* Mettre la carte sous tension, et vérifier que la petit LED du module EZO (module auquel on relie la sonde) clignote﻿. Si ce n'est pas le cas,
  * Vérifier qu'il y a bien une tension de 5V entre la borne VCC et la borne GND du module violet. Si ce n'est pas le cas, c'est probablement le voltage booster qui n'est pas bon (le petit module munie d'une bobine se trouvant sous la carte ESP). Une solution de secours consiste à soit alimenter directement le module violet avec la sortie 3.3V de la carte ESP, soit à faire un court circuit entre la première et la troisième patte du module voltage booster.

**VÉRIFIER QUE LE MODULE DE CONDUCTIMÉTRIE EZO EST BIEN CONFIGURÉ**

* Par défaut, le capteur communique en UART. Notre programme utilise le protocole I2c pour communiquer avec. Vous savez qu'il est en UART si le module vert clignote en vert puis bleu clair. Il clignote seulement en bleu foncé s'il est en I2c.
* Pour procéder en changement, munissez vous d'une alimentation stabilisée 5V (une Arduino ou une alimentation de laboratoire), et de 3 fils de connection.
* Détachez le module vert du module violet et branchez-le de la sorte :

![](.gitbook/assets/image.png)﻿<br>

* Le LED s'allume en bleu, c'est bon !
* Remettez le module vert sur le module violet (dans le bon sens !)

Lien de la doc : [https://files.atlas-scientific.com/EC\_EZO\_Datasheet.pdf](https://files.atlas-scientific.com/EC_EZO_Datasheet.pdf)<br>
