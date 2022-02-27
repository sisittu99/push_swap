# #42_tutorial: PUSH_SWAP
### L.I.S. algorithm (vers. 02/22)

### grade: 125/100

---------------------

### 🇮🇹 

Data la mancanza di spiegazioni del progetto attraverso l'utilizzo del **Longest Increasing Suqsequence algorithm** (trad. "algoritmo della maggiore sottosequenza crescente"), ho deciso di scrivere questo README per venire in soccorso a tutti quegli studenti che non hanno ben capito come implementarlo.

#### SUBJECT
Il progetto richiede di ordinare una qualsiasi sequenza di numeri interi, esattamente come fa un qualsiasi algoritmo Sort ideato e collaudato da almeno 60 anni.
Tuttavia, non stareste leggendo questo testo se non apparteneste ad un qualsiasi corso della 42 in giro per il mondo, ed è statisticamente appurato che la vostra probabilità di perdere capelli aumenta proporzionalmente al vostro leggere nuovi subject.
Quindi, senza alcun indugio, spieghiamo le particolarità delle richieste!


##### Le mosse
Abbiamo anzitutto due *stack*: una riempita dai numeri casuali dati, la "a", e una vuota che ci servirà da appoggio, la "b".
Le mosse a nostra disposizione sono 11, ma per semplicità le andremo a suddividere nelle 4 tipologie:

* sa 	/	sb	/	ss	: _**switch**_, scambia il primo numero della stack col secondo.
* ra	/	rb	/	rr	: ___rotate___, sposta l'ultimo numero della stack in prima posizione, facendo conseguentemente scalare tutti gli altri.
* rra	/	rrb	/	rrr	: ___reverse rotate___, banalmente la stessa cosa di cui sopra ma nel senso opposto.
* pa	/	pb			: ____push in *___, sposta il numero in prima posizione della stack opposta nella stack nominata. Quindi pb porta il primo numero da _a_ a _b_.

Non starò qui a spiegare per bene come funzionano e come vanno utilizzate, penso che a riguardo ci siano ottimi lavori scritti da colleghe e colleghi in giro per il mondo. Vi lascio un link che ha aiutato me e [il mio compagno di merende](https://github.com/fdrudi, "Go follow him!") durante il brainstorming iniziale.
Sappi che le sue istruzioni sono valide anche per il nostro progetto fino alla _size 3_ e _size 5_!

[Ecco a te!](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a, "Ce ne fosse di gente come lui *sigh*")

Il motivo per cui non abbiamo voluto seguire tutta la sua linea di pensiero è perché purtroppo a nostro parere non si può arrivare al massimo dei voti con una tecnica del genere, ma saremmo ben lieti di essere smentiti! Nel caso in cui il suo ragionamento vi piaccia di più, un altro ragazzo italiano ha pubblicato [questo codice molto simile e super ordinato](https://github.com/AlessandroMetta/push_swap) col quale ha ottenuto un ottimo voto di 90/100. 

_N.b.:	purtroppo senza il massimo dei voti, il bonus non verrà contato. 90/100 è praticamente il secondo miglior voto ottenibile. Vi conviene davvero clonare e pushare senza prima quantomeno provare a prendere qualcosa in più?_

Veniamo ora alla vera bestia di Satana di questo progetto: **il numero di mosse possibili.**
Se leggete approfonditamente il subject, non troverete comunque un riferimento a riguardo. Vi basta tuttavia sapere che per ottenere il massimo dei voti servono _700 mosse con 100 numeri_ e _5.500 mosse con 500 numeri_.



