# 2016WS_OPS
Übungsprojekt OPS WS 2016 Nichtlineare Optimierung ohne Nebenbedingungen: Eindimensionale Verfahren (C++)
Gruppe 050015-7, Team 3: Stomakhin Andrey, Fruehwirth Franz, Hanzer Daniel, Cherches Nicole, Filippovits Lukas 
2016-12-15

Dateien:
NotLinOpt.cpp  ... Hauptmodul: Hier lassen wir ein Schleife laufen, wo man eingeben kann welche Funktion man mit welchem Verfahren
                               und in wewlchem Bereich man das Minimum suchen will
                               
Funktion.h     ... Abstrakte Klasse/Interface Funktion laut Angaben reduziert auf das was wir brauchen

Funktion.cpp   ... Implementierung von Funktion

Funktionen.h   ... Unsere Testfunktionen, abgeleitet jeweils von Funktion. damit können sie im main als Parameter übergeben werden

InterfaceOptVerfahren.h    ... Interface für die Verfahren damit man die auch als Parameter übergeben kann

InterfaceOptVerfahren.cpp  ... Implementierung falls wir die überhaupt brauchen

GS.h                       ... Goldener Schnitt Verfahren

FB.h                       ... Fibonacci Verfahren

BI.h                       ... Bisektions Verfahren 

