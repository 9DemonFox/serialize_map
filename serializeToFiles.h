#ifndef STLSERIALIZATION_SERIALIZATION_H
#define STLSERIALIZATION_SERIALIZATION_H

#include <string>
#include <sstream>
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
using namespace std;


namespace stl_serialization
{

    template <class T>
    class Serialization : public T
    {
    public:
        void serialization(std::ostringstream &ostream,const char* filePath)
        {
            boost::archive::binary_oarchive oa(ostream);
            oa << *this;
            fstream file;
            file.open(filePath,ios::binary|ios::out);
            file << ostream.str(); // write date to file
        }

        void unserialization(std::istringstream &istream)
        {
            boost::archive::binary_iarchive ia(istream);
            ia >> *this;
        }

        void unserialization(const char* filePath)
        {
            ifstream file(filePath,ifstream::in);
            ostringstream ost;
            ost << file.rdbuf();
            istringstream istream(ost.str());
            boost::archive::binary_iarchive ia(istream);
            ia >> *this; // write date to file
        }

    private:
        friend class boost::serialization::access;

        template <class Archive>
        void serialize(Archive &ar, const unsigned int version)
        {
            ar &boost::serialization::base_object<T>(*this);
        }
    };

} // namespace stl_serialization

#endif // STLSERIALIZATION_SERIALIZATION_H