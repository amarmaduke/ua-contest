#include <iostream>
#include <fstream>

using namespace std;

int fail(string failure)
{
    cout << failure << endl;
    return 43;
}

double x[200001];
double y[200001];

int main(int argc, char *argv[])
{
    ifstream problemInput;
	problemInput.open(argv[1]);
    
    int queries = 0;
    
    cout << "In pto..." << endl;
    
    while(problemInput >> x[queries] >> y[queries])
    {
        ++queries;
    }
    
    double xx, yy;
    int count = 0;
    
    double maxError = 10e-6;
    
    while(cin >> xx >> yy)
    {
        if(count >= queries)
        {
            return fail("Excessive output");
        }
        
        double diffx = abs(x[count] - xx);
        double diffy = abs(y[count] - yy);
        
        if(diffx > maxError || diffy > maxError)
        {
            if(diffx < 0.1 && diffy < 0.1)
            {
                return fail("Small error - probably not enough digits");
            }
            else
            {
                char buf[1024];
                sprintf(buf, "Significant difference - wrong answer. Correct (%.7f, %.7f), given (%.7f, %.7f)", x[count], y[count], xx, yy);
                
                return fail(buf);
            }
        }
        
        ++count;
    }
    
    if(count < queries)
    {
        return fail("Not enough answers");
    }
    
    cout << "Accepted" << endl;
    
    return 42;
}

