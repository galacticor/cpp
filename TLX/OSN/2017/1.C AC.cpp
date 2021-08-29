#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <map>
#include <string.h>
#define ll long long

using namespace std;

string in;
int n, angka[5][30], arr[10][10], row = 5, col = 5;
vector<int> baris[10], kolom[10];
//1 = kanan 	2 = atas 	3 = kiri 	4 = bawah

int ask(int a){
	int ret;
	if(a == 1){
		cout <<"KANAN"<< endl;
	}else if(a == 2){
		cout <<"ATAS"<< endl;
	}else if(a == 3){
		cout <<"KIRI"<< endl;
	}else{
		cout <<"BAWAH"<< endl;
	}
	cin >> ret;
	return ret;
}

void get(int curr, int next, int a){
	if(a == 1){
		angka[1][curr] = next;
		angka[3][next] = curr;
	}else if(a == 2){
		angka[2][curr] = next;
		angka[4][next] = curr;
	}else if(a == 3){
		angka[3][curr] = next;
		angka[1][next] = curr;
	}else{
		angka[4][curr] = next;
		angka[2][next] = curr;
	}
}

bool vis[30];

void interact(int curr){
	//kanan
	if(vis[curr])
		return;
	vis[curr] = true;
	int next = ask(1);
	get(curr, next, 1);
	interact(next);
	ask(3);
	//atas
	vis[curr] = true;
	next = ask(2);
	get(curr, next, 2);
	interact(next);
	ask(4);
}

void print(){
	for(int i = 1; i <= 5; i ++){
		for(int j = 1; j < 5; j ++){
			cout << arr[i][j] << " ";
		}
		cout << arr[i][5] << endl;
	}
}

void debug(){
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= 4; j ++){
			cout << angka[j][i] <<" ";
		}
		cout << endl;
	}
}

bool haha = false;

bool check(){
	for(int i = 1; i <= row; i ++){
		for(int j = 1; j <= col; j ++){
			int kiri = -1, kanan = -1, atas = -1, bawah = -1, num = arr[i][j];
			if(num == 0)continue;
			int tmp1 = j - 1;
			//kiri
			if(tmp1 <= 0)tmp1 = col;
			while(arr[i][tmp1] == 0){
				tmp1--;
				if(tmp1 <= 0)tmp1 = col;
			}
			kiri = arr[i][tmp1];
			//kanan
			tmp1 = j + 1;
			if(tmp1 > col)tmp1 = 1;
			while(arr[i][tmp1] == 0){
				tmp1 ++;
				if(tmp1 > col)tmp1 = 1;
			}
			kanan = arr[i][tmp1];
			//atas
			tmp1 = i - 1;
			if(tmp1 <= 0)tmp1 = row;
			while(arr[tmp1][j] == 0){
				tmp1 --;
				if(tmp1 <= 0)tmp1 = row;
			}
			atas = arr[tmp1][j];
			//bawah
			tmp1 = i + 1;
			if(tmp1 > row)tmp1 = 1;
			while(arr[tmp1][j] == 0){
				tmp1 ++;
				if(tmp1 > row)tmp1 = 1;
			}
			bawah = arr[tmp1][j];

			if(kiri != angka[3][num])return 0;
			if(kanan != angka[1][num])return 0;
			if(atas != angka[2][num])return 0;
			if(bawah != angka[4][num])return 0;
		}
	}
	return 1;
}

void precom(){
	memset(vis,0,sizeof(vis));
	int cnt = 1;
	for(int i = 1; i <= n; i ++){
		if(vis[i])continue;
		int curr = i;
		while(!vis[curr]){
			vis[curr] = true;
			baris[cnt].push_back(curr);
			curr = angka[3][curr];
		}
		cnt++;
	}
	memset(vis,0,sizeof(vis));
	cnt = 1;
	for(int i = 1; i <= n; i ++){
		if(vis[i])continue;
		int curr = i;
		while(!vis[curr]){
			vis[curr] = true;
			kolom[cnt].push_back(curr);
			curr = angka[4][curr];
		}
		cnt++;
	}
}

pair<int,int> koor[30];

void make(){
	do{
		do{
			memset(arr,0,sizeof(arr));
			for(int i = 5; i >= 1;i--){
				for(int j = 0; j < baris[i].size(); j ++){
					int num = baris[i][j];
					koor[num].first = i;
				}
			}
			for(int i = 5; i >= 1; i --){
				for(int j = 0; j < kolom[i].size(); j++){
					int num = kolom[i][j];
					koor[num].second = i;
				}
			}
			for(int i = 1; i <= n; i ++){
				int r = koor[i].first, c= koor[i].second;
				arr[r][c] = i;
			}
			if(check())break;
		}while(next_permutation(baris+1, baris+6));
		if(check())break;
	}while(next_permutation(kolom+1, kolom+6));
}

int main(){

	cin >> in;
	cin >> n;
	interact(1);
	// debug();
	precom();
	make();
	cout <<"JAWAB" <<endl;
	print();

	return 0;
}