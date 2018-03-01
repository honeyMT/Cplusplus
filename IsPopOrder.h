#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//	stack<int> st;
//	int id = 0;
//	for (int i = 0; i<popV.size(); ++i){
//		while (st.empty() || st.top() != popV[i]){
//
//			st.push(pushV[id]);
//			if (id > pushV.size()){
//				id += 1;
//				return false;
//			}
//		}
//		st.pop();
//	}
//	if (st.empty())
//		return true;
//	else
//		return false;
//}

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
	if (pushV.empty())
		return false;
	if (popV.empty())
		return false;
	if (pushV.size() != popV.size())
		return false;

	vector<int> stack;

	for (int i = 0, j = 0; i < pushV.size();)
	{
		stack.push_back(pushV[i]);

		while (stack.back() == popV[j] && j < popV.size())
		{
			stack.pop_back();
			++j;
		}
		++i;
	}
	return stack.empty();
}

void Test()
{
	vector<int> pushV;
	vector<int> popV;

	pushV.push_back(1);
	pushV.push_back(2);
	pushV.push_back(3);
	pushV.push_back(4);
	pushV.push_back(5);

	popV.push_back(4);
	popV.push_back(3);
	popV.push_back(5);
	popV.push_back(1);
	popV.push_back(2);

	cout << IsPopOrder(pushV, popV) << endl;

	system("pause");
}