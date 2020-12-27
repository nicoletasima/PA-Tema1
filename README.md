		README TEMA 1 PROIECTAREA ALGORITMILOR
		Sima Nicoleta-Lavinia

	PROBLEMA 1:
	Primul set de instructiuni: Pentru fiecare bancnota pusa la dispozitie
exista alte 2 bancnote care pot urma dupa si deoarece sunt 5 bancnote care pot fi
utilizate, am ajuns la concluzia ca problema se poate rezolva folosind formula
5 * (2 ^ N), unde N reprezinta numarul de bancnote pe care Gigel trebuie sa le 
aseze. Pentru deducerea formulei am urmarit si exemplul din enunt. Functia pe care
am folosit-o pentru rificarea la putere a numerelor este cea pe care am implementat-o
in cadrul laboratorului de Divide et Impera si are are complexitatea O(log(exponent)).
Principiul se bazeaza pe verificarea paritatii exponentului. Retin rezultatul in
variabila res si folosesc restul impartirii la 1000000007 pentru numerele foarte 
mari si 1LL pentru a nu genera overflow. Aplic recursiv functia pana cand exponentul
devine 1.
	Al doilea set de instructiuni: Bancnota de 200 de lei poate fi urmata
acum si de bancnota de 100 de lei pe langa cele doua de la primul set. Am
inceput rezolvarea prin urmarirea exemplului din enunt si asa am ajuns
la concluzia ca pot genera bancnotele pana la N pe baza numarului anterior 
de bancnote. Cazul de baza este pentru N = 1, caz in care exista 5 modalitati
de le aranja, adica se ia fiecare o singura data. Pentru N = 2, am observat
ca daca la fiecare bancnota se adauga bancnotele care pot urma se formeaza
noi posibilitati de le aranja. Fiecare grup anterior se extinde deci pe 
baza regulilor de completare pana cand vor exista grupuri formate din cate N
bancnote. O reprezentare a modului in care am gandit problema ar fi urmatoarea:

	10	 50	 100	  200	     500      	N = 1
       / \      / \      / \     / |  \      / \
      50 100   10 200   10 100  50 100 500  10  200     N = 2

Adunand numarul de bancnote de pe ultimul nivel se obtine numarul de
moduri in care pot fi asezate cele N bancnote. Am retinut numarul de bancnote
de la ultimul pas in vectori incepand cu cazul de baza si l-am 
completat conform regulilor pana la elementul N. Adunand elementele
de pe pozitia N din fiecare vector, se obtine rezultatul. 
Complexitatea obtinuta este: O(n).

	PROBLEMA 2:
	Problema 2 este e problema de tip Greedy si prin urmare am ales
sa adaug perechile de coordonate ale bucatilor de gard intr-un vector
de structuri. Am ordonat vectorul crescator in functie de coordonata xStart,
iar daca acestea erau egale pentru cele 2 elemente ordonate, am ordonat
descrescator in functie de coordonata xEnd pentru a curpinde o bucata 
cat mai mare din gard. Retin numarul de bucati de gard in variabila del, 
iar variabila index retine ultima bucata de gard asezata corect.
In implementare am parcurs vectorul de coordonate si in momentul in care 
o bucata de gard era cuprinsa in alta bucata, adica coordonata de start
era mai mare decat cea precedenta, iar cea de end mai mica, inseamna
ca trebuie sa fie eliminata. Deci variabila del se incrementeaza, iar 
variabila index este actualizata. 
Complexitatea obtinuta: O(N), unde N reprezinta numarul elemente
din vectorul in care retin coordonatele.

	PROBLEMA 3:
	Pentru problema 3 am considerat o rezolvare prin metoda
programare dinamica. Am adaugat intr-un vector capetele intervalelor in care
se regasesc problemele rezolvate de catre cei N elevi. Cazul de baza este 
pentru un singur elev, caz in care cele M bomboane pot fi impartite
intr-un singur mod daca numarul lor se afla intrvalul problemelor
rezolvate de elev. Pentru cazul general am considerat o matrice cu
N + 1 linii si M + 1 coloane. Linia si coloana 0 sunt completate cu valoarea 0.
Pentru a completa linia i, parcurg coloanele de la inceputul intervalului
si pana la suma maxima M pe care trebuie sa o obtin. Daca sfarsitul
intervalului este mai mare decat numarul maxim, actualizez intervalul.
Parcurg de fiecare data intervalul si reconstitui toate modurile in care
se poate obtine suma j adunand elementele de pe coloanele j-b...j-a
(luand in considerare diferentele pozitive) apartinand liniei i-1.
Rezultatul este reprezentat de elementul de pe ultima linie, 
ultima coloana a matricii. 
Complexitatea obtinuta: O(N * M ^ 2), unde N este numarul de elevi si 
M este numarul de bomboane.



