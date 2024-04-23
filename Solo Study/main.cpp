//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//
//// ó�� ���� ������ �������� ®�� ��, ķ ��ġ�� ���� �������� ���, ķ�� �ű��� �ʴ´ٸ�,
//// ���� ���� ���� ���� ������ ���� ���� ���� ���� �̳��� ������ ��� �����ϰ� �Ǿ� �ùٸ��� �ʴ�.
//// ��, ���� ������ ķ�� ��ġ�ϰ�, ���� ������ ���� ������ �˻��� ��� �����ϰ� ķ�� ��ġ���� �ʴ� ��찡 �ִ�.
//// 
//// ���� ķ�� ��ġ�� ���� ������ ����, ���� ������ ��� ������ ķ�� ��ġ�� �����ϰ�, ķ ��ġ�� �Űܵ� ���� ���ϴ� �����
//// ķ�� �ϳ� ���� ��ġ�� ���־�� �Ѵ�.
////
//// ���� ������ ó�� Ȯ���� ��, ������ ķ �ϳ��� ����Ѵ�. ��� �����ϸ� �ȴ�.
//// 
//// �̶�, sort�� �̿��� ���� ������ �������� ������ �صξ��� ������
//// ���������� �����ص� �ϳ��� ķ���� ��Ƴ� �� �ֳ�, ���ĸ� ���� �б⸦ ������ ���� �ʾƵ� �ȴ�.
//// ��Ƴ�..
//// 
//// #������ �������� ������, #��Ʈ�� �������� Ʋ����, #����� ���� �� �÷� ������ Ǯ��, # ���� �ٽ� �ѹ� �� Ǯ������� ����.
//// 
////int solution(vector<vector<int>> routes) {
////	int answer = 0;
////
////	sort(routes.begin(), routes.end(), less<vector<int>>());
////
////	int StartPoint = routes[0][0];
////	int EndPoint = routes[0][1];
////	answer++;
////
////	for (size_t i = 1; i < routes.size(); ++i)
////	{
////		if (EndPoint >= routes[i][0])
////			continue;
////
////		StartPoint = routes[i][0];
////		EndPoint = routes[i][1];
////
////		answer++;
////	}
////
////	return answer;
////}
//
//
//int solution(vector<vector<int>> routes) {
//	int answer = 0;
//
//	sort(routes.begin(), routes.end(), less<vector<int>>());
//
//	int StartPoint = routes[0][0];
//	int EndPoint = routes[0][1];
//	int CamPos = EndPoint;
//	answer++;
//
//	for (size_t i = 1; i < routes.size(); ++i)
//	{
//		int NewStart = routes[i][0];
//		int NewEnd = routes[i][1];
//		if (CamPos >= NewStart)
//		{
//			if (CamPos > NewEnd)
//				CamPos = NewEnd;
//		}
//		else if (CamPos < NewStart)
//		{
//			CamPos = NewEnd;
//			answer++;
//		}
//	}
//
//	return answer;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;

 //dfs�� Ǯ�� ��Ȯ�ϱ�� ������, ���� �ð��� �ʰ��� ���.
 //int DFS(vector<int>& A, vector<int>& B, vector<bool>& Visit_A, vector<bool>& Visit_B, bool _Add, int PrevTargetNum)
 //{
 //    int Result = 0x3f3f3f3f;
 //    int Return = 0;
 //    int TargetNum = 0;
 //    bool bVisit = false;
 //    for (size_t i = 0; i < A.size(); ++i)
 //    {
 //        if (Visit_A[i] == false)
 //        {
 //            bVisit = true;
 //            TargetNum = A[i];
 //            
 //            // �̹��� ���̸�,
 //            if (!_Add)
 //            {
 //                TargetNum = PrevTargetNum* TargetNum;
 //            }
 //
 //            Visit_A[i] = true;
 //            Return = DFS(B, A, Visit_B, Visit_A, !_Add, TargetNum);
 //            Visit_A[i] = false;
 //
 //            // ���ƿ��� ��, ���̸� -> TargetNum
 //            if (!_Add)
 //            {
 //                Result = min(Result, Return + TargetNum);
 //            }
 //            // ���ƿ��� ��, ���̸�, ->
 //            else
 //            {
 //                Result = Return;
 //            }
 //        }
 //    }
 //
 //    // ���� ������ ���� ��� 0 ��ȯ
 //    if (!bVisit)
 //        return 0;
 //
 //    // ��� ��ȯ
 //    return Result;
 //}
 //
 //int solution(vector<int> A, vector<int> B)
 //{
 //    int answer = 0;
 //
 //    vector<bool> Visit_A(A.size(), false);
 //    vector<bool> Visit_B(B.size(), false);
 //
 //    answer = DFS(A, B, Visit_A, Visit_B, true, 0);
 //
 //    return answer;
 //}


