#include<stdio.h>
#include<vector>
using namespace std;
unsigned long long f[3001];
//201621427 ���缺 ��ǻ���������к� 
int main(void){
	int n;
	unsigned long long ans=1;//������ ����ϱ� ���� ���� 
	unsigned long long cnt;//���� ������ ���� ������ ī��Ʈ�ϱ� ���� ���� 
	unsigned long long k=0;//���丮���� ���� ���� 
	scanf("%d",&n);
	vector<int> v(n);
	f[0]=1;//���丮�� �ʱ�ȭ 
	for(int i=1;i<3001;i++){//�̸� ���丮���� �迭�� �־��ش� ������ ��� ������ �ǰ��Ͽ� 12377�� ������ ������ ���ش� 
		f[i]=(f[i-1]*i)%12377;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	if(n==1)printf("1\n");//1����� �ݵ�� 1�� �� 
	else if(n==2){//2����� �� �� ����ũ�� �� �� 1 or 2 �� ��� 
		if(v[0]<v[1])printf("1\n");
		else printf("2\n");
	}
	else{//3�� �̻���� 
		for(int i=n-2;i>=0;i--){//������ �Ϸķ� �������� �� �� �������� �������� 
			cnt=0;//�� ��° ������ ���ʷ� �ڽ��� ������ ������ ���� �� ���� ���� ������ ī��Ʈ �Ѵ� 
			k++;//ī��Ʈ �� ����ŭ ������ ���� ���丮�� ���� �Էµ� ���� ũ�⿡ �˸°� ���߾� ���ؼ� �����ش� 
			for(int j=i+1;j<n;j++){
				if(v[i]>v[j])cnt++;
			}
			ans=ans+(cnt*f[k]);
		}
		printf("%llu\n",ans%12377);//���� ���  
	}
	return 0;
}
