#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Span
{
    int left, right;
    int y;
};

struct CircleRenderer
{
    CircleRenderer(int xc_, int yc_, int r_) : xc(xc_), yc(yc_), r(r_)
    {
        spans.resize(2 * r + 1);
        
        for(int i = 0; i < 2 * r + 1; ++i)
        {
            spans[i].left = 0x7FFFFFFF;
            spans[i].right = -0x7FFFFFFF;
            spans[i].y = i - r + yc;
        }
    }
    
    void putpixel(int x, int y)
    {
        Span& s = spans[y + r - yc];
        
        
        s.left = min(s.left, x);
        s.right = max(s.right, x);
    }
    
    vector<Span>& render()
    {
        for(long long y = yc - r; y <= yc + r; ++y)
        {
            for(long long x = xc - r; x <= xc + r; ++x)
            {
                float dx = x - xc + 0.5;
                float dy = y - yc + 0.5;
                
                if(dx * dx + dy * dy <= r * r)
                    putpixel(x, y);
            }
        }
        
        return spans;
    }
    
    int xc;
    int yc;
    int r;
    vector<Span> spans;
};

struct Polygon
{
    vector<Span> spans;
    char color;
    int depth;
};

Polygon poly[10000];

int totalPoly;
int totalSpans;

const int MAX_SPANS = 100000;
const int MAX_POLY = 10000;

int screenW, screenH;
int viewportW, viewportH;
int viewportX, viewportY;

void clipSpans(vector<Span>& spans)
{
    int writePos = 0;
    
    for(int i = 0; i < (int)spans.size(); ++i)
    {
        spans[i].left = max(spans[i].left, 0);
        spans[i].right = min(spans[i].right, screenW - 1);
        
        if(spans[i].left <= spans[i].right && spans[i].y >= 0 && spans[i].y < screenH)
            spans[writePos++] = spans[i];
    }
    
    spans.resize(writePos);
}

void addPolygon(vector<Span>& spans, int color, int depth)
{
    if(totalPoly > MAX_POLY)
        return;
    
    clipSpans(spans);
    
    int totalSpansToAdd = min((int)spans.size(), MAX_SPANS - totalSpans);
    
    if(totalSpansToAdd <= 0)
        return;
    
    spans.resize(totalSpansToAdd);
    
    poly[totalPoly].spans = spans;
    poly[totalPoly].depth = depth;
    poly[totalPoly].color = color;
    
    totalSpans += totalSpansToAdd;
    
    ++totalPoly;
}

void addCirclePolygon(int xc, int yc, int r, int color, int depth)
{
    CircleRenderer renderer(xc, yc, r);
    addPolygon(renderer.render(), color, depth);
}

void addRectanglePolygon(int x1, int y1, int x2, int y2, int color, int depth)
{
    vector<Span> spans;
    
    for(int y = y1; y <= y2; ++y)
    {
        Span s;
        s.left = x1;
        s.right = x2;
        s.y = y;
        
        spans.push_back(s);
    }
    
    addPolygon(spans, color, depth);
}

#include <ctime>

void addSpanFile(const char* fileName)
{
    srand(time(NULL));
    
    ifstream file(fileName);
    if(!file.is_open())
    {
        throw -1;
    }
    
    char c[] = ".#^X-|/\\@";
    
    char subset[50];
    
    int subsize = rand() % 50;
    
    for(int i = 0; i < subsize; ++i)
    {
        subset[i] = c[rand() % sizeof(c - 1)];
    }
    
    char colors[] = "";
    
    int i = 0;
    
    do
    {
        vector<Span> spans;
        
        int color;
        file >> color;
        
        if(color == -1)
            break;

        
        do
        {
            Span s;
            file >> s.left >> s.right >> s.y;
            
            if(s.y == -100)
                break;
            
            spans.push_back(s);
        } while(true);
        
        --i;
        
        addPolygon(spans, subset[color % subsize], i + 10000);
    } while(true);
}

void write()
{
    cout << screenW << " " << screenH << endl;
    cout << viewportW << " " << viewportH << endl;
    cout << viewportX << " " << viewportY << endl;
    
    cout << totalPoly << endl;
    
    for(int i = 0; i < totalPoly; ++i)
    {
        cout << poly[i].color << " " << poly[i].spans.size() << " " << poly[i].depth << endl;
        
        for(int j = 0; j < poly[i].spans.size(); ++j)
        {
            Span s = poly[i].spans[j];
            cout << s.left << " " << s.right << " " << s.y << endl;
        }
    }
}

void genSample1()
{
    screenW = 12;
    screenH = 12;
    
    viewportW = 12;
    viewportH = 12;
    
    viewportX = 0;
    viewportY = 0;
    
    addRectanglePolygon(1, 1, 8, 8, '.', 5);
    addCirclePolygon(8, 8, 4, '#', 10);
    
    write();
}

void genX3dSample()
{
    screenW = 80;
    screenH = 60;
    
    viewportW = 80;
    viewportH = 60;
    
    viewportX = 0;
    viewportY = 0;
    
    addSpanFile("quake.in");
    write();
}

int main()
{
    genX3dSample();
}