// DFS�� Ǯ���� �ʾƼ� �ٸ� ����� �����ϴٰ� ������ �غ��� ��� �����ߴ�.
// ������ �� ���� �������� �������� ��, �� ���� ���� ���� ���ذ��� �ּҰ��� ������ ���ؼ���
// ���� �� * ū �� Ȥ�� ū �� * ���� ���� ������ ��� �ּҰ��� ���´ٴ� ���� ����Ҵ�.
// 
// �̰� �³� �����ϱ� ���� ������ ���� ������ ���Ҵ�.
// 
// �� ���� ���ϱ�
// ������ ��, ���� ������ + ���� ������ �� ���� ���� ��
// ������ �� ���� ���� ������ ���ؼ��� ������ �� ���� ��
// ������ 1, 5, 10  1, 5, 10�϶�
// 1*1 + 5*5 + 10* 10�� �ּڰ��� �ƴϴ�.
// 
// �̰�� ���� ���� ���� ���ؼ���
// 1 * 10 + 5 * 5 + 10 * 1 �̾�� �Ѵ�.
// ��, A�� ���� �� �� B�� ū�� + A�� ���� ���� �� * B�� ���� ū�� + ... �̾�� �Ѵ�.
// 
// ������
// A�� ������������ �����ϰ�, B�� ������������ ������ ��, �迭�� �����ŭ ��ȸ�ϸ鼭, �� ����� i �ε����� ���� ����
// Answer�� �����ָ鼭 Ǯ����.
// �� �����غ���, ���� Ǯ �� �ִ� �������µ�, �ش� ������ �ʹ� �ʰ� ���ö���.
// ��� O(n) �ΰ�? �¾ƺ��̴µ�..

//int solution(vector<int> A, vector<int> B)
//{
//    int answer = 0;
//
//    sort(A.begin(), A.end(), less<int>());
//    sort(B.begin(), B.end(), greater<int>());
//
//    for (size_t i = 0; i < A.size(); ++i)
//    {
//        answer += A[i] * B[i];
//    }
// 
//    return answer;
//}


//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//// ������ Ǯ�� ���ؼ� �����غ����� ��, �־��� �ð����� �����غ��� ���� ���� �� ���ٴ� ������ �ߴ�.
//// ������ compare �Լ��� ���� �ð��� ���� �������� ���� �ð��� ���������� ������ �־���.
//// 
//// ������ Ǯ�� ���ؼ� 9�� ���� ����ϴ� ��� ���� �ð� ���̺��� ������ �ϰ�, �ش� �ð� ���̺� �°��� �¿�����,
//// ��� ���� ���̺��� ä���, ������ �������� �ش� �迭�� ����ֳ� �ƴϳķ� �ذ��� ������.
//// 
//// ã�ƺ��� �ð��� �ð��� ������ ������ �ʰ�, ������ ȯ���ؼ� Ǫ�°� �ξ� �����ϰ� �ڵ尡 ���´�.
//// �������� �ð� ������ Ǯ�� �ð��� ���� ������ �ʰ� ������ ȯ���� Ǯ��, �ʿ��ϴٸ� �ð�:������ �ٽ� �����־� Ǫ�°� �ξ� ������ �� ����.
////
//// �̺� Ž�����ε� Ǯ���� �����غ� ��.
//// 
//
//bool compare(string _A, string _B)
//{
//	int A_hour = stoi(_A.substr(0, 2));
//	int A_Min = stoi(_A.substr(3, 5));
//
//	int B_hour = stoi(_B.substr(0, 2));
//	int B_Min = stoi(_B.substr(3, 5));
//
//	if (A_hour != B_hour)
//		return A_hour < B_hour;
//	else if (A_hour == B_hour)
//		return A_Min < B_Min;
//
//}
//
//struct tTime
//{
//	int iHour;
//	int iMin;
//};
//
//string MakeStrTime(int _iHour, int _iMin)
//{
//	string StrTime = "";
//
//	if (_iHour < 10)
//		StrTime = "0";
//
//	StrTime += to_string(_iHour) + ":";
//
//	if (_iMin < 10)
//		StrTime += "0";
//
//	StrTime += to_string(_iMin);
//
//	return StrTime;
//}
//
//string solution(int n, int t, int m, vector<string> timetable)
//{
//	string answer = "";
//
//	vector<pair<tTime, vector<string>>> vec_BusTime;
//
//	// ����
//	sort(timetable.begin(), timetable.end(), compare);
//	
//	// ���� 9�ú��� ������ ���, nȸ �ݺ�, t�� ����, �ִ� �°� m
//
//	// ���� �ð�ǥ �����
//	tTime TempTime = {};
//	TempTime.iHour = 9;
//	TempTime.iMin = 0;
//	vec_BusTime.push_back(make_pair(TempTime, vector<string>(m)));
//
//	for (int i = 1; i < n; ++i)
//	{
//		TempTime.iMin += t;
//		if (TempTime.iMin >= 60)
//		{
//			TempTime.iHour++;
//			TempTime.iMin -= 60;
//		}
//		vec_BusTime.push_back(make_pair(TempTime, vector<string>(m)));
//	}
//
//	// ���� �ð�ǥ�� ��ȸ�ϸ鼭 �°� �¿��
//	for (size_t i = 0; i < vec_BusTime.size(); ++i)
//	{
//		for (size_t j = 0; j < vec_BusTime[i].second.size(); ++j)
//		{
//			if (timetable.empty())
//				continue;
//
//			int BusHour = vec_BusTime[i].first.iHour;
//			int BusMin = vec_BusTime[i].first.iMin;
//			int PassengerHour = stoi(timetable[0].substr(0, 2));
//			int PassengerMin = stoi(timetable[0].substr(3, 5));
//
//			if (BusHour < PassengerHour)
//				continue;
//			if (BusHour == PassengerHour && BusMin < PassengerMin)
//				continue;
//
//			vec_BusTime[i].second[j] = timetable[0];
//			timetable.erase(timetable.begin());
//		}
//	}
//
//	// �������� ����ִٸ�, �ش� �ð��� answer��
//	if (vec_BusTime[n - 1].second[m - 1] == "")
//	{
//		int BusHour = vec_BusTime[n - 1].first.iHour;
//		int BusMin = vec_BusTime[n - 1].first.iMin;
//		answer = MakeStrTime(BusHour, BusMin);
//	}
//	// �������� ä���� �ִٸ�, ���� ���ִ� �ð����� -1 
//	else
//	{
//		TempTime.iHour = stoi(vec_BusTime[n - 1].second[m - 1].substr(0, 2));
//		TempTime.iMin = stoi(vec_BusTime[n - 1].second[m - 1].substr(3, 5)) - 1;
//
//		if (TempTime.iMin < 0)
//		{
//			TempTime.iHour--;
//			TempTime.iMin += 60;
//		}
//
//		answer = MakeStrTime(TempTime.iHour, TempTime.iMin);
//	}
//
//	return answer;
//}

