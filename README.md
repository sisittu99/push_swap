### #42_tutorial: PUSH_SWAP
### L.I.S. algorithm (vers. 02/22)
grade: 125/100

# 🇬🇧🇺🇸
Looking for a translated version? Just [click here!](https://github.com/sisittu99/push_swap/blob/master/README_EN.md)

 # 🇮🇹 

Data la mancanza di spiegazioni del progetto attraverso l'utilizzo del **Longest Increasing Suqsequence algorithm** (trad. "algoritmo della maggiore sottosequenza crescente"), ho deciso di scrivere questo README per venire in soccorso a tutti quegli studenti che non hanno ben capito come implementarlo.
1. [Il subject](https://github.com/sisittu99/push_swap#il-subject)
2. [Le mosse](https://github.com/sisittu99/push_swap#le-mosse)
3. [L'algoritmo L.I.S.](https://github.com/sisittu99/push_swap#lalgoritmo-lis)
4. [L'ordinamento e l'ottimizzazione](https://github.com/sisittu99/push_swap#lordinamento-e-lottimizzazione)
- [Il calcolo delle mosse](https://github.com/sisittu99/push_swap#il-calcolo-delle-mosse)
- [La scelta del numero](https://github.com/sisittu99/push_swap#la-scelta-del-numero)
5. [Conclusione codice](https://github.com/sisittu99/push_swap#conclusione-codice)

# Il subject
Il progetto richiede di ordinare una qualsiasi sequenza di numeri interi, esattamente come fa un qualsiasi algoritmo Sort ideato e collaudato da almeno 60 anni.
Tuttavia, non stareste leggendo questo testo se non apparteneste ad un qualsiasi corso della 42 in giro per il mondo, ed è statisticamente appurato che la vostra probabilità di perdere capelli aumenta proporzionalmente al vostro leggere nuovi subject.
Quindi, senza alcun indugio, spieghiamo le particolarità delle richieste!

## Le mosse
Abbiamo anzitutto due *stack*: una riempita dai numeri casuali dati, lo _stack_a_, e una vuota che ci servirà da appoggio, la _stack_b_.

Le stack **non** hanno una definizione obbligatoria! Noi abbiamo lavorato a liste per ovviare al fatto che gli array di `int` non hanno un termine nullo di conclusione col quale contarne la lunghezza. 
Altre idee che abbiamo sentito da colleghi sono quelle di lavorare a strutture, con i due array accompagnati dalle loro size ed eventualmente da altri array di appoggio per i vostri calcoli successivi. Personalmente mi sento di dissuadervi da questa idea semplicemente per non dover gestire troppe allocazioni, ma lascio al vostro giudizio la decisione. Dopotutto, quello che conta è il risultato!

Le mosse a nostra disposizione sono 11, ma per semplicità le andremo a suddividere nelle 4 tipologie:

* `sa` 	/	`sb`	/	`ss`	: _**switch**_, scambia il primo numero della stack col secondo.
* `ra`	/	`rb`	/	`rr` 	: ___rotate___, sposta l'ultimo numero della stack in prima posizione, facendo conseguentemente scalare tutti gli altri.
* `rra`	/	`rrb`	/	`rrr`	: ___reverse rotate___, banalmente la stessa cosa di cui sopra ma nel senso opposto.
* `pa`	/	`pb`			: ____push in *___, sposta il numero in prima posizione della stack opposta nella stack nominata. Quindi pb porta il primo numero da _a_ a _b_.

Non starò qui a spiegare per bene come funzionano e come vanno utilizzate, penso che a riguardo ci siano ottimi lavori scritti da colleghe e colleghi in giro per il mondo. Vi lascio un link che ha aiutato me e [il mio compagno di merende](https://github.com/fdrudi "Go follow him!") durante il brainstorming iniziale.
Sappi che le sue istruzioni sono valide anche per il nostro progetto fino alla _size 3_ e _size 5_. [Ecco a te!](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a "Ce ne fosse di gente come lui *sigh*")

Il motivo per cui non abbiamo voluto seguire tutta la sua linea di pensiero è perché purtroppo a nostro parere non si può arrivare al massimo dei voti con una tecnica del genere, ma saremmo ben lieti di essere smentiti! Nel caso in cui il suo ragionamento vi piaccia di più, un altro ragazzo italiano ha pubblicato [questo codice molto simile e super ordinato](https://github.com/AlessandroMetta/push_swap) col quale ha ottenuto un ottimo voto di 90/100. 

> N.b.:	purtroppo senza il massimo dei voti, il bonus non verrà contato. 90/100 è praticamente il secondo miglior voto ottenibile. Vi conviene davvero clonare e pushare senza prima quantomeno provare a prendere qualcosa in più?

Veniamo ora alla vera bestia di Satana di questo progetto: **il numero di mosse possibili.**
Se leggete approfonditamente il subject, non troverete comunque un riferimento a riguardo. Vi basta tuttavia sapere che per ottenere il massimo dei voti servono _700 mosse con 100 numeri_ e _5.500 mosse con 500 numeri_. Abbiamo stimato un 58% di bestemmie sul progetto dedicate soltanto alla loro ottimizzazione.
Noi abbiamo agito così.

# L'algoritmo L.I.S.

L'idea di fondo è particolarmente semplice ma non altrettanto facile da pensare senza aiuti da parte di altri.
Per chi è particolarmente bravo in matematica, la logica è molto simile a quella dei sottoinsiemi ordinati. Per tutti gli altri, partiamo dall'analisi del nome dell'algoritmo:
* _longest_: fin qui tutto ok, no?
* _increasing_: letteralmente _"crescente"_
* _subsequence_: sottosequenza, ossia un gruppo di numeri presi dall'insieme totale, solitamente (ma non necessariamente) con un criterio matematico.

Banalmente, significa che tra tutte le possibili sottosequenze o combinazioni dobbiamo prenderne una ___ordinata___ in maniera ___crescente___, in particolare ___la più lunga di tutte!___



Facciamo un esempio: abbiamo una serie di numeri casuali come

```4 - 8 - 2 - 9 - 12 - 1 - 27 - 13 - 32 - 10```

Di questi, una _sottosequenza crescente_ può benissimo essere `4 - 8 - 9`, `2 - 9 - 13 - 32` o anche `1 - 10`.
Il nostro obiettivo tuttavia è  quello di prendere la più lunga possibile, in questo caso:

`4 - 8 - 9 - 12 - 27 - 32` oppure `4 - 8 - 9 - 12 - 13 - 32`. 

Le due sottosequenze sono equivalenti in quanto entrambe sono lunghe 6.
> Fate caso al mantenimento dell'ordine iniziale! Non possiamo prima mescolare i numeri e poi prenderci i valori che più ci piacciono, o avremmo già ordinato tutto e il nostro lavoro sarebbe finito...

Non è mio compito qui spiegarvi come implementare il codice, l'idea di fondo di fatto è lunga 4 righe di codice (che vi lascio qui sotto) ma il grosso viene nel prendersi tutti i valori desiderati.
I due cicli necessari sono:

```
for (int i = 1; i < n; i++) 
{
	lis[i] = 1;
	for (int j = 0; j < i; j++)
	{
		if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			lis[i] = lis[j] + 1;
	}
}
```

Per aiutarvi nella comprensione dell'algoritmo, vi lascio [il link di GeeksForGeeks](https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/ "Spulciatevi anche i video!") che ci ha aiutato a capire la logica dietro. Prestate attenzione al fatto che loro ritornano soltanto la grandezza massima della sottosequenza...

Una volta trovata la sequenza ordinata, vi rimane soltanto da tenervela sulla _stack_a_ e da portare tutti gli altri numeri sulla _stack_b_.

A fine lavoro vi risulterà una struttura simile:

<img width="769" alt="Screen Shot 2022-02-28 at 11 53 26" src="https://user-images.githubusercontent.com/92301111/155971088-9a4ea247-8a76-4d11-958c-4bca2424fef5.png">

> Ancora non vi ho parlato del visualizer? [Vi tornerà molto utile a fine stesura del codice...](https://github.com/o-reo/push_swap_visualizer)

# L'ordinamento e l'ottimizzazione

Nei passaggi precedenti non ho esternato il motivo per cui cominciamo il progetto calcolando il LIS. Nel caso non lo abbiate capito, l'obiettivo è quello di inserire tutti gli altri numeri in uno stack già ordinato, seppur non completo! Questo ci permette infatti di effettuare scambi tra lo _stack_a_ e lo _stack_b_ soltanto una volta, per poi chiudere subito l'ordinamento.
Il modo per spostare i numeri puó essere uno soltanto: spostare il primo numero della _stack_b_ di fronte al numero successivamente maggiore dello _stack_a_, che dovrà essere obbligatoriamente messo in prima posizione nello stesso.

Abbiamo tuttavia un problema non banale: inserire sempre il primo numero della _stack_b_ nella _stack_a_ fa roteare quest'ultima a vuoto troppe volte, aumentando esponenzialmente le mosse. 
> Vi basti sapere che l'algoritmo più banale possibile supera abbondantemente le 100.000 mosse con 500 numeri...
Quindi, come ottimizzare?

La nostra soluzione è molto a rischio di TLE (lett. _Time Limit Exceeded_), siamo consapevoli che esistono soluzioni più veloce e meno rischiose, ma siamo estremamente certi che a livello teorico-pratico funzioni e che permetta una delle migliori ottimizzazioni su tutte le possibili.
Ma prima, forse è meglio prendersi una pausa, che ne dici?


![gerry scotti caffè borbone](https://user-images.githubusercontent.com/92301111/157418321-9fbdbced-83e1-4565-8a45-ed56c204daa3.jpeg)
## Il calcolo delle mosse

Se state immaginando una quindicina di funzioni da scrivere dopo questo titolo, probabilmente avete sottostimato il lavoro che avete ancora di fronte.

Non c'è molto da fare: dovete calcolarvi per ogni numero quante mosse dovete fare nel migliore dei casi. Abbiamo ragionato così:

1. Create due array di appoggio (`mov_a` e `mov_b` possono andare benissimo!) dove salvare i valori di cui sotto 😉 Entrambi devono avere dimensione `size_b`: infatti i numeri da salvarsi sono riferiti unicamente ai numeri nella _stack_b_. Mi spiego peggio: siccome il nostro obiettivo è riportare tutti i numeri di _b_ nella _a_, dobbiamo calcolare quante mosse dobbiamo fare sia per muovere il numero di _b_ in prima posizione, sia per muovere lo _stack_a_ in modo tale da poter inserire correttamente il numero di _b_. Conseguentemente, ad ogni numero di b corrisponde _non solo_ un tot di mosse per arrivare in prima posizione ed applicare quindi `pa`, _ma anche_ un tot di mosse per mettere in prima posizione il numero corretto di _a_, tale per cui con l'inserimento del numero di _b_ la _stack_a_ rimanga ordinata.
2. Cominciamo quindi a fare i nostri calcoli: si prende la _stack_b_ e **si calcola la distanza** di ogni numero dalla prima posizione. Banalmente, a seconda che loro si trovino sopra o sotto la posizione `size_b / 2`, si utilizzeranno le mosse `rb` o `rrb`. Il valore assegnato sarà positivo se bisogna utilizzare `rb`, negativo se bisogna utilizzare `rrb`. 
3. si trova nello _stack_a_ il numero _immediatamente maggiore_ a quello preso in considerazione nello _stack_b_. Aiutatevi col presupposto che **lo _stack_a_ è già ordinato!** Trovate la coppia per il quale `mov_a[i] < mov_b[j] < mov_a[i + 1]` e mettete `mov_a[i + 1]` in prima posizione. Esempio: se abbiamo da inserire un `5` in uno _stack_a_ uguale a `3 - 8 - 19 - 25`, sarà l'`8` ad andare in prima posizione.
4. si calcola lo stesso valore del passaggio 2, ma riguardante `mov_a[i + 1]`.

Vi porto un esempio pragmatico più complesso, preso da una simulazione reale in cui avevo 7 numeri sullo _stack_b_ e più di 12 numeri sullo _stack_a_:
```
MOV_A   MOV_B
4       0
-5      1
3       2
-1      3
0       -3
4       -2
-5      -1
```
La colonna B indica la distanza di ogni numero di _stack_b_, mentre la colonna A indica la distanza del numero di _stack_a_ immediatamente maggiore al suo corrispondente in _b_. Vediamo ora come arrivare all'atto pratico!

## La scelta del numero

Ok, sappiamo tutte le mosse per ogni numero che abbiamo nella stack_b. Ma quale prendiamo?
La risposta dipende dalle casistiche, a seconda del senso di rotazione del vettore:
```
	|	mov_b +		|	mov_b -
--------|-----------------------|-----------------------
mov_a +	|   max(mov_a, mov_b)	|   mov_a + |mov_b|
--------|-----------------------|-----------------------
mov_a -	|  |mov_a| + mov_b	|  |min(mov_a, mov_b)|
```
> Prendo per assodato che ricordiate il valore assoluto...

In tutti e quattro i casi, il valore rilasciato altro non è che il numero totale di mosse che dovete fare prima di `pa`!

Ma prima occorre sottolineare perché sia necessario prendere il massimo o il minimo dei due valori nel caso dello stesso segno per i due numeri. Se vogliamo ottimizzare al meglio il codice, dobbiamo per forza usufruire delle mosse `rr` e `rrr`, che con una sola riga di output effettuano la rotazione ad entrambi gli stack. Va da sé che dividere per 2 le mosse è un guadagno di tempo che non possiamo lasciarci sfuggire...

Riprendendo quindi l'esempio di cui alla sezione sopra, va da sé che `4   0` diventa meno conveniente di `3   2`, in quanto per il primo si eseguono 4 mosse mentre per il secondo 3.

Ovviamente tutti questi calcoli vanno ripetuti `size_b` volte!


# Conclusione codice

Una volta effettuate tutte le mosse `pa` possibili, dovreste ritrovarvi in una situazione simile in cui il vettore è ordinato ma non comincia nella giusta posizione:

<img width="773" alt="Screen Shot 2022-02-28 at 14 45 02" src="https://user-images.githubusercontent.com/92301111/155993619-4d3da32d-d4fe-458d-9d80-c39f8e6c8e9e.png">

Ricordatevi di minimizzare le mosse anche qui! O rischierete di perdervi qualche centinaio di mosse nell'ultima parte.

***

Il nostro progetto è così concluso! Fatemi sapere se avete problemi o suggerimenti, sarò ben lieto di discuterne con voi su Slack (@mcerchi) o [via mail](mailto:mcerchi@student.42roma.it).
