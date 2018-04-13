#include <iostream>

using namespace std;

struct Span
{
    int left, right;
    int y;
};

struct Pixel
{
    char color;
    int depth;
};

Pixel screen[240][320];

int screenW, screenH;
int viewportW, viewportH;
int viewportX, viewportY;

void drawSpan(Span& span, int depth, char color)
{
    if(span.y < viewportY || span.y >= viewportY + viewportH)
        return;
    
    span.left = max(span.left, viewportX);
    span.right = min(span.right, viewportX + viewportW - 1);
    
    if(span.left > span.right)
        return;
    
    for(int i = span.left; i <= span.right; ++i)
    {
        int x = i - viewportX;
        int y = span.y - viewportY;
        
        if(depth > screen[y][x].depth)
        {
            screen[y][x].depth = depth;
            screen[y][x].color = color;
        }
    }
}

int main()
{
    
    cin >> screenW >> screenH;
    cin >> viewportW >> viewportH;
    cin >> viewportX >> viewportY;
    
    for(int i = 0; i < viewportH; ++i)
    {
        for(int j = 0; j < viewportW; ++j)
        {
            screen[i][j].depth = 0;
            screen[i][j].color = ' ';
        }
    }
    
    int totalPolygons;
    cin >> totalPolygons;
    
    for(int i = 0; i < totalPolygons; ++i)
    {
        char color;
        cin >> color;
        
        int totalSpans;
        int depth;
        cin >> totalSpans >> depth;
        
        for(int j = 0; j < totalSpans; ++j)
        {
            Span s;
            cin >> s.left >> s.right >> s.y;
            
            drawSpan(s, depth, color);
        }
    }
    
    for(int i = 0; i < viewportH; ++i)
    {
        for(int j = 0; j < viewportW; ++j)
        {
            cout << screen[i][j].color << " ";
        }
        
        cout << endl;
    }
}



