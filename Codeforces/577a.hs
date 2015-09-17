main = interact $ show . length . (\(x:y:_) -> [a | a <- [1..x], mod y a == 0, div y a <= x]) . map read . words
