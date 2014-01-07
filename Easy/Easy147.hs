validScoreNoSafeties :: Int -> String
validScoreNoSafeties v
	| v > 5 = "Valid Score"
	| v == 3 = "Valid Score"
	| otherwise = "Invalid Score"

validScoreWithSafeties :: Int -> String
validScoreWithSafeties v
	| v == 1 = "Invalid Score"
	| otherwise = "Valid Score"
