--TLE on right solution?
import Data.List
import Data.Int

main = interact $ show . foo . tail . map read . words

foo (x:xs) = f x 0 0 0 0 (sort (pairing xs))

f :: Int64 -> Int64 -> Int64 -> Int -> Int -> [(Int64, Int64)] -> Int64
f d m n lo hi xs
    |hi == length xs = m
    |fst (xs !! hi) - fst (xs !! lo) >= d = f d  m    sub (next lo) hi       xs
    |otherwise                            = f d  max' add  lo      (next hi) xs
    where
        add = n + snd (xs !! hi)
        sub = n - snd (xs !! lo)
        max' = max m add
        next = (1+)

pairing :: [Int64] -> [(Int64, Int64)]
pairing [] = []
pairing (x:y:xs) = (x,y) : pairing xs
