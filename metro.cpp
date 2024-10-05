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
    // function for add the station mapping to system
    void Edge(T u, T v, float dist, bool isBidirex=true)
    {
        adjList[u].push_back(make_pair(v,dist));
        if(isBidirex)
        {
            adjList[v].push_back(make_pair(u,dist));
        }
    }

    // function to store the all the station to list
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
    void makedotfile();
    vector<string> split (const string &s, char delim)
    {
        vector<string> result;
        stringstream ss (s);
        string item;

        while (getline (ss, item, delim))
        {
            result.push_back (item);
        }

        return result;
    }

    bool check(string, string);
    void calcPrice(string, string);

          
};

int main(){
   
    
    string source, destination;
    Graph<string> Metro;
    //red
    
    map<string,float> dist;
    map<string,string> prev;
    string sourcestn, deststn;
    cout<<endl<<endl<<endl;

    system("echo  \"\e[32m\""); //green
    cout<<"\t\t";
    cout<<"Enter source station: ";
    getline(cin,sourcestn);
    cout<<endl;

    system("echo  \"\e[33m\""); //yellow
    cout<<"\t\t";
    cout<<"Enter destination station: ";
    getline(cin,deststn);
    

    
    Metro.dijsktraSSSP(sourcestn, dist, prev);
    
    system("echo  \"\e[34m\"");  // blue
    cout<<endl<<"\t\t";
    cout<<"Distance from "<<sourcestn<<" to "<<deststn<<" - "<<dist[deststn]<<" Kms"<<endl;
    cout<<endl<<"\t\tPath: "<<endl;
    Metro.DijkstraGetShortestPathTo(deststn,prev);
    Metro.makedotfile();
    Metro.calcPrice(sourcestn,deststn);
    cout<<endl;

    //system("dot -Tpng finalmap.dot > path.png");
    return 0;
}
