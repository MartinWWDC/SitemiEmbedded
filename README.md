# Progetto Sistemi Embedded

Nome: Conta Monete
Autore: Martino Francesco Leone 
Descrizione: il progetto consiste in un Contatore di monete in valuta euro.

Lo scopo di questo progetto è permettere all'utente di inserire le monete nel apposito divisiore il quale si occuperà  di smistarle  in base al diametro e di collocarle nell'apposita colonna. 

Le monete una volta separate il sensore si occuperà di segnalare ad arduino l'inserimento di un nuova moneta il quale aggiornerà il totale mostrato a schermo .

## Lista Materiale:

* 1 x Arduino Nano

* 5 x Angeek KY-033 - Modulo Sensore TCRT5000

* 1 x Freenove I2C LCD 1602 Module, New Type IIC TWI Serial 16x2 Display

## Features

le monete verranno inserite nello smistamonete il quale dividerà le monete e le inserirà le rispettive colonne e al momento della caduta i sensori  identificheranno quale monete è stata inserita.

## Schema

<img src="file:///C:/Users/Martino/Desktop/laboratori/Sistemi%20Embedded/documentazione/mainCircuito.png" title="" alt="" data-align="center">

## Modelli Utilizzati

### Colonne

Componente Stampato in 3d che andrà a contenerere le singole monete 

![](C:\Users\Martino\Desktop\laboratori\Sistemi%20Embedded\documentazione\cilindri-2.png)

![](C:\Users\Martino\Desktop\laboratori\Sistemi%20Embedded\documentazione\cilindri-3.png)

### Base

base che permettera di far scorrore  una volta il clinata e di permettere una divisione dei coin

![](C:\Users\Martino\Desktop\laboratori\Sistemi%20Embedded\documentazione\base-1.png)

![](C:\Users\Martino\Desktop\laboratori\Sistemi%20Embedded\documentazione\base-2.png)

# Immagini

## Foto Progetto

![](https://i.ibb.co/Qk3KVvV/1.jpg)
![](https://i.ibb.co/3MX5Bjb/2.jpg)
![](https://i.ibb.co/MNpxrm4/3.jpg)
![](https://i.ibb.co/jZvCGFk/4.jpg)

## Video progetto

[Video Presentazione Contamonete-Sistemi embedded - YouTube](https://youtu.be/x5DmvLtoh-8)

# Difficoltà riscontrate

* **Appesantimento del codice:** la difficoltà principlae è stata riscontrata nella scrittura del codice in quand essendo che la caduta delle monete dura solo pochi millisecondi è stato necessario assicurarsi di scrivere un codice suffficentemente efficente tale da poter suddisfare tutti i requisiti  nel modo più efficente possibile.
* **Monete sotto i 10 cent:** i sensori kr-033 hanno il problema di non essere molto precisi nel captare elementi di piccola dimensione, in particolare le monete da 1,2 e 5 cent dato il loro spessore risultano di difficile implementazione (in quanto si richierebbe molto spesso di incorrere nella macata rilevazione della moneta) per questo motivo per mancanza di precisione e mancanza di sensori  non verrà implementato 
* **Caduta Monete:** a progetto terminato è stato riscontrato un imperfezione nel componente "base" il quale non fa cadere correttamente le monete come espresso nel video segnalazione([sistemi ebedded-problema base - YouTube](https://youtu.be/bRrj2EUDvSM) )

Link a repo: https://github.com/MartinWWDC/SitemiEmbedded
Licenza scelta: GNU GENERAL PUBLIC LICENSE version 3 (GPLv3)
Data *indicativa* di presentazione: settembre 2023

# Link utili

[Aceti Ceribelli / Progetto sistemi embedded / Relazione · GitLab](https://gitlab.di.unimi.it/aceti-ceribelli/progetto-sistemi-embedded/relazione)

[SistemiEmbedded · GitLab](https://gitlab.di.unimi.it/sistemiembedded)