//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//// ������ �ؼ� Ǯ� ������ ���� ���� ���ø�
//// �ܼ��� ������������ �ؼ� 0�� �ε����� Ǯ���� �� ��, ���ܻ�Ȳ�� �߻���.
//// 20, 20, 20, 20, 30, 40, 80, 80, 80 �� ���. (����Ʈ�� 100)
//// �տ����� �ϸ�, {20, 20, 20, 20}, {30, 40}, {80}, {80}, {80} ���� 5�� �ݺ��ؾ���.
//// ������ �ּ��� ���� ������ ����. {20, 80}, {20, 80}, {20, 80}, {20, 30, 40} ���� �� 4�� �ݺ��Ѵ�.
//// 
//// ������ �� ��, ����Ʈ��� ���� �ִ��� ä�����鼭 �ݺ��� ���°� ���� ����Ʈ��� ������ ����.
//// 
//// ������
//// ���� ������ �� <= ����Ʈ - ������ ���� �� ������ ���ư��� �� �� ����.
//// 
//// �ش� ���� ������δ� �����̳ʿ��� ���� ������ ���� ã�Ƽ� �湮 ó���� ���־�� �ϱ� ������ ���� �ʴ�.
//// �� �����̳ʿ��� ���ϴ� ������ ����ϴ� ���� ã�����ؼ� vector�� �ݺ� �����ؾ��ϱ� ������ ���� Ʈ�� ������ set�� ����ϱ�� ����
//// ���� set�� �̿��ϸ� �����͸� �Է��� ��, ���� ����� �����̵Ǹ� ���� ������ ���ĵ� ���� �ʿ� ����δ�.
//// 
//// �湮ó���� �Բ����ֱ� ���� set���� map�� ����ϴ°� �� ���� ���δ�.
////
//
//// �ٽôٽ� �ٽ� ����
//// ���� ������ �� <= ����Ʈ - ������ ����
//// ��� ���� �Ҷ�, ���� ��� 40 <= 60�̸�, 60���� ���ڸ� Ž���ϴ°� ����..
//// �̷��� ��� 60������ ���� �ٷ� Ž���ϴ°� �ƴ϶� ������ �� 60�� ������ �� ������ �ִ����� ���� Ž���ؾ� ����..
//// 
//// �ƹ��� �����ص� �̻��ؼ� �ٽ� ���� �ִ� 2����� �¿�� �ſ��� ������������������������������������������
//// -> �̰� ������ ������ �������..? ��� ����
//// �̷��� �׳� sort ������ �������� ����ؼ� Ǫ�°� ���ƺ���.
////
// 
// bast cast�� O(logN)
//
//int solution(vector<int> people, int limit) {
//	int answer = 0;
//
//	sort(people.begin(), people.end());
//
//
//	int iFrontIdx = 0;
//	int iBackIdx = people.size() - 1;
//	while (iFrontIdx >= iBackIdx)
//	{
//		if (people[iFrontIdx] + people[iBackIdx] <= limit)
//		{
//			iFrontIdx++;
//			iBackIdx--;
//		}
//		// ���� �Ǿ��ٴ� ���� ���ſ� ����� Ÿ�� ������ �Ѵٴ� ��.
//		else
//		{
//			iBackIdx--;
//		}
//
//		answer++;
//	}
//
//	return answer;
//}

//#include <string>
//#include <vector>
//#include <map>
//#include <cmath>
//
//using namespace std;

// ���� ������� ������ ����Ǵ� ���� �� ���� �����ϰ� Ǯ �� �־���.
// 
// 1. �׷��� �����
// �켱 �׷����� ������ �Ѵٰ� �����ߴ�.
// �����ϴٰ� ã�� ����� tNode�� �̿��� map�� ����� ��.
// -> ���� map�� key�� �̸� val�� pair�� ���� Ű��, ����� �� ���� �Ϸ����ߴµ�, make_pair�� 2������ؼ� �бⰡ �����غ��� ����ü�� ���� �����.
// 
// 2. �ݺ� ����
// �ᱹ ���� ��忡������ Ÿ�� �ö󰡸� ������־�� �Ѵٰ� ��������.
// -> ������ ���� ������ �ö� �ʿ���� ������ �� ������� ��忡�� ������ �÷��ְ�,
//	  �ش� ���鿡���� �����ϸ� �ɰ� ���ƺ�����. (������ ����)
// 
// ���� seller�� �ݺ� ������ �ֵ��� �ڵ� ����
// 
// ����
// SellersMonny : ���� ��尡 ���� �ݾ� (�Ʒ����� ���� �ö󰡱� ������ ���� ��尡 �ƴ� ��쿣 ���� ���� ���� ���� ������..?��.)
// Pay : ���� ��忡�� ���� ���� �������� ������
// �ݺ��� (���� ��尡 ���� ����� �� �׸��� ���� ��尡 ���� �ݾ��� 0�� �ƴҰ�쿡�� ����)
//		   -> ������ �ƴ� ��, ���� ��忡�� �� �����ᰡ 0�� ��� (���� ��尡 ���� �ݾ� : 8, �ش� ��尡 ���� ��忡�� ������ ������ 8 * 0.1 = 0.xxx��, 0��)
//		   -> ����� ����� ���� �ʿ䰡 ����. -> ��� +0�� �����´ϱ�
// 
// 1. �����Ḧ ������ ���� ������ ���� ���� ���
// 2. ���� ��忡�� ����� ��, ���� ��尡 ���� ���� ������� ����
// 3. ���� ��� Ž��
// 
// �ݺ��� �� ���� ��尡 ���� ��('-'), ��ȣ���� �� �����Ḧ ������ ���� ���� ������ָ� ��.
// 
// �ݺ����� ��� ��ģ ��
// ���޹��� ���� ��� ������� answer�� �ش� ������ ���� ���� �ݾ��� �߰��� ��������.
//


