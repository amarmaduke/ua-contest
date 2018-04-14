#include <iostream>
#include <fstream>

using namespace std;

int fail(string failure)
{
    cout << failure << endl;
    return 43;
}

struct Vec2
{
    double x, y;
};

struct Joint
{
    double time;
    Vec2 pos;
};

Joint joints[100001];
int n, q;

int binSearch(int low, int hi, double time)
{
    if(low > hi)
        return low - 1;
    
    int mid = (low + hi) / 2;
    
    if(time < joints[mid].time)
        return binSearch(low, mid - 1, time);
    else
        return binSearch(mid + 1, hi, time);
}

Vec2 lerp(Vec2 a, Vec2 b, double t)
{
    Vec2 res;
    res.x = a.x + (b.x - a.x) * t;
    res.y = a.y + (b.y - a.y) * t;
    
    return res;
}

Vec2 solve(double time)
{
    int lower = binSearch(0, n, time);
    
    double t = (time - joints[lower].time) / (joints[lower + 1].time - joints[lower].time);
    
    return lerp(joints[lower].pos, joints[lower + 1].pos, t);
}

Vec2 bruteForce(double time)
{
    int lower = 0;
    while(joints[lower + 1].time < time)
        ++lower;
    
    double t = (time - joints[lower].time) / (joints[lower + 1].time - joints[lower].time);
    
    return lerp(joints[lower].pos, joints[lower + 1].pos, t);
}

int main(int argc, char* argv[])
{
    ifstream input(argv[1]);
    
    input >> n;
    for(int i = 0; i < n; ++i)
    {
        input >> joints[i].time >> joints[i].pos.x >> joints[i].pos.y;
    }
    
    input >> q;
    for(int i = 0; i < q; ++i)
    {
        double time;
        input >> time;
        
        Vec2 res = solve(time);
        
        double x, y;
        if(cin >> x >> y)
        {            
            double diffx = abs(x - res.x);
            double diffy = abs(y - res.y);
            double maxError = 10e-6;
        
            if(diffx > maxError || diffy > maxError)
            {
                if(diffx < 0.1 && diffy < 0.1)
                {
                    return fail("Small error - probably not enough digits");
                }
                else
                {
                    char buf[1024];
                    sprintf(buf, "Significant difference - wrong answer. Correct (%.7f, %.7f), given (%.7f, %.7f)", res.x, res.y, x, y);
                    
                    return fail(buf);
                }
            }
        }
    }
    
    cout << "Accepted" << endl;
    
    return 42;
}

