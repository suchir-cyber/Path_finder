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

    
    // ------- RED LINE-------

    
    
    Metro.Edge("Miyapur","Jntu college",2.6);//1 to 2
    Metro.Edge("Jntu college","Kphb colony",2.4);//2 to 3
    Metro.Edge("Kphb colony","Kukatpally",1.4);// 3 to 4
    Metro.Edge("Kukatpally","Dr BR Ambedkar Balanagar",1.2);//4 to 5
    Metro.Edge("Dr BR Ambedkar Balanagar","Moosapet",1.3);//5 to 6
    Metro.Edge("Moosapet","Bharat nagar",1.9);//6 to 7
    Metro.Edge("Bharat nagar","Erragadda",2.6);//7 to 8
    Metro.Edge("Erragadda","Esi hospital",1.6);//8 to 9
    Metro.Edge("Esi hospital","Sr nagar",0.7);//9 to 10
    Metro.Edge("Sr nagar","Ameerpet",0.6);//10 to 11
    Metro.Edge("Ameerpe","Punjagutta",1.1);//11 to 12
    Metro.Edge("Punjagutta","Irrum manzil",1.3);//12 to 13
    Metro.Edge("Irrum manzil","Khairatabad",2.2);//13 to 14
    Metro.Edge("Khairatabad","Lakdi ka pul",1.6);//14 to 15
    Metro.Edge("Lakdi ka pul","Assembly",3.7);//15 to 16
    Metro.Edge("Assembly","Nampally",0.6);//16 to 17
    Metro.Edge("Nampally","Gandhi Bhavan",1.4);//17 to 18
    Metro.Edge("Gandhi Bhavan","Osmania medical college",0.8);//18 to 19
    Metro.Edge("Osmania medical college","Mg bus station",0.9);//19 to 20
    Metro.Edge("Mg bus station","Malakpet",2.4);//20 to 21
    Metro.Edge("Malakpet","New market",0.073);//21 to 22
    Metro.Edge("New market","Musarambagh",1.1);//22 to 23
    Metro.Edge("Musarambagh","Dilsukhnagar",1.4);//23 to 24
    Metro.Edge("Dilsukhnagar","Chaitanyapuri",1);//24 to 25
    Metro.Edge("Chaitanyapuri","Victoria Memorial",1.3);//25 to 26
    Metro.Edge("Victoria Memorial","LB Nagar",3.1);//26 to 27
    


    // ------BLUE LINE-------

    

    Metro.Edge("Nagole","Uppal",1);//1 to 2
    Metro.Edge("Uppal","Stadium",1.5);//2 to 3
    Metro.Edge("Stadium","Ngri",1.9);//3 to 4
    Metro.Edge("Ngri","Habsiguda",0.95);//4 to 5
    Metro.Edge("Habsiguda","Tarnaka",1.5);//5 to 6
    Metro.Edge("Tarnaka","Mettuguda",1.2);//6 to 7
    Metro.Edge("Mettuguda","Secunderabad east",2);//7 to 8
    Metro.Edge("Secunderabad east","Jbs parade ground",1.8);//8 to 9
    Metro.Edge("Jbs parade ground","Paradise",2.6);//9 to 10
    Metro.Edge("Paradise","Rasoolpura",1.1);//10 to 11
    Metro.Edge("Rasoolpura","Prakash nagar",1.1);//11 to 12
    Metro.Edge("Prakash nagar","Begumpet",1.4);//12 to 13
    Metro.Edge("Begumpet","Ameerpet",1.9);//13 to 14
    Metro.Edge("Ameerpet","Madhura nagar",0.75);//14 to 15
    Metro.Edge("Madhura nagar","Yousufguda",1.4);//15 to 16
    Metro.Edge("Yousufguda","Jubilee hills road No 5",0.75);//16 to 17
    Metro.Edge("Jubilee hills road No 5","Jubilee hills check post",1.3);//17 to 18
    Metro.Edge("Jubilee hills check post","Peddamma temple",0.65);//18 to 19
    Metro.Edge("Peddamma temple","Madhapur",1.1);//19 to 20
    Metro.Edge("Madhapur","Durgam cheruvu",1.7);//20 to 21
    Metro.Edge("Durgam cheruvu","Hitec city",0.75);//21 to 22
    Metro.Edge("Hitec city","Raidurg",1.4);//22 to 23
    


    // -------GREEEN LINE--------

    

    Metro.Edge("Jbs parade ground","Secunderabad west",1.5);//1 to 2
    Metro.Edge("Secunderabad west","Gandhi hospital",1.6);//2 to 3
    Metro.Edge("Gandhi hospital","Musheerabad",0.75);//3 to 4
    Metro.Edge("Musheerabad","Rtc x road",2);//4 to 5
    Metro.Edge("Rtc x road","Chikadpally",0.8);//5 to 6
    Metro.Edge("Chikadpally","Narayanguda",0.75);//6 to 7
    Metro.Edge("Narayanguda","Sultan bazar",1.9);//7 to 8
    Metro.Edge("Sultan bazar","Mg bus station",1.4);//8 to 9


    
    
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
