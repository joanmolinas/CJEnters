###!
###! JOC DE PROVES CJ_ENTERS
###!
###!--------------------------------------------------------
###! Nota 1: Suposem que la implementacio mes extesa tin-
###!         dra  els elements  del conjunt  completament
###!         ordenats en tot moment, donat que aquesta es
###!         la mes eficient  respecte els  operadors  de
###!         conjunts (unir, intersectar i restar).
###!   [ * : Suponemos que la  implementacion mas  exten-
###!         dida tendra los elementos  del conjunto com-
###!         pletamente  ordenados en  cualquier momento,
###!         dado que esta es la mas eficiente respecto a
###!         los operadores de conjuntos (unir, intersec-
###!         tar y restar).]
###!
###! Nota 2: Aquest conjunt es d'enters, i per tant poden
###!         inserir-se  tant nombres  positius com nega-
###!         tius.
###!   [ * : Este conjunto  es de enteros, y por lo tanto
###!         pueden  insertarse  tanto numeros  positivos
###!         como negativos.]
###!
###! Nota 3: No es pot  comprovar  el comportament de les
###!         operacions min i  max  quan  el  conjunt  es
###!         buit, ja que aixo  no esta definit a l'espe-
###!         cificacio de la classe.
###!   [ * : No se  puede  comprobar el comportamiento de
###!         las operaciones min i max cuando el conjunto
###!         esta vacio, ya que  esto no esta definido en
###!         la especificacion de la clase.]
###!
###! Nota 4: L'operacio "conte"  sempre s'ha de provar
###!         doblement: amb  elements presents al conjunt
###!         i amb elements no presents al conjunt.
###!   [ * : La operacion "conte" siempre se tiene que
###!         probar doblemente: con elementos presentes y
###!         con elementos no presentes en el conjunto.]
###!
###! Nota 5: |A| indica la cardinalitat del conjunt A, es
###!         a dir, el nombre d'elements del conjunt A.
###!   [ * : |A| indica la cardinalidad del conjunto A, o
###!         sea, el numero de elementos del conjunto A.]
###!--------------------------------------------------------
###!
###!------------------------------
###1 Un element
###!------------------------------
###!
###!------------------------------
###1.1 Element positiu
###!------------------------------
###!
#init a cj_enters
#insereix 1
###!
#conte 2
false
##false
#conte -1
false
##false
#conte 0
false
##false
#conte 1
true
##true
#max
1
##1
#min
1
##1
#card
1
##1
###! inserim un element ja present
#insereix 1
###!
#conte 2
false
##false
#conte -1
false
##false
#conte 0
false
##false
#conte 1
true
##true
#max
1
##1
#min
1
##1
#card
1
##1
###!
###!
###!------------------------------
###1.2 Element negatiu
###!------------------------------
###!
#init a cj_enters
#insereix -1
###!
#conte 2
false
##false
#conte -1
true
##true
#conte 0
false
##false
#conte 1
false
##false
#max
-1
##-1
#min
-1
##-1
#card
1
##1
###! inserim un element ja present
#insereix -1
###!
#conte 2
false
##false
#conte -1
true
##true
#conte 0
false
##false
#conte 1
false
##false
#max
-1
##-1
#min
-1
##-1
#card
1
##1
###!
###!
###!
###!------------------------------
###2 Dos elements
###!------------------------------
###!
###!------------------------------
###2.1 El 2n s'insereix al principi
###!------------------------------
###!
#init b cj_enters
#insereix -1
#insereix -12
###!
#conte -1
true
##true
#conte 0
false
##false
#conte 1
false
##false
#conte -12
true
##true
#max
-1
##-1
#min
-12
##-12
#card
2
##2
###! inserim un element ja present
#insereix -12
###!
#conte -12
true
##true
#card
2
##2
###!
###!
###!------------------------------
###2.2 El 2n s'insereix al final
###!------------------------------
###!
#init b cj_enters
#insereix 12
#insereix 21
###!
#conte 21
true
##true
#conte 0
false
##false
#conte 1
false
##false
#conte 12
true
##true
#max
21
##21
#min
12
##12
#card
2
##2
###! inserim un element ja present
#insereix 21
###!
#conte 21
true
##true
#card
2
##2
###!
###!
###!
###!------------------------------
###3 Tres elementos
###!------------------------------
###!
###!------------------------------
###3.1 El 3o se insereix al principio
###!------------------------------
###!
#init c cj_enters
#insereix 12
#insereix 21
#insereix 1
###!
#conte 21
true
##true
#conte 0
false
##false
#conte 1
true
##true
#conte 12
true
##true
#max
21
##21
#min
1
##1
#card
3
##3
###! inserim un element ja present
#insereix 1
###!
#conte 1
true
##true
#card
3
##3
###!
###!
###!------------------------------
###3.2 El 3o se insereix al final
###!------------------------------
###!
#init c cj_enters
#insereix 12
#insereix 21
#insereix 17
###!
#conte 12
true
##true
#conte 0
false
##false
#conte 17
true
##true
#conte 21
true
##true
#max
21
##21
#min
12
##12
#card
3
##3
###! inserim un element ja present
#insereix 17
###!
#conte 17
true
##true
#card
3
##3
###!
###!
###!------------------------------
###3.3 El 3o se insereix en el medio
###!------------------------------
###!
#init c cj_enters
#insereix 12
#insereix 21
#insereix 121
###!
#conte 21
true
##true
#conte 12
true
##true
#conte 1
false
##false
#conte 121
true
##true
#max
121
##121
#min
12
##12
#card
3
##3
###! inserim un element ja present
#insereix 121
###!
#conte 121
true
##true
#card
3
##3
###!
###!
###!------------------------------
###4 Cinco Elementos
###!------------------------------
###!
#init d cj_enters
#insereix 12
#insereix 21
#insereix 121
#insereix -8
#insereix 21
#insereix 12
#insereix 119
###!
#conte 21
true
##true
#conte 12
true
##true
#conte 1
false
##false
#conte -8
true
##true
#conte 14
false
##false
#conte 119
true
##true
#conte 121
true
##true
#max
121
##121
#min
-8
##-8
#card
5
##5
###!
###!
###!
###!------------------------------
###5 Union
###!------------------------------
###!
###!------------------------------
###5.1 Union  |A| = |B| y elementos comunes
###!------------------------------
###!
###!------------------------------
###5.1.1 Union  |A| = |B| = 0
###! A = []
###! B = []
###! res = []
###!------------------------------
###!
#init a cj_enters
#init b cj_enters
###!
#b unir a
[]

