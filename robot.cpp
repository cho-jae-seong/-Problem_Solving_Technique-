#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
//201621427 ���缺 ��ǻ���������к� 
int main(void){
	vector<pair<int,int> >v;//(����ð�,����)�� �����ϱ� ���� ���� �� 
	vector<pair<int,int> >v2;//(�ʱ���ġ,����ġ)�� �����ϱ� ���� ���� �� 
	deque<int>dq;//����ġ�� �����ϱ� ���� deque 
	int n,b,w,x,d,check=0;
	int ans=0;//���ͷ� �� ���� �κ��� ����ġ�� ��ü ���� �κ� ����ġ ���� �ݰ� ���ϱ� ���� ���� 
	double sum=0;//��ü ���� �κ� ����ġ ���� ���� ��Ÿ�� ���� 
	scanf("%d%d",&n,&b);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&w,&x,&d);
		sum+=w;
		if(d<0)v.push_back(make_pair(x,d));//���⿡ ���߾ (����ð�,����)���� �����Ѵ�. 
		else v.push_back(make_pair(b-x,d)); 
		v2.push_back(make_pair(x,w));//(�ʱ���ġ,����ġ) ����. 
	}
	sum/=2;
	sort(v.begin(),v.end());//����ð��� �°� �������� ����
	sort(v2.begin(),v2.end());//�ʱ���ġ�� �°� �������� ����
	for(int i=0;i<v2.size();i++){//deque�� ����ġ�� �־��ش�. 
		dq.push_back(v2[i].second);
	} 
	for(int i=0;i<n;i++){//���ĵ� ����ð��� ���� ���⿡ ���� ����ġ�� ���� �����鼭 ���� ������ ������ �� ���� ���. 
		if(v[i].second<0){//������ �����̶�� 
			ans+=dq.front();//����ġ�� ���ʰ��� �����ش�. 
			if(ans>=sum){//���ǿ� �����ϸ� ������ ����ϰ� ����. 
				printf("%d\n",v[i].first);
				break;
			}
			else dq.pop_front();
		}
		else{//������ �������̶�� 
			ans+=dq.back();//����ġ�� �����ʰ��� �����ش�. 
			if(ans>=sum){//���ǿ� �����ϸ� ������ ����ϰ� ����. 
				printf("%d\n",v[i].first);
				break;
			}
			else dq.pop_back();
		}
	}
	return 0;
}
