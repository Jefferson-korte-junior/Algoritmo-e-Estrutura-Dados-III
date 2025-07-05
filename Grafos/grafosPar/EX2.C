// A) O grafo possui 11 Arestas.
// B) O grafo possui 7 vestices.
// C) Não, não é possível ir diretamente de DFW -> JFK, pois não há uma aresta de DFW -> JFK

// D) MIA -> LAX (diretamente) custa 611. Ja se for de MIA -> DFW -> LAX (custa 572) entao esse caminho sai mais barato.

// E) 
//     SFO LAX DFW ORD BOS JFK MIA
//SFO	0	0	0	0	0	0	0
//LAX	0	0	0	1	0	0	0
//DFW	0	1	0	1	0	0	0
//ORD	0	0	1	0	0	0	0
//BOS	0	0	0	0	0	1	1
//JFK	0	0	1	0	0	0	1
//MIA	0	1	1	0	0	0	0

// F)

//SFO → (nenhuma ligação)
//LAX → ORD
//DFW → LAX, ORD
//ORD → DFW
//BOS → JFK, MIA
//JFK → DFW, MIA
//MIA → LAX, DFW

//G)
