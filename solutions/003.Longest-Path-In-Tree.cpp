#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct tree
{
	int value;
	vector<tree> children;
};

int longest_path(
	const tree& current,
	int parent_value, 
	int current_chain, 
	int longest)
{
	if (current.value == parent_value + 1)
	{
		current_chain++;
	}
	else
	{
		current_chain = 1;
	}
	if (current_chain > longest)
	{
		longest = current_chain;
	}
	for (const tree& child : current.children)
	{
		int child_length = longest_path(child, current.value, current_chain, longest);
		if (child_length > longest)
		{
			longest = child_length;
		}
	}
	return longest;
}

int longest_path(const tree& root)
{
	return longest_path(root, INT_MIN, 1, 0);
}
