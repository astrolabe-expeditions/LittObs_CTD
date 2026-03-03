# Module 4 : Mise en route

Une fois le programme téléversé sur le microcontrôleur ESP32 et le fichier config mis sur la carte micro SD, on peut brancher les capteurs de température et pression sur la carte électronique (peut importe l’emplacement, les 2 sont intervertibles).

Pour tester la carte, la laisser branchée par USB à l'ordinateur et ouvrir le terminal série du logiciel Arduino pour voir les lignes de debug.

Si cela ne fonctionne pas du premier coup, il est possible de tester individuellement les composants via les codes présents sur le dépôt Github ci-dessous :&#x20;

{% embed url="https://github.com/astrolabe-expeditions/LittObs_CTD/tree/728df0fae9c06897e10d569524ac387f5888bd25/software/firmware/Individual_tests/OSO_tools-main" %}

Les dossier [Set\_time\_DS3231\_SD3031](https://github.com/astrolabe-expeditions/LittObs_CTD/tree/728df0fae9c06897e10d569524ac387f5888bd25/software/firmware/Individual_tests/OSO_tools-main/Set_time_DS3231_SD3031) permet par exemple de mettre à l'heure l'horloge RTC (les dernières utilisées sont des DS3231)
