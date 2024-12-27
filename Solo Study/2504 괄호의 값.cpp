//#include <iostream>
//#include <string>
//#include <stack>
//
//using namespace std;
//
////int main()
////{
////	string Input;
////	cin >> Input;
////
////	stack<pair<char, int>> st;
////	int answer = 0;
////
////	bool Prev_Open = false;
////	for (int i = 0; i < Input.length(); ++i)
////	{
////		if (Input[i] == '(')
////		{
////			st.push({ '(', 0 });
////			Prev_Open = true;
////		}
////
////		else if (Input[i] == '[')
////		{
////			st.push({ '[', 0 });
////			Prev_Open = true;
////		}
////
////		else if (Input[i] == ')')
////		{
////			if (!st.empty() && st.top().first == '(')
////			{
////				int tempnum = st.top().second;
////				st.pop();
////				if (!st.empty())
////				{
////					if (Prev_Open)
////						st.top().second += 2;
////					else
////						st.top().second += (tempnum * 2);
////				}
////				else
////				{
////					if (Prev_Open)
////						answer += 2;
////					else
////						answer += (tempnum * 2);
////				}
////
////				Prev_Open = false;
////			}
////			else
////			{
////				answer = 0;
////				break;
////			}
////		}
////		
////		else if (Input[i] == ']')
////		{
////			if (!st.empty() && st.top().first == '[')
////			{
////				int tempnum = st.top().second;
////				st.pop();
////				if (!st.empty())
////				{
////					if (Prev_Open)
////						st.top().second += 3;
////					else
////						st.top().second += (tempnum * 3);
////				}
////				else
////				{
////					if (Prev_Open)
////						answer += 3;
////					else
////						answer += (tempnum * 3);
////				}
////
////				Prev_Open = false;
////			}
////			else
////			{
////				answer = 0;
////				break;
////			}
////		}
////	}
////
////	cout << answer;
////
////	return 0;
////}
//
//int main()
//{
//	string Input;
//	cin >> Input;
//
//	stack<char> st;
//	int answer = 0, tempnum = 1;
//	bool Prev_Open = false;
//
//	for (int i = 0; i < Input.length(); ++i)
//	{
//		if (Input[i] == '(')
//		{
//			st.push('(');
//			tempnum *= 2;
//			Prev_Open = true;
//		}
//		else if (Input[i] == '[')
//		{
//			st.push('[');
//			tempnum *= 3;
//			Prev_Open = true;
//		}
//		else if (Input[i] == ')')
//		{
//			if (!st.empty() && st.top() == '(')
//			{
//				st.pop();
//				if (Prev_Open)
//					answer += tempnum;
//				tempnum /= 2;
//				Prev_Open = false;
//			}
//			else
//			{
//				answer = 0;
//				break;
//			}
//		}
//		else if (Input[i] == ']')
//		{
//			if (!st.empty() && st.top() == '[')
//			{
//				st.pop();
//				if (Prev_Open)
//					answer += tempnum;
//				tempnum /= 3;
//				Prev_Open = false;
//			}
//			else
//			{
//				answer = 0;
//				break;
//			}
//		}
//	}
//
//	if (!st.empty())
//		answer = 0;
//
//	cout << answer;
//
//	return 0;
//}