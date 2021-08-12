#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Examinee
{
    string id;
    float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science,
    social_science, foreign_language;
};

Examinee readExaminee(string line_info){
    stringstream s(line_info);
    Examinee a;
    getline(s, a.id, ',');
    string math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science,
    social_science, foreign_language;
    getline(s, math, ',');
    getline(s, math, ',');
    getline(s, literature, ',');
    getline(s, physic, ',');
    getline(s, chemistry, ',');
    getline(s, biology, ',');
    getline(s, history, ',');
    getline(s, geography, ',');
    getline(s, civic_education, ',');
    getline(s, natural_science, ',');
    getline(s, social_science, ',');
    getline(s, foreign_language, ',');
    a.math = stof(math!="" ? math : "0");
    a.literature = stof(literature != "" ? literature : "0");
    a.physic = stof(physic!="" ? physic : "0");
    a.chemistry = stof(chemistry!=""  ? chemistry : "0");
    a.biology = stof(biology!="" ? biology : "0");
    a.history = stof(history!="" ? history : "0");
    a.geography = stof(geography!="" ? geography : "0");
    a.civic_education = stof(civic_education != "" ? civic_education : "0");
    a.natural_science = stof(natural_science != "" ? natural_science : "0");
    a.social_science = stof(social_science != "" ? social_science : "0");
    a.foreign_language = stof(foreign_language != "" ? foreign_language : "0");
    return a;
}

vector<Examinee> readExamineeList(string file_name){
    vector<Examinee> list;
    ifstream file(file_name);
    string t;
    getline(file, t);
    while (!file.eof())
    {
        getline(file,t);
        list.push_back(readExaminee(t));
    }
    file.close();
    return list;
}

float total(Examinee &contestant){
    contestant.natural_science = contestant.physic + contestant.chemistry + contestant.biology;
    contestant.social_science = contestant.geography + contestant.history + contestant.civic_education;
    float sum = contestant.math+ contestant.literature+ contestant.foreign_language+ contestant.natural_science + contestant.social_science;
    return sum;
}

void writeTotal(vector<Examinee> examinee_list, string out_file_name){
    ofstream file(out_file_name);
    for (int i = 0; i < examinee_list.size(); i++)
    {
        file << examinee_list[i].id << " " << total(examinee_list[i]) <<endl;
    }
    file.close();
}

int main()
{
    vector<Examinee> list;
    list = readExamineeList("data.txt");
    writeTotal(list,"writeFile.txt");
    system("pause");
    return 0;
}
