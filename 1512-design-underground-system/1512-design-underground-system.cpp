class UndergroundSystem {
    map<int,pair<string,int>>inOut;
    map<pair<string,string>,pair<double,int>> stations;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        inOut[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string st1=inOut[id].first;
        int time=inOut[id].second;
        inOut.erase(id);
        int diff=t-time;
        if(stations.count({st1,stationName})){
            auto st=stations[{st1,stationName}];
            int num=st.second;
            double sum=st.first;
            double newSum=sum+diff;
            stations[{st1,stationName}]={newSum,num+1};
        }
        else{
            stations[{st1,stationName}]={(double)diff,1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        return stations[{startStation,endStation}].first/stations[{startStation,endStation}].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */