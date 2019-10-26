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

  * Chaque memmbre de l'équipe a le temps de parler,
  * Personne ne coupe la parole,
  * L'équipe n'est pas perturbée pendant le _Sprint_.

Le rôle de _Scrum Master_ peut être assuré la même personne ou changer à chaque
_Sprint_. Le _Product Owner_ ne peut pas être _Scrum Master_.


I. Backlog Produit
------------------

_Backlog Produit_ : L'ensemble des _User Stories_ d'un produit.

_User Story_ : « En tant que __ , je veux pouvoir __ . » Une _user story_
comprend :

  * Importance pour le client,
  * Difficulté pour l'équipe,
  * _Definition of Ready (D.o.R.)_ : tout ce qui est nécessaire avant de pouvoir
  commencer à travailler,
  * _Definition of Done (D.o.D.)_ : tout ce qui doit être fait pour que la
  _user story_ soit considérée terminée.

Idéalement, les _Definitions of Done_ de toutes les _User Stories_ sont réunies.

Le premier sprint, lors duquel est définit le _Backlog Produit_, est surnommé
« _Sprint Zéro_ ». Suivant la taille du produit, ce premier _Sprint_ peut être
très long.


II. Sprint Planning
-------------------

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
  « 0 0,5 1 2 5 8 13 21 50 100 ∞ ? »,
  * Pour chaque _User Story_, chaque personne montre une carte et l'équipe se
  concerte pour lui assigner une valeur en _Story Points_.


III. Développement
------------------

Chaque équipier choisit une tâche, le développement commence.

_Daily Meeting_ / _Stand-up Meeting_ : Réunion de 5 à 10 minutes durant
laquelle chaque memebre de l'équipe expose :

  * Son travail effectué la veille,
  * Son travail à effectuer ce-jour,
  * Quels sont les problèmes rencontrés.

Le _Daily Meeting_ n'est pas une réunion de débuggage, le but n'est pas de
résoudre les problèmes techniques pendant la réunion.

Si le _Product Owner_ est présent, il doit rester silencieux.

Plusieurs méthodes sont à la disposition du _Scrum Master_ pour assurer une
répartition équitable de la parole et une réunion de courte durée :

  * Faire tourner un ballon,
  * Demander aux membres de l'équipe de se mettre en position « de gainage »,
  * Utiliser un sablier…

Un _Kanban_ peut être utilisé.


IV. Démonstration produit
-------------------------

Le but de la démonstration produit est de présenter les _User Stories_ qui ont
été terminées pendant le _Sprint_, et uniquement celles-ci. Un bon exemple à
suivre est la conférence Keynote d'Apple. Il peut toutefois être intéressant de
lister les _User Stories_ inachevées.

Cette démonstration est l'occasion d'inviter le _manager_ et le chef de projet.

C'est lors de cette démonsration que l'on détermine la vélocité de l'équipe,
c'est-à-dire le nombre de _Story Points_ réalisables par l'équipe divisé par la
durée d'un _Sprint_.

En général, la vélocité est égale à la somme des vélocités de chaque membre de
l'équipe multipliée par un facteur 0,6 à 0,8. Attention toutefois, il ne faut
jamais essayer de déterminer la vélocité d'un seul membre de l'équipe.

Au bout d'un certain nombre de _Sprints_, il peut être intéressant de faire un
graphe de la vélocité de l'équipe en fonction du temps. Une régression permet
alors d'essayer de prédire la vélocité de l'équipe au prochain _Sprint_.




