#include<iostream>
using namespace std;

int Capacity;				//背包容量
bool selected[10000];		//当前选择方案
bool optimal[10000];		//最佳选择方案
int maxTotalValue = 0;		//最大价值
int valueofPackage = 0;		//当前背包价值
int residualCapacity;		//剩余背包价值
int n;
int weight[10000];			//背包重量
int value[10000];			//背包价值

void dfs(int i)
{
	if(i > n){
		if(valueofPackage >= maxTotalValue){
			for(int i = 1 ; i <= n ; i++){
				optimal[i] = selected[i];
			}
			maxTotalValue = valueofPackage;
		}
		return;
	}else{
		residualCapacity -= weight[i];
		if(residualCapacity >= 0){	//遍历左子树
			selected[i] = 1;
			valueofPackage += value[i];
			dfs(i+1);
			selected[i] = 0;
			valueofPackage -= value[i];
			residualCapacity += weight[i];
		}else{//不满足原路返回
			residualCapacity += weight[i];
		}
	}
	//遍历右子树
	dfs(i+1);
}


int main(){
	cout<<"输入背包容量："<<endl;
	cin>>Capacity;
	residualCapacity = Capacity;
	cout<<"请输入背包个数："<<endl;
	cin>>n;
	cout<<"请输入每个背包重量："<<endl;
	for(int i = 1 ; i <= n ; i++){
		cin>>weight[i];
	}
	cout<<"请输入每个背包价值："<<endl;
	for(int i = 1 ; i <= n ; i++){
		cin>>value[i];
	}
	dfs(1);
	cout<<"最佳方案为："<<endl;
	for(int i = 1 ; i <= n ; i++){
		if(optimal[i] == 1){
			cout<<i<<" ";
		}
	}
	cout<<endl<<"最大背包价值为："<<endl<<maxTotalValue;

	return 0;
}
