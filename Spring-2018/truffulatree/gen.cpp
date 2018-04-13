#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        cout << "Usage: " << argv[0] <<  " <# branches> <# queries>\n";
        return 0;
    }
    
    srand(time(NULL));
    
    int n = atoi(argv[1]);
    int time = 0;
    const int MAX_DIFF = 100;
    
    cout << n << endl;
    
    for(int i = 0; i < n; ++i)
    {
        int dx, dy;
        
        do
        {
            dx = (rand() % (2 * MAX_DIFF)) - MAX_DIFF;
            dy = (rand() % (2 * MAX_DIFF)) - MAX_DIFF;
        } while(dx == 0 && dy == 0);
        
        int dtime = rand() % 100 + 1;
        
        time += dtime;
        
        cout << time << " " << dx << " " << dy << endl;
    }
    
    int q = atoi(argv[1]);
    
    cout << q << endl;
    
    for(int i = 0; i < q; ++i)
    {
        int t = rand() % time;
        
        cout << t << endl;
    }
}

