import Data.List
main = interact $ show . foo . tail . map read . words

foo :: [Int] -> Int
foo x
    |(head x) == (maximum x) && not (elem (head x) (tail x)) = 0
    |otherwise = 1 + (foo $ (1 + head x) : (bar (maximum x) (tail x)))
        where
            bar a [] = []
            bar a as
                |a == head as = a - 1 : tail as
                |otherwise = (head as) : bar a (tail as)