// ���� answer���� �����ؾ��� ������ ��� ���� ���� ��� ������ �����ϱ� ������
// map�� ������ �ش� ������ �°� ��ġ�ϴ°� ���� ���ƺ�������.. (�ܼ� iter ��ȸ�� ������ָ� �ȴϱ�.. �ƴϴ� ��¥�� �ҿ�ð��� ����ϰڴ�..)
// 
// answer�� vector�ϱ� ���ʿ� ����ϴ� �͵� vector�� ������ �� ����.
// �ٵ�.. �װ� ��ã��... �� �ٺξ�..

// �׸��� ó�� ���� ���� �ݺ��� if������ �ܼ��� ���� ��尡 �ֳ� ���ĸ� ����ߴµ�,
// �̷����� 11 ~ 14�� �׽�Ʈ ���̽��� �ð� �ʰ��� ����..
// �����غ��� ������� �۾��� �ݺ��Ѵٴ� ������ ���� ������ ���� ��(������)�� 0�� �� �� �̻� �ݺ����� �ʵ��� ������. (�� ���￡ ���� ������..?)
//

//struct tNode
//{
//	string	str_next;
//	int		i_monny;
//};
//
//vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
//	vector<int> answer;
//
//	map<string, tNode> map_Person;
//	tNode TempNode = {};
//	for (size_t i = 0; i < enroll.size(); ++i)
//	{
//		TempNode.str_next = referral[i];
//		TempNode.i_monny = 0;
//
//		map_Person.insert(make_pair(enroll[i], TempNode));
//	}
//
//	int SellersMonny = 0;
//	int Pay = 0;
//	// map<string, tNode>::iterator -> auto�� ���� ����.
//	map<string, tNode>::iterator TempIter = map_Person.begin();
//	for (size_t i = 0; i < seller.size(); ++i) // ++i�� �������� �� ����� �մµ�, �����Ϸ��� �����ϸ鼭 ũ�� �ǹ� ������.
//	{
//		SellersMonny = amount[i] * 100;
//		TempIter = map_Person.find(seller[i]);
//		while (TempIter->second.str_next != "-"
//			&& SellersMonny != 0)
//		{
//			Pay = trunc(SellersMonny * 0.1);
//			TempIter->second.i_monny += SellersMonny - Pay;
//
//			SellersMonny = Pay;
//
//			TempIter = map_Person.find(TempIter->second.str_next);
//		}
//
//		if (TempIter->second.str_next == "-")
//			TempIter->second.i_monny += SellersMonny - trunc(SellersMonny * 0.1);
//	}
//
//	for (size_t i = 0; i < enroll.size(); ++i)
//	{
//		answer.push_back(map_Person.find(enroll[i])->second.i_monny);
//	}
//
//	return answer;
//}


//#include <string>
//#include <vector>
//#include <math.h>
//
////
////
////
//
//using namespace std;
//
//vector<int> solution(int brown, int yellow) {
//	vector<int> answer;
//	answer.resize(2);
//
//	int a = 2;
//	int b = (brown - 4) * -1;
//	int c = 2 * yellow;
//
//	// x1 = (-b + ��Ʈ(b^2 - 4ac)) / 2a
//	int row = ((-1 * b) + sqrt(pow(b, 2) - (4 * (a * c)))) / (2 * a);
//	// x2 = (-b - ��Ʈ(b^2 - 4ac)) / 2a
//	int col = ((-1 * b) - sqrt(pow(b, 2) - (4 * (a * c)))) / (2 * a);
//
//	if (row < col)
//	{
//		int temp = row;
//		row = col;
//		col = temp;
//	}
//
//	answer[0] = row + 2;
//	answer[1] = col + 2;
//
//	return answer;
//}

