Cahier des charges :
1 : Types d'acteurs :
  -> Phénomène :  - source d'évènements (température externe, source d'éclairage ext, code ouverture de porte, ...)
                    * varient de manière aléatoire
                    / affecte l'état (set valeur)
                    & val_phen (générée)
                    & val_phen_min
                    & val_phen_max


  -> Contrôleur : - régulation de l'effet d'un événement (chauffage, clime, variation de lumière, ...)
                    * réponse binaire ou proportionelle
                    * peut lire les phénomènes
                    * peut lire les états
                    / affecte l' état
                    / communique avec le serveur
                    & stock Etat_courant ?
                    & calcule val_ctrl


  -> Etat :       - Etat affecté par un phénomène (température interne, niveau d'éclairage, accès, ...)
                    * affecté de manière pondérée par les contrôleurs et les phénomènes (facteurs d'influences)
                    & enregistre val_phen
                    & enregistre val_ctrl
                    & calcule etat_effectif


  -> Serveurs :   - Enregistrement des évènements (journalisation, gestion de bases de données, statistiques, ...)
                    * ne communique qu'avec les contrôleurs
                    % prévision d'affichage des données par Gnuplot


  -> Simulation : - agent virtuel qui ne fait que géré la simulation. Il ne comprend rien à ce qui se passe.
                    * appelle les fonction dans un certain ordre
                    & gère le temps




2 : proposition :
  -> structure dans contrôle pour savoir quel info transmettre :
                    * si porte d'entrée : transmet vaine tentative d'ouverture
                    * si chauffage : pas de transfert si pas de changement d'etat


  -> donnée pour savoir si le controleur peut agir et/ou s'il peut lire les information extérieur
                    * si aquarium : ne peux agire sur la température extérieur
                    * si capteur de température extérieur : ne peux enclancher le chauffage (tâche du capteur intérieur)


  -> plusieurs fichier créés par le serveur ? : journal d'évènements + journal des informations