##[]
#b conte 0
false
##false
#b conte -1
false
##false
#b conte 12
false
##false
#b card
0
##0
###!
###!------------------------------
###5.1.2 Union  |A| = |B| = 1
###! A = [12]
###! B = [12]
###! res = [12]
###!------------------------------
###!
#init a cj_enters
#a insereix 12
#init b cj_enters
#b insereix 12
###!
#b unir a
[12]

##[12]
#b max
12
##12
#b min
12
##12
#b card
1
##1
###!
###!------------------------------
###5.1.3 Union  |A| = |B| = 2
###! A = [12 13]
###! B = [12 13]
###! res = [12 13]
###!------------------------------
###!
#init a cj_enters
#insereix 13
#insereix 12
#init b cj_enters
#insereix 12
#insereix 13
###!
#b unir a
[12 13]

##[12 13]
#b max
13
##13
#b min
12
##12
#b card
2
##2
###!
###!
###!------------------------------
###5.1.4 Union  |A| = |B| = 3
###! A = [-13 12 13]
###! B = [-13 12 13]
###! res = [-13 12 13]
###!------------------------------
###!
#init a cj_enters
#insereix 13
#insereix -13
#insereix 12
#init b cj_enters
#insereix -13
#insereix 12
#insereix 13
#insereix -13
###!
#b unir a
[-13 12 13]

##[-13 12 13]
#b max
13
##13
#b min
-13
##-13
#b card
3
##3
###!
###!------------------------------
###5.1.5 Union  |A| = |B| = 5
###! A = [-13 12 13 43 60]
###! B = [-13 12 13 43 60]
###! res = [-13 12 13 43 60]
###!------------------------------
###!
#init a cj_enters
#insereix 13
#insereix -13
#insereix 12
#insereix 60
#insereix 43
#init b cj_enters
#insereix -13
#insereix 12
#insereix 13
#insereix -13
#insereix 60
#insereix 43
###!
#b unir a
[-13 12 13 43 60]