//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//// ó���� ��� Ǯ�� �ϴٰ�..
//// Cost�� �������� ������������ ������ ��, �̾� �ַ��� �ߴ�.
//// ������ �ܼ��� �̷��� �ϸ�, ���ܰ� �߻��ϱ� ������ �ּ� �ڽ�Ʈ�� ã�� �� ������.
////
//// ������ �˻��� �غ��� ũ�罺�� �˰����̶�� �ּ� ��� ���� Ʈ���� ���ϴ� �˰����� �־���.
//// �ش� �˰����� �̿��ϸ�, ���� Ǯ �� �־���.
//// 
//// ������ ������ �ͱ����� �״�� ����ϰ�, ��� �׷��� ������ΰ�
//// ���� ������ �����Ѵٸ� �ش� �׷��� ���� �����ְ�,
//// ���� ������ ������ ������ �ش� �׷��� ���� �ٸ� �׷������� Ȯ���ϸ� ����� �־���.
//// 
//// ��Ƴ�..
//// 
////  ======= ���� ���� ��� =======
//// �־��� �������� �������� �� �ּ��� ����� ã�ƾ� �Ѵ�.
//// �̶�, ������ �ٸ����� �ٽ� �ǳ� �� �ִ�.
//// �� ��� ��������� �ּ� ��� �ٸ��� ���� ����Ŭ�� �̷��� �ʴ� ����̴�.
//// 
//// ������ ���� Ʈ�� ������ ������ �� �ְ�, �̶� �ּ� ������� ������ �ϱ� ������
//// �ּ� ��� ���� Ʈ���� ����� ��츦 ã���� �ȴ�.
//// 
//// ������ �ּ� ��� ���� Ʈ���� ���ϴ� �˰����� ũ�罺�� �˰����� �̿���
//// ���(������ ����ġ)�� ���� answer�� ���ϸ� �ȴ�.
//// ==============================
//
//bool compare(vector<int> vec_Front, vector<int> vec_Back)
//{
//	if (vec_Front[2] != vec_Back[2])
//		return vec_Front[2] < vec_Back[2];
//	else
//	{
//		return  vec_Front[0] < vec_Back[0];
//	}
//}
//
//int GetParent(vector<int>& vec_Group, int Node)
//{
//	// ���� ��尡 ����Ű�� ��尡 �����̶��, �ֻ��� �θ� ���
//	if (vec_Group[Node] == Node)
//		return Node;
//
//	// �ƴ϶��, ������ �ֻ��� �θ� ��带 ã�ƾ���.
//	return GetParent(vec_Group, vec_Group[Node]);
//}
//
//// ���� �� ����Ŭ�� �̷���� Ȯ���Ѵ�.
//bool IsCycle(vector<int>& vec_Group, int Node_A, int Node_B)
//{
//	int iGroupA = GetParent(vec_Group, Node_A);
//	int iGroupB = GetParent(vec_Group, Node_B);
//
//	return iGroupA == iGroupB;
//}
//
//// �� ��带 ���� �׷����� ���´�.
//void MakeGroup(vector<int>& vec_Group, int Node_A, int Node_B)
//{
//	int iParent_A = vec_Group[GetParent(vec_Group, Node_A)];
//	int iParent_B = vec_Group[GetParent(vec_Group, Node_B)];
//
//	if (iParent_A < iParent_B)
//	{
//		vec_Group[iParent_B] = iParent_A;
//	}
//	else
//	{
//		vec_Group[iParent_A] = iParent_B;
//	}
//}
//
//int solution(int n, vector<vector<int>> costs) {
//	int answer = 0;
//
//	// ���� �� �ڽ�Ʈ�� ���� �͵���� �����ϴ� ��� (���)
//	sort(costs.begin(), costs.end(), compare);
//	
//	// ���� ��� ���� �����
//	vector<int> vec_Node(n, -1);
//	for (size_t NodeVal = 0; NodeVal < vec_Node.size(); ++NodeVal)
//	{
//		vec_Node[NodeVal] = NodeVal;
//	}
//
//	int iStartIland = 0, iEndIland = 0, iCost = 0;
//	for (size_t iCostIdx = 0; iCostIdx < costs.size(); ++iCostIdx)
//	{
//		iStartIland = costs[iCostIdx][0];
//		iEndIland = costs[iCostIdx][1];
//		iCost = costs[iCostIdx][2];
//
//		// ���� �� ����Ŭ�� �̷���� �ʴ´ٸ�,
//		if (!IsCycle(vec_Node, iStartIland, iEndIland))
//		{
//			// ������ ����
//			MakeGroup(vec_Node, iStartIland, iEndIland);
//
//			// ���������� ����ġ�� �����Ѵ�.
//			answer += iCost;
//		}
//	}
//
//	return answer;
//}

