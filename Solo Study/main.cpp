//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//
//// 처음 진출 지점을 기준으로 짰을 때, 캠 위치를 진출 지점으로 잡고, 캠을 옮기지 않는다면,
//// 다음 차량 진입 진출 지점이 이전 진입 진출 지점 이내에 존재할 경우 무시하게 되어 올바르지 않다.
//// 즉, 진출 지점에 캠을 설치하고, 다음 차량의 진입 지점만 검사할 경우 무시하고 캠이 설치되지 않는 경우가 있다.
//// 
//// 따라서 캠의 위치와 다음 차량의 진입, 진출 지점을 모두 점검해 캠의 위치를 갱신하고, 캠 위치를 옮겨도 잡지 못하는 경우라면
//// 캠을 하나 새로 설치를 해주어야 한다.
////
//// 생각 접근을 처음 확인할 때, 무조건 캠 하나를 써야한다. 라고 생각하면 된다.
//// 
//// 이때, sort를 이용해 진입 지점을 기준으로 정렬을 해두었기 때문에
//// 순차적으로 진행해도 하나의 캠으로 잡아낼 수 있냐, 없냐를 따로 분기를 나누어 주지 않아도 된다.
//// 어렵네..
//// 
//// #스스로 생각하지 못했음, #힌트를 봤음에도 틀렸음, #경우의 수를 더 늘려 생각해 풀음, # 이후 다시 한번 더 풀어봐야할 문제.
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

 //dfs로 풀면 정확하기는 하지만, 실행 시간이 초과가 뜬다.
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
 //            // 이번이 곱이면,
 //            if (!_Add)
 //            {
 //                TargetNum = PrevTargetNum* TargetNum;
 //            }
 //
 //            Visit_A[i] = true;
 //            Return = DFS(B, A, Visit_B, Visit_A, !_Add, TargetNum);
 //            Visit_A[i] = false;
 //
 //            // 돌아왔을 때, 곱이면 -> TargetNum
 //            if (!_Add)
 //            {
 //                Result = min(Result, Return + TargetNum);
 //            }
 //            // 돌아왔을 때, 합이면, ->
 //            else
 //            {
 //                Result = Return;
 //            }
 //        }
 //    }
 //
 //    // 다음 접근이 없을 경우 0 반환
 //    if (!bVisit)
 //        return 0;
 //
 //    // 결과 반환
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


