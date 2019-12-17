#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    FILE* fp1 = fopen("sort.inp","r");
    FILE* fp2 = fopen("sort.out","w");
    int T; int n; int t1 = 0; vector<int> a;
    vector<int> b; vector<int> c;
    /*T는 testcase n은 배열의 크기
    배열 크기는 최대 1000개, 숫자는 10000까지 나올수 있음
    a는 기존의 배열 공간 b는 짝수 c는 홀수 담을 공간 t1은 테스트케이스 순서
    */
    fscanf(fp1,"%d",&T);
    while(T--)
    {
        t1++;/*Testcase 증가*/
        fscanf(fp1,"%d",&n);

        for(int i = 0; i < n; i++)
        {
            int tmp;
            fscanf(fp1,"%d",&tmp);
            if(tmp %2 != 0){
                /* 홀수이면 b에 저장 짝수이면 c에 저장 */
                b.push_back(tmp);
            }
            else{
                c.push_back(tmp);
            }
        }

        stable_sort(b.begin(),b.end());    /*b는 오름차순 , c는 내림차순*/
        stable_sort(c.begin(),c.end(),greater<int>());

        for(unsigned int i = 0; i < b.size(); i++)
        {
            a.push_back(b[i]);
        }
        for(unsigned int i = 0; i < c.size(); i++)
        {
            a.push_back(c[i]);
        }

        fprintf(fp2,"Test Case #%d\n",t1);

        for(unsigned int i = 0; i < a.size(); i++)
        {
            if(i== a.size()-1)
            {
                fprintf(fp2,"%d\n",a[i]);
            }
            else{
                fprintf(fp2,"%d ",a[i]);
            }
        }

        a.clear();
        b.clear();
        c.clear();
    }

    return 0;
}
