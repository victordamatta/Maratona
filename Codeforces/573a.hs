main = interact $ show' . eql . map red . tail . map read . words

red :: Integer -> Integer
red x
    |mod x 2 == 0 = red $ x `div` 2
    |mod x 3 == 0 = red $ x `div` 3
    |otherwise = x

eql :: Eq a => [a] -> Bool
eql x = and $ map (== head x) (tail x)

show' :: Bool -> [Char]
show' True = "Yes"
show' False = "No"
