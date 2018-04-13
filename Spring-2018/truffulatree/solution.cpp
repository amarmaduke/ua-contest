#include <iostream>

using namespace std;

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

int main()
{
    double x = 0;
    double y = 0;
    
    joints[0].pos.x = 0;
    joints[0].pos.y = 0;
    joints[0].time = 0;
    
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        double dx, dy;
        cin >> joints[i].time >> dx >> dy;
        
        joints[i].pos.x = joints[i - 1].pos.x + dx;
        joints[i].pos.y = joints[i - 1].pos.y + dy;
    }
    
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        double time;
        cin >> time;
        
        Vec2 res = solve(time);
        
        cout << "Case " << i + 1 << ": (" << res.x << ", " << res.y << ")\n";
    }
}

