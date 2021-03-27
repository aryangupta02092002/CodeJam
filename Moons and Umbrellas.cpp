#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

using namespace std;
char calc(char a, char b, map<string, int> m) {
    vector<char> v;
    v.push_back('C');
    v.push_back('J');
    int min = INT_MAX;
    char tar;
    for(char x: v) {
        int t = 0;
        string ti = "";
        string tii = "";
        ti.push_back(a);
        ti.push_back(x);
        
        tii.push_back(x);
        tii.push_back(b);
        if(m.count(ti)) {
            t += m[ti];
        }

        if(m.count(tii)) {
            t += m[tii];
        }

        if(min > t) {
            min = t;
            tar = x;
        }
    }
    
    return tar;
}

int main(int argc, char **argv)
{

#ifdef FILEIO
    freopen("MoonsAndUmbrellas_2021.in", "r", stdin);
    freopen("MoonsAndUmbrellas_2021.out", "w", stdout);
#endif

    int T;
    scanf("%d\n", &T);
    char array[1000];
    for (int z = 1; z <= T; z++)
    {
        int a, b;
        scanf("%d %d ", &a, &b);
        memset(array, '0', 1000*sizeof(char));

        char t1='0';
        int count= 0;

        map<string, int> m;
        m["CJ"] = a;
        m["JC"] = b;
        while(scanf("%c", &t1) != EOF) {
            if(t1 == '\n') break;
            array[count++] = t1;
        }
        vector<char> v;
        v.push_back('0');
        for(int i=0;i<count;i++) {
            int c2 = 0;
            if(array[i] == '?') {
                c2++;
            } else{
                if(c2%2 == 1) {
                    v.push_back('?');
                }
                v.push_back(array[i]);
            }
        }
        v.push_back('0');
        int result = 0;
        for(int i=1;i<v.size() - 1;i++) {
            if(v[i] == '?') {
                v[i] = calc(v[i-1], v[i+1], m);
            } 
        }

        for(int i=1;i<v.size() - 2;i++) {
            string t = "";
            t.push_back(v[i]);
            t.push_back(v[i+1]);
            if(m.count(t)) {
                result += m[t];
            }
        }
        cout << "Case #" << z <<": "<< result << endl;
    }

#ifdef FILEIO
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
