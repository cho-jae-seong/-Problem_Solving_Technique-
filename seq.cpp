#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
//201621427 ���缺 ��ǻ���������к� 
int main(void){
	int n,num;//�Է� ���� n�� ���Ϳ� �־��� ����num 
	vector<int> v;//�ʱ⿡ �Է¹��� ���ҵ��� ������ vector v 
	vector<int> v2;//�������� Ȯ�� �� ������ ���ҵ��� ������ vector v2 
	vector<int> v3;//������������ Ȯ�� �� ���ҵ��� ������ vector v3  
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		v.push_back(num);
	}
	sort(v.begin(),v.end());//������������ ���� 
	if(n==2){//n�� 2,3,4 �� ���� ������������ ���������� �����ǹǷ� �Ʒ��� ���� ����Ѵ�. 
		printf("1\n");
		printf("%d\n",v[0]);
		printf("1\n");
		printf("%d\n",v[1]);
	}
	else if(n==3){
		printf("1\n");
		printf("%d\n",v[0]);
		printf("2\n");
		printf("%d %d\n",v[1],v[2]);
	}
	else if(n==4){
		printf("2\n");
		printf("%d %d\n",v[0],v[1]);
		printf("2\n");
		printf("%d %d\n",v[2],v[3]);
	}
	else{//�� �ܿ� n�� 5�̻��� �Ʒ��� ����. 
		int idx;//���������� �ε��� Ȯ�ο� ���� 
		int cnt;//���� Ȯ�ο� ���� 
		int check[100001];//���������� �� �κ����� ������ ���� üũ �迭 
		int diff;//������ ��Ÿ���� ���� ���� 
		int ccnt=1;//ù ���Ҹ� ������ ������ ���ҵ��� ���������� �̷� �� ���� üũ�� ���� 
		int ddiff=v[2]-v[1];//���� ���� ����� ������ ��Ÿ���� ���� ���� 
		for(int i=3;i<n;i++){//������ ���ϴٰ� �ϳ��� �ٸ��� �ٷ� break 
			if(ddiff!=v[i]-v[i-1])break;
			else ccnt++;
		}//���� ���� ������ ������ �� ����ϰ� �ٷ� ���� 
		if(ccnt==n-2){
			printf("1\n");
			printf("%d\n",v[0]);
			printf("%d\n",n-1);
			for(int i=1;i<n;i++){
				printf("%d ",v[i]);
			}
			exit(0);
		}//ù ��° ���Ҵ� �� �������� �κ� �� ��� �� �κп��� ���ϹǷ� ù ���Ҹ� �������� ���������� �Ǻ� 
		for(int i=1;i<n;i++){//
			memset(check,0,sizeof(check));//üũ �迭�� �Ź� �ʱ�ȭ 
			diff=v[i]-v[0];//���� 
			check[i]=check[0]=1;//üũ 
			idx=i;//�ε��� 
			cnt=2;//���� 
			v2.clear();//�ʱ�ȭ 
			v3.clear();//�ʱ�ȭ 
			v3.push_back(v[0]);v3.push_back(v[i]);//Ȯ������ �� ���Ҵ� �̸� ���� 
			for(int k=0;k<n;k++){//������ üũ �ȵ� ���ҵ��� ���� 
				if(check[k]==0)v2.push_back(v[k]);
			}
			if(v2.size()==1||v2.size()==2){//ũ�Ⱑ 1 or 2 ��� �ݵ�� �����ϹǷ� �Ʒ��� ���� ��� �� �ٷ� ���� 
				printf("%d\n",cnt);
				for(int m=0;m<v3.size();m++)printf("%d ",v3[m]);
				printf("\n");
				printf("%d\n",v2.size());
				for(int q=0;q<v2.size();q++)printf("%d ",v2[q]);
				exit(0);
			}
			else{//ũ�Ⱑ 3 �̻��̶�� 
				int count=1;
				int dif=v2[1]-v2[0];
				for(int l=2;l<v2.size();l++){//������������ �Ǻ��Ѵ�. 
					if(dif!=v2[l]-v2[l-1])break;//�ƴϸ� �ٷ� break 
					else count++;
				}
				if(count==v2.size()-1){//���������̶�� �Ʒ��� ���� ��� �� �ٷ� ���� 
				printf("%d\n",cnt);
				for(int m=0;m<v3.size();m++)printf("%d ",v3[m]);
				printf("\n");
				printf("%d\n",v2.size());
				for(int q=0;q<v2.size();q++)printf("%d ",v2[q]);
				exit(0);
				}
			}
			memset(check,0,sizeof(check));//üũ �迭�� �Ź� �ʱ�ȭ
			check[i]=check[0]=1;//üũ
			v2.clear();//�ʱ�ȭ
			for(int j=i+1;j<n;j++){
				if(diff<v[j]-v[idx])break;//���ϴ� �������� ũ�� �ٷ� break 
				else if(diff==(v[j]-v[idx])){//������ �����ϴٸ� ���� ���� �� üũ,�ε��� ����,���� �߰� 
					v3.push_back(v[j]);
					check[j]=1;
					idx=j;
					cnt++;
					for(int k=0;k<n;k++){//������ üũ �ȵ� ���ҵ��� ���� 
				if(check[k]==0)v2.push_back(v[k]);
			}
			if(v2.size()==1||v2.size()==2){//ũ�Ⱑ 1 or 2 ��� �ݵ�� �����ϹǷ� �Ʒ��� ���� ��� �� �ٷ� ���� 
				printf("%d\n",cnt);
				for(int m=0;m<v3.size();m++)printf("%d ",v3[m]);
				printf("\n");
				printf("%d\n",v2.size());
				for(int q=0;q<v2.size();q++)printf("%d ",v2[q]);
				exit(0);
			}
			else{//ũ�Ⱑ 3 �̻��̶�� 
				int count=1;
				int dif=v2[1]-v2[0];
				for(int l=2;l<v2.size();l++){//������������ �Ǻ��Ѵ�. 
					if(dif!=v2[l]-v2[l-1])break;//�ƴϸ� �ٷ� break 
					else count++;
				}
				if(count==v2.size()-1){//���������̶�� �Ʒ��� ���� ��� �� �ٷ� ���� 
				printf("%d\n",cnt);
				for(int m=0;m<v3.size();m++)printf("%d ",v3[m]);
				printf("\n");
				printf("%d\n",v2.size());
				for(int q=0;q<v2.size();q++)printf("%d ",v2[q]);
				exit(0);
				}
			}
			v2.clear();//�ʱ�ȭ
				}
				else continue;//�������� �۴ٸ� �����ϰ� ���� ���� ���� 
			}
			for(int k=0;k<n;k++){//������ üũ �ȵ� ���ҵ��� ���� 
				if(check[k]==0)v2.push_back(v[k]);
			}
			if(v2.size()==1||v2.size()==2){//ũ�Ⱑ 1 or 2 ��� �ݵ�� �����ϹǷ� �Ʒ��� ���� ��� �� �ٷ� ���� 
				printf("%d\n",cnt);
				for(int m=0;m<v3.size();m++)printf("%d ",v3[m]);
				printf("\n");
				printf("%d\n",v2.size());
				for(int q=0;q<v2.size();q++)printf("%d ",v2[q]);
				exit(0);
			}
			else{//ũ�Ⱑ 3 �̻��̶�� 
				int count=1;
				int dif=v2[1]-v2[0];
				for(int l=2;l<v2.size();l++){//������������ �Ǻ��Ѵ�. 
					if(dif!=v2[l]-v2[l-1])break;//�ƴϸ� �ٷ� break 
					else count++;
				}
				if(count==v2.size()-1){//���������̶�� �Ʒ��� ���� ��� �� �ٷ� ���� 
				printf("%d\n",cnt);
				for(int m=0;m<v3.size();m++)printf("%d ",v3[m]);
				printf("\n");
				printf("%d\n",v2.size());
				for(int q=0;q<v2.size();q++)printf("%d ",v2[q]);
				exit(0);
				}
			}
		}
		printf("-1\n");
	}
	return 0;
}
