#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

class UF
{
    protected:
        int N;
        int coun;
        vector<int> Peop;
        vector<int> Weig;
        vector<int> Max;
    public:
        UF(int Nm)
        {
            N = Nm;
            coun = 0;
            for(int i = 0; i< Nm; i++)
            {
                Peop.push_back(i);
                Weig.push_back(1);
                Max.push_back(i);
            }
        }

        int cnt()
        {
            return coun;
        }

        void show()
        {
            for(int i = 0; i< N; i++)
            {
                cout << Peop[i] << "\t";
            }
            cout << endl;
            for(int i = 0; i< N; i++)
            {
                cout << Weig[i] << "\t";
            }
            cout << endl;
            for(int i = 0; i< N; i++)
            {
                cout << Max[i] << "\t";
            }
            cout << endl;
        }

        void unite(int i, int j)
        {
            int ri = root(i);
            int rj = root(j);
            if(rj != ri)
            {
                if(Weig[rj] > Weig[ri])
                {
                    int temp = ri;
                    ri = rj;
                    rj = temp;
                }

                Peop[rj] = ri;
                Weig[ri] += Weig[rj];
                if(Weig[ri] == N)
                {
                    show();
                    cout << "They become friends at " << coun+1 << " timestamp." << endl;
                    exit(EXIT_SUCCESS);
                }

                if(Max[ri] > Max[rj])
                {
                    Max[rj] = Max[ri];
                }
                else
                {
                    Max[ri] = Max[rj];
                }
            }
            coun++;
        }

        int root(int i)
        {
            while(i != Peop[i])
                {i = Peop[i];}
            return i;
        }

        int findMax(int i)
        {
            return Max[root(i)];
        }
};

int main()
{
    int Num;
    ifstream myfile( "data.dat" );
    myfile >> Num;

    UF first(Num);
    first.show();

    int a, b;
    while(myfile >> a >> b)
    {
            first.unite(a,b);
            first.show();
            int M;
            M = first.findMax(0);
            cout << "Maximal number in zero connected components group: " << M << endl;
    }

    cout << "They are not friends in " << first.cnt() << " steps" << endl;
    return 1;
}
