#include "io/seqio.h"

namespace as4::io
{
    namespace operators
    {
        /* Put your code here */
        std::ofstream& operator<<(std::ofstream& fout, as4::model::VectorSeq& seq)
        {
            using namespace std;
            string sdfa;

            std::vector<as4::model::Note*> temp;
            temp = seq.GetOrdered();
            for(size_t i=0;i<temp.size();i++){
                fout << temp.front()->GetPitch();
            }
        }
    }
}
