main = interact $ show' . f . map read . words

show' :: Bool -> [Char]
show' True = "YES"
show' False = "NO"

f :: [Int] -> Bool
f (x:y:xs) 
    |x >= y = True
    |otherwise = pd 0 0 y xs 0

pd :: Int -> Int -> Int -> [Int] -> Int -> Bool
pd k s n xs aux
    |k == length xs && aux == 0 = False
    |k == length xs && s == 0 = True
    |k == length xs = False
    |otherwise = pd (k + 1) s n xs aux || pd (k + 1) (mod (s + xs !! k) n) n xs 1
