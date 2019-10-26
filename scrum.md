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


V. Rétrospective
----------------

Lors de la rétrospective, chaque membre de l'équipe de développement explique
quel a été son ressenti pendant le _Sprint_. Cette rénion n'a pas de limite de
durée et comporte plusieurs règles :

  * Seuls les membres de l'équipe sont présents,
  * La présence de téléphones portables et d'ordinateurs est interdite,
  * « Tout ce qui est dit en rétrospective reste en rétrospective »,
  * « Pas de jugement, pas de coupale »,
  * Personne ne peut couper la parole.

Le _Scrum Master_ dispose une fois de plus de plusieurs méthodes pour animer la
retrospective :

  * Demander à chaque membre de l'équipe de noter son ressenti sur une échelle
  de un à cinq, puis afficher et discuter des résultats,
  * Demander à chaque membre ce qui l'a rendu heureux, triste et malheureux et
  placer des post-its correspondants dans trois colonnes : « _Mad Sad Glad_ »,
  * Dresser cinq catégories d'actions pouvant être augmentées en fréquence,
  diminuées en fréquence, commencées, arrêtées ou conservées :  « _Starfish_ »,
  * Déterminer quelles actions vont être mises en œuvre immédiatement pour
  améliorer la situation. Celles-ci deviennent alors des _User Stories_.


VI. Planning Client
-------------------

Le _Planning Client_ consiste à mettre à jour le _Backlog Produit_ avec le
client.

Tout au long de l'application de la méthode Scrum, un _Kanban_ peut être établi
pour tracer quelles actions sont réalisées et par qui, et ainsi donner une idée
de ce qui prend le plus de temps. Cette méthode consiste à représenter les
tâches par des post-its et à les répartir dans un tableau de quatre colonnes :
« _Todo_, _In Progress_, _Review_, _Done_ ». Chaque post-it comprend :

  * La description de la tâche,
  * La personne qui l'effectue,
  * Les ressources nécessaires pour réaliser cette tâche,
  * Les conditions à satisfaire pour réaliser la tâche.

Les post-its sont déplacés de colonne en colonne suivant leur état d'avancement.
Une pastille de couleur peut être ajoutée sur un post-it à chaque fois que la
personne effectuant une tâche rencontre un problème.
