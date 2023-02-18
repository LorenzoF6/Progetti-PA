module Tree where

-- Definizione del tipo di dato Albero
data Tree a = Empty | Node a (Tree a) (Tree a)  deriving (Eq,Show)

--INSERIMENTO E RIMOZIONE DI ELEMENTI NELL'ALBERO
--Inserisce un elemento nell'albero
--Caso base: se si inserisce x nell'albero vuoto, si ottiene un albero che contiene solo x
--Passo induttivo: 
-- x == a : l'albero è invariato e come = si ha l'espressione che ricostruisce lo stesso albero
-- x < a : elemento più piccolo della radice, si continua la ricerca per l'inserimento nel sotto-albero sinistro
-- x > a : caso duale
insert :: Ord a => a -> Tree a -> Tree a
insert x Empty = Node x Empty Empty
insert x (Node a left right)
    | x == a = Node x left right
    | x <  a = Node a (insert x left) right
    | x >  a = Node a left (insert x right)

--Rimuove un elemento presente nell'albero
--Caso base: gestisce situazione di albero vuoto (1)
--Casi di rimozione dell'elemento che più piccolo/grande di quello che si trova nella radice:
--in questi casi la radice n soppravvive mentre x viene cercato e rimosso in uno dei due sotto-alberi
--a seconda della sua relazione con la radice (2)
--Casi in cui l'elemento da rimuovere si trova nella radice:
--(3) gestisce i casi in cui uno dei due sotto-alberi è vuoto  
--(5) gestisce il caso in cui nessun sotto-albero è vuoto:
--in questo caso come nuova radice si sceglie l'elemnto più grande nell'sotto-albero sinistro
delete :: Ord a => a -> Tree a -> Tree a
delete _ Empty = Empty --(1)
delete x (Node n left right) --(2)
   | x < n = Node n (delete x left) right
   | x > n = Node n left (delete x right)
delete x (Node _ t Empty) = t --(3.1)
delete x (Node _ Empty t) = t --(3.2)
delete x (Node _ left right)  = Node n (delete n left) right --(5)
  where
    n = maxElem left

--Genera un albero a partire da una List fornita in Input
--Si assume che il primo elemento della lista sia la testa dell'albero
--Caso base: lista vuota in input, crea un albero vuoto
--Passo induttivo: 
--per l'elemento x (la testa) della lista xs, genera un albero avente
--Node l'elemento x
--sotto-albero sinitro gli elementi <x presenti in xs (tramite funzione filter)
--sotto-albero destro gli elementi >x presenti in xs (tramite funzione filter)
treeFromList :: Ord a => [a] -> Tree a
treeFromList [] = Empty
treeFromList (x:xs) = Node x (treeFromList (filter (<x) xs)) (treeFromList (filter (>x) xs)) 

--INFORMAZIONI DI BASE SULL'ALBERO
--Restituisce l'altezza dell'albero
depth :: Tree a -> Int
depth Empty = 0
depth (Node _ left right) = 1 + max (depth left) (depth right)

--Restituisce il numero di nodi dell'albero
size :: Tree a -> Int
size Empty = 0
size (Node a left right) = 1 + size left + size right

--Verifica se un albero è vuoto
isEmpty :: Tree a -> Bool
isEmpty Empty = True
isEmpty _    = False

--Restituisce il numero delle foglie
leafNumb :: Tree a -> Int
leafNumb Empty = 0
leafNumb (Node x Empty Empty) = 1
leafNumb (Node x left right) = leafNumb left + leafNumb right


--VISTA E RICERCA NELL'ALBERO 
--Visita anticipata dell'albero
anticipatedVisit :: Tree a -> [a]
anticipatedVisit Empty = []
anticipatedVisit (Node x left right) = [x] ++ anticipatedVisit left ++ anticipatedVisit right

--Visita simmetrica dell'albero
symmetricalVisit :: Tree a -> [a]
symmetricalVisit Empty = []
symmetricalVisit (Node x left right) = symmetricalVisit left ++ [x] ++ symmetricalVisit right

--Ricerca di un elemento nell'albero
searchElem :: Ord a => a -> Tree a -> Bool
searchElem x Empty = False
searchElem x (Node a left right)
    | x == a = True
    | x <  a = searchElem x left
    | x >  a = searchElem x right

--Si sfrutta il tipo Maybe = Just | Nothing, il quale incapsula un valore facoltativo
--Un valore di tipo Maybe a contiene una valore di tipo a, caso di Just a, oppure è vuoto, caso Nothing
--Maybe gestisce casi eccezzionali, come in questo caso la gestione della ricerca di un elemento in un albero vuoto
--Ricerca valore Max nell'albero
maxElem :: Tree a -> Maybe a
maxElem Empty = Nothing 
maxElem (Node x _ Empty) = Just a
maxElem (Node _ _ t)    = maxElem t

--Ricerca valore Min nell'albero
minElem :: Tree a -> Maybe a
minElem Empty = Nothing
minElem (Node x Empty _) = Just x
minElem (Node _ t _)    = minElem t


--ALTRE OPERAZIONI
--Verifica che un albero è un albero binario
--Caso base: un albero vuoto è sempre binario
--Passo induttivo
--chiamata ricorsiva sui sotto-alberi sinistro e destro verificando che:
--sotto-albero sinistro: sia vuoto oppure ogni x è minore dell'elemento massimo
--sotto-albero destro: sia vuoto oppure ogni x è maggiore dell'elemento minore
isBinaryTree :: Ord a => Tree a -> Bool
isBinaryTree Empty = True
isBinaryTree (Node x left right) = isBinaryTree left && isBinaryTree right 
                                   && (isEmpty left || maxElem left < x) 
                                   && (isEmpty right || x < minElem right)
                                                         
--Visualizzazione dell'albero
--(1) stampa sullo standard output della lista contenente la struttura dell'albero
--(2) costruzione in modo ricorsivo della struttura dell'albero
printTree :: Show a => Tree a -> IO ()
printTree = (mapM_ putStrLn) . treeIndent (1)
  where 
    treeIndent Empty = ["-- /-"] (2)
    treeIndent (Node x left right) = ["--" ++ (show x)] ++ map ("  |" ++) l ++ ("  `" ++ r) : map ("   " ++) rs (2)
      where
        (r:rs) = treeIndent $ right
        l      = treeIndent $ left



--TEST 
--Main di prova per testare il modulo Tree.hs
{--main = do
       let bst
--}
