#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::string;

// class for counting motives, which lie in density zones
class CMotiveCounter
{

private:

    std::ifstream fs_motif_coord; //
    std::ifstream fs_zones_coord;
    std::ofstream fs_output;

    long int a;

public:

    CMotiveCounter(const string& mot_coord_fname, const string& zon_coord_fname, const string& output_fname)
    {

        if(&mot_coord_fname == NULL)
            throw "mot_coord_fname invalid fname";
        if(&zon_coord_fname == NULL)
            throw "zon_coord_fname invalid fname";
        if(&output_fname == NULL)
            throw "output invalid fname";

        fs_motif_coord.open(mot_coord_fname.data());
        fs_zones_coord.open(zon_coord_fname.data());
        fs_output.open(output_fname.data());

    }

    ~CMotiveCounter()
    {

        fs_motif_coord.close();
        fs_zones_coord.close();
        fs_output.close();

    }

    void Run()
    {

        string smth;

        fs_motif_coord >> smth;
        fs_output << "Hello biology!\n" << smth;

    }

};

int main()
{

    try
    {

        string motifes_fname = "data/motifes_coordinates/M0101_1.02.txt.chipmunk.1e-4.bed";
        string zones_fname   = "data/motifes_coordinates/M0101_1.02.txt.chipmunk.1e-4.bed";
        string output        = "output.txt";

        CMotiveCounter counter(motifes_fname, zones_fname, output);
        counter.Run();

        cout << "Hello biology!\n";

    }
    catch(const char* err)
    {

        cout << err << "\n";

    }


    return 0;

}