// DFS로 풀리지 않아서 다른 방법을 생각하다가 정렬을 해보면 어떨까 생각했다.
// 정렬을 한 것을 기준으로 생각했을 때, 두 수를 곱한 값을 더해가며 최소값이 나오기 위해서는
// 작은 수 * 큰 수 혹은 큰 수 * 작은 수를 더해줄 경우 최소값이 나온다는 것을 깨닳았다.
// 
// 이게 맞나 검증하기 위해 다음과 같이 생각해 보았다.
// 
// 곱 이후 더하기
// 곱했을 때, 가장 작은값 + 이후 곱했을 때 가장 작은 값
// 곱했을 때 작은 값이 나오기 위해서는 작은값 곱 작은 값
// 하지만 1, 5, 10  1, 5, 10일때
// 1*1 + 5*5 + 10* 10은 최솟값이 아니다.
// 
// 이경우 작은 값을 내기 위해서는
// 1 * 10 + 5 * 5 + 10 * 1 이어야 한다.
// 즉, A의 작은 값 곱 B의 큰값 + A의 다음 작은 값 * B의 다음 큰값 + ... 이어야 한다.
// 
// 때문에
// A를 오름차순으로 정렬하고, B를 내림차순으로 정렬한 뒤, 배열의 사이즈만큼 순회하면서, 두 행렬의 i 인덱스의 값을 곱해
// Answer에 더해주면서 풀었다.
// 잘 생각해보면, 쉽게 풀 수 있는 문제였는데, 해당 생각이 너무 늦게 떠올랐다.
// 얘는 O(n) 인가? 맞아보이는데..

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
//// 문제를 풀기 위해서 생각해보았을 때, 주어진 시간들을 정렬해보고 나면 편할 것 같다는 생각을 했다.
//// 때문에 compare 함수를 만들어서 시간과 분을 기준으로 빠른 시간이 먼저오도록 정렬해 주었다.
//// 
//// 문제를 풀기 위해선 9시 부터 출발하는 통근 버스 시간 테이블을 만들어야 하고, 해당 시간 테이블에 승객을 태워가며,
//// 통근 버스 테이블을 채우면, 마지막 기준으로 해당 배열이 비어있냐 아니냐로 해결이 가능함.
//// 
//// 찾아보니 시간을 시간과 분으로 나누지 않고, 분으로 환산해서 푸는게 훨씬 간단하게 코드가 나온다.
//// 다음에는 시간 문제를 풀때 시간과 분을 나누지 않고 분으로 환산해 풀고, 필요하다면 시간:분으로 다시 돌려주어 푸는게 훨씬 간결할 것 같다.
////
//// 이분 탐색으로도 풀리니 공부해볼 것.
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
//	// 정렬
//	sort(timetable.begin(), timetable.end(), compare);
//	
//	// 차가 9시부터 역에서 출발, n회 반복, t분 간격, 최대 승객 m
//
//	// 버스 시간표 만들기
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
//	// 버스 시간표를 순회하면서 승객 태우기
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
//	// 마지막이 비어있다면, 해당 시간을 answer로
//	if (vec_BusTime[n - 1].second[m - 1] == "")
//	{
//		int BusHour = vec_BusTime[n - 1].first.iHour;
//		int BusMin = vec_BusTime[n - 1].first.iMin;
//		answer = MakeStrTime(BusHour, BusMin);
//	}
//	// 마지막이 채워져 있다면, 기존 들어가있는 시간에서 -1 
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
//// 정렬을 해서 풀어볼 생각을 가장 먼저 떠올림
//// 단순히 오름차순으로 해서 0번 인덱스로 풀려고 할 때, 예외상황이 발생함.
//// 20, 20, 20, 20, 30, 40, 80, 80, 80 일 경우. (리미트는 100)
//// 앞에서만 하면, {20, 20, 20, 20}, {30, 40}, {80}, {80}, {80} 으로 5번 반복해야함.
//// 하지만 최소의 경우는 다음과 같다. {20, 80}, {20, 80}, {20, 80}, {20, 30, 40} 으로 총 4번 반복한다.
//// 
//// 생각해 볼 때, 리미트라는 수를 최대한 채워가면서 반복을 도는게 제일 베스트라는 생각이 들음.
//// 
//// 때문에
//// 다음 선택할 수 <= 리미트 - 선택한 숫자 를 선택해 나아가면 될 것 같다.
//// 
//// 해당 접근 방식으로는 컨테이너에서 다음 선택할 수를 찾아서 방문 처리를 해주어야 하기 때문에 쉽지 않다.
//// 또 컨테이너에서 원하는 조건을 통과하는 수를 찾기위해서 vector는 반복 수행해야하기 때문에 이진 트리 구조인 set을 사용하기로 결정
//// 또한 set을 이용하면 데이터를 입력할 때, 작은 수대로 정렬이되며 들어가기 때문에 정렬도 굳이 필요 없어보인다.
//// 
//// 방문처리를 함께해주기 위해 set보다 map을 사용하는게 더 좋아 보인다.
////
//
//// 다시다시 다시 생각
//// 다음 선택할 수 <= 리미트 - 선택한 숫자
//// 라는 것을 할때, 예를 들어 40 <= 60이면, 60부터 숫자를 탐색하는게 좋음..
//// 이러면 사실 60이하의 수를 바로 탐색하는게 아니라 합했을 때 60이 나오는 수 집합이 있는지를 먼저 탐색해야 맞음..
//// 
//// 아무리 생각해도 이상해서 다시 보니 최대 2명까지 태우는 거였음 ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
//// -> 이게 그정도 까지의 문제라고..? 라는 생각
//// 이러면 그냥 sort 돌려서 투포인터 사용해서 푸는게 나아보임.
////
// 
// bast cast는 O(logN)
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
//		// 오버 되었다는 것은 무거운 사람만 타고 나가야 한다는 것.
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

// 어제 어떤식으로 문제가 진행되는 지를 들어서 쉽게 이해하고 풀 수 있었다.
// 
// 1. 그래프 만들기
// 우선 그래프를 만들어야 한다고 생각했다.
// 생각하다가 찾은 방법이 tNode를 이용해 map을 만드는 것.
// -> 원래 map에 key가 이름 val에 pair로 다음 키값, 사원의 돈 으로 하려고했는데, make_pair를 2번써야해서 읽기가 불편해보여 구조체로 묶어 사용함.
// 
// 2. 반복 구현
// 결국 리프 노드에서부터 타고 올라가며 계산해주어야 한다고 생각했음.
// -> 하지만 리프 노드부터 올라갈 필요없이 물건을 판 사원들의 노드에서 시작해 올려주고,
//	  해당 노드들에서만 시작하면 될거 같아보였다. (실제로 맞음)
// 
// 따라서 seller를 반복 수행해 주도록 코드 구현
// 
// 변수
// SellersMonny : 현재 노드가 얻은 금액 (아래에서 부터 올라가기 때문에 리프 노드가 아닐 경우엔 이전 노드로 부터 받은 수수료..?임.)
// Pay : 현재 노드에서 다음 노드로 전달해줄 수수료
// 반복부 (다음 노드가 있을 경우일 때 그리고 현재 노드가 얻은 금액이 0이 아닐경우에만 수행)
//		   -> 리프가 아닐 때, 이전 노드에서 준 수수료가 0일 경우 (이전 노드가 얻은 금액 : 8, 해당 노드가 다음 노드에게 전해줄 수수료 8 * 0.1 = 0.xxx즉, 0원)
//		   -> 계속해 기록을 남길 필요가 없음. -> 계속 +0만 해줄태니까
// 
// 1. 수수료를 제외한 실제 본인이 얻은 돈을 기록
// 2. 다음 노드에서 사용할 즉, 다음 노드가 얻은 돈을 수수료로 변경
// 3. 다음 노드 탐색
// 
// 반복문 후 다음 노드가 없을 때('-'), 민호에게 줄 수수료를 제외한 값만 더해 기록해주면 됨.
// 
// 반복문을 모두 마친 후
// 전달받은 직원 목록 순서대로 answer에 해당 직원이 얻은 최종 금액을 추가해 전달해줌.
//