##[-13 12 13 43 60]
#b max
60
##60
#b min
-13
##-13
#b card
5
##5
###!
###!
###!------------------------------
###5.2 Union  |A| = |B| y elementos NO comunes
###!------------------------------
###!
###!------------------------------
###5.2.1 Union  |A| = |B| = 1
###! A = [12]
###! B = [15]
###! res = [12 15]
###!------------------------------
###!
#init a cj_enters
#insereix 12
#init b cj_enters
#insereix 15
###!
#b unir a
[12 15]

##[12 15]
#b max
15
##15
#b min
12
##12
#b card
2
##2
###!
###!------------------------------
###5.2.2 Union  |A| = |B| = 2
###! A = [12 15]
###! B = [15 19]
###! res = [12 15 19]
###!------------------------------
###!
#init a cj_enters
#insereix 15
#insereix 12
#init b cj_enters
#insereix 15
#insereix 19
###!
#b unir a
[12 15 19]

##[12 15 19]
#b max
19
##19
#b min
12
##12
#b card
3
##3
###!
###!------------------------------
###5.2.3 Union  |A| = |B| = 3
###! A = [12 15 19]
###! B = [-13 15 56]
###! res = [-13 12 15 19 56]
###!------------------------------
###!
#init a cj_enters
#insereix 15
#insereix 19
#insereix 12
#init b cj_enters
#b insereix 15
#b insereix -13
#b insereix 56
###!
#b unir a
[-13 12 15 19 56]

##[-13 12 15 19 56]
#b max
56
##56
#b min
-13
##-13
#b card
5
##5
###!
###!------------------------------
###5.2.4 Union  |A| = |B| = 5
###! A = [-13 12 15 19 56]
###! B = [34 43 45 60 98]
###! res = [-13 12 15 19 34 43 45 56 60 98]
###!------------------------------
###!
#init a cj_enters
#insereix 56
#insereix -13
#insereix 15
#insereix 19
#insereix -13
#insereix 12
#init b cj_enters
#b insereix 60
#b insereix 43
#b insereix 98
#b insereix 34
#b insereix 45
###!
#b unir a
[-13 12 15 19 34 43 45 56 60 98]

##[-13 12 15 19 34 43 45 56 60 98]
#b max
98
##98
#b min
-13
##-13
#b card
10
##10
###!
###!
###!------------------------------
###5.3 Union  |A| < |B|
###! Nota: Los casos en que los conjuntos tienen
###!       elementos comunes, y tienen elementos
###!       NO comunes estan mezclados.
###!------------------------------
###!
###!------------------------------
###5.3.1 Union  |A| = 0 y  |B| = 1
###! A = []
###! B = [11]
###! res = [11]
###!------------------------------
###!
#init a cj_enters
#init b cj_enters
#insereix 11
###!
#b unir a
[11]

##[11]
#b max
11
##11
#b min
11
##11
#b card
1
##1
###!
###!------------------------------
###5.3.2 Union  |A| = 0 y  |B| = 2
###! A = []
###! B = [4 11]
###! res = [4 11]
###!------------------------------
###!
#init a cj_enters
#init b cj_enters
#insereix 11
#insereix 4
###!
#b unir a
[4 11]

##[4 11]
#b max
11
##11
#b min
4
##4
#b card
2
##2
###!
###!------------------------------
###5.3.3 Union  |A| = 0 y  |B| = 3
###! A = []
###! B = [11 18 26]
###! res = [11 18 26]
###!------------------------------
###!
#init a cj_enters
#init b cj_enters
#insereix 26
#insereix 11
#insereix 18
###!
#b unir a
[11 18 26]

##[11 18 26]
#b max
26
##26
#b min
11
##11
#b card
3
##3
###!
###!------------------------------
###5.3.4 Union  |A| = 0 y  |B| = 5
###! A = []
###! B = [-11 0 2 7 11]
###! res = [-11 0 2 7 11]
###!------------------------------
###!
#init a cj_enters
#init b cj_enters
#insereix 11
#insereix 0
#insereix -11
#insereix 2
#insereix 7
###!
#b unir a
[-11 0 2 7 11]

