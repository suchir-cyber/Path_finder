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

    void Edge(T u, T v, float dist, bool isBidirex=true)
    {
        adjList[u].push_back(make_pair(v,dist));
        if(isBidirex)
        {
            adjList[v].push_back(make_pair(u,dist));
        }
    }


    void DijkstraGetShortestPathTo(T destination, map<T,T> &prev)
    {
        for( ; destination != ""; destination = prev[destination])
        {
            path.push_back(destination);
        }
        path.reverse();
        cout<<"\t\t\t";
        //--
        copy(path.begin(), path.end(), ostream_iterator<T>(cout, "\n\t\t\t"));
    }

    void dijsktraSSSP(T,map<T,float> &dist, map<T,T> &prev);

   

    bool check(string, string);
    void calcPrice(string, string);

          
};

int main(){
   
    
    string source, destination;
    Graph<string> Metro;

    
    map<string,float> dist;
    map<string,string> prev;
    string sourcestn, deststn;
    cout<<endl<<endl<<endl;

    
    cout<<"Enter source station: ";
    getline(cin,sourcestn);
    cout<<endl;

    cout<<"Enter destination station: ";
    getline(cin,deststn);
    

    
    Metro.dijsktraSSSP(sourcestn, dist, prev);
    
    
    cout<<"Distance from "<<sourcestn<<" to "<<deststn<<" - "<<dist[deststn]<<" Kms"<<endl;
    cout<<endl<<"\t\tPath: "<<endl;
    Metro.DijkstraGetShortestPathTo(deststn,prev);
    Metro.calcPrice(sourcestn,deststn);
    cout<<endl;

    return 0;
}