// 최종 answer에서 제출해야할 순서가 사실 받은 직원 목록 순서와 동일하기 때문에
// map의 정렬을 해당 순서에 맞게 일치하는게 제일 좋아보였지만.. (단순 iter 순회로 기록해주면 된니까.. 아니다 어짜피 소요시간은 비슷하겠다..)
// 
// answer가 vector니까 애초에 기록하는 것도 vector면 좋았을 것 같다.
// 근데.. 그걸 못찾음... 난 바부양..

// 그리고 처음 제출 때는 반복부 if조건이 단순히 다음 노드가 있냐 없냐만 사용했는데,
// 이랬더니 11 ~ 14번 테스트 케이스가 시간 초과가 나옴..
// 생각해보니 쓸대없는 작업을 반복한다는 생각이 나서 직원이 얻은 돈(수수료)이 0일 때 더 이상 반복하지 않도록 변경함. (왜 진즉에 생각 못했지..?)
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
//	// map<string, tNode>::iterator -> auto로 쓰면 좋다.
//	map<string, tNode>::iterator TempIter = map_Person.begin();
//	for (size_t i = 0; i < seller.size(); ++i) // ++i이 예전에는 더 비용이 쌌는데, 컴파일러가 발전하면서 크게 의미 없어짐.
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
//	// x1 = (-b + 루트(b^2 - 4ac)) / 2a
//	int row = ((-1 * b) + sqrt(pow(b, 2) - (4 * (a * c)))) / (2 * a);
//	// x2 = (-b - 루트(b^2 - 4ac)) / 2a
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
//// 처음에 어떻게 풀까 하다가..
//// Cost를 기준으로 오름차순으로 정렬한 뒤, 이어 주려고 했다.
//// 하지만 단순히 이렇게 하면, 예외가 발생하기 때문에 최소 코스트를 찾을 수 없었다.
////
//// 때문에 검색을 해보니 크루스컬 알고리즘이라는 최소 비용 신장 트리를 구하는 알고르짐이 있었다.
//// 해당 알고리즘을 이용하면, 쉽게 풀 수 있었다.
//// 
//// 때문에 정렬한 것까지는 그대로 사용하고, 노드 그룹을 나누어두고
//// 만약 간선을 연결한다면 해당 그룹을 서로 합쳐주고,
//// 이후 간선을 연결할 때마다 해당 그룹이 서로 다른 그룹인지를 확인하며 만들어 주었다.
//// 
//// 어렵네..
//// 
////  ======= 문제 접근 방법 =======
//// 주어진 간선들을 연결했을 때 최소한 비용을 찾아야 한다.
//// 이때, 연결한 다리들은 다시 건널 수 있다.
//// 이 경우 만들어지는 최소 비용 다리는 서로 사이클을 이루지 않는 경우이다.
//// 
//// 때문에 신장 트리 구조로 변경할 수 있고, 이때 최소 비용으로 만들어야 하기 때문에
//// 최소 비용 신장 트리를 만드는 경우를 찾으면 된다.
//// 
//// 때문에 최소 비용 신장 트리를 구하는 알고리즘인 크루스컬 알고리즘을 이용해
//// 비용(간선의 가중치)를 더해 answer를 구하면 된다.
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
//	// 만약 노드가 가리키는 노드가 본인이라면, 최상위 부모 노드
//	if (vec_Group[Node] == Node)
//		return Node;
//
//	// 아니라면, 본인의 최상위 부모 노드를 찾아야함.
//	return GetParent(vec_Group, vec_Group[Node]);
//}
//
//// 연결 시 사이클을 이루는지 확인한다.
//bool IsCycle(vector<int>& vec_Group, int Node_A, int Node_B)
//{
//	int iGroupA = GetParent(vec_Group, Node_A);
//	int iGroupB = GetParent(vec_Group, Node_B);
//
//	return iGroupA == iGroupB;
//}
//
//// 두 노드를 같은 그룹으로 묶는다.
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
//	// 정렬 후 코스트가 작은 것들부터 연결하는 방식 (폐기)
//	sort(costs.begin(), costs.end(), compare);
//	
//	// 최초 노드 집합 만들기
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
//		// 연결 시 사이클을 이루는지 않는다면,
//		if (!IsCycle(vec_Node, iStartIland, iEndIland))
//		{
//			// 실제로 연결
//			MakeGroup(vec_Node, iStartIland, iEndIland);
//
//			// 연결했으니 가중치를 증가한다.
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
//// 처음에는 최단 거리를 찾는 것이기 때문에 DFS와 BFS를 떠올렸다.
//// 하지만 DFS보다 BFS가 훨씬 더 효율적이라 판단했다.
//// 왜냐하면, DFS는 쭉쭉 내려가기 때문에 결국 전체를 다 탐색해야만 한다.
//// 하지만 BFS의 경우 동일 깊이의 모든 노드를 탐색하기 때문에 결국 도착지점에 그중 하나라도 도착한다면,
//// 그게 제일 최소 거리로 판단할 수 있기 때문이다.
////
//// 하지만, 이 문제는 A*로도 풀 수 있어보였다.
//// A*의 경우 현재까지온 거리와 남은 거리를 계산해서 최단 거리를 찾기 때문이다.
//// 따라서 A*를 사용해보며 공부하기 위해서 A*를 사용해서 풀어보았다.
//// 
//// 하지만 A*의 경우 효율성 테스트를 통과하지 못했다..
//// 만약 막힌길이 전혀 없다면, 제일 빠르게 찾겠지만, 도착지점이 막혀있을 경우
//// 결국 전체 순회를 하기 때문 + 기록하는것들과 계산하는게 더 많기 때문?
//// 
//// 암튼 실패해서 BFS로 풀음..
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
////			// 다음 인덱스 범위가 유효하지 않거나 벽이 있을 때는 넘김
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

