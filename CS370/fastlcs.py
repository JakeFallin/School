def fast_LCS(S1, S2):
	def fast_LCS_helper(S1, S2, memo):
		if (S1, S2) in memo:
			return memo[(S1, S2)]
		if S1 == '' or S2 == '':
			result = 0
		elif S1[0] == S2[0]:
			result = 1 + fast_LCS_helper(S1[1:], S2[1:], memo)
		else:
			result = max(fast_LCS_helper(S1[1:], S2, memo), fast_LCS_helper(S1, S2[1:], memo))

		memo[(S1, S2)] = result
		return result
	return fast_LCS_helper(S1, S2, {})


def fast_LCS_with_values(S1, S2):
	def fast_LCS_helper(S1, S2, memo):
		if (S1, S2) in memo:
			return memo[(S1, S2)]
		if S1 == '' or S2 == '':
			result = (0, '')
		elif S1[0] == S2[0]:
			lose_both = fast_LCS_helper(S1[1:], S2[1:], memo)
			result = (1 + lose_both[0], S1[0] + lose_both[1])
		else:
			useS2 = fast_LCS_helper(S1[1:], S2, memo)
			useS1 = fast_LCS_helper(S1, S2[1:], memo)
			result = useS1 if useS1[0] > useS2[0] else useS2

		memo[(S1, S2)] = result
		return result


	return fast_LCS_helper(S1, S2, {})




print(fast_LCS_with_values("dshgfjadsghfkashdfkamdfkas", "asdgfjaskdfgasdkjfgankh"))