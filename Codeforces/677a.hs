main = interact $ show . f . tail . map read . words

f :: [Int] -> Int
f (b : xs) = sum (map (\x -> if x > b then 2 else 1) xs)
