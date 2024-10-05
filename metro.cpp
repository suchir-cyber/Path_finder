#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
#include<list>
using namespace std;
template<typename T>

class Graph
{
private:
    map<T, list<pair<T,float>>> adjList;

public:
    list<T> path;

    void Edge(T u, T v, float dist)
    {
        adjList[u].push_back(make_pair(v,dist));
        adjList[v].push_back(make_pair(u,dist));
    }


    void Path(T destination, map<T,T> &prev)
    {
        for( ; destination != ""; destination = prev[destination])
        {
            path.push_back(destination);
        }
        path.reverse();

        copy(path.begin(), path.end(), ostream_iterator<T>(cout, "\n\t\t\t"));
    }

    void dijsktra(T,map<T,float> &dist, map<T,T> &prev);
    bool check(string, string);
};

int main(){
   
    
    string source, destination;
    Graph<string> Metro;

    
    map<string,float> dist;
    map<string,string> prev;
    string src, dest;
    cout<<endl<<endl<<endl;

    
    cout<<"Enter source station: ";
    getline(cin,src);
    cout<<endl;

    cout<<"Enter destination station: ";
    getline(cin,dest);
    

    
    Metro.dijsktra(src, dist, prev);
    
    
    cout<<"Distance from "<<src<<" station to "<<dest<<" station - "<<dist[dest]<<" Kms"<<endl;
    cout<<endl<<"\t\tPath: "<<endl;
    Metro.Path(dest,prev);
    cout<<endl;

    return 0;
}