##[-11 0 2 7 11]
#b max
11
##11
#b min
-11
##-11
#b card
5
##5
###!
###!------------------------------
###5.3.5 Union  |A| = 1 y  |B| = 2
###! A = [4]
###! B = [4 11]
###! res = [4 11]
###!------------------------------
###!
#init a cj_enters
#insereix 4
#insereix 4
#init b cj_enters
#insereix 11
#insereix 4
###!
#b unir a
[4 11]

##[4 11]
#b max
11
##11
#b min
4
##4
#b card
2
##2
###!
###!------------------------------
###5.3.6 Union  |A| = 1 y  |B| = 3
###! A = [12]
###! B = [11 44 87]
###! res = [11 12 44 87]
###!------------------------------
###!
#init a cj_enters
#insereix 12
#init b cj_enters
#insereix 87
#insereix 44
#insereix 11
#insereix 87
###!
#b unir a
[11 12 44 87]

##[11 12 44 87]
#b max
87
##87
#b min
11
##11
#b card
4
##4
###!
###!------------------------------
###5.3.7 Union  |A| = 1 y  |B| = 5
###! A = [4]
###! B = [1 4 11 44 87]
###! res = [1 4 11 44 87]
###!------------------------------
###!
#init a cj_enters
#insereix 4
#init b cj_enters
#insereix 11
#insereix 1
#insereix 4
#insereix 44
#insereix 87
###!
#b unir a
[1 4 11 44 87]

##[1 4 11 44 87]
#b max
87
##87
#b min
1
##1
#b card
5
##5
###!
###!------------------------------
###5.3.8 Union  |A| = 2 y  |B| = 3
###! A = [12 87]
###! B = [11 44 87]
###! res = [11 12 44 87]
###!------------------------------
###!
#init a cj_enters
#insereix 12
#insereix 87
#insereix 87
#init b cj_enters
#insereix 44
#insereix 11
#insereix 44
#insereix 87
###!
#b unir a
[11 12 44 87]

##[11 12 44 87]
#b max
87
##87
#b min
11
##11
#b card
4
##4
###!
###!------------------------------
###5.3.9 Union  |A| = 2 y  |B| = 5
###! A = [12 54]
###! B = [11 44 87 111 657]
###! res = [11 12 44 54 87 111 657]
###!------------------------------
###!
#init a cj_enters
#insereix 54
#insereix 12
#init b cj_enters
#insereix 11
#insereix 657
#insereix 11
#insereix 111
#insereix 44
#insereix 87
#insereix 657
#insereix 87
###!
#b unir a
[11 12 44 54 87 111 657]

##[11 12 44 54 87 111 657]
#b max
657
##657
#b min
11
##11
#b card
7
##7
###!
###!------------------------------
###5.3.10 Union  |A| = 3 y  |B| = 5
###! A = [11 44 87]
###! B = [11 14 30 44 87]
###! res = [11 14 30 44 87]
###!------------------------------
###!
#init a cj_enters
#insereix 11
#insereix 44
#insereix 87
#init b cj_enters
#insereix 14
#insereix 11
#insereix 30
#insereix 44
#insereix 87
###!
#b unir a
[11 14 30 44 87]

##[11 14 30 44 87]
#b max
87
##87
#b min
11
##11
#b card
5
##5
###!
###!
###!------------------------------
###5.4 Union  |A| > |B|
###! Nota: Los casos en que los conjuntos tienen
###!       elementos comunes, y tienen elementos
###!       NO comunes estan mezclados.
###!------------------------------
###!
###!------------------------------
###5.4.1 Union  |A| = 1 y  |B| = 0
###! A = [11]
###! B = []
###! res = [11]
###!------------------------------
###!
#init a cj_enters
#insereix 11
#init b cj_enters
###!
#b unir a
[11]

##[11]
#b max
11
##11
#b min
11
##11
#b card
1
##1
###!
###!------------------------------
###5.4.2 Union  |A| = 2 y  |B| = 0
###! A = [4 11]
###! B = []
###! res = [4 11]
###!------------------------------
###!
#init a cj_enters
#insereix 11
#insereix 4
#init b cj_enters
###!
#b unir a
[4 11]