// 오늘 다른 BFS 문제를 풀었어서인지
// 그냥 BFS로 풀어볼까 하는 생각이 들음..
// 
// 이전꺼 코드에서 방향 배열, Pass 함수를 가져오고, BFS야 비슷하게 구조를 짜봄.
// 해당 문제에서는 visist보다 코스트를 넣은 배열이 있으면 될거 같다 생각함.
// 남은 문제는 이제 방향관련인데..
// 
// 처음에는 Cost vector에 cost와 dir를 pair로 묶어서 관리함.
// 테스트 케이스 1번의 경우 통과하지만, 3번의 경우 통과하지 못함.
// 
// 하나하나 디버깅 모드로 돌려가며 생각해보니
// 반복당 결과를 cost에 담아두는데 dir까지 함께 담아버리니까
// queue에서 다음 검사할 현재 인덱스를 가져와도, 결국 비교할 방향은 이전에 마지막으로 기록해둔 방향임.
// 
// 즉, 기록해둔 방향과 이번 탐색까지 온 방향이 일치 하지 않음.
// 때문에 queue에 방향까지 함께 전달하는것이 옳다 생각함.
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
//			// 이전과 방향이 같으면, 또는 0,0이 처음 들어갔을 때 즉, END일 때,
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
//// 문제가 좋다고 해야할지..
//// 나쁘다고 해야할지..
//// 아무튼 결국 나오는 수의 범위를 생각해보지 않은건 아닌데,
//// 
//// 피보나치 수열 수를 잘 몰라서 ㅋㅋㅋㅋ 44번째 수만해도 2971215073이나 나올 줄이야..
//// 아무튼 요는 기존 자료형 사이즈로는 부족하기 때문에
//// 1234567이라는 값으로 나눈 나머지를 기준으로 계속 기록해주어야 한다...
//// 
//// == 모듈러 연산의 성질 ==
//// 어떤 수 A, B, C가 있을 때,
//// A + B % C = ((A % C) + (B % C)) % C
//// 결국 해당 성질을 아느냐 모르느냐 + 자료형의 범위가 부족하지 않은지 확인하는 능력에 관한 문제.
//// 
//// 답을 N으로 나누라는 것은 오버플로우가 발생할 확률이 높은 문제일 가능성이있다.
//// 따라서 자료형 사이즈등을 잘 검토해볼 것.
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

		// 크면, min을 mid + 1로
		if (PersonCount < n)
		{
			llMinTime = llMidTime + 1;
   			llMidTime = (llMinTime + llMaxTime) / 2;
		}
		// 작으면, max를 mid - 1로
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