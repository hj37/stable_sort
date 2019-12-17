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
    /*T�� testcase n�� �迭�� ũ��
    �迭 ũ��� �ִ� 1000��, ���ڴ� 10000���� ���ü� ����
    a�� ������ �迭 ���� b�� ¦�� c�� Ȧ�� ���� ���� t1�� �׽�Ʈ���̽� ����
    */
    fscanf(fp1,"%d",&T);
    while(T--)
    {
        t1++;/*Testcase ����*/
        fscanf(fp1,"%d",&n);

        for(int i = 0; i < n; i++)
        {
            int tmp;
            fscanf(fp1,"%d",&tmp);
            if(tmp %2 != 0){
                /* Ȧ���̸� b�� ���� ¦���̸� c�� ���� */
                b.push_back(tmp);
            }
            else{
                c.push_back(tmp);
            }
        }

        stable_sort(b.begin(),b.end());    /*b�� �������� , c�� ��������*/
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
