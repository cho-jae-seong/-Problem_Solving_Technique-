#include<stdio.h>
#include<algorithm>
using namespace std;
//201621427 ���缺 ��ǻ���������к� 
int main(void){
	int n;//�Է¹��� n 
	int sum1=0,sum2=0;//n=3�� �� �ִ밪 ���ϱ� ���� ������ 
	int maximum=-987654321;//������� ����ϱ� ���� ����,�ִ밪�� ����ϱ����� �ʱⰪ�� ���ʰ� ���� ���� 
	int num[1001];//���ڵ��� �Է¹ޱ� ���� �迭 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	sum1=(num[1]-num[2])-num[3];
	sum2=num[1]-(num[2]-num[3]);
	maximum=max(sum1,sum2);//�ʱ� 3���� ���ڵ鸸���� �ִ밪�� ���Ѵ�. 
	if(n==3)printf("%d\n",maximum);//n=3�̸� �״�� ���� ��� 
	else{//n�� 3 �ʰ���� �� ������ ���ڵ��� ���Ѵ�. ������ �״�� ���ϰ� ������� ����� �ٲٰ� ���Ѵ�. 
		for(int i=4;i<=n;i++){
			if(num[i]>=0)maximum+=num[i];
			else maximum+=(-1*num[i]);
		}
		printf("%d\n",maximum);//��� ��� 
	}
	return 0;
}
