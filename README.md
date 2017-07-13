Notes sur le circuit:

Il faudra regarder combien les LEDs tirent de courant, le stabilisateur 5V devient très vite un peu chaud et risque de griller.
Sinon, acheter un composant plus solide sur le courant ou diminuer la luminosité des LEDs.

Pourquoi pas faire deux conversions: une pour la puissance (leds), une pour le circuit (arduino), même si ce dernier est directement alimentable avec une 4S.
Pour le moment, je pense juste lui mettre une autre LiPo en 2S (7,4V)

Il faudra regarder aussi comment faire varier le contraste de l'écran avec le potentiomètre. Vu le bordel niveau fils, acheter des petites sockets en plastique pour faire des terminaisons simples pour Arduino va être obligatoire.
Les boutons poussoirs sont niquels, par contre le gros bouton fout le bordel niveau place... C'était à prévoir.

Souder le XT60 et regarder la vitesse de décharge avec une LiPo 4S.

Pour l'instant on n'a donc pas grand chose comme composant, ca devrait être assez simple à monter. 
Ca va se compliquer quand l'ESP arrivera. il va falloir faire des branchements en direct dessus, et je n'ai plus de socket pour ce dernier (pourtant j'en avais c'est sur!)
On se débrouillera à l'ancienne.

Ca pourrait être cool de désouder l'USB de l'Arduino et de le cabler sur le board, pour faciliter les mises à jour.

Ce serait aussi stylé de pouvoir charger directement en externe, avec un connecteur XT60 et le connecteur 4S mais n'en faisons pas trop pour le moment.


