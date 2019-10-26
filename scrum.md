Scrum
=====


                         +-+
                         | |  +-+   <---  Planning Client  <---  Rétrospective
                    +-+  +-+  | |
                    | |       | |                                      ^
                    | |  +-+  +-+                                      |
    Produit  --->   | |  | |
                    | |  +-+  +-+                 Release  <---  Démo. produit
                    | |       | |
                    +-+  +-+  | |                                      ^
                         | |  +-+                                      |
                         +-+                            +--------------+
                                                        |              |
                   Backlog Produit                      v              |

                          |                       Daily Meeting  Développement
                          v
                                                        |              ^
                   +-+                                  |              |
                   | |                                  +--------------+
                   | |                                                 |
                   | | +-+ +-+
           +-+ +-+ | | | | | | +-+                                +-+ +-+ +-+
           | | | | | | | | | | | |                                | | | | | |
           +-+ +-+ +-+ +-+ +-+ +-+                                +-+ +-+ +-+

           Classement par priorité  --->  Sprint Planning  --->  Backlog Sprint


_Sprint_ : Cycle de développement.

_Product Owner (P.O.)_ : Le client.

_Scrum Master (S.M.)_ : La personne qui s'assure que le processus _Agile_ est
respecté. Elle s'assure entre autres que :

  * Chaque memmbre de l'équipe a le temps de parler
  * Personne ne coupe la parole
  * L'équipe n'est pas perturbée pendant le _Sprint_.

Le rôle de _Scrum Master_ peut être assuré la même personne ou changer à chaque
_Sprint_. Le _Product Owner_ ne peut pas être _Scrum Master_.


I. _Backlog Produit_
--------------------

_Backlog Produit_ : L'ensemble des _user stories_ d'un produit.

_User Story_ : « En tant que __ , je veux pouvoir __ . » Une _user story_
comprend :

  * Importance pour le client
  * Difficulté pour l'équipe
  * _Definition of Ready (D.o.R.)_ : tout ce qui est nécessaire avant de pouvoir
  commencer à travailler.
  * _Definition of Done (D.o.D.)_ : tout ce qui doit être fait pour que la
  _user story_ soit considérée terminée.

Idéalement, les _Definitions of Done_ de toutes les _user stories_ sont réunies.

Le premier sprint, lors duquel est définit le _Backlog Produit_, est surnommé
« _Sprint Zero_ ». Suivant la taille du produit, ce premier _Sprint_ peut être
très long.


II. _Sprint Planning_
---------------------

Le _Sprint Planning_ est la définition de :

  1. La durée du _Sprint_ : Généralement entre deux et trois semaines, rarement
  une semaine, très rarement quatre semaines.

  2. La capacité de l'équipe : Combien de _Story Points_ pourront être traités
  par l'équipe pendant le sprint. Un _Story Point_ est une unité de travail.

  3. Combien de _Story Points_ correspondent à chaque _User Story_.

  4. Le _Backlog Sprint_ : Quelles _User Stories_ doivent être effectuées
  pendant le _Sprint_. Seules les _User Stories_ pour lesquelles les conditions
  de la _Definition of Ready_ sont remplies peuvent être sélectionnées.

  5. Un but unique pour le _Sprint_. Par exemple : « Le plus important pour ce
  sprint, c'est d'achever le développement d'une interface. »

La méthode du Poker peut être utilisée pour déterminer les _Story Points_ :

  * Des cartes avec différents _Story Points_ sont distribuées à chaque membre
  de l'équipe. Celles-ci suivent une séquence exponentielle, par exemple :
  0, 0.5, 1, 2, 5, 8, 13, 21, 50, 100, ∞, ?.
  * Pour chaque _User Story_, chaque personne montre une carte et l'équipe se
  concerte pour lui assigner une valeur en _Story Points_.
