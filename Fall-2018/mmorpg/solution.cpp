#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;

int nextPacket;
vector<int> generatedSeqeunces;

string randstr()
{
    string s;
    int len = rand() % 20 + 1;

    for(int i = 0; i < len; ++i)
    {
        s += (char)((rand() % 26) + 'a');
    }

    return s;
}

int calcChecksum(string data)
{
     int sum = 0;
    for(char c : data)
    {
        sum += c;
    }

    return sum;
}

struct Packet
{
    bool hasValidChecksum() const
    {
        return checksum == calcChecksum(data);
    }

    bool operator<(const Packet& p) const
    {
        return sequence > p.sequence;
    }

    int sequence;
    string data;
    int checksum;
};

Packet good()
{
    Packet p;
    p.sequence = nextPacket++;
    p.data = randstr();

    generatedSeqeunces.push_back(p.sequence);

    p.checksum = calcChecksum(p.data);

    return p;
}

Packet bad()
{
    Packet p = good();
    p.checksum = rand();

    return p;
}

Packet duplicate()
{
    if(nextPacket == 0)
    {
        return good();
    }

    Packet p;
    p.data = randstr();
    p.checksum = 0;
    p.sequence = generatedSeqeunces[rand() % generatedSeqeunces.size()];

    return p;
};

void drop()
{
    ++nextPacket;
}

priority_queue<Packet> packetQueue;
set<Packet> alreadyReceived;

int timeToLive = 0;
int currentSequence;
int minAllowedPacket;

void receivePacket(const Packet& packet)
{
    if(packet.hasValidChecksum())
    {
        printf("%d: valid %s\n", currentSequence, packet.data.c_str());
    }
    else
    {
        printf("%d: corrupt\n", currentSequence);
    }
}

void dropPacket()
{
    printf("%d: dropped\n", currentSequence);
}

void processPacketUntil(int seq)
{
    while(currentSequence < seq && packetQueue.size() != 0)
    {
        if(packetQueue.top().sequence == currentSequence)
        {
            receivePacket(packetQueue.top());
            packetQueue.pop();
        }
        else
        {
            dropPacket();
        }

        ++currentSequence;
    }
}

void processPacket(const Packet packet)
{
    if(packet.sequence < minAllowedPacket)
    {
        return;
    }

    if(alreadyReceived.count(packet) != 0)
    {
        return;
    }

    alreadyReceived.insert(packet);

    minAllowedPacket = max(minAllowedPacket, packet.sequence - timeToLive);
    processPacketUntil(minAllowedPacket);

    packetQueue.push(packet);
}

void flushQueue()
{
    processPacketUntil(1000000);
}

void printPacket(const Packet& p)
{
    cout << p.sequence << " " << p.data << " " << p.checksum << endl;
}

void genTestCase()
{
    srand(time(nullptr));

    int ttl = rand() % 1000;
    cout << ttl << endl;

    int total = rand() % 1000;

    for(int i = 0; i < total; ++i)
    {
        int opt = rand() % 4;
        Packet p;

        switch(opt)
        {
            case 0:
                p = good();
                break;

            case 1:
                p = bad();
                break;

            case 2:
                drop();
                continue;

            case 3:
                p = duplicate();
                break;
        }

        printPacket(p);
    }

    Packet end;
    end.data = "end";
    end.sequence = generatedSeqeunces[generatedSeqeunces.size() - 1] + 1;
    end.checksum = calcChecksum(end.data);

    printPacket(end);
}

void run()
{
    cin >> timeToLive;

    do
    {
        Packet p;
        cin >> p.sequence;
        cin >> p.data >> p.checksum;

        processPacket(p);

        if(p.data == "end")
        {
            break;
        }
    } while(true);

    flushQueue();
}

int main()
{
#if 1
    run();
#else
    genTestCase();
#endif
}