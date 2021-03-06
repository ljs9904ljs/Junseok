#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;




vector<string> line_parsing(string &buf, char delimeter = ',') {
    vector<string> result;
    stringstream ss(buf);
    while(ss.good()) {
        string substr;
        getline(ss, substr, delimeter);
        result.push_back(substr);
    }
    return result;
}

void file_parsing(fstream &infile, vector<vector<string> > &list) {
    while(!infile.eof()) {
        string str_buf;
        getline(infile, str_buf, '\n');

        list.push_back(line_parsing(str_buf));
    }
}

void dump(vector<vector<string> > v) {
    static int count = 1;
    //std::locale::global(std::locale("Korean"));
    //fstream outfile;
    //outfile.open("result.txt", ios::out);
    
    fstream out;
    out.open("C_C++_Projects\\CPP_files\\parsing\\res.txt", ios::out);
    
    for(auto list : v) {
        out << "[" << count++ << "] ";
        for(auto elem : list) {
            out << elem.c_str() << " ";
        }
        out << "\n";
    }
    out.close();
}

int main() {
    fstream students, grades;
    vector<vector<string> > student_list;
    vector<vector<string> > grade_list;
    vector<string> tmp;
    vector<vector<string> > result;

    students.open("C:\\Users\\user\\Desktop\\students.csv", ios::in);
    grades.open("C:\\Users\\user\\Desktop\\csed211.csv", ios::in);

    file_parsing(students, student_list);
    file_parsing(grades, grade_list);

    students.close();
    grades.close();

    for(auto s : student_list) {
        int code = static_cast<int>(sqrt(atoi(s.at(1).c_str())) * 100000) % 10000;
        //cout << code << " -> s.at(1) -> " << s.at(1) << endl;
        
        
        for(auto g : grade_list) {
            
            if(code == atoi(g.at(0).c_str()) ) {
                
                tmp.push_back(to_string(code));
                tmp.push_back(g[1]);

                for(int i=0; i<4; i++) {
                    tmp.push_back(s[i]);
                }
                result.push_back(tmp);
                tmp.clear();
                
                break;
            }
            if(atoi(g.at(0).c_str()) == 9907) break;
        }
        
       
       if(code == 2494) break;
    }
    
    dump(result);


    return 0;
}