##[4 11]
#b max
11
##11
#b min
4
##4
#b card
2
##2
###!
###!------------------------------
###5.4.3 Union  |A| = 2 y  |B| = 1
###! A = [4 11]
###! B = [4]
###! res = [4 11]
###!------------------------------
###!
#init a cj_enters
#insereix 11
#insereix 4
#init b cj_enters
#insereix 4
#insereix 4
###!
#b unir a
[4 11]

##[4 11]
#b max
11
##11
#b min
4
##4
#b card
2
##2
###!
###!------------------------------
###5.4.4 Union  |A| = 3 y  |B| = 0
###! A = [11 44 87]
###! B = []
###! res = [11 44 87]
###!------------------------------
###!
#init a cj_enters
#insereix 87
#insereix 44
#insereix 11
#insereix 87
#init b cj_enters
###!
#b unir a
[11 44 87]

##[11 44 87]
#b max
87
##87
#b min
11
##11
#b card
3
##3
###!
###!------------------------------
###5.4.5 Union  |A| = 3 y  |B| = 1
###! A = [11 44 87]
###! B = [12]
###! res = [11 12 44 87]
###!------------------------------
###!
#init a cj_enters
#insereix 87
#insereix 44
#insereix 11
#insereix 87
#init b cj_enters
#insereix 12
###!
#b unir a
[11 12 44 87]

##[11 12 44 87]
#b max
87
##87
#b min
11
##11
#b card
4
##4
###!
###!------------------------------
###5.4.6 Union  |A| = 3 y  |B| = 2
###! A = [11 44 87]
###! B = [12 87]
###! res = [11 12 44 87]
###!------------------------------
###!
#init a cj_enters
#insereix 44
#insereix 11
#insereix 44
#insereix 87
#init b cj_enters
#insereix 12
#insereix 87
#insereix 87
###!
#b unir a
[11 12 44 87]

##[11 12 44 87]
#b max
87
##87
#b min
11
##11
#b card
4
##4
###!
###!------------------------------
###5.4.7 Union  |A| = 5 y  |B| = 0
###! A = [1 4 11 44 87]
###! B = []
###! res = [1 4 11 44 87]
###!------------------------------
###!
#init a cj_enters
#insereix 11
#insereix 1
#insereix 4
#insereix 44
#insereix 87
#init b cj_enters
###!
#b unir a
[1 4 11 44 87]

##[1 4 11 44 87]
#b max
87
##87
#b min
1
##1
#b card
5
##5
###!
###!------------------------------
###5.4.8 Union  |A| = 5 y  |B| = 1
###! A = [1 4 11 44 87]
###! B = [4]
###! res = [1 4 11 44 87]
###!------------------------------
###!
#init a cj_enters
#insereix 11
#insereix 1
#insereix 4
#insereix 44
#insereix 87
#init b cj_enters
#insereix 4
###!
#b unir a
[1 4 11 44 87]

##[1 4 11 44 87]
#b max
87
##87
#b min
1
##1
#b card
5
##5
###!
###!------------------------------
###5.4.9 Union  |A| = 5 y  |B| = 2
###! A = [11 44 87 111 657]
###! B = [12 54]
###! res = [11 12 44 54 87 111 657]
###!------------------------------
###!
#init a cj_enters
#insereix 11
#insereix 657
#insereix 12
#insereix 11
#insereix 111
#insereix 44
#insereix 87
#insereix 12
#insereix 657
#insereix 87
#init b cj_enters
#insereix 54
#insereix 12
###!
#b unir a
[11 12 44 54 87 111 657]

##[11 12 44 54 87 111 657]
#b max
657
##657
#b min
11
##11
#b card
7
##7
###!
###!------------------------------
###5.4.10 Union  |A| = 5 y  |B| = 3
###! A = [11 14 30 44 87]
###! B = [11 44 87]
###! res = [11 14 30 44 87]
###!------------------------------
###!
#init a cj_enters
#insereix 14
#insereix 11
#insereix 30
#insereix 44
#insereix 87
#init b cj_enters
#insereix 87
#insereix 11
#insereix 44
#insereix 11
#insereix 87
###!
#b unir a
[11 14 30 44 87]

##[11 14 30 44 87]
#b max
87
##87
#b min
11
##11
#b card
5
##5
###!
###!
###!
[0/0]