//#include<vector>
//#include <queue>
//#include <math.h>
//using namespace std;
//
//// ó������ �ִ� �Ÿ��� ã�� ���̱� ������ DFS�� BFS�� ���÷ȴ�.
//// ������ DFS���� BFS�� �ξ� �� ȿ�����̶� �Ǵ��ߴ�.
//// �ֳ��ϸ�, DFS�� ���� �������� ������ �ᱹ ��ü�� �� Ž���ؾ߸� �Ѵ�.
//// ������ BFS�� ��� ���� ������ ��� ��带 Ž���ϱ� ������ �ᱹ ���������� ���� �ϳ��� �����Ѵٸ�,
//// �װ� ���� �ּ� �Ÿ��� �Ǵ��� �� �ֱ� �����̴�.
////
//// ������, �� ������ A*�ε� Ǯ �� �־����.
//// A*�� ��� ��������� �Ÿ��� ���� �Ÿ��� ����ؼ� �ִ� �Ÿ��� ã�� �����̴�.
//// ���� A*�� ����غ��� �����ϱ� ���ؼ� A*�� ����ؼ� Ǯ��Ҵ�.
//// 
//// ������ A*�� ��� ȿ���� �׽�Ʈ�� ������� ���ߴ�..
//// ���� �������� ���� ���ٸ�, ���� ������ ã������, ���������� �������� ���
//// �ᱹ ��ü ��ȸ�� �ϱ� ���� + ����ϴ°͵�� ����ϴ°� �� ���� ����?
//// 
//// ��ư �����ؼ� BFS�� Ǯ��..
////
//
//
////struct tMemo
////{
////	int iCost;
////	int iDist;
////	int iResult = 0x3f3f3f3f;
////
////	bool bOpen = false;
////	bool bClose = false;
////};
////
////struct tPQMemo
////{
////	int X;
////	int Y;
////	int iResult;
////
////	tPQMemo(int x, int y, int result) { X = x; Y = y; iResult = result; }
////};
////
////struct cmp
////{
////	bool operator() (tPQMemo t_A, tPQMemo t_B)
////	{
////		return t_A.iResult > t_B.iResult;
////	}
////};
////
////// UP, Down, Left, Right
////int Dir_X[4] = { 0,0,-1,1 };
////int Dir_Y[4] = { 1,-1,0,0 };
////
////bool Pass(int iMax_Y, int iMax_X, int iY, int iX)
////{
////	return (iY >= 0 && iY < iMax_Y) && (iX >= 0 && iX < iMax_X);
////}
////
////int Dist(int iX_1, int iX_2, int iY_1, int iY_2)
////{
////	return sqrt(pow(iX_2 - iX_1, 2) + pow(iY_2 - iY_1, 2));
////}
////
////int Astar(vector<vector<int>>& vec_Map, vector<vector<tMemo>>& vec_Memo, priority_queue<tPQMemo, vector<tPQMemo>, cmp>& pq)
////{
////	int iMax_Y = vec_Map.size();
////	int iMax_X = vec_Map[0].size();
////
////	while (!pq.empty())
////	{
////		int icutX= pq.top().X;
////		int icutY = pq.top().Y;
////		pq.pop();
////
////		if (vec_Memo[icutY][icutX].bClose)
////			continue;
////
////		vec_Memo[icutY][icutX].bClose = true;
////
////		int iNewCost = vec_Memo[icutY][icutX].iCost + 1;
////
////		for (size_t iDirIdx = 0; iDirIdx < 4; ++iDirIdx)
////		{
////			int NxtY = icutY + Dir_Y[iDirIdx];
////			int NxtX = icutX + Dir_X[iDirIdx];
////
////			// ���� �ε��� ������ ��ȿ���� �ʰų� ���� ���� ���� �ѱ�
////			if (!Pass(iMax_Y, iMax_X, NxtY, NxtX) || vec_Map[NxtY][NxtX] == 0)
////				continue;
////
////			vec_Memo[NxtY][NxtX].iCost = iNewCost;
////			vec_Memo[NxtY][NxtX].iDist = Dist(NxtX, iMax_X, NxtY, iMax_Y);
////
////			if (vec_Memo[NxtY][NxtX].iResult < vec_Memo[NxtY][NxtX].iCost + vec_Memo[NxtY][NxtX].iDist)
////				continue;
////
////			vec_Memo[NxtY][NxtX].iResult = vec_Memo[NxtY][NxtX].iCost + vec_Memo[NxtY][NxtX].iDist;
////
////			pq.push(tPQMemo(NxtX, NxtY, vec_Memo[NxtY][NxtX].iResult));
////		}
////	}
////
////	if (vec_Memo[iMax_Y - 1][iMax_X - 1].iResult == 0x3f3f3f3f)
////		vec_Memo[iMax_Y - 1][iMax_X - 1].iResult = -1;
////
////	return vec_Memo[iMax_Y - 1][iMax_X - 1].iResult;
////}
////
////int solution(vector<vector<int> > maps)
////{
////	int answer = 0;
////	priority_queue<tPQMemo, vector<tPQMemo>, cmp> pq;
////	vector<vector<tMemo>> vec_Memo(maps.size(), vector<tMemo>(maps[0].size()));
////	vec_Memo[0][0].iCost = 0;
////	vec_Memo[0][0].iDist = Dist(0, maps[0].size(),0, maps.size());
////	vec_Memo[0][0].iResult = vec_Memo[0][0].iCost + vec_Memo[0][0].iDist;
////	pq.push(tPQMemo(0, 0, vec_Memo[0][0].iResult));
////	
////	answer = Astar(maps, vec_Memo, pq);
////
////
////	return answer;
////}
//
//// UP, Down, Left, Right
//int Dir_X[4] = { 0,0,-1,1 };
//int Dir_Y[4] = { 1,-1,0,0 };
//
//bool Pass(int iMax_Y, int iMax_X, int iY, int iX)
//{
//	return (iY >= 0 && iY < iMax_Y) && (iX >= 0 && iX < iMax_X);
//}
//
//int bfs(vector<vector<int>>& maps, queue<pair<int, int>>& queue, vector<vector<bool>>& vec_Visit, vector<vector<int>>& vec_Dist)
//{
//	int iMax_X = maps[0].size(), iMax_Y = maps.size();
//	queue.push({ 0, 0 });
//	vec_Dist[0][0] = 1;
//
//	while (!queue.empty())
//	{
//		int iCurY = queue.front().first, iCurX = queue.front().second;
//		queue.pop();
//
//		if (vec_Visit[iCurY][iCurX])
//			continue;
//
//		vec_Visit[iCurY][iCurX] = true;
//
//		for (size_t iDistIdx = 0; iDistIdx < 4; iDistIdx++)
//		{
//			int iNxtY = iCurY + Dir_Y[iDistIdx];
//			int iNxtX = iCurX + Dir_X[iDistIdx];
//
//			if (!Pass(iMax_Y, iMax_X, iNxtY, iNxtX) || maps[iNxtY][iNxtX] == 0)
//				continue;
//
//			vec_Dist[iNxtY][iNxtX] = vec_Dist[iCurY][iCurX] + 1;
//
//			if (iNxtY == iMax_Y - 1 && iNxtX == iMax_X - 1)
//				return vec_Dist[iMax_Y - 1][iMax_X - 1];
//
//			queue.push({ iNxtY , iNxtX });
//		}
//	}
//
//	return vec_Dist[iMax_Y - 1][iMax_X - 1];
//}
//
//int solution(vector<vector<int>> maps)
//{
//	int answer = 0;
//	queue<pair<int, int>> queue;
//	vector<vector<bool>> vec_Visit(maps.size(), vector<bool>(maps[0].size(), false));
//	vector<vector<int>> vec_Dist(maps.size(), vector<int>(maps[0].size(), -1));
//
//	answer = bfs(maps, queue, vec_Visit, vec_Dist);
//
//	return answer;
//}



