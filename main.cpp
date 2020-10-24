// #include "serialization.h"
#include "serializeToFiles.h"
#include <map>
#include <vector>
using namespace stl_serialization;
#include <boost/serialization/map.hpp>
#include <boost/serialization/vector.hpp>
#include <string>
#include <iostream>
using namespace std;

template <class T1, class T2>
class MapSerialization : public Serialization<map<T1, T2>>
{
};

int main(int argc, char *argv[])
{
    int _size = 10;
    std::ostringstream _ost;
    MapSerialization<int, vector<int>> ms_src;
    int t;
    for(int i=0;i<_size;i++){
        vector<int> temp;
        for(t=0;t<=i;t++){
            temp.push_back(t);
        }
        ms_src[i]=temp;
    }
    ms_src.serialization(_ost,"test.bin"); //  oa  << _ost
    MapSerialization<int, vector<int>> ms_des;
    std::istringstream ist(_ost.str());// initial from _ost
    // ms_des.unserialization(ist);
    ms_des.unserialization("test.bin");
    for (std::map<int, vector<int>>::iterator it = ms_des.begin(); it != ms_des.end(); it++)
    {
        int k = it->first;
        for (int k = 0; k <= it->first; k++)
        {
            cout << it->second[k]<<endl;
        }
    }
}