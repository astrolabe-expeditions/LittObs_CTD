---
description: >-
  Nous remercions Jonathan Flye-Sainte-Marie (LEMAR/IUEM/UBO) ainsi qu'Emmanuel
  Augereau (CNRS/IUEM/UBO) pour la conception de ces caissons.
---

# Module 2 : Caisson CTD

Notez que BlueRobotics propose de bons boîtiers étanches, voir par exemple (https://bluerobotics.com/store/watertight-enclosures/wtevp/# tube) , mais le prix est assez élevé. Nous avons conçu un boîtier rapide et facile à construire qui ne nécessite que peu d'outils à l'exception d'un lasercut et d'une imprimante 3D (que l'on peut trouver dans la plupart des Fablabs voir : https://www.fablabs.io/labs/map).

-> Le corps de l'enceinte est constitué d'un tube PVC standard (européen) à pression (63mm, épaisseur 4.7). Chaque capuchon est constitué de 2 « disques » de PMMA (plexiglas) d'une épaisseur de 10mm comme illustré ci-dessous. Les deux disques des capuchons des capteurs sont maintenus ensemble avec les capteurs BAR30 et FastTemp, un filetage M10 a été réalisé dans le disque PMMA intérieur.&#x20;

\
Caisson conçu pour les sondes CTD.

### Compétences requises

* Découpeuse laser
* Imprimante 3D
* Affleureuse
* Taraudage

## Matériel

| 0,25 | [Plaque plexiglass épais. 10mm transparent, L. 50cm x H. 30cm](https://plaqueplastique.fr/product/plaque-plexiglass-xt-10mm-transparent/)                                                                                                                                                                                                                 |
| ---- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 2    | [Joint torique, Ø int. 52mm, Ø ext. 60mm, épais. 4mm](http://fr.rs-online.com/web/p/joints-et-joints-toriques/1965129)                                                                                                                                                                                                                                    |
| 1    | [Joint torique, Ø int. 12mm, Ø ext. 16mm, épais. 2mm](https://fr.rs-online.com/web/p/joints-et-joints-toriques/1964869?gb=a)                                                                                                                                                                                                                              |
| 3    | [Écrou borgne M4, inox A4 316](https://www.vis-express.fr/ecrou-borgne-inox-a4-din-1587-vs0100/37773-2559648-ecrou-borgne-m4-inox-a4.html#/267-conditionnement-200_pieces)                                                                                                                                                                                |
| 3    | [Écrou à oreilles M4, inox A4 316](https://fr.rs-online.com/web/p/ecrous-a-oreilles/2484315?gb=s)                                                                                                                                                                                                                                                         |
| 2    | [Vis à tête cylindrique pozi M3 x L. 20mm, inox A4 316](https://fr.rs-online.com/web/p/vis-a-metaux/0190478?gb=s)                                                                                                                                                                                                                                         |
| 6    | [Vis à tête cylindrique pozi M3 x L. 10mm, inox A4 316](https://fr.rs-online.com/web/p/vis-a-metaux/0190440?gb=s)                                                                                                                                                                                                                                         |
| 1    | [Tige filetée M4 x L. 1m, inox A4 316](https://www.vis-express.fr/tige-filetee-longueur-1-metre-inox-a4-din-975vs3347vs0104/21608-tige-filetee-m4-longueur-1-metre-inox-a4.html)                                                                                                                                                                          |
| 1    | [Tube PVC PN16, Ø ext. 63mm, épais. 4,7mm](https://connexion-pression.com/tubes-rigides-pvc-pression/63-915-tube-d-63-pn16-pvc-pression.html#/13-taille_de_la_decoupe-decoupe_1_metre)                                                                                                                                                                    |
| 4    | Colliers de serrage nylon 4,8mm x 300mm                                                                                                                                                                                                                                                                                                                   |
| 0,1  | [Filament 3D PETG 1kg noir 1,75 mm](https://eu.store.bambulab.com/fr/products/petg-hf?id=49068714754396)                                                                                                                                                                                                                                                  |
| 2    | [Vis à tête hexagonale M8 x L. 40mm, inox A4 316](https://www.vis-express.fr/vis-metaux-tete-hexagonale-th-inox-a4-din-933/20979-2322303-vis-metaux-tete-hexagonale-th-m8x40-inox-a4.html?_gl=1*1kk97gb*_up*MQ..*_gs*MQ..\&gclid=Cj0KCQiA_NC9BhCkARIsABSnSTarAGtmwjGLn0YNz8O_tkDtvD-51bRM3g7qLIVmRQDK-fGx2-1gUb4aAhp9EALw_wcB#/conditionnement-30_pieces) |
| 0,1  | [Graisse silicone pour joints toriques](https://fr.rs-online.com/web/p/graisses/0494124)                                                                                                                                                                                                                                                                  |

## ﻿﻿Outils

* Outils de base (tournevis, pince plate, pince coupante, clef anglaise, clef plate...)
* Imprimante 3D (pour support PCB et fixation CTD)
* Découpeuse laser
* Perceuse à colonne (avec foret à acier 2,5mm)
* Lime à métaux
* Scie sauteuse (avec lame à métaux)
* Tarauds
* Scie circulaire
* Affleureuse

### Vue d'ensemble du caisson

<figure><img src=".gitbook/assets/IMG_20260204_164212.jpg" alt=""><figcaption></figcaption></figure>



## **Pièces**

<figure><img src=".gitbook/assets/Pièces LAMOS LittObs (15).png" alt=""><figcaption></figcaption></figure>

<mark style="background-color:$danger;">**AJOUTER LES PIECES 3D calle-corde**</mark>

### **Étape 1 : Impression 3D**

À l'aide d'une imprimante 3D, de filaments en PETG et des fichiers ci-dessous, imprimez les pièces 28 (PCB\_Holder.stl), 29 (PCB\_Support.stl) et 31 (Sensor\_protection.stl) à 15% de remplissage :&#x20;

{% embed url="https://github.com/astrolabe-expeditions/LittObs_CTD/tree/ed4291ef54c2eff3621bca63024c3ba20032e0d1/hardware/enclosures" %}

## **Étape 2 : Découpe laser**

À l'aide d'une découpeuse laser et des fichiers ci-dessous, découpez les pièces 23, 24, 25 et 26 (PMMA\_Caps\_TD.svg) sur une plaque de PMMA 10mm.

{% embed url="https://github.com/astrolabe-expeditions/LittObs_CTD/tree/ed4291ef54c2eff3621bca63024c3ba20032e0d1/hardware/enclosures" %}

_<mark style="color:$info;">**Réglages de la découpeuse laser Trotec**</mark>_\
&#xNAN;_<mark style="color:$info;">\* pour la gravure :</mark>_\
&#xNAN;_<mark style="color:$info;">Matériau : PMMA / Puissance : 90 / Vitesse : 28/ Fréquence : 1000PPI</mark>_\
&#xNAN;_<mark style="color:$info;">\* pour la découpe :</mark>_\
&#xNAN;_<mark style="color:$info;">Matériau : PMMA 10mm / Puissance : 100 / Vitesse : 0.10 / Fréquence : 8000Hz</mark>_

## **Étape 3 : Taraudage des bouchons**

<mark style="background-color:$danger;">Bouchons :</mark><br>

<figure><img src=".gitbook/assets/Bouchon A.jpg" alt="" width="188"><figcaption><p>Bouchon A</p></figcaption></figure>

<mark style="background-color:$danger;">Chanfreiner l’ouverture centrale du bouchon A à 1,5 mm de profondeur avec la</mark>\ <mark style="background-color:$danger;">perceuse à colonne (équipée d’une fraise à chanfreiner de 15 mm de diamètre). Ne pas chanfreiner plus profond que 2 mm. Pour que le chanfrein soit lisse ajuster la vitesse de la perceuse à colonne au minimum (500 rpm). Le joint qui s'y glissera fait 2 mm de diamètre.</mark>

<figure><img src=".gitbook/assets/Bouchon B.jpg" alt="" width="188"><figcaption><p>Bouchon B</p></figcaption></figure>

<mark style="background-color:$danger;">Tarauder les 4 petits pas de vis du bouchon B en M3. Tarauder les deux grands pas de vis opposés du bouchon B en M10.</mark>

<figure><img src=".gitbook/assets/Bouchon C.jpg" alt="" width="188"><figcaption><p>Bouchon C</p></figcaption></figure>

<mark style="background-color:$danger;">Les cibles sur le bouchon C correspondent à la position de deux perçages non-</mark>\ <mark style="background-color:$danger;">traversants. Percer les cibles à 6 mm de profondeur avec la perceuse à colonne</mark>\ <mark style="background-color:$danger;">(équipée d'un foret à acier de 2,5 mm de diamètre). Tarauder ensuite les pas de vis en M3.</mark>

<figure><img src=".gitbook/assets/Bouchon D (1) (1).jpg" alt="" width="188"><figcaption><p>Bouchon D</p></figcaption></figure>

<mark style="background-color:$danger;">Rien à faire de particulier sur le bouchon D.</mark>

A l'aide d'un taraud M10, tarauder les pièces 23 et 24.

<div><figure><img src=".gitbook/assets/WhatsApp Image 2025-09-25 at 19.36.10 (1).jpeg" alt=""><figcaption></figcaption></figure> <figure><img src=".gitbook/assets/WhatsApp Image 2025-09-25 at 19.36.08.jpeg" alt=""><figcaption></figcaption></figure></div>

Les cibles sur la paroi 26 correspondent à la position de deux perçages non-traversants sur la paroi 25. Percez les cibles sur la pièce 25 à 6 mm de profondeur avec la perceuse à colonne (équipée d'un foret à acier de 2,5 mm de diamètre). Tarauder ensuite en M3 les pièces 25 et 26.

<figure><img src=".gitbook/assets/20240731_172030.jpg" alt="" width="375"><figcaption><p>Perceuse à colonne à utiliser pour percer la pièce 25 avec un forêt 2,5 mm</p></figcaption></figure>

## **Étape 4 : Assemblage des bouchons**

Pour assembler le bouchon avant, superposez la pièce 24 sur la pièce 23 en alignant bien les trous centraux puis placez un joint taurique (27) à la jonction entre les deux pièces.

<div><figure><img src=".gitbook/assets/WhatsApp Image 2025-09-30 at 18.22.43 (2).jpeg" alt=""><figcaption></figcaption></figure> <figure><img src=".gitbook/assets/WhatsApp Image 2025-09-30 at 18.22.44.jpeg" alt=""><figcaption></figcaption></figure></div>

Vissez ensuite l’interrupteur (22) et le <mark style="color:$warning;background-color:$danger;">??</mark> dans les trous de la pièce 23 (paroi extérieure du bouchon):

<figure><img src=".gitbook/assets/WhatsApp Image 2025-09-30 at 18.22.42 (1).jpeg" alt="" width="188"><figcaption></figcaption></figure>

Vissez la grande calle (29) à la pièce 24 (paroi arrière du bouchon) à l’aide de 4 petites visses M3 de 20mm.

<div><figure><img src=".gitbook/assets/WhatsApp Image 2025-09-30 at 18.22.58.jpeg" alt=""><figcaption></figcaption></figure> <figure><img src=".gitbook/assets/WhatsApp Image 2025-09-30 at 18.22.44 (1).jpeg" alt=""><figcaption></figcaption></figure></div>

Assembler maintenant le second bouchon à l'aides des pièces 25, 26, 27 et 28 et de 2 petites visses M3.

<div><figure><img src=".gitbook/assets/WhatsApp Image 2025-10-08 at 18.35.59 (1).jpeg" alt=""><figcaption></figcaption></figure> <figure><img src=".gitbook/assets/WhatsApp Image 2025-10-08 at 18.35.59.jpeg" alt=""><figcaption></figcaption></figure></div>

Callez et vissez la carte électronique à la grande calle (29) à l’aide de 2 petites visses en nylon <mark style="color:$warning;background-color:$danger;">type M?</mark>

<figure><img src=".gitbook/assets/WhatsApp Image 2025-09-30 at 18.22.42 (3).jpeg" alt=""><figcaption></figcaption></figure>

## **Étape 5 : Découpe et chanfreinage du tube**

Dans un tube en PVC PN16 de 63mm de diamètre, découpez un cylindre de 24,5 cm de longueur avec la scie circulaire.

Chanfreinez les bords du tube, avec une défonceuse (ou affleureuse) montée à l'envers sur une petite table avec une fraise à roulement à 45°. Réglez la profondeur d'usinage (sortie de la fraise par rapport à la table) de telle sorte à faire un logement suffisant pour le joint.

<div><figure><img src=".gitbook/assets/20240709_171148.jpg" alt=""><figcaption></figcaption></figure> <figure><img src=".gitbook/assets/WhatsApp Image 2025-09-30 at 18.37.48.jpeg" alt=""><figcaption></figcaption></figure></div>

Si besoin, découpez également les tige filetées, pour cela, fixez les dans un étau, avec des cales en bois pour la protéger. Découpez trois tiges de 28,5 cm de longueur avec la scie sauteuse (équipée d'un foret à métaux). Limez les extrémités avec une lime à métaux pour faciliter l’insertion des écrous à oreilles.\
![](<.gitbook/assets/20240731_162153 (1) (1).jpg>)

<div align="left"><figure><img src=".gitbook/assets/20240731_165449.jpg" alt="" width="188"><figcaption></figcaption></figure></div>

## **Étape 6 : Assemblage du tube**

Placez les deux calle-corde sur le tube.

Placez des écrous borgnes au bout des 3 tiges filetés (20).

Emboiter la pièce 31 par l'autre extrémité des tiges filetés et faites la glisser jusqu'aux écrous.

<figure><img src=".gitbook/assets/WhatsApp Image 2025-09-30 at 18.22.41 (3).jpeg" alt=""><figcaption></figcaption></figure>

Faites glisser l'assemblage bouchon avant + grande calle + PCB dans les tiges filetés.

Faites glisser le tube et les calle-corde sur les tiges filetés.

Placez le bouchon arrière (25, 26, 27.b et 28) à l'extrémité du tube et sur les tiges filetés.

Emboiter fermement le tout et bloquez avec des écrous à oreilles.﻿<br>