//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;

// ���� �ٸ� BFS ������ Ǯ�������
// �׳� BFS�� Ǯ��� �ϴ� ������ ����..
// 
// ������ �ڵ忡�� ���� �迭, Pass �Լ��� ��������, BFS�� ����ϰ� ������ ¥��.
// �ش� ���������� visist���� �ڽ�Ʈ�� ���� �迭�� ������ �ɰ� ���� ������.
// ���� ������ ���� ��������ε�..
// 
// ó������ Cost vector�� cost�� dir�� pair�� ��� ������.
// �׽�Ʈ ���̽� 1���� ��� ���������, 3���� ��� ������� ����.
// 
// �ϳ��ϳ� ����� ���� �������� �����غ���
// �ݺ��� ����� cost�� ��Ƶδµ� dir���� �Բ� ��ƹ����ϱ�
// queue���� ���� �˻��� ���� �ε����� �����͵�, �ᱹ ���� ������ ������ ���������� ����ص� ������.
// 
// ��, ����ص� ����� �̹� Ž������ �� ������ ��ġ ���� ����.
// ������ queue�� ������� �Բ� �����ϴ°��� �Ǵ� ������.
//


//enum class DIR_TYPE
//{
//	DOWN,
//	UP,
//	LEFT,
//	RIGHT,
//	END
//};
//
//struct PrevResult
//{
//	int i_Idx_X;
//	int i_Idx_Y;
//
//	DIR_TYPE DIR;
//};
//
////Down, UP, Left, Right
//int Dir_X[(int)DIR_TYPE::END] = {0,0,-1,1};
//int Dir_Y[(int)DIR_TYPE::END] = { 1,-1,0,0 };
//int INF = 0x3f3f3f3f;
//
//bool Pass(int iMax_Y, int iMax_X, int iY, int iX)
//{
//	return (iY >= 0 && iY < iMax_Y) && (iX >= 0 && iX < iMax_X);
//}
//
//int bfs(vector<vector<int>>& Board, queue<PrevResult>& queue_Idx, vector<vector<vector<int>>>& vec_Cost)
//{
//	int iMax_Y = Board.size(), iMax_X = Board[0].size();
//	vec_Cost[0][0][0] = 0;
//	vec_Cost[0][0][1] = 0;
//	vec_Cost[0][0][2] = 0;
//	queue_Idx.push({ 0, 0, DIR_TYPE::END });
//
//	while (!queue_Idx.empty())
//	{
//		int CurIdx_Y = queue_Idx.front().i_Idx_Y;
//		int	CurIdx_X = queue_Idx.front().i_Idx_X;
//		DIR_TYPE PrevDir = queue_Idx.front().DIR;
//		queue_Idx.pop();
//
//		for (size_t DirIdx = 0; DirIdx < (int)DIR_TYPE::END; ++DirIdx)
//		{
//			int iNxt_Y = CurIdx_Y + Dir_Y[DirIdx];
//			int iNxt_X = CurIdx_X + Dir_X[DirIdx];
//
//			if (!Pass(iMax_Y, iMax_X, iNxt_Y, iNxt_X) || 1 == Board[iNxt_Y][iNxt_X])
//				continue;
//
//			int iNewCost = 0;
//			// ������ ������ ������, �Ǵ� 0,0�� ó�� ���� �� ��, END�� ��,
//			if ((int)PrevDir == DirIdx)
//				iNewCost = vec_Cost[CurIdx_Y][CurIdx_X][(int)PrevDir] + 1;
//			else if((int)PrevDir == (int)DIR_TYPE::END)
//				iNewCost = vec_Cost[CurIdx_Y][CurIdx_X][0] + 1;
//			else
//				iNewCost = vec_Cost[CurIdx_Y][CurIdx_X][(int)PrevDir] + 6;
//
//			if (vec_Cost[iNxt_Y][iNxt_X][(int)DirIdx] == INF || iNewCost <= vec_Cost[iNxt_Y][iNxt_X][(int)DirIdx])
//			{
//				vec_Cost[iNxt_Y][iNxt_X][(int)DirIdx] = iNewCost;
//
//				queue_Idx.push({ iNxt_X ,iNxt_Y, (DIR_TYPE)DirIdx });
//			}
//		}
//	}
//	
//	return *min_element(vec_Cost[iMax_Y - 1][iMax_X - 1].begin(), vec_Cost[iMax_Y - 1][iMax_X - 1].end()) * 100;
//
//}
//
//int solution(vector<vector<int>> board) {
//	int answer = 0;
//
//	queue<PrevResult> qeueu_Idx;
//	vector<vector<vector<int>>> vec_Cost(board.size(), vector<vector<int>>(board[0].size(), vector<int>( (int)DIR_TYPE::END, INF)));
//
//	answer = bfs(board, qeueu_Idx, vec_Cost);
//
//	return answer;
//}

