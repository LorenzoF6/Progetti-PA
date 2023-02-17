module Tree where

-- Definizione del tipo di dato Albero
data Tree a = Empty | Node a (Tree a) (Tree a)  deriving (Ord,Eq,Show)

--INSERIMENTO E RIMOZIONE DI ELEMENTI NELL'ALBERO
--Inserisce un elemento nell'albero
insert :: (Ord a) => a -> Tree a -> Tree a
insert x Empty = Node x Empty Empty
insert x (Node a left right)
    | x == a = Node x left right
    | x <  a = Node a (insert x left) right
    | x >  a = Node a left (insert x right)

--Rimuove un elemento presente nell'albero
delete :: Ord a => a -> Tree a -> Tree a
delete _ Empty = Empty
delete x (Node n left right)
   | x < n = Node n (delete x left) right
   | x > n = Node n left (delete x right)
delete x (Node _ t Empty) = t
delete x (Node _ Empty t) = t
delete x (Node _ left right)  = Node n (delete n left) right
  where
    n = maxElem left

--Genera un albero a partire da una List fornita in Input
--Si assume che il primo elemento della lista sia la testa dell'albero
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
searchElem :: (Ord a) => a -> Tree a -> Bool
searchElem x Empty = False
searchElem x (Node a left right)
    | x == a = True
    | x <  a = searchElem x left
    | x >  a = searchElem x right

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
isBinaryTree :: Ord a => Tree a -> Bool
isBinaryTree Empty = True
isBinaryTree (Node x left right) = isBinaryTree left && isBinaryTree right 
                                   && (isEmpty left || maxElem left < x) 
                                   && (isEmpty right || x < minElem right)
                                                         
--Visualizzazione dell'albero
printTree :: Show a => Tree a -> IO ()
printTree = (mapM_ putStrLn) . treeIndent
  where
    treeIndent Empty = ["-- /-"]
    treeIndent (Node x left right) = ["--" ++ (show x)] ++ map ("  |" ++) l ++ ("  `" ++ r) : map ("   " ++) rs
      where
        (r:rs) = treeIndent $ right
        l      = treeIndent $ left


--BILANCIAMENTO DELL'ALBERO
-- Quicksort
sort :: (Ord a) => [a] -> [a]
sort [] = []
sort (e:xs) = sort [x | x <- xs, x <= e] ++ [e] ++ sort [x | x <- xs, x > e]

-- Middle item of list
middle :: [a] -> [a]
middle [] = []
middle xs = xs !! midPos : []
  where midPos = length xs `div` 2

-- Balanced list from unbalanced list
balancedList :: (Ord a) => [a] -> [a]
balancedList [] = []
balancedList xs = [m] ++ left ++ right
  where 
    m = head . middle $ xs
    left = balancedList [x | x <- xs, x < m]
    right = balancedList [x | x <- xs, x > m]

-- Balanced tree from unbalanced tree
balance :: (Ord a) => Tree a -> Tree a
balance Empty = Empty
balance tree = fromList . balancedList . toList $ tree


--TEST 
--Main di prova per testare il modulo Tree.hs
{--main = do
       let bst
--}



























