main = interact $ show . foo 0 0 . tail . map read . words

foo :: Int -> Int -> [Int] -> Int
foo a b [x] = max a (b + 1)
foo a b (x:xs)
    |x <= head xs = foo a (b + 1) xs
    |otherwise = foo (max a (b + 1)) 0 xs