//#include <string>
//#include <vector>
//
//// ������ ���ٰ� �ؾ�����..
//// ���ڴٰ� �ؾ�����..
//// �ƹ�ư �ᱹ ������ ���� ������ �����غ��� ������ �ƴѵ�,
//// 
//// �Ǻ���ġ ���� ���� �� ���� �������� 44��° �����ص� 2971215073�̳� ���� ���̾�..
//// �ƹ�ư ��� ���� �ڷ��� ������δ� �����ϱ� ������
//// 1234567�̶�� ������ ���� �������� �������� ��� ������־�� �Ѵ�...
//// 
//// == ��ⷯ ������ ���� ==
//// � �� A, B, C�� ���� ��,
//// A + B % C = ((A % C) + (B % C)) % C
//// �ᱹ �ش� ������ �ƴ��� �𸣴��� + �ڷ����� ������ �������� ������ Ȯ���ϴ� �ɷ¿� ���� ����.
//// 
//// ���� N���� ������� ���� �����÷ο찡 �߻��� Ȯ���� ���� ������ ���ɼ����ִ�.
//// ���� �ڷ��� ��������� �� �����غ� ��.
////
//
//using namespace std;
//
//int Fibonacci(int n, vector<long long>& vec_Memo)
//{
//	int icurIdx = 0;
//	while (n != icurIdx)
//	{
//		if (icurIdx == 0 || icurIdx == 1)
//			vec_Memo[icurIdx] = icurIdx % 1234567;
//		else
//			vec_Memo[icurIdx] = vec_Memo[icurIdx - 1] + vec_Memo[icurIdx - 2] % 1234567;
//		
//		icurIdx++;
//	}
//
//	return vec_Memo[n - 1];
//}
//
//int solution(int n) {
//	int answer = 0;
//
//	vector<long long> vec_Memo(n + 1, -1);
//
//	answer = Fibonacci(n + 1, vec_Memo);
//
//	return answer;
//}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;

	sort(times.begin(), times.end());

	long long llMinTime = 0;
	long long llMaxTime = times[times.size() - 1] * n;
	long long llMidTime = (llMinTime + llMaxTime) / 2;

	long long PersonCount = 0;
	while (llMinTime <= llMaxTime)
	{
		PersonCount = 0;

		for (size_t iTimeIdx = 0; iTimeIdx < times.size(); ++iTimeIdx)
		{
 			PersonCount += llMidTime / times[iTimeIdx];
		}

		// ũ��, min�� mid + 1��
		if (PersonCount < n)
		{
			llMinTime = llMidTime + 1;
   			llMidTime = (llMinTime + llMaxTime) / 2;
		}
		// ������, max�� mid - 1��
		else
		{
			answer = llMidTime;
			llMaxTime = llMidTime - 1;
			llMidTime = (llMinTime + llMaxTime) / 2;
		}
	}

	return answer;
}

void main()
{
	//int answer = solution(vector<vector<int>>{ { -20, -15},{-14, -5}, {-18, -13},{-5, -3} });
	//int answer = solution(vector<int>{1, 2}, vector<int>{3, 4}); // 1, 4, 2    5, 4, 4
	//string answer = solution(1, 1, 5, vector<string>{"08:00", "08:01", "08:02", "08:03"});
	//int answer = solution(vector<int>{70, 50, 80, 50}, 100);

	//vector<int> answer = solution(vector<string>{"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"}
	//, vector<string>{"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"}
	//, vector<string>{"young", "john", "tod", "emily", "mary"}, vector<int>{12, 4, 2, 5, 10});

	//vector<int> answer = solution(8, 1);

	//int answer = solution(4, vector<vector<int>>{ {0, 1, 1}, { 0,2,2 }, { 1,2,5 }, { 1,3,1 }, {2,3,8} } );

	//vector<int> answer = solution(6, vector<vector<int>>{ {1, 2, 3}, { 2, 3, 5 }, { 2, 4, 2 }, { 2, 5, 4 }, { 3, 4, 4 }, { 4, 5, 3 }, { 4, 6, 1 }, { 5, 6, 1 } }
	//, vector<int>{1, 3}, vector<int>{5});

	//int answer = solution(vector<vector<int>>{ {1, 0, 1, 1, 1}, { 1, 0, 1, 0, 1 }, { 1, 0, 1, 1, 1 }, { 1, 1, 1, 0, 1 }, { 0, 0, 0, 0, 1 } });

	//int answer = solution({ {0, 0, 1, 0}, {0, 0, 0, 0},{0, 1, 0, 1},{1, 0, 0, 0} });
	//int answer = solution({ {0, 0, 0, 0, 0}, { 0, 1, 1, 1, 0 }, { 0, 0, 1, 0, 0 }, { 1, 0, 0, 0, 1}, {0, 1, 1, 0, 0} });

	//int answer = solution(5);

	//int answer = solution(10, vector<int>{5, 7, 10});
	int answer = solution(4, vector<int>{1,1,1});

	int a = 0;

	return;
}