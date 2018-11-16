let pal = {
	palindromeChecker(palindrome) {
		palindrome = palindrome.toLowerCase();
		palindrome = palindrome.replace(/[^0-9a-z]/gi,'');
		palindrome = palindrome.replace(/\s+/g, '');

		let j = palindrome.length - 1;
		for(let i = 0; i < palindrome.length; i++) {
			if(palindrome[i] != palindrome[j]) {
				return false;
			}
			j--;
		}
		return true;
	}
}
module.exports = pal;