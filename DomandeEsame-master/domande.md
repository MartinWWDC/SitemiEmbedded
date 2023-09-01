# (esempi di) Domande d'esame

Vorrei tenere un approccio aperto anche nelle domande d'esame, elencandone qui il maggior numero e aprendo a contribuzioni da parte degli studenti.
Potete contribuire, basta che siano domande aperte.

Le raggruppo per capitolo del libro.



## Intro: tutto, in dettaglio.

* definizione di sistema embedded
* panoramica generale sui sistemi embedded, classi di device, caratteristiche, ordini di grandezza (dimensioni, potenze, consumi, ecc.), ambiti di utilizzo
* componenti interni di un MCU
* descrivere PLC
* definire SoC, cosa contiene, come si "combina" per la realizzazione dei vari prodotti reali



## Concetti: tutto, in dettaglio.

* sistemi monoprogrammati e multiprogrammati, differenze, caratteristiche, cosa c'entra la MdT?
* conversione AD e DA, caratteristiche, pregi e difetti, considerazioni sul flusso di dati campionati
* spiegare tecniche di multiplexing (divisione tempo, frequenza), shift register
* differenza fra controllo a loop chiuso e aperto, problemi del loop aperto
* spiegare tecnica PID per controllo a loop chiuso
* considerazioni sull'uso della memoria in un Arduino, rispetto ai tipi di dati disponibili
* architettura Von Neumann vs. Harvard
* argomentare validità della ricorsione in ambito embedded, vantaggi e svantaggi
* descrivere la gestione della memoria in un sistema embedded
* spiegare meccanismo dell'interrupt
* definire categorie "real time"
* spiegare licenza proprietaria vs. libera
* fare esempio di licenza software libera, descrivendone le caratteristiche salienti
* descrivere il concetto di watchdog



## Richiami: tutto, in dettaglio.

* descrivere a grandi linee il funzionamento di un resistore/condensatore/transistor/etc./... citare utilizzi
* panoramica delle unità di misura (elettricità/elettronica) e loro significato
* spiegare i collegamenti serie e parallelo per resistori e condensatori
* descrivere un filtro passa alto/basso, elencare utilizzi
* spiegare Veff (efficace)
* descrivere leggi di Kirchhoff
* differenza fra corrente alternata e continua
* cos'è la potenza elettrica?
* cos'è un segnale?
* quale effetto ha un condensatore su un segnale variabile?
* cosa si intende con "forma d'onda"?
* spiegare costante di tempo RC
* descrivere integratore (passa basso) e differenziatore (passa alto) RC
* descrivere leggi di Ohm e loro significato
* panoramica generale su sensori "fisici", esempi
* panoramica generale su sensori "numerici", esempi
* panoramica generale su attuatori, esempi
* panoramica generale su motori, esempi
* panoramica strumenti di misura, esempi
* spiegare PWM e utilizzi
* panoramica strumenti di misura e loro uso, problemi possibili



## Architetture: tutto, in dettaglio.

* cos'è un ISA?
* differenze fra CISC, RISC, VLIW, EPIC
* esempi CISC e RISC
* cosa si intende con "endianness"?
* cos'è un FPGA?
* descrivere architettura AVR con esempi
* descrivere architettura Xtensa con esempi
* cosa si intende con SoC/demo board/eval board/validation board?
* storia e architettura Arduino
* descrivere piattaforma STM32
* descrivere piattaforma ESP8266/ESP32
* cos'è NodeMCU?
* cosa si intende con PCB?



## Mem e I/O: tutto, in dettaglio.

* differenze fra i vari tipi di memoria (RAM/ROM/flash/EPROM/sequenziale/casuale/SDRAM/DRAM/DDR/etc.)
* cos'è e cosa fa una MMU?
* panoramica supporti memoria di massa nell'embedded, pregi e difetti
* cosa si intende con XIP? pregi e difetti?
* quali tipi di filesystem vengono usati nell'embedded? pregi e difetti
* cos'è il "wear leveling"?
* cos'è una RS232? che caratteristiche ha?
* descrivere NMEA0183
* descrivere I2C
* descrivere I2S
* descrivere SPI
* descrivere CAN-BUS
* descrivere Ethernet
* a cosa serve una linea di CLOCK? se ne può fare a meno?
* vantaggi e svantaggi del "chip select"
* cosa si intende con GPIO? come viene usato?
* pullup e pulldown
* cos'è il "bit banging"?
* vantaggi e svantaggi del bit banging
* perchè negli alimentatori switching non riesco a notare le oscillazioni di corrente?
* cos'è il JTAG?



## S.O.: overview

* cos'è un S.O.?
* descrivere architettura monolitica/microkernel/etc.
* cosa si intende con "preemptive multitasking"?
* cos'è un filesystem?
* cos'è il "root filesystem"?
* cos'è un "init system"?
* cos'è una shell?
* cos'è e cosa serve un bootloader?



## Linux: overview

* cos'è una toolchain?
* cos'è un build system? citarne qualcuno e descrivere
* cosa sono le partizioni? che tipi puoi citare e descrivere?



## FreeRTOS: overview

* descrivere cos'è FreeRTOS e come viene utilizzato
* cos'è un task in FreeRTOS?
* cos'è e a cosa serve un semaforo?



## Arduino: tutto, in dettaglio

* origine di Arduino
* pro e contro della piattaforma
* spiegare meccanismo di boot di un Arduino (classico: UNO)
* spiegare il funzionamento di setup() e loop()
* panoramica tipi di dato
* panoramica operatori
* cos'è un array?
* spiegare direttive compilatore
* panoramica costrutti di controllo di flusso
* cos'è una funzione?
* descrivere il meccanismo di gestione degli interrupt facendo esempi di codice
* descrivere funzionalità del piedino AREF/VIN/D0-1-2-...-N/GND/A0-1-2-...-N/RX/TX/SDA/SCL/... di Arduino/Wemos/...
* spiegare differenza fra GPIO digitale e analogico



## Rete: overview (tranne i temi *embedded* come MQTT)

* spiegare livelli ISO/OSI e TCP/IP
* citare protocolli "normali" e "IoT", differenze, pro e contro
* panoramica topologie di rete
* Descrivere a grandi linee il protocollo OSC/MQTT...
* cos'è LoRa?



## App A: NO



## App B: overview (anche perché questi argomenti saranno oggetto di lab e progetto finale)
