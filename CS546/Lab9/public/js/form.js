(function () {
    const Palindrome = {
        isPalindrome(text) { 
        	if(!text)
        		throw "No text inputted";
            text = text.toLowerCase();
			text = text.replace(/[^0-9a-z]/gi,'');
			text = text.replace(/\s+/g, '');
            let j = text.length - 1;
			for(let i = 0; i < text.length; i++) {
				if(text[i] != text[j]) {
					return false;
				}
			j--;
			}
		return true;
		}	
    }
    

    const static = document.getElementById('static-form');

    if(static) {
        const user = document.getElementById('input-text');
        const error = document.getElementById('error-container');
        const errorText = error.getElementsByClassName('text-goes-here')[0];
        const result = document.getElementById('result-container');
        const resultText = document.getElementById('attempts');

        static.addEventListener('submit', event => {
            event.preventDefault();
            try {
                error.classList.add('hidden');
                result.classList.add('hidden');
                const value = user.value;
                const li = document.createElement('li');
                li.appendChild(document.createTextNode(value));
                if (Palindrome.isPalindrome(value))
                    li.setAttribute('class', 'is-palindrome');
                else
                    li.setAttribute('class', 'not-palindrome');
                resultText.appendChild(li);
                result.classList.remove('hidden');
            } catch (e) {
                const message = typeof e === "string" ? e : e.message;
        		errorText.textContent = e;
        		error.classList.remove("hidden");
            }
        })
    }
})();
