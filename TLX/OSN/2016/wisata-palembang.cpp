# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <cstring>
# include <stdio.h>
# include <map>
# include <queue>

# define ll long long
# define pii pair<int,int>
# define FOR(a,b) for(int a=1; a<=b; a++)
# define REP(a,b) for(int a=0; a<b; a++)
# define FORU(a,b,c) for(int a=b; a<=c; a++)
# define FORD(a,b,c) for(int a=b; a>=c; a--)

using namespace std;
//include random buat nge-random pake machine twister. Randomnya lebih bagus biasanya
# include <random>
# include <unordered_map>
mt19937 rnd(0);

ll randomizeBetween(ll lo, ll hi){
    int value = rnd()%(hi-lo+1);
    value += lo;
    return value;
}

ll adj[15][15];

//Cost untuk pergi dari kota awal ke permutasi urutan kota saat ini
ll calculateCost(vector<int> town){
    ll cost = 0;
    cost += adj[1][town[0]];
    REP(i, town.size()-1){
        cost += adj[town[i]][town[i+1]];
    }
    cost += adj[town.back()][1];
    return cost;
}

//Untuk dapat banyaknya path berbeda, kita generate semua kemungkinan permutasi yang mungkin
ll getDifferentLength(vector<int> town){
    unordered_map<ll, bool> occ;
    do{
        ll cost = calculateCost(town);
        occ[cost] = 1;
    }
    while(next_permutation(town.begin(), town.end()));
    return (int)occ.size();
}

void generateGraph(int N, int M, ll L){
    int differentPath = 0;
    
    //Cek apakah graf yang dibentuk sekarang memiliki "unique path" sudah tidak kurang dari M
    //selama kurang dari M, bikin graf baru
    while(differentPath < M){
        
        //Random bobot dari setiap edge pada graf baru. Edge yang dibentuk memiliki panjang > L
        FOR(i,N){
            adj[i][i] = 0;
            FORU(j,i+1, N){  
                adj[i][j] = randomizeBetween(1ll, 3ll*L);
                adj[j][i] = adj[i][j];
            }
        }
        
        //Hitung banyak different path pake function
        vector<int> town;
        FORU(i,2,N) town.push_back(i);
        differentPath = getDifferentLength(town);
    }
}

int main(){

    ios :: sync_with_stdio(false);
    //Karena mau incar subtask 1 sampe 5, maka loop 5x
    for(int tc=1; tc<=5; tc++){

        //inputFile : Nama file yang jadi input. Semua file input jadi 1 folder dengan source code
        string inputFile = "osn-2016-wisata-palembang_";
        inputFile += (char)(tc + '0');
        inputFile += "_1.in";

        //outputFile : Nama file yang jadi output. Begitu program dijalanin, output akan ke generate dalem file ini
        string outputFile = "osn-2016-wisata-palembang_";
        outputFile += (char)(tc + '0');
        outputFile += "_1.out";

        //freopen untuk redirect input menggunakan file. Parameter nya c string (bukan String tapi array of char)
        //jadi string nya mesti dikasih c_str()
        //stdin untuk redirect input dari input file, stdout untuk redirect output ke output file
        freopen(inputFile.c_str(), "r", stdin);
        freopen(outputFile.c_str(), "w", stdout);

        string subtask;
        cin >> subtask;

        //Do stuffs untuk generate output
        int N, M, L;
        cin >> N >> M >> L;
        memset(adj, 0, sizeof(adj));
        generateGraph(N, M, L);

        FOR(i,N){
            FOR(j,N){
                cout << adj[i][j];
                if(j != N) cout << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

//Untuk melakukan zip kita dapat melakukan ini :
/*
    1. Buka command Line / Terminal
    2. Ketik perintah "zip -r [NAMAZIP].zip [NAMAFILE-FILE]" (tanpa tanda petik)
        [NAMAZIP] adalah nama file untuk zip
        [NAMAFILE-FILE] adalah nama kumpulan file yang mau di zip
    3. Karena ada banyak file output, jadinya bisa di giniin
        "zip -r Wisata-Palembang.zip osn-2016*.out" (tanpa tanda petik)
        Artinya :
            zip : untuk melakukan zip
            osn-2016*.out artinya kita akan zip SEMUA file yang punya prefix "osn-2016" dan suffix ".out"
            karakter '*' itu menyatakan wildcard (bisa diisi karakter apa aja), ini udah ada di terminalnya
*/