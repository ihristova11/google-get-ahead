#include <string>
#include <cassert>
#include <stack>

size_t longest_balanced(std::string str) {
	std::stack<size_t> stack;
	size_t longest = 0;
	size_t len = str.size();

	for (size_t i = 0; i < len; i++) {
		if (str[i] == '(') {
			stack.push(i);
		}
		else if (!stack.empty()) {
			size_t open_i = stack.top();
			size_t length = i - open_i + 1;
			stack.pop();
			if (length > longest) longest = length;
		}
	}
	return longest;
}


int main()
{
	assert(longest_balanced("(())") == 4);
	assert(longest_balanced("()(") == 2);
	assert(longest_balanced("())") == 2);
	assert(longest_balanced("()()") == 2);
	assert(longest_balanced("(()())") == 6);
	assert(longest_balanced("())(())") == 4);
	assert(longest_balanced(")(()))))(((()") == 4);
